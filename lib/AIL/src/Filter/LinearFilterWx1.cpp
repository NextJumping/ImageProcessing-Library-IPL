
#include "LinearFilterWx1.h"
#include "BaseLinearFilterAlgorithm.h"
#include <Algorithm/AlgorithmWx1.h>
#include "SimpleWx1dataOperationBaseAlgorithm.h"
#include <Algorithm/BaseOperationTempType.h>
#include "BaseLinearFilterParametersType.h"

namespace Filter {

template <
	typename PixelType
> void LinearFilterWx1<PixelType>::applyTo(const Image::Image<PixelType> & srcImage,Image::Image<PixelType> & dstImage) const {

	typedef typename PixelType::DataType        PixelDataType;
	typedef typename PixelType::ComputationType PixelComputationType;

	BaseLinearFilterParametersType<PixelDataType,PixelComputationType> parameters(
		getFilterData()