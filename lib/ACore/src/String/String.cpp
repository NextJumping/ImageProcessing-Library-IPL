
#include "AString.h"
#include <sstream>
#include <iomanip>

namespace String {

//TODO: Rewrite these functions to not use sstream - it is slow
ACORE_DLL_EXPORT std::string getString(const I4  & number){
	std::stringstream stream;
	stream<<number;
	return stream.str();
}
ACORE_DLL_EXPORT std::string getString(const I8  & number){
	std::stringstream stream;
	stream<<number;
	return stream.str();
}
ACORE_DLL_EXPORT std::string getString(const I8u & number){
	std::stringstream stream;
	stream<<number;
	return stream.str();
}
ACORE_DLL_EXPORT std::string getString(const I4  & number,const I4 & zeros){
	std::stringstream stream;
	stream<<std::setw(zeros)<<std::setfill('0')<<number;
	return stream.str();
}
ACORE_DLL_EXPORT std::string getString(const I8  & number,const I4 & zeros){
	std::stringstream str