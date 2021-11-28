

#include "FFMPEGmediaPlayerAgent.h"

#include <Data/DataManager.h>
#include <Video/Frame.h>
#include <Video/Config.h>
#include <Audio/Frame.h>
#include <Audio/Config.h>
#include <limits.h>

#pragma warning (disable : 4244) // Ignore conversion from 'int64_t' to 'int32_t' - determined safe
#pragma warning (disable : 4005) // Ignore redefinition of macro UINT64_C
extern "C" {
#include <libavutil/avutil.h>
#include <libswscale/swscale.h>
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
}
#pragma warning (default : 4244)
#pragma warning (default : 4005)


namespace Media {

class AML_FFMPEG_DLL_EXPORT FFMPEGmediaPlayerAgent::FFMPEGmediaPlayerAgent_d {
	public:
		FFMPEGmediaPlayerAgent_d()
			:formatCtx(nullptr)
			,codecCtx(nullptr)
			,codec(nullptr)
			,frame(nullptr)
			,numBytes(0)
			,videoStreamID(0)
			,hasVideoStream(false)
			,audioStreamID(0)
			,hasAudioStream(false)
			,buffer(nullptr)
			,img_convert_ctx(nullptr)
		{
		}

		//Video Support
		AVFormatContext * formatCtx;
		AVCodecContext  * codecCtx;
		AVCodec         * codec;
		AVStream        * vStream;
		AVFrame         * frame;
		AVPacket          packet;
		int               numBytes;
		unsigned int      videoStreamID;
		bool              hasVideoStream;
		uint8_t         * buffer;
		SwsContext      * img_convert_ctx;

		//Audio Support
		AVCodecContext * aCodecCtx;
		AVCodec        * aCodec;
		AVFrame        * aFrame;
		AVStream       * aStream;
		unsigned int     audioStreamID;
		bool             hasAudioStream;
};

AML_FFMPEG_DLL_EXPORT FFMPEGmediaPlayerAgent::FFMPEGmediaPlayerAgent(Data::DataManager * const & _dataManager, Concurrency::ISource<Media::Player::ControlPacket> & _controlQueue , Thread::Queue::Pipe & _videoPipe, Thread::Queue::Pipe & _audioPipe)
	:dataManager(_dataManager)
	,controlQueue(_controlQueue)
	,videoPipe(_videoPipe)
	,audioPipe(_audioPipe)
	,flushID(0)
{
	_this = new FFMPEGmediaPlayerAgent_d;
	av_register_all();
	state = State::closed;
	_this->buffer    = nullptr;
	_this->frame     = nullptr;
	_this->aFrame    = nullptr;
	_this->codecCtx  = nullptr;
	_this->aCodecCtx = nullptr;
	_this->formatCtx = nullptr;
}
AML_FFMPEG_DLL_EXPORT FFMPEGmediaPlayerAgent::~FFMPEGmediaPlayerAgent(){
	closeFile();
	sws_freeContext(_this->img_convert_ctx);
	delete _this;
}
AML_FFMPEG_DLL_EXPORT void FFMPEGmediaPlayerAgent::sendFlush(){
	videoPipe.sendFlush();
	audioPipe.sendFlush();
}
AML_FFMPEG_DLL_EXPORT void FFMPEGmediaPlayerAgent::sendPause(){
	videoPipe.sendStop();
	audioPipe.sendStop();
	lastVideoTimeStamp = 0.0;
	lastVideoTimeDelta = 0.0;
	lastAudioTimeStamp = 0.0;
	lastAudioTimeDelta = 0.0;
	resetVideoTime = true;
	resetAudioTime = true;
}
AML_FFMPEG_DLL_EXPORT void FFMPEGmediaPlayerAgent::sendPlay(){
	videoPipe.sendStart();
	audioPipe.sendStart();
	lastVideoTimeStamp = 0.0;
	lastVideoTimeDelta = 0.0;
	lastAudioTimeStamp = 0.0;
	lastAudioTimeDelta = 0.0;
	resetVideoTime = true;
	resetAudioTime = true;
}
AML_FFMPEG_DLL_EXPORT void FFMPEGmediaPlayerAgent::sendQuit(){
	videoPipe.sendQuit();
	audioPipe.sendQuit();
}
AML_FFMPEG_DLL_EXPORT void FFMPEGmediaPlayerAgent::run(){
	auto & pCodecCtx  = _this->codecCtx;
	auto & pACodecCtx = _this->aCodecCtx;
	auto & pFrame     = _this->frame;
	auto & pAFrame    = _this->aFrame;
	auto & packet     = _this->packet;
	auto & hasVideoStream = _this->hasVideoStream;
	auto & hasAudioStream = _this->hasAudioStream;

	int frameFinished = 0;
	lastVideoTimeStamp = 0.0;
	lastVideoTimeDelta = 0.0;
	lastAudioTimeStamp = 0.0;
	lastAudioTimeDelta = 0.0;
	resetVideoTime = true;
	resetAudioTime = true;
	for(;;){
		Concurrency::Context::Yield();
		Media::Player::ControlPacket controlPacket;
		B1 gotControlPacket = false;
		if(state!=State::playing){
			controlPacket = Concurrency::receive(controlQueue);
			gotControlPacket=true;
		}else if(Concurrency::try_receive(controlQueue,controlPacket)==true){
			gotControlPacket=true;
		}
		if(gotControlPacket==true){
			const Media::Player::CommandOpenParameter      * openParameter      = nullptr;
			const Media::Player::CommandPlayPauseParameter * playPauseParameter = nullptr;
			const Media::Player::CommandSeekParameter      * seekParameter      = nullptr;
			int dir;
			int code;
			switch(controlPacket.getCommand()){
				case Media::Player::Command::play :
					if((state==State::stopped) || (state==State::paused)){
						state = State::playing;
						sendPlay();
					}
				break;
				case Media::Player::Command::pause :
					if(state==State::playing){
						state = State::paused;
						sendPause();
					}
				break;
				case Media::Player::Command::stop :
					if((state==State::playing)||(state==State::paused)){
						state = State::stopped;
						sendFlush();
						//TODO: Seek to beginning
					}
				break;
				case Media::Player::Command::playPause :
					if(controlPacket.getParameter()!=nullptr){
						playPauseParameter = static_cast<const Media::Player::CommandPlayPauseParameter * const>(controlPacket.getParameter());
						if(playPauseParameter->getState()==true){
							state = State::playing;
							sendPlay();
						}else if(playPauseParameter->getState()==false){
							state = State::paused;
							sendPause();
						}
						delete playPauseParameter;
					}else{
						if(state==State::playing){
							state = State::paused;
							sendPause();
						}else if(state==State::paused){
							state = State::playing;
							sendPlay();
						}
					}
				break;
				case Media::Player::Command::seek :
					seekParameter = static_cast<const Media::Player::CommandSeekParameter * const>(controlPacket.getParameter());
					sendFlush();
					videoFrameIndex = seekParameter->getVideoFrameIndex();
					audioFrameIndex = 0;
					dir = (seekParameter->getVideoFrameIndex() < videoFrameIndex) ? AVSEEK_FLAG_BACKWARD : 0;
					code = av_seek_frame(_this->formatCtx,_this->videoStreamID,seekParameter->getVideoFrameIndex(),dir | AVSEEK_FLAG_FRAME );
					if(code<0){
						//TODO: ERROR:
						dir=0;
					}
					if(state==State::playing){
						sendPlay();
					}
					delete seekParameter;
				break;
				case Media::Player::Command::open :
					if(state!=State::closed){
						closeFile();
					}
					sendFlush();
					openParameter = static_cast<const Media::Player::CommandOpenParameter * const>(controlPacket.getParameter());
					if(openFile(openParameter->getFileName())==true){
						if(openParameter->getAutoPlay()==true){
							state = State::playing;
							sendPlay();