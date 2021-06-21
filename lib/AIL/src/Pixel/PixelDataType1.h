
#ifndef PIXEL__PixelDataType1_H
#define PIXEL__PixelDataType1_H

#include <AIL.h>
#include <Data/DataTypes.h>

namespace Pixel {

template <
	typename NumberType
> class AIL_DLL_EXPORT PixelDataType1 {
	public:
		typedef NumberType                 NumberType;
		typedef PixelDataType1<NumberType> ThisType;

		FINLINE explicit Pixe