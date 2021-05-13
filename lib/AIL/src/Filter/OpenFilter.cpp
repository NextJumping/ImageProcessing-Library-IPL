
#include "OpenFilter.h"
#include "ErodeFilter.h"
#include "DilateFilter.h"

namespace Filter {

template <
	typename PixelType
> void OpenFilter<PixelType>::applyTo(const Image::Image<PixelType> & srcImage,Image::Image<PixelType> & dstImage) const {
	ErodeFilter <PixelType> erodeFilter (iterations,type);
	DilateFilter<PixelType> dilateFilter(itera