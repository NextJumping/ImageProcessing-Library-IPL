
#include "LinearFilter1xH.h"
#include "BaseLinearFilterAlgorithm.h"
#include <Algorithm/Algorithm1xH.h>
#include "Simple1xHdataOperationBaseAlgorithm.h"
#include <Algorithm/BaseOperationTempType.h>
#include "BaseLinearFilterParametersType.h"

namespace Filter {

template <
	typename PixelType
> void LinearFilter1xH<PixelType>::applyTo(const Image::Image<Pixe