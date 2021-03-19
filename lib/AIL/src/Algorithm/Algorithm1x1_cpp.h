

#ifndef ALGORITHM__Algorithm1x1_CPP_H
#define ALGORITHM__Algorithm1x1_CPP_H

#include "AIL.h"
#include "BaseAlgorithm1x1.h"
#include <Image/ImageView.h>

#ifdef PPL
#include <ppl.h>
#endif

namespace Algorithm {

template <
	typename AlgorithmType,
	typename SrcPixelDataType,
	typename DstPixelDataType,
	typename ParameterType
> void Algorithm1x1p (
	const Image::ImageView<SrcPixelDataType> & srcImage,
	Image::ImageView<DstPixelDataType> & dstImage,
	const ParameterType & parameter)
{
	#ifdef PPL
		if(srcImage.getSize()!=dstImage.getSize()){return;}
		auto srcGrid = srcImage.makeGrid(100,100,0,0,1,1);
		auto dstGrid = dstImage.makeGrid(100,100,0,0,1,1);
		Concurrency::parallel_for<I8u>(0,srcGrid.size(),[&](I8u i){
			BaseAlgorithm1x1p<AlgorithmType,SrcPixelDataType,DstPixelDataType>(srcGrid[i],dstGrid[i],parameter);
		});
	#else
		BaseAlgorithm1x1p<AlgorithmType,SrcPixelDataType,DstPixelDataType>(srcImage,dstImage,parameter);
	#endif
}

template <
	typename AlgorithmType,
	typename SrcPixelDataType,
	typename DstPixelDataType
> void Algorithm1x1(
	const Image::ImageView<SrcPixelDataType> & srcImage,
	Image::ImageView<DstPixelDataType> & dstImage)
{
	#ifdef PPL
		if(srcImage.getSize()!=dstImage.getSize()){return;}
		if((srcImage.isSimpleView()==false)||(dstImage.isSimpleView()==false)){return;}
		auto srcGrid = srcImage.makeGrid(100,100,0,0,1,1);
		auto dstGrid = dstImage.makeGrid(100,100,0,0,1,1);
		Concurrency::parallel_for<I8u>(0,srcGrid.size(),[&](I8u i){
			BaseAlgorithm1x1<AlgorithmType,SrcPixelDataType,DstPixelDataType>(srcGrid[i],dstGrid[i]);
		});
	#else
		BaseAlgorithm1x1<AlgorithmType,SrcPixelDataType,DstPixelDataType>(srcImage,dstImage);
	#endif
}

template <