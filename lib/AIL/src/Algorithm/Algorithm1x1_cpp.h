

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
	typename AlgorithmType,
	typename PixelDataType
> void Algorithm1x1(
	Image::ImageView<PixelDataType> & image)
{
	#ifdef PPL
		if(image.isSimpleView()==false){return;}
		auto grid = image.makeGrid(100,100,0,0,1,1);
		Concurrency::parallel_for<I8u>(0,grid.size(),[&](I8u i){
			BaseAlgorithm1x1<AlgorithmType,PixelDataType>(grid[i]);
		});
	#else
		BaseAlgorithm1x1<AlgorithmType,PixelDataType>(image);
	#endif
}

template <
	typename AlgorithmType,
	typename PixelDataType,
	typename ParameterType
> void Algorithm1x1p(
	Image::ImageView<PixelDataType> & image,
	const ParameterType & parameter)
{
	#ifdef PPL
		if(image.isSimpleView()==false){return;}
		auto grid = image.makeGrid(100,100,0,0,1,1);
		Concurrency::parallel_for<I8u>(0,grid.size(),[&](I8u i){
			BaseAlgorithm1x1p<AlgorithmType,PixelDataType>(grid[i],parameter);
		});
	#else
		BaseAlgorithm1x1p<AlgorithmType,PixelDataType>(image,parameter);
	#endif
}

template <
	typename AlgorithmType,
	typename PixelDataType
> void Algorithm1x1p(
	Image::ImageView<PixelDataType> & srcImage,
	const Image::ImageView<PixelDataType> & parameterImage)
{
	#ifdef PPL
		if(srcImage.getSize()!=parameterImage.getSize()){return;}
		if((srcImage.isSimpleView()==false)||(parameterImage.isSimpleView()==false)){return;}
		auto srcGrid       = srcImage.makeGrid(      100,100,0,0,1,1);
		auto parameterGrid = parameterImage.makeGrid(100,100,0,0,1,1);
		Concurrency::parallel_for<I8u>(0,srcGrid.size(),[&](I8u i){
			BaseAlgorithm1x1p<AlgorithmType,PixelDataType>(srcGrid[i],parameterGrid[i]);
		});
	#else
		BaseAlgorithm1x1p<AlgorithmType,PixelDataType>(srcImage,parameterImage);
	#endif
}

}


#endif 