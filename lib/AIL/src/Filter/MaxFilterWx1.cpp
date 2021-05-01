
#include "MaxFilterWx1.h"
#include <Algorithm/AlgorithmWx1.h>
#include "BaseMaxFilterAlgorithm.h"
#include "SimpleWxHbooleanOperationParametersType.h"
#include "SimpleWx1booleanOperationBaseAlgorithm.h"
#include <Algorithm/BaseOperationTempType.h>

namespace Filter {

template <
	typename PixelType
> void AIL_DLL_EXPORT MaxFilterWx1<PixelType>::applyTo(const Image::Image<PixelType> & srcImage,Image::Image<PixelType> & dstImage) const {

	typedef typename PixelType::DataType        PixelDataType;
	typedef typename PixelType::ComputationType PixelComputationType;

	filterData.calculateKernelSkipData(srcImage.getWidth());

	SimpleWxHbooleanOperationParametersType parameters(getFilterData(),getXoffset(),getYoffset());

	Algorithm::AlgorithmWx1<
		SimpleWx1booleanOperationBaseAlgorithm<
			BaseMaxFilterAlgorithm<
				PixelDataType,
				PixelComputationType,
				SimpleWxHbooleanOperationParametersType,
				Algorithm::BaseOperationTempType<PixelDataType,PixelComputationType>
			>,
			PixelDataType,
			PixelComputationType,
			SimpleWxHbooleanOperationParametersType,
			Algorithm::BaseOperationTempType<PixelDataType,PixelComputationType>
		>,
		PixelDataType,
		SimpleWxHbooleanOperation