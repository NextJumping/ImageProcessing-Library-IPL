
#ifndef VIDEO__WidgetSurface_H
#define VIDEO__WidgetSurface_H

#include "AVL_Qt.h"

#include <Data/DataTypes.h>
#include <Image/Image.h>

#include <QtCore/QRect>
#include <QtGui/QImage>
#include <QtMultimedia/QAbstractVideoSurface>
#include <QtMultimedia/QVideoFrame>

namespace Video {

class AVL_QT_DLL_EXPORT WidgetSurface : public QAbstractVideoSurface {
	Q_OBJECT
	public:
		WidgetSurface(QWidget * widget, QObject * parent = 0);

		~WidgetSurface();

		QList<QVideoFrame::PixelFormat> supportedPixelFormats(QAbstractVideoBuffer::HandleType handleType = QAbstractVideoBuffer::NoHandle) const;
		bool isFormatSupported(const QVideoSurfaceFormat & format, QVideoSurfaceFormat * similar) const;

		bool start(const QVideoSurfaceFormat & format);
		void stop();

		QRect videoRect() c