
#ifndef PIXEL__PixelY_H
#define PIXEL__PixelY_H

#include <AIL.h>
#include <Meta/TypeVector.h>
#include <Meta/Boolean.h>
#include "PixelDataType1.h"
#include "PixelRange.h"

namespace Pixel {

template <
	typename NumberType,
	typename ComputationDataType,
	typename PixelRangeType
> class PixelYbaseType
	: public PixelDataType1<NumberType>
{
	public:

		typedef typename NumberType                 NumberType;
		typedef typename PixelRangeType             R