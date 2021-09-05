
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
		FINLINE          PixelYUVbaseType(const DataType   & _pixel ):ParentType(_pixel ){}
		FINLINE          PixelYUVbaseType(const ThisType   & _pixel ):ParentType(_pixel ){}

		FINLINE explicit PixelYUVbaseType(const NumberType & _y,const NumberType & _u,const NumberType & _v){setY(_y);setU(_u);setV(_v);}

		FINLINE void setY(const NumberType & _y) {this->set<Yposition>(_y);}
		FINLINE void setU(const NumberType & _u) {this->set<Uposition>(_u);}
		FINLINE void setV(const NumberType & _v) {this->set<Vposition>(_v);}

		FINLINE void clip(){RangeType::clip(*static_cast<ParentType*>(this));}
		
		FINLINE NumberType & getY() {return this->get<Yposition>();}
		FINLINE NumberType & getU() {return this->get<Uposition>();}
		FINLINE NumberType & getV() {return this