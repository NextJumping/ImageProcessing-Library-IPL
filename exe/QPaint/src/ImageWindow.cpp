

#include "ImageWindow.h"
#include "MorphologicalDialog.h"

#include <QtGui>
#include <QPainter>
#include <time.h>

#include <String/AString.h>
using String::getString;
#include <Image/Image.h>
#include <Image/Image_IO.h>
#include <Image/Image_Qt.h>
#include <Filter/DilateFilter.h>
#include <Filter/LinearFilterWxH.h>
#include <Algorithm/Algorithm1x1.h>
#include <Algorithm/Algorithm3x3.h>


//--- ImageWindow Constructor ---												//Constructor
ImageWindow::ImageWindow(Data::DataManager * const _dataManager)
	:dataManager(_dataManager)
{
	imageLabel = new QLabel;
	imageLabel->setBackgroundRole(QPalette::Base);
	imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
	imageLabel->setScaledContents(true);

	scrollArea = new QScrollArea;
	scrollArea->setBackgroundRole(QPalette::Dark);
	scrollArea->setWidget(imageLabel);
	setCentralWidget(scrollArea);

	wImage = nullptr;

	createActions();
	createMenus();

	setWindowTitle(tr("Image Viewer"));
	resize(600, 600);
}

ImageWindow::~ImageWindow(){
	if (wImage != nullptr){delete wImage; wImage = nullptr;}
}

// --- Blur ---																//Blur
void ImageWindow::blur(){
	if(wImage==nullptr){return;}
	//blurFilter.makeGaussianFilter(5,3);

	/*blurFilter(0,0) = -1; blurFilter(0,1) = -1; blurFilter(0,2) = -1;
	blurFilter(1,0) = -1; blurFilter(1,1) =  8; blurFilter(1,2) = -1;
	blurFilter(2,0) = -1; blurFilter(2,1) = -1; blurFilter(2,2) = -1;*/

	/*Image::WMaxFilter<PixelType> maxFilter(3,3);
	maxFilter(0,2) = 0; maxFilter(1,2) = 0; maxFilter(2,2) = 0;
	maxFilter(0,1) = 0; maxFilter(1,1) = 1; maxFilter(2,1) = 1;
	maxFilter(0,0) = 0; maxFilter(1,0) = 1; maxFilter(2,0) = 1;
	maxFilter.resetTotalColor();
	wImage = maxFilter.applyToCopy(*wImage);//*/

	/*Image::Image<Image::WPixelYd> *tempImage = new Image::Image<Image::WPixelYd>(wImage->getImageSize());
	clock_t totalTimeDiff=0.0;
	double totalRuns = 50.0;
	for(int i=0;i<totalRuns;++i){
		clock_t startTime = clock();
		tempImage->setAs_pixel_cast(*wImage);
		wImage->setAs_pixel_cast(*tempImage);
		clock_t endTime = clock();
		totalTimeDiff += endTime-startTime;
	}
	delete tempImage;//*/

	Filter::DilateFilter<PixelType> blurFilter(13);
	//Image::WLinearFilter2D<PixelType> blurFilter(13,13);
	/*blurFilter(0,0) = 1;
	blurFilter(1,0) = 2;
	blurFilter(2,0) = 1;
	/*blurFilter(0,0) = 1; blurFilter(0,1) = 2; blurFilter(0,2) = 1;
	blurFilter(1,0) = 2; blurFilter(1,1) = 4; blurFilter(1,2) = 2;
	blurFilter(2,0) = 1; blurFilter(2,1) = 2; blurFilter(2,2) = 1;//*/
	//blurFilter.makeGaussianFilter(5.0,2.0);
	//blurFilter.resetTotalColor();

	Image::Image<PixelType> *tempImage = new Image::Image<PixelType>(*wImage);
	clock_t totalTimeDiff=0.0;
	double totalRuns = 1.0;
	for(int i=0;i<1;++i){
		clock_t startTime = clock();
		blurFilter.applyTo(*wImage,*tempImage);
		clock_t endTime = clock();
		totalTimeDiff += endTime-startTime;
	}
	delete wImage;
	wImage=tempImage;
	tempImage=nullptr;
	//wImage=tempImage;//*/
	std::string diffTime = getString(totalTimeDiff/totalRuns);
	QMessageBox::about(this, tr(("Time (cycles), "+getString(totalRuns)+" runs").c_str()),
		tr(diffTime.c_str())
	);
	
	imageLabel->setPixmap(QPixmap::fromImage(Image::Convert::toQt(*wImage)));
}

class NegateObj {
	public:
		typedef ImageWindow::PixelType::DataType PixelDataType;

		static FINLINE void process(PixelDataType * const & srcImageDataPtr){
			(*srcImageDataPtr) = 255 - (*srcImageDataPtr);
		}
		//static FINLINE void process(const PixelDataType * const & srcImageDataPtr,PixelDataType * const & dstImageDataPtr){
		//	(*dstImageDataPtr) = 1.0 - (*srcImageDataPtr);
		//}
		static FINLINE void process(PixelDataType * const & dstImageDataPtr,const PixelDataType * const & srcImageDataPtr){
			(*dstImageDataPtr) = 1.0 - (*srcImageDataPtr);
		}
		/*static FINLINE void process(PixelDataType *dstPixelPtr,const PixelDataType *srcPixelPtr02,const PixelDataType *srcPixelPtr12,const PixelDataType *srcPixelPtr22,
																	 const PixelDataType *srcPixelPtr01,const PixelDataType *srcPixelPtr11,const PixelDataType *srcPixelPtr21,
																	 const PixelDataType *srcPixelPtr00,const PixelDataType *srcPixelPtr10,const PixelDataType *srcPixelPtr20){
			(*dstPixelPtr) = (((*srcPixelPtr21) - (*srcPixelPtr01)) / 2) + 0.5;
		}//*/
		static FINLINE void process(PixelDataType *dstPixelPtr,const PixelDataType *srcPixelPtr02,const PixelDataType *srcPixelPtr12,const PixelDataType *srcPixelPtr22,
															   const PixelDataType *srcPixelPtr01,const PixelDataType *srcPixelPtr11,const PixelDataType *srcPixelPtr21,
															   const PixelDataType *srcPixelPtr00,const PixelDataType *srcPixelPtr10,const PixelDataType *srcPixelPtr20){
			PixelDataType Gx = (((*srcPixelPtr01)*2) + (*srcPixelPtr02) + (*srcPixelPtr00) - (((*srcPixelPtr21)*2) + (*srcPixelPtr22) + (*srcPixelPtr20)));
			PixelDataType Gy = (((*srcPixelPtr12)*2) + (*srcPixelPtr02) + (*srcPixelPtr22) - (((*srcPixelPtr10)*2) + (*srcPixelPtr00) + (*srcPixelPtr20)));
			(*dstPixelPtr).get<0>() = sqrt((Gx.get<0>()*Gx.get<0>()+Gy.get<0>()*Gy.get<0>()) / 32);
			(*dstPixelPtr).get<1>() = sqrt((Gx.get<1>()*Gx.get<1>()+Gy.get<1>()*Gy.get<1>()) / 32);
			(*dstPixelPtr).get<2>() = sqrt((Gx.get<2>()*Gx.get<2>()+Gy.get<2>()*Gy.get<2>()) / 32);
		}//*/
		/*static FINLINE void process(PixelDataType *dstPixelPtr,const PixelDataType *srcPixelPtr02,const PixelDataType *srcPixelPtr12,const PixelDataType *srcPixelPtr22,
																	 const PixelDataType *srcPixelPtr01,const PixelDataType *srcPixelPtr11,const PixelDataType *srcPixelPtr21,
																	 const PixelDataType *srcPixelPtr00,const PixelDataType *srcPixelPtr10,const PixelDataType *srcPixelPtr20){
			PixelDataType Gx = (((*srcPixelPtr01)*2) + (*srcPixelPtr02) + (*srcPixelPtr00) - (((*srcPixelPtr21)*2) + (*srcPixelPtr22) + (*srcPixelPtr20)));
			PixelDataType Gy = (((*srcPixelPtr12)*2) + (*srcPixelPtr02) + (*srcPixelPtr22) - (((*srcPixelPtr10)*2) + (*srcPixelPtr00) + (*srcPixelPtr20)));
			(*dstPixelPtr).get<0>() = (sqrt(Gx.get<0>()*Gx.get<0>()+Gy.get<0>()*Gy.get<0>())) / 5.6568542494923;
			(*dstPixelPtr).get<1>() = (sqrt(Gx.get<1>()*Gx.get<1>()+Gy.get<1>()*Gy.get<1>())) / 5.6568542494923;
			(*dstPixelPtr).get<2>() = (sqrt(Gx.get<2>()*Gx.get<2>()+Gy.get<2>()*Gy.get<2>())) / 5.6568542494923;
		}//*/
		/*static FINLINE void process(PixelDataType *dstPixelPtr,const PixelDataType *srcPixelPtr02,const PixelDataType *srcPixelPtr12,const PixelDataType *srcPixelPtr22,
																	 const PixelDataType *srcPixelPtr01,const PixelDataType *srcPixelPtr11,const PixelDataType *srcPixelPtr21,
																	 const PixelDataType *srcPixelPtr00,const PixelDataType *srcPixelPtr10,const PixelDataType *srcPixelPtr20){
			(*dstPixelPtr) = (((*srcPixelPtr01)*2) + (*srcPixelPtr02) + (*srcPixelPtr00) - (((*srcPixelPtr21)*2) + (*srcPixelPtr22) + (*srcPixelPtr20))) / 8 + 0.5;
		}//*/
		/*AlgorithmType::process(dstImageDataPtr,srcImageDataPtr+srcImageWidth,srcImageDataPtr+srcImageWidth,srcImageDataPtr+srcImageWidthp1,
										   srcImageDataPtr              ,srcImageDataPtr              ,srcImageDataPtr+1              ,
										   srcImageDataPtr              ,srcImageDataPtr              ,srcImageDataPtr+1              );//*/
};

// --- Negative ---															// Negative
void ImageWindow::negative(){
	if(wImage==nullptr){return;}
	/*Image::WImage<PixelType> *fImage = Image::WImage<>::CreateImage(*wImage);
	Image::Morph<PixelType>::erode3x3(*wImage,*fImage);
	delete wImage;
	wImage=fImage;
	fImage=nullptr;*/
	clock_t startTime = clock();
	//(*wImage)*= -1.0;
	//(*wImage)+=  1.0;
	//Image::BaseAlgorithm1x1<Image::ImageBase::DefaultPixelType::DataType,NegateObj>(wImage->getView());

	//Image::Image<PixelType> tempImage1 = Image::Image<PixelType>(wImage->getSize(),dataManager);
	//Algorithm::Algorithm1x1<NegateObj,ImageWindow::PixelType::DataType>(wImage->getDataView(),tempImage1.getDataView());
	//wImage->swap(tempImage1);

	//Algorithm::Algorithm1x1<NegateObj,ImageWindow::PixelType::DataType>(wImage->getDataView(),tempImage1.getDataView());
	Algorithm::Algorithm1x1<NegateObj,ImageWindow::PixelType::DataType>(wImage->getDataView());
	
	//wImage->clip();
	//(*wImage)+= wImage->getMaxValueVol();
	clock_t endTime = clock();
	std::string diffTime = getString(endTime-startTime);
