
#ifndef PIXEL__pixel_cast_H
#define PIXEL__pixel_cast_H

#include "PixelY.h"
#include "PixelRGB.h"
#include "PixelRGBA.h"
#include "PixelYUV.h"

namespace Pixel {

template <
	typename DstPixelType,
	typename SrcPixelType
> class pixel_cast_alg {
	public:
		static FINLINE void process(DstPixelType * const & dstPixel,const SrcPixelType * const & srcPixel){
			(*dstPixel) = pixel_cast<DstPixelType>(*srcPixel);
		}
};

// TODO: split these into seperate header files
template <typename DstPixelType,typename SrcPixelType> FINLINE DstPixelType pixel_cast(const SrcPixelType & color);

template <> FINLINE PixelYb1 pixel_cast<PixelYb1>(const PixelYi1u & _color){
	if(_color.getY()>128){return PixelYb1(true);}return PixelYb1(false);
}
template <> FINLINE PixelYb1 pixel_cast<PixelYb1>(const PixelYi4 & _color){
	if(_color.getY()>128){return PixelYb1(true);}return PixelYb1(false);
}
template <> FINLINE PixelYb1 pixel_cast<PixelYb1>(const PixelRGBi1u & _color){
	I8 tempY;
	tempY = static_cast<I8>(_color.getR())*299; // TODO: Check the asm generated for this line
	tempY+= static_cast<I8>(_color.getG())*587;
	tempY+= static_cast<I8>(_color.getB())*114;
	if(tempY>127500){return PixelYb1(true);}return PixelYb1(false); // 127500 = 0.5 * 255 * 1000
}
template <> FINLINE PixelYb1 pixel_cast<PixelYb1>(const PixelRGBi4 & _color){
	I8 tempY;
	tempY = static_cast<I8>(_color.getR())*299; // TODO: Check the asm generated for this line
	tempY+= static_cast<I8>(_color.getG())*587;
	tempY+= static_cast<I8>(_color.getB())*114;
	if(tempY>127500){return PixelYb1(true);}return PixelYb1(false