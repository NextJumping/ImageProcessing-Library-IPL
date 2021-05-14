
#ifndef FILTER__OpenFilter_H
#define FILTER__OpenFilter_H

#include "AIL.h"
#include "ImageOperation.h"
#include "MorphKernelType.h"

namespace Filter {

template <
	typename PixelType
> class AIL_DLL_EXPORT OpenFilter
	: public ImageOperation<PixelType>
{

	public:
		OpenFilter():iterations(3),type(MorphKernelType::square){};
		OpenFilter(const I4 & _iterations):iterations(_iterations),type(MorphKernelType::square){};
		OpenFilter(const I4 & _iterations,const MorphKernelType & 