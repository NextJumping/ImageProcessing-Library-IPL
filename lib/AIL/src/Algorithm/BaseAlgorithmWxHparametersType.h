
#ifndef IMAGE__BaseAlgorithmWxHparametersType_H
#define IMAGE__BaseAlgorithmWxHparametersType_H

#include "AIL.h"

namespace Image {

class AIL_DLL_EXPORT BaseAlgorithmWxHparametersType {
	public:

		BaseAlgorithmWxHparametersType(
			const I4 & _xOffset,
			const I4 & _yOffset,
			const I4 & _filterWidth,
			const I4 & _filterHeight)
			:x