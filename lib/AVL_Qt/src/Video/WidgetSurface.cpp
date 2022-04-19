
#include "WidgetSurface.h"

#include <QtMultimedia/QtMultimedia>

namespace Video {

AVL_QT_DLL_EXPORT WidgetSurface::WidgetSurface(QWidget *widget, QObject *parent)
	:QAbstractVideoSurface(parent)
	,widget(widget)
	,currentFrame(nullptr)
{
}
AVL_QT_DLL_EXPORT WidgetSurface::~WidgetSurface(){
	if(currentFrame!=nullptr){delete currentFrame;currentFrame = nullptr;}
}
QList<QVideoFrame::PixelFormat> AVL_QT_DLL_EXPORT WidgetSurface::supportedPixelFormats(QAbstractVideoBuffer::HandleType handleType) const {
	return QList<QVideoFrame::PixelFormat>();
}

bool AVL_QT_DLL_EXPORT WidgetSurface::isFormatSupported(const QVideoSurfaceFormat & format, QVideoSurfaceFormat * similar) const {
	Q_UNUSED(similar);

	const QImage::Format imageFormat = QVideoFrame::imageFormatFromPixelFormat(format.pixelFormat());
	const QSize size = format.frameSize();

	return imageFormat != QImage::Format_Invalid
		&& !size.isEmpty()
		&& format.handleType() == QAbstractVideoBuffer::NoHandle;
}

bool AVL_QT_DLL_EXPORT WidgetSurface::start(const QVideoSurfaceFormat & format){
	const QSize size = format.frameSize();

	if (size.isEmpty()==false) {
		imageSize.set(size.width(),size.height());
		sourceRect = format.viewport();

		QAbstractVideoSurface::start(format);

		widget->updateGeometry();
		updateVideoRect();

		return true;
	}else{
		return false;
	}
}
void AVL_QT_DLL_EXPORT WidgetSurface::updateVideoRect(){
	QSize videoSize  = surfaceFormat().sizeHint();
	QSize widgetSize = widget->size();

	QSize targetSize = videoS