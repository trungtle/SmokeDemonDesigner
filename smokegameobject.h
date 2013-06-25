#ifndef SMOKEGAMEOBJECT_H
#define SMOKEGAMEOBJECT_H

#include <QStandardItem>
#include <QGraphicsPixmapItem>
#include <QAbstractItemModel>
#include "smokegraphicsitem.h"
#include "smoketransformationcomponent.h"

const int ROWS = 100;
const int COLS = 2;

class SmokeGameObject : public QStandardItemModel
{
public:
    explicit SmokeGameObject(qreal x,
            qreal y,
            qreal z = 0,
            qreal angle = 0,
            qreal scale = 1);
    ~SmokeGameObject();

    QGraphicsPixmapItem*
    getGraphicsItem();

    //
    // Subclass
    //

private:
    SmokeGraphicsItem* m_graphicsItem;
    QMap<QString, SmokeGameObjectComponent*> m_components;

    void
    createTransformation(
            qreal x,
            qreal y,
            qreal z,
            qreal angle,
            qreal scale
            );

    QStandardItem*
    createLabelItem(
            QString name
            );

    void
    createLabelEditRow(
            QString label,
            QString value,
            QStandardItem* parent
            );
    
signals:
    
public slots:
    
};

#endif // SMOKEGAMEOBJECT_H
