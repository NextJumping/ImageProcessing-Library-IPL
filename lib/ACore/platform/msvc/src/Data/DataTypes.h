
#ifndef DATA__DataTypes_H
#define DATA__DataTypes_H

#include "ACore.h"

///////////////////////////////////////////////
typedef bool B1n;

#include <Meta/Boolean.h>
//NOTE: This is required to break an include cycle
#ifdef META__Boolean_H_END

typedef Meta::Boolean B1c; //bool

typedef B1c B1;

///////////////////////////////////////////////

typedef 		 __int8  I1n ; //char
typedef unsigned __int8  I1un;
typedef 		 __int16 I2n ; //short
typedef unsigned __int16 I2un;
typedef 		 __int32 I4n ; //int or long
typedef unsigned __int32 I4un;
typedef 		 __int64 I8n ; //long long
typedef unsigned __int64 I8un;

//TODO: Create structures for Ix types

typedef I1n  I1 ;
typedef I1un I1u;
typedef I2n  I2 ;
typedef I2un I2u;
typedef I4n  I4 ;
typedef I4un I4u;
typedef I8n  I8 ;
typedef I8un I8u;

///////////////////////////////////////////////

typedef f