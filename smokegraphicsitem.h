#ifndef SMOKEGRAPHICSITEM_H
#define SMOKEGRAPHICSITEM_H

#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include "SmokeHoverPoints.h"

//
// Forward declarations
//

class SmokeGameObject;

class SmokeGraphicsItem : public QGraphicsPixmapItem
{
public:
    explicit SmokeGraphicsItem(
            SmokeGameObject* object,
            const QPixmap & pixmap,
            QGraphicsItem * parent = 0
            );
    ~SmokeGraphicsItem();

    void
    showHoverGraphicsItems();

    void
    hideHoverGraphicsItems();

    //
    // Accessors
    //

    SmokeGameObject*
    gameObject();

    int
    ID() const;

protected:

    QVariant
    itemChange (
            GraphicsItemChange change,
            const QVariant & value
            );

private:

    int m_ID;

    SmokeHoverPoints* m_hoverPoints;

    //
    // @tle_todo: temp label
    //

    QGraphicsSimpleTextItem* m_label;

    //
    // Do not delete this m_object
    //

    SmokeGameObject* m_object;


signals:
    
public slots:
    
};

#endif // SMOKEGRAPHICSITEM_H
