
#ifndef PIXEL__Pixel_RGBA_H
#define PIXEL__Pixel_RGBA_H

#include <AIL.h>
#include <Meta/TypeVector.h>
#include <Pixel/PixelTypeID.h>
#include <Pixel/PixelDataType3A.h>
#include <Pixel/PixelRange.h>
#include <Data/DataTypes.h>

namespace Pixel {

template <
	typename NumberType,
	typename ComputationDataType,
	typename PixelRangeType,
	int Rposition,
	int Gposition,
	int Bposition,
	int Aposition
> class AIL_DLL_EXPORT PixelRGBAbaseType
	: public PixelDataType3A<NumberType,Rposition,Gposition,Bposition,Aposition>
{
	public:

		typedef typename NumberType     NumberType;
		typedef typename PixelRangeType RangeType;
		typedef PixelDataType3A<NumberType         ,Rposition,Gposition,Bposition,Aposition> DataType;
		typedef PixelDataType3A<ComputationDataType,Rposition,Gposition,Bposition,Aposition> ComputationType;
		typedef PixelDataType3A<NumberType         ,Rposition,Gposition,Bposition,Aposition> ParentType;
		typedef PixelRGBAbaseType<NumberType,ComputationDataType,PixelRangeType,Rposition,Gposition,Bposition,Aposition> ThisType;

		FINLINE explicit PixelRGBAbaseType(){}
		FINLINE explicit PixelRGBAbaseType(const NumberType & _scalar):ParentType(_scalar){}
		FINLINE          PixelRGBAbaseType(const DataType   & _pixel ):ParentType(_pixel ){}
		FINLINE          PixelRGBAbaseType(const ThisType   & _pixel ):ParentType(_pixel ){}

		FINLINE explicit PixelRGBAbaseType(const NumberType & _r,const NumberType & _g,const NumberType & _b){setR(_r);setG(_g);setB(_b);setA(RangeType::maxValue);}
		FINLINE explicit PixelRGBAbaseType(const NumberType & _r,const NumberType & _g,const NumberType & _b,const NumberType & _a){setR(_r);setG(_g);setB(_b);setA(_a);}
		
		FINLINE void setR(const NumberType & _r) {this->set<Rposition>(_r);}
		FINLINE void setG(const NumberType & _g) {this->set<Gposition>(_g);}
		FINLINE void setB(const NumberType & _b) {this->set<Bposition>(_b);}
		FINLINE void setA(const NumberType & _a) {this->set<Aposition>(_a);}

		FINLINE void clip(){RangeType::clip(*static_cast<ParentType*>(this));}

		FINLINE const NumberType & getR() const {return this->get<Rposition>();}
		FINLINE const NumberType & getG() const {return this->get<Gposition>();}
		FINLINE const NumberType & getB() const {return this->get<Bposition>();}
