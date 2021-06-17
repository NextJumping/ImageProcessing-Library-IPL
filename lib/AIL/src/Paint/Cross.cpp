
#ifndef IMAGE__Cross_CPP_H
#define IMAGE__Cross_CPP_H

#include "Cross.h"

namespace Paint {

//TODO use ImageSize
Image::Image<Pixel::PixelYb1> MakeCross(const I4 & width,const I4 & height){
	return MakeCross(width,height,width/2,height/2);
}

Image::Image<P