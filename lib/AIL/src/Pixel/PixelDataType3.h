
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
		FINLINE explicit PixelDataType3(const NumberType & _scalar1,const NumberType & _scalar2,const NumberType & _scalar3):x(_scalar1) ,y(_scalar2) ,z(_scalar3){}
		FINLINE          PixelDataType3(const ThisType   & _pixel) :x(_pixel.x),y(_pixel.y),z(_pixel.z){}
	
		FINLINE ThisType & operator =(const ThisType   & _pixel ){x=_pixel.x;y=_pixel.y;z=_pixel.z;return (*this);}
		FINLINE ThisType & operator =(const NumberType & _scalar){x=_scalar ;y=_scalar ;z=_scalar ;return (*this);}

		FINLINE bool operator ==(const ThisType   & _pixel ) const {if(x==_pixel.x){if(y==_pixel.y){if(z==_pixel.z){return true;}}}return false;}
		FINLINE bool operator ==(const NumberType & _scalar) const {if(x==scalar  ){if(y==scalar  ){if(z==scalar  ){return true;}}}return false;}

		template <typename DiffNumberType> FINLINE const void setComp(const PixelDataType3<DiffNumberType> & _pixel){x=_pixel.get<0>();