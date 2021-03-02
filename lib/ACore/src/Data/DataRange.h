
#ifndef DATA__DataRange_H
#define DATA__DataRange_H

#include <ACore.h>
#include <Meta/Boolean.h>
#include <Data/DataTypes.h>

namespace Data {

//TODO: This is designed to be used as constexpr (but compiler support hasn't caught up yet)
//      - when the compiler supports constexpr -> replace const with constexpr
template <
	typename NumberType
> class ACORE_DLL_EXPORT DataRange_Base {
	public:
		static const NumberType min;
		static const NumberType max;

		static FINLINE const NumberType & getMin() {return min;}
		static FINLINE const NumberType & getMax() {return max;}
};

template <
	typename NumberType,
	int depthID
> class ACORE_DLL_EXPORT DataRange_BaseDepth {
	public:
		static const NumberType min;
		static const NumberType max;

		static FINLINE const NumberType & getMin() {return min;}
		static FINLINE const NumberType & getMax() {return max;}
};

typedef DataRange_Base<B1 > DataRange_B1 ;
typedef Dat