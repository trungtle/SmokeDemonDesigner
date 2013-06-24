#include "smokegraphicsitem.h"

SmokeGraphicsItem::SmokeGraphicsItem(
        const QPixmap & pixmap,
        QGraphicsItem * parent
        ) :
    QGraphicsPixmapItem(pixmap, parent)
{
}
