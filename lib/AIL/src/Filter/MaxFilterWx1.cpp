
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

	typedef type