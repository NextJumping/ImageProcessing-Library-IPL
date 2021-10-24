
#ifndef MEDIA__FFMPEGqtPlayer_H
#define MEDIA__FFMPEGqtPlayer_H

#include "AML_Qt.h"

#include <Data/DataTypes.h>
#include <Image/Image.h>

#include <QtCore/QRect>
#include <QtGui/QImage>
#include <QtMultimedia/QAbstractVideoSurface>
#include <QtMultimedia/QVideoFrame>

#include <Thread/QueuePipe.h>
#include <Thread/QueueReaderAgent.h>
#include <Media/PlayerControl.h>