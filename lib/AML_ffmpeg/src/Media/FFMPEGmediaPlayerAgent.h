

#ifndef VIDEO__FFMPEGplayer_H
#define VIDEO__FFMPEGplayer_H

#include "AML_ffmpeg.h"
#include <Image/Image.h>

#include <Media/PlayerControlPacket.h>
#include <Thread/QueuePipe.h>
#include <Thread/QueueReaderAgentTarget.h>

#include <agents.h>
#include <string>

namespace Media {

class AML_FFMPEG_DLL_EXPORT FFMPEGmediaPlayerAgent : public Concurrency::agent {
	public:
		typedef FFMPEGmediaPlayerAgent ThisType;

		FFMPEGmediaPlayerAgent(Data::DataManager * const & _dataManager,Concurrency::ISo