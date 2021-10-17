
#include "PlayerControl.h"

namespace Media {

namespace Player {

void AML_DLL_EXPORT Control::open(const std::string & fileName){
	open(fileName,true);
}
void AML_DLL_EXPORT Control::open(const std::string & fileName,const B1 & autoPlay){
	auto messageParameter = new CommandOpenParameter(fileName,autoPlay);
	auto controlPacket = ControlPacket(Command::open,messageParameter);
	Concurrency::asend(controlQueue,controlPacket);
}
void AML_DLL_EXPORT Control::close(){
	auto controlPacket = ControlPacket(Command::close);
	Concurrency::asend(controlQueue,controlPacket);
}
void AML_DLL_EXPORT Control::play(){
	auto controlPacket = ControlPacket(Command::play);
	Concurrency::asend(controlQueue,controlPacket);
}
void AML_DLL_EXPORT Control::pause(){
	auto controlPacket = ControlPacket(Command::pa