#ifndef SMOKEGRAPHICSITEM_H
#define SMOKEGRAPHICSITEM_H

#include <QGraphicsPixmapItem>
#include "smokegameobject.h"

class SmokeGraphicsItem : public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit SmokeGraphicsItem(QObject *parent = 0);

private:
    SmokeGameObject* object;
    
signals:
    
public slots:
    
};

#endif // SMOKEGRAPHICSITEM_H
