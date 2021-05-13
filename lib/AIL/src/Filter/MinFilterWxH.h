

#ifndef FILTER__MinFilterWxH_H
#define FILTER__MinFilterWxH_H

#include "BaseMinFilter.h"

namespace Filter {

template <
	typename PixelType
> class AIL_DLL_EXPORT MinFilterWxH
	: public BaseMinFilter<PixelType>
{

	public:
		MinFilterWxH(I