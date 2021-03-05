
#ifndef DATA__Float_H
#define DATA__Float_H

#include "ACore.h"

//TODO: Verify that these structures actually work
//TODO: Examine the x64 generated for accessing the struct components versus the function versions

class ACORE_DLL_EXPORT F16c { //TODO: Complete a quad precision floating point class
	public:
		union {
			struct {
				I8u u1;
				I8u u2;
			} u ;
			struct {
				I8u mantissa1 : 64; //112 mantissa bits
				I8u mantissa2 : 48;
				I8u exponent : 15;
				I8u sign : 1;
			} s ;
		};
		F16c(const I8u & _u1,const I8u & _u2){u.u1=_u1;u.u2=_u2;}

};

class ACORE_DLL_EXPORT F8c {
	public:
		union {
			F8n f;
			I8u u;
			struct {
				I8u mantissa : 52;
				I8u exponent : 11;
				I8u sign : 1;
			} s ;
		};
		FINLINE          F8c(){}
		FINLINE          F8c(const F8n & _f):f(_f){}
		FINLINE explicit F8c(const I8u & _u,const B1 & dummy):u(_u){}
		FINLINE operator F8n(){return f;}

	    FINLINE B1  sign()     const { return (u >> 63) != 0; }
		FINLINE I8u mantissa() const { return  u & ((1i64 << 52) - 1); }
		FINLINE I8u exponent() const { return (u >> 52) & 0x7FF; }

};

class ACORE_DLL_EXPORT F4c {
	public:
		union {
			F4n f;
			I4u u;
			struct {
				I4u mantissa : 23;
				I4u exponent : 8;
				I4u sign : 1;
			} s ;
		};
		FINLINE          F4c(){}
		FINLINE          F4c(const F4n & _f):f(_f){}
		FINLINE explicit F4c(const I4u & _u,const B1 & dummy):u(_u){}
		FINLINE operator F4n(){return f;}

	    FINLINE B1  sign()     const { return (u >> 31) != 0; }
		FINLINE I4u mantissa() const { return  u & ((1 << 23) - 1); }
		FINLINE I4u exponent() const { return (u >> 23) & 0xFF; }

};

//Half precision floating point based on https://gist.github.com/2156668 (revision 685a30) and http://fgiesen.wordpress.com/2012/03/28/half-to-float-done-quic/ by rygorous
//TODO: Use the SEE version of float_to_half_SSE2()
class ACORE_DLL_EXPORT F2c {
	public:
		union {
			I2u u;
			struct {
				I2u mantissa : 10;
				I2u exponent : 5;
				I2u sign : 1;
			} s ;
		};

		FINLINE B1  sign()     const { return (u >> 15) != 0; }
		FINLINE I2u mantissa() const { return u & ((1 << 10) - 1); }
		FINLINE I2u 