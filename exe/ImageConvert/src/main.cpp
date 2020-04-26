
#include <Image/Image_IO.h>

#include <string>
#include <iostream>

int main(int argc, char * argv[]){
	if(argc!=3){
		std::cout<<"Usage example: ./ImageConvert.exe A.bmp A.png"<<std::endl;
		return 0;
	}
	std::string fromFileName = argv[1];
	std::string toFileName   = argv[2];
	Image::Image<Pixel::PixelRGBf8> image = Image::IO::r