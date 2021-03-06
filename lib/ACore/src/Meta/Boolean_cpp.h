

#ifndef META__Boolean_CPP_H
#define META__Boolean_CPP_H

#include "Boolean.h"

namespace Meta {

void Boolean::setAs(const ThisType   &  other){value=other.value;}
void Boolean::setAs(const NumberType & _value){value=_value;}

// Operators:
//With NumberType
B1n Boolean::operator ==(const NumberType & _value) const {return (value==_value);}
Boolean & Boolean::operator =(const NumberType & _value){value=_value; return (*this);}