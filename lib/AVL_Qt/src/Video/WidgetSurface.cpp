
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

	const QImage::Format imageFormat = QVideoFrame::imageFormatFromP