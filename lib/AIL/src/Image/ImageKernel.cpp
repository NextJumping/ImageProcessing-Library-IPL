
#include "ImageKernel.h"
#include <Data/DataManager.h>
#include <Meta/Forward.h>

namespace Image {

template <
	typename PixelType,
	typename InclusionTestType
> ImageKernel<PixelType,InclusionTestType>::ImageKernel(Image<PixelType> && _kernel)
	:kernel(Meta::forward(_kernel))
	,kernelSkipDataPtr(nullptr)
	,kernelSkipDataPtrEnd(nullptr)
	,kernelSize(0)
	,parentImageWidth(0)
{
}

template <
	typename PixelType,
	typename InclusionTestType
> ImageKernel<PixelType,InclusionTestType>::ImageKernel(Image<PixelType> && _kernel,const I4 & _parentImageWidth)
	:kernel(Meta::forward(_kernel))
	,kernelSkipDataPtr(nullptr)
	,kernelSkipDataPtrEnd(nullptr)
	,kernelSize(0)
	,parentImageWidth(0)
{
	if(_parentImageWidth<kernel.getWidth()){return;} //TODO: Report an error
	calculateKernelSkipData(_parentImageWidth);
}

template <
	typename PixelType,
	typename InclusionTestType
> ImageKernel<PixelType,InclusionTestType>::~ImageKernel(){
	if(kernelSkipDataPtr!=nullptr){
		Data::DataManager::release(kernelSkipDataPtr);
		kernelSkipDataPtr=nullptr;
	}
	kernelSkipDataPtrEnd=nullptr;
}

template <
	typename PixelType,
	typename InclusionTestType
> void ImageKernel<PixelType,InclusionTestType>::calculateKernelSkipData(const I4 & _parentImageWidth){
	
	if(parentImageWidth==_parentImageWidth){return;}

	parentImageWidth=_parentImageWidth;

	kernelSize = calculateKernelSize(kernel);

	if(kernelSkipDataPtr!=nullptr){
		Data::DataManager::release(kernelSkipDataPtr);
		kernelSkipDataPtr=nullptr;
	}
	kernelSkipDataPtrEnd=nullptr;

	kernelSkipDataPtr = static_cast<I4*>(Data::DataManager::getMemory(sizeof(I4) * (kernelSize+2)));
	kernelSkipDataPtrEnd=kernel