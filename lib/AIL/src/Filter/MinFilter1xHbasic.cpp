
#include "MinFilter1xHbasic.h"
#include <Algorithm/Algorithm1xH.h>
#include "BaseMinFilterAlgorithm.h"
#include <Algorithm/Basic1xHbaseAlgorithmParametersType.h>
#include <Algorithm/Basic1xHbaseAlgorithm.h>
#include <Algorithm/BaseOperationTempType.h>

namespace Filter {

template <
	typename PixelType
> void AIL_DLL_EXPORT MinFilter1xHbasic<PixelType>::applyTo(c