
#ifndef QPAINT__MORPHOLOGICAL_DIALOG
#define QPAINT__MORPHOLOGICAL_DIALOG

#include <QDialog>

class QRadioButton;
class QLabel;
class QLineEdit;
class QPushButton;
class QSpinBox;
class QButtonGroup;
class QGroupBox;
class QSlider;

#include <Image/Image.h>
#include <Filter/MorphKernelType.h>
#include <Data/DataManager.h>

class MorphologicalDialog : public QDialog {
	Q_OBJECT

	public:
		typedef Pixel::PixelRGBi1u PixelType;

		MorphologicalDialog(Data::DataManager * const _dataManager,const Image::Image<PixelType> *inputImage,QWidget *parent = nullptr);
		~MorphologicalDialog();

		int size;
		int operatorChoice;
		Filter::MorphKernelType kernelType;

		QSpinBox * sizeSpinBox;

	//signals:
	//	void applyOperator();

	private slots