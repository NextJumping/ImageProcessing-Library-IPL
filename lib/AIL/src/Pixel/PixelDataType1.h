
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

		FINLINE explicit PixelDataType1(){}
		FINLINE explicit PixelDataType1(const NumberType & _scalar):x(_scalar){}
		FINLINE          PixelDataType1(const ThisType   & _pixel) :x(_pixel.x){}
	
		FINLINE ThisType & operator =(const ThisType   & _pixel ){x=_pixel.x;return (*this);}
		FINLINE ThisType & operator =(const NumberType & _scalar){x=_scalar ;return (*this);}

		FINLINE bool operator ==(const ThisType   & _pixel ) const {return (x==_pixel.x);}
		FINLINE bool operator ==(const NumberType & _scalar) const {return (x==_scalar );}

		template <typename DiffNumberType> FINLINE const void setComp(const PixelDataType1<DiffNumberType> & _pixel){x=_pixel.get<0>();};

		template <typename DiffNumberType> FINLINE PixelDataType1<DiffNumberType> getAsComp() const {return PixelDataType1<DiffNumberType>(x);};

		FINLINE void setAs   (const ThisType & _pixel){x=_pixel.x;}
		FINLINE void setAsMin(const ThisType &  pixel){if(x>pixel.x){x=pixel.x;}}
		FINLINE void setAsMax(const ThisType &  pixel){if(x<pixel.x){x=pixel.x;}}

		FINLINE void setAs   (const NumberType & _scalar){x=_scalar;}
		FINLINE void setAsMin(const NumberType &  scalar){if(x>scalar){x=scalar;}}
		FINLINE void setAsMax(const NumberType &  scalar){if(x<scalar){x=scalar;}}

	//Operators
		//With Scalar:
		FINLINE ThisType & operator -=(const NumberType & scalar){x-=scalar;return (*this);}
		FINLINE ThisType & operator +=(const NumberType & scalar){x+=scalar;return (*this);}
		FINLINE ThisType & operator *=(const NumberType & scalar){x*=scalar;return (*this);}
		FINLINE ThisType & 