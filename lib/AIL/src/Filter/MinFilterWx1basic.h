
#ifndef FILTER__MinFilterWx1basic_H
#define FILTER__MinFilterWx1basic_H

#include "BaseMinFilter.h"

namespace Filter {

template <
	typename PixelType
> class AIL_DLL_EXPORT MinFilterWx1basic {

	public:
		MinFilterWx1basic(
			const I4 & _filterWidth
		)
			:filterWidth(_filterWidth)	
			,xOffset( (_filterWidth - 1) / 2 )
		{
		};
		MinFilterWx