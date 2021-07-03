
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

		template <typename DiffNumberType> FINLINE const void setComp(const PixelDataType3<DiffNumberType> & _pixel){x=_pixel.get<0>();y=_pixel.get<1>();z=_pixel.get<2>();};

		template <typename DiffNumberType> FINLINE PixelDataType3<DiffNumberType> getAsComp() const {return PixelDataType3<DiffNumberType>(x,y,z);};

		FINLINE void setAs   (const ThisType & _pixel){x=_pixel.x;y=_pixel.y;z=_pixel.z;}
		FINLINE void setAsMin(const ThisType &  pixel){if(x>pixel.x){x=pixel.x;}if(y>pixel.y){y=pixel.y;}if(z>pixel.z){z=pixel.z;}}
		FINLINE void setAsMax(const ThisType &  pixel){if(x<pixel.x){x=pixel.x;}if(y<pixel.y){y=pixel.y;}if(z<pixel.z){z=pixel.z;}}

		FINLINE void setAs   (const NumberType & _scalar){x=_scalar;y=_scalar;z=_scalar;}
		FINLINE void setAsMin(const NumberType &  scalar){if(x>scalar){x=scalar;}if(y>scalar){y=scalar;}if(z>scalar){z=scalar;}}
		FINLINE void setAsMax(const NumberType &  scalar){if(x<scalar){x=scalar;}if(y<scalar){y=scalar;}if(z<scalar){z=scalar;}}

	//Operators
		//With Scalar:
		FINLINE ThisType & operator -=(const NumberType & scalar){x-=scalar;y-=scalar;z-=scalar;return (*this);}
		FINLINE ThisType & operator +=(const NumberType & scalar){x+=scalar;y+=scalar;z+=scalar;return (*this);}
		FINLINE ThisType & operator *=(const NumberType & scalar){x*=scalar;y*=scalar;z*=scalar;return (*this);}
		FINLINE ThisType & operator /=(const NumberType & scalar){x/=scalar;y/=scalar;z/=scalar;return (*this);}
		
		FINLINE ThisType operator-(const NumberType & scalar) const {return ThisType(*this)-=scalar;}
		FINLINE ThisType operator+(const NumberType & scalar) const {return ThisType(*this)+=scalar;}
		FINLINE ThisType operator*(const NumberType & scalar) const {return ThisType(*this)*=scalar;}
		FINLINE ThisType operator/(const NumberType & scalar) const {return ThisType(*this)/=scalar;}

		//With Pixel:
		FINLINE ThisType & operator -=(const ThisType & pixel){x-=pixel.x;y-=pixel.y;z-=pixel.z;return (*this);}
		FINLINE ThisType & operator +=(const ThisType & pixel){x+=pixel.x;y+=pixel.y;z+=pixel.z;return (*this);}
		FINLINE ThisType & operator *=(const ThisType & pixel){x*=pixel.x;y*=pixel.y;z*=pixel.z;return (*this);}
		FINLINE ThisType & operator /=(const ThisType & pixel){x/=pixel.x;y/=pixel.y;z/=pixel.z;return (*this);}

		FINLINE ThisType operator-(const ThisType & pixel) const {return ThisType