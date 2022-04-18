 
#include "Widget.h"
#include "WidgetSurface.h"

#include <QtMultimedia/QtMultimedia>

namespace Video {

Widget::Widget(QWidget *parent)
	:QWidget(parent)
	,surface(0)
{
	setAutoFillBackground(false);
	setAttribute(Qt::WA_NoSystemBackground, true);
	setAttribute(Qt::WA_PaintOnScreen, true);
	setAttribute(Qt::WA_OpaquePaintEvent, true);
	setAttribute(Qt::WA_PaintUnclipped, true);

	QPalette palette = this->palette();
	palette.setColor(QPalette::Background, Qt::black);
	setPalette(palette);

	//setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

	surface = new WidgetSurface(this);
}

Widget::~Widget(){
	delete surface;
}

QSize Widget::sizeHint() const {
	return surface->surfaceFormat(