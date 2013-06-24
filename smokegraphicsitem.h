#ifndef SMOKEGRAPHICSITEM_H
#define SMOKEGRAPHICSITEM_H

#include <QGraphicsPixmapItem>

class SmokeGraphicsItem : public QGraphicsPixmapItem
{

public:
    explicit SmokeGraphicsItem(
            const QPixmap & pixmap,
            QGraphicsItem * parent = 0
            );

private:
    
signals:
    
public slots:
    
};

#endif // SMOKEGRAPHICSITEM_H
