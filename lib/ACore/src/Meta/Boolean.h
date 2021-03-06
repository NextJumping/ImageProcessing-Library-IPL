
#ifndef META__Boolean_H
#define META__Boolean_H

#include "ACore.h"

namespace Meta {

class ACORE_DLL_EXPORT Boolean {

	public:

		typedef Boolean ThisType;
		typedef B1n NumberType;

		NumberType value;

		FINLINE Boolean():value(false){}
		FINLINE Boolean(const ThisType   &  other);
		FINLINE Boolean(const NumberType & _value);

		FINLINE ThisType & operator =(const ThisType   &  other);
		FINLINE ThisType & operator =(const NumberType & _value);

		FINLINE operator B1n() const {return value;}

		FINLINE B1n operator ==(const ThisType   &  other) const ;
		FINLINE B1n operator ==(const NumberType & _value) const ;

		FINLINE void setAs(const ThisType   &  other);
		FINLINE void setAs(const NumberType & _val