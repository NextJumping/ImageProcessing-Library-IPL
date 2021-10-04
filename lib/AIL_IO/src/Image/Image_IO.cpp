
#include "Image_IO.h"
#include <Image/Image.h>
#include <Image/Image_Qt.h>
#include <Image/Image_png.h>
#include <Image/image_cast.h>
#include <String/AString.h>

namespace Image {

namespace IO {

template<typename PixelType> AIL_IO_DLL_EXPORT Image<PixelType> read(Data::DataManager * const dataManager,const std::string & fileName) {
	if(String::hasEnding(fileName,".png")){ //TODO: Add intelligent determination of fileType using Magic Bytes - or at least try multiple
		return readPNG<PixelType>(dataManager,fileName);
	}else{
		return readQt<PixelType>(dataManager,fileName);
	}
}

//TODO: Add configuration parameters (for color space, compression settings, etc..)
template<typename PixelType> AIL_IO_DLL_EXPORT void write(const Image<PixelType> & image,const std::string & fileName) {
	if(String::hasEnding(fileName,".png")){
		writePNG(image,fileName);
	}else if(String::hasEnding(fileName,".ppm")){
		writePPM(image,fileName