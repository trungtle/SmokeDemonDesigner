#ifndef HOVERPOINTS_H
#define HOVERPOINTS_H

#include <QObject>
#include <QPen>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>

class SmokeHoverPoint : public QGraphicsEllipseItem
{
public:
    explicit SmokeHoverPoint(
            qreal x,
            qreal y,
            qreal w,
            qreal h,
            QGraphicsItem* parent = 0
            );

    QVariant
    itemChange(
            QGraphicsItem::GraphicsItemChange change,
            const QVariant &value
            );
};

class SmokeHoverPoints
{
public:
    explicit SmokeHoverPoints(
            QGraphicsItem *parent = 0
            );
    
    void
    show();

    void
    hide();

    bool
    isSelected();

private:

    SmokeHoverPoint* m_anchorPoint;
    SmokeHoverPoint* m_rotatePoint;
    QGraphicsLineItem* m_connectionLine;

signals:
    
public slots:
    
};

#endif // HOVERPOINTS_H
