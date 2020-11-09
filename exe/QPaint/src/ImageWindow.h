
#ifndef ImageWindow_H
#define ImageWindow_H

#include <QMainWindow>
#include <QPrinter>
#include <QImageWriter>

#include <Image/Image.h>
#include <Pixel/PixelRGB.h>
#include <Data/DataManager.h>

QT_BEGIN_NAMESPACE
class QAction;
class QLabel;
class QMenu;
class QScrollArea;
class QScrollBar;
QT_END_NAMESPACE

class ImageWindow : public QMainWindow {
	Q_OBJECT

	public:
		ImageWindow(Data::DataManager * const _dataManager);
		~ImageWindow();

		typedef Pixel::P