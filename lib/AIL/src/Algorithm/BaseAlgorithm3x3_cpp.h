
#ifndef ALGORITHM__BaseAlgorithm3x3_CPP_H
#define ALGORITHM__BaseAlgorithm3x3_CPP_H

#include <Image/ImageView.h>

namespace Algorithm {

template <
	typename AlgorithmType,
	typename PixelDataType
> void BaseAlgorithm3x3 (
	const Image::ImageView<PixelDataType> & srcImage,
	Image::ImageView<PixelDataType> & dstImage)
{
	if(srcImage.getSize()!=dstImage.getSize()){return;}

	if((srcImage.isSimpleView()==true)&&(dstImage.isSimpleView()==true)){
		auto srcImageHeightm1 = srcImage.getHeight()-1;

		const auto & srcImageWidth   = srcImage.getWidth();
			  auto   srcImageWidthm1 = srcImage.getWidth()-1;
			  auto   srcImageWidthp1 = srcImage.getWidth()+1;

		auto srcImageDataPtr = srcImage.getDataPtr();
		auto dstImageDataPtr = dstImage.getDataPtr();
	
		I4 y = 0; // TODO: Write these loops to get rid of x and y ... and make sure that the complier still unrolls the loops
		I4 x = 0;

		//First Row - First Pixel
		AlgorithmType::process(dstImageDataPtr,srcImageDataPtr              ,srcIm