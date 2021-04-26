

#include "ErodeFilter.h"
#include "MinFilterWxH.h"
#include "MinFilterWx1basic.h"
#include "MinFilter1xHbasic.h"
#include "MorphFilterAlgorithm.h"
#include <Algorithm/BaseAlgorithm3x3.h>
#include <Paint/Cross.h>
#include <Paint/Circle.h>

namespace Filter {

template <
	typename PixelType
> void ErodeFilter<PixelType>::applyTo(const Image::Image<PixelType> & srcImage,Image::Image<PixelType> & dstImage) const {
	if(type==MorphKernelType::cross){
		this->applyToCross(srcImage,dstImage);
	}else if(type==MorphKernelType::square){
		this->applyToSquare(srcImage,dstImage);
	}else if(type==MorphKernelType::circle){