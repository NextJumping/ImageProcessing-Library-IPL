

#include "MediaPlayer.h"

#include <QtGui>

#include <Video/Widget.h>
#include <Video/WidgetSurface.h>

#include <Media/FFMPEGmediaPlayerAgent.h>
#include <Thread/QueuePipe.h>
#include <Thread/QueueReaderAgent.h>

MediaPlayer::MediaPlayer(Data::DataManager * const _dataManager)
	:dataManager(_dataManager)
	,player(_dataManager)
{
	auto videoWidget = new Video::Widget();
	auto surface = videoWidget->videoSurface();

	player.start(surface);
	mediaControl = player.getMediaControl();

	playPauseButton = new QPushButton;
	playPauseButton->setEnabled(false);
	playPauseButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
	playPauseButton->setText("PlayPause");

	connect(playPauseButton, SIGNAL(clicked()),this, SLOT(playPause()));

	positionSlider = new QSlider(Qt::Horizontal);
	positionSlider->setRange(0, 10000);
	connect(positionSlider, SIGNAL(sliderMoved(int)),this, SLOT(sliderChanged(int)));
	connect(positionSlider, SIGNAL(sliderPressed()),this, SLOT(sliderPressed()));
	connect(positionSlider, SIGNAL(sliderReleased()),this, SLOT(sliderReleased()));

	connect(surface, SIGNAL(frameChanged(I8u)),this, SLOT(frameChanged(I8u)));
	connect(surface, SIGNAL(durationFramesChanged(I8u)),this, SLOT(durationFramesChanged(I8u)));

	connect(this, SIGNAL(setSlider(int)),positionSlider, SLOT(setValue(int)));
	
	QBoxLayout * controlLayout = new QHBoxLayout;
	controlLayout->addWidget(playPauseButton);
	controlLayout->addWidget(positionSlider);

	QBoxLayout * layout = new QVBoxLayout;
	layout->addWidget(videoWidget);
	layout->addLayout(controlLayout);
