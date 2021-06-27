
#ifndef PIXEL__PixelDataType3_H
#define PIXEL__PixelDataType3_H

#include <AIL.h>
#include <Data/DataTypes.h>

namespace Pixel {

template <
	typename NumberType
> class AIL_DLL_EXPORT PixelDataType3 {
	public:
		typedef NumberType                 NumberType;
		typedef PixelDataType3<NumberType> ThisType;

		FINLINE explicit PixelDataType3(){}
		FINLINE explicit PixelDataType3(const NumberType & _scalar):x(_scalar) ,y(_scalar) ,z(_scalar){}
		FINLINE explicit PixelDataType3(const NumberType & _scalar1,const NumberType & _scalar2,const NumberType & _scalar3):x(_scalar1) ,y(_scalar2) ,z(_sc