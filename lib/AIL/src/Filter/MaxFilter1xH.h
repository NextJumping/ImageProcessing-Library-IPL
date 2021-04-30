
#ifndef FILTER__MaxFilter1xH_H
#define FILTER__MaxFilter1xH_H

#include "BaseMaxFilter.h"

namespace Filter {

template <
	typename PixelType
> class AIL_DLL_EXPORT MaxFilter1xH
	: public BaseMaxFilter<PixelType>
{

	public:
		MaxFilter1xH(Image::Image<Pixel::PixelYb1> && _filt