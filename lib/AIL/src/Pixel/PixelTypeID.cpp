
#include "PixelTypeID.h"

namespace Pixel {

std::string getTypeName(const PixelTypeID & typeID){
	switch(typeID){
		case PixelTypeID::Yb     : return "Yb"     ; break;
		case PixelTypeID::Yi1u   : return "Yi1u"   ; break;
		case PixelTypeID::Yi4    : return "Yi4"    ; break;
		case PixelTypeID::Yf4    : return "Yf4"    ; break;
		case PixelTypeID::Yf8    : return "Yf8"    ; break;
		case PixelTypeID::RGBi1u : return "RGBi1u" ; break;
		case PixelTypeID::RGBi4  : return "RGBi4"  ; break;
		case PixelTypeID::RGBf4  : return "RGBf4"  ; break;
		case PixelTypeID::RGBf8  : return "RGBf8"  ; break;
		case PixelTypeID::BGRi1u : return "BGRi1u" ; break;
		case PixelTypeID::BGRi4  : return "BGRi4"  ; break;
		case PixelTypeID::BGRf4  : return "BGRf4"  ; break;
		case PixelTypeID::BGRf8  : return "BGRf8"  ; break;
		case PixelTypeID::YUVi1u : return "YUVi1u" ; break;
		case PixelTypeID::YUVi4  : return "