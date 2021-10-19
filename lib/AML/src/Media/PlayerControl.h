
#ifndef MEDIA__PLAYER__Control_H
#define MEDIA__PLAYER__Control_H

#include "AML.h"
#include <Data/DataTypes.h>
#include <Media/PlayerControlPacket.h>

#include <agents.h>

namespace Media {

namespace Player {

class AML_DLL_EXPORT Control {
	public:
		typedef Control ThisType;

		Control(Concurrency::ITarget<ControlPacket> & _controlQueue):controlQueue(_controlQueue){};

		void open(const std::string & fileName);
		void open(const std::string & fileName,const B1 & autoPlay);
		void close();
		void play();
		