
#ifndef FILTER__SimpleWxHdataOperationBaseAlgorithm_H
#define FILTER__SimpleWxHdataOperationBaseAlgorithm_H

#include "AIL.h"

namespace Filter {

template <
	typename DerivedAlgorithmType,
	typename PixelDataType,
	typename PixelComputationType,
	typename ParametersType,
	typename TempType
> class SimpleWxHdataOperationBaseAlgorithm {
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
			I4 yf=y-parameters.yOffset;
			I4 xf=x-parameters.xOffset;
			DerivedAlgorithmType::first(tempData,parameters,srcImage.getPixel(xf,yf).getAsComp<PixelComputationType::NumberType>(),(*filterDataPtr).getAsComp<PixelComputationType::NumberType>());
			++filterDataPtr;++xf;
			for(;xf<x+(parameters.filterWidth-parameters.xOffset); ++xf){
				Deriv