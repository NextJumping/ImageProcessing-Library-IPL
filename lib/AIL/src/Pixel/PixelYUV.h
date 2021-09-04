
#ifndef PIXEL__PixelYUV_H
#define PIXEL__PixelYUV_H

#include <AIL.h>
#include <Meta/TypeVector.h>
#include <Pixel/PixelTypeID.h>
#include <Pixel/PixelDataTypeY2.h>
#include <Pixel/PixelRange.h>
#include <Data/DataTypes.h>

namespace Pixel {

template <
	typename NumberType,
	typename ComputationDataType,
	typename PixelRangeType,
	int Yposition,
	int Uposition,
	int Vposition
> class AIL_DLL_EXPORT PixelYUVbaseType
	: public PixelDataTypeY2<NumberType,Yposition>
{
	public:

		typedef typename NumberType                            NumberType;
		typedef typename PixelRangeType                        RangeType;
		typedef PixelDataTypeY2<NumberType,Yposition>          DataType;
		typedef PixelDataTypeY2<ComputationDataType,Yposition> ComputationType;
		typedef PixelDataTypeY2<NumberType,Yposition>          ParentType;
		typedef PixelYUVbaseType<NumberType,ComputationDataType,PixelRangeType,Yposition,Uposition,Vposition> ThisType;

		FINLINE explicit PixelYUVbaseType(){}
		FINLINE explicit PixelYUVbaseType(const NumberType & _scalar):ParentType(_scalar){}
		FINLINE       