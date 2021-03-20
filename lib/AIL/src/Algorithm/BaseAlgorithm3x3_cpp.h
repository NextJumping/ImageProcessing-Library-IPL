
#ifndef ALGORITHM__BaseAlgorithm3x3_CPP_H
#define ALGORITHM__BaseAlgorithm3x3_CPP_H

#include <Image/ImageView.h>

namespace Algorithm {

template <
	typename AlgorithmType,
	typename PixelDataType
> void BaseAlgorithm3x3 (
	const Image::ImageView<PixelD