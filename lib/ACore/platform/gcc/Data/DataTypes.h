
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

typedef 		 char      I1n ; //char
typedef unsigned char      I1un;
typedef 		 short     I2n ; //short
typedef unsigned short     I2un;
typedef 		 int       I4n ; //int or long
typedef unsigned int       I4un;
typedef 		 long long I8n ; //long long
typedef unsigned long long I8un;

//TODO: Create structures for Ix types

typedef I1n  I1 ;
typedef I1un I1u