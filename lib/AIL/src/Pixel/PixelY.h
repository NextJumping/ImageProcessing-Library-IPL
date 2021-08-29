
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
		typedef typename PixelRangeType             RangeType;
		typedef PixelDataType1<NumberType>          DataType;
		typedef PixelDataType1<ComputationDataType> ComputationType;
		typedef PixelDataType1<NumberType>          ParentType;
		typedef PixelYbaseType<NumberType,ComputationDataType,PixelRangeType> ThisType;

		FINLINE explicit PixelYbaseType(){}
		FINLINE explicit PixelYbaseType(const NumberType & _scalar):ParentType(_scalar){}
		FINLINE          PixelYbaseType(const DataType   & _pixel ):ParentType(_pixel ){}
		FINLINE          PixelYbaseType(const ThisType   & _pixel ):ParentType(_pixel ){}

		FINLINE void setY(const NumberType & _y) {this->set<0>(_y);}

		FINLINE const NumberType & getY() const {return this->get<0>();}

};

typedef PixelYbaseType<B1 ,I4,PixelRange_1b1 > PixelYb1