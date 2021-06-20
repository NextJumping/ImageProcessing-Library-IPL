
#include "Gaussian.h"
#include <Image/Image.h>
#include <math.h> //For: exp()

namespace Paint {

template <typename PixelType> AIL_DLL_EXPORT Image::Image<PixelType> MakeGaussian(const I4 & width, const I4 & height,const F8 & sigma){
	return MakeGaussian<PixelType>(width,height,2*width+2*height,sigma);
}
template <typename PixelType> AIL_DLL_EXPORT Image::Image<PixelType> MakeGaussian(const I4 & width, const I4 & height,const F8 & radius,const F8 & sigma){
	return MakeGaussian<PixelType>(width,height,width/2,height/2,radius,sigma);
}
template <typename PixelType> AIL_DLL_EXPORT Image::Image<PixelType> MakeGaussian(const I4 & width, const I4 & height,const I4 & xCenter,c