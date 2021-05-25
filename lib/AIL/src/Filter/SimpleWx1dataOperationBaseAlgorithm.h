
#ifndef FILTER__SimpleWx1dataOperationBaseAlgorithm_H
#define FILTER__SimpleWx1dataOperationBaseAlgorithm_H

#include "AIL.h"

namespace Filter {

template <
	typename DerivedAlgorithmType,
	typename PixelDataType,
	typename PixelComputationType,
	typename ParametersType,
	typename TempType
> class SimpleWx1dataOperationBaseAlgorithm {
	public:
		static FINLINE void process(
			PixelDataType * const & dstImageDataPtr,
			const Image::ImageView<PixelDataType> & srcImage,
			const ParametersType & parameters,
			const I4 & x,
			const I4 & y)
		{
			TempType tempData;
			DerivedAlgorithmType::initial(tempData,parameters);
			auto filterDataPtr = parameters.filterDataPtr;
			I4 xf=x-parameters.xOffset;
			DerivedAlgorithmType::first(tempData,parameters,srcImage.getPixel(xf,y).getAsComp<PixelComputationType::NumberType>(),(*filterDataPtr).getAsComp<PixelComputationType::NumberType>());
			++filterDataPtr;++xf;
			for(;xf<x+(parameters.filterWidth-parameters.xOffset); ++xf){
				DerivedAlgorithmType::inner(tempData,param