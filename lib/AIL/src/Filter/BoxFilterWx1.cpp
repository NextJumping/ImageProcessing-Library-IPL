
#include "BoxFilterWx1.h"
#include "BaseBoxFilterAlgorithm.h"
#include "BoxFilterWx1parametersType.h"
#include <Algorithm/AlgorithmWx1.h>
#include <Algorithm/BasicWx1baseAlgorithm.h>

namespace Filter {

template <
	typename PixelType
> void AIL_DLL_EXPORT BoxFilterWx1<PixelType>::applyTo(const Image::Image<PixelType> & srcImage,Image::Image<PixelType> & dstImage) const {

	typedef typename PixelType::DataType        PixelDataType;
	typedef typename PixelType::ComputationType PixelComputationType;

	BoxFilterWx1parametersType<PixelDataType,PixelComputationType> parameters(xOffset,filterWidth,PixelType::ComputationRange::getMinPixel(),PixelComputationType(filterWidth));

	Algorithm::AlgorithmWx1<
		Algor