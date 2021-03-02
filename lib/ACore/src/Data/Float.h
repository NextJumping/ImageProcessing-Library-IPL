
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
	pu