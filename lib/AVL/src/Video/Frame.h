
#ifndef VIDEO__Frame_H
#define VIDEO__Frame_H

#include "AVL.h"
#include <Data/DataTypes.h>
#include <Image/Image.h>

namespace Video {

template<typename PixelType> class AVL_DLL_EXPORT Frame {
	public:
		typedef Frame ThisType;
		Frame(ThisType && other){
			image=other.image;
			timeStamp=other.timeStamp;
			frameIndex=other.frameIndex;
			other.image=nullptr;
			other.timeStamp=0;
			other.frameIndex=0;
		}
		Frame(Image::Image<PixelType> * const & _image,const F8 & _timeStamp,const I8u & _frameIndex):image(_image),timeStamp(_timeStamp),frameIndex(_frameIndex){}

		Image::Image<PixelType> * takeImage() {
			auto tempImage = image;
			image = nullptr;
			return tempImage;
		}

		const Image::Image<PixelType> * const & getI