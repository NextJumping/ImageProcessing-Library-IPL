
#include "image_cast.h"
#include "Algorithm/Algorithm1x1.h"
#include <Pixel/pixel_cast.h>
#include <Meta/enable_if.h>
#include <Meta/disable_if.h>
#include <Meta/is_same.h>

namespace Image {

template<class DstPixelType,class SrcPixelType> AIL_DLL_EXPORT typename Meta::enable_if<  Meta::is_same<DstPixelType,SrcPixelType>, Image<DstPixelType> >::type image_cast(const Image<SrcPixelType> & _image){
	return Image<DstPixelType>(_image);
}
template<class DstPixelType,class SrcPixelType> AIL_DLL_EXPORT typename Meta::disable_if< Meta::is_same<DstPixelType,SrcPixelType>, Image<DstPixe