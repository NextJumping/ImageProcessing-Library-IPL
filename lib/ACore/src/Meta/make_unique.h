
#ifndef META__make_unique_H
#define META__make_unique_H

#include "ACore.h"

#include <Meta/Forward.h>

namespace Meta {

	template <
		typename Type
	> std::unique_ptr<Type> make_unique(){
		return std::unique_ptr<Type>(new Type());
	}
	template <
		typename Type,
		typename Parameter1
	> std::unique_ptr<Type> make_unique(Parameter1 && parameter1){
		return std::unique_ptr<Type>(new Type(Meta::forward(parameter1)));
	}
	template <
		typename Type,
		typen