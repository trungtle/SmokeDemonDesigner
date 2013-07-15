#ifndef HOVERPOINTS_H
#define HOVERPOINTS_H

#include <QObject>
#include <QPen>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>

class SmokeGraphicsItem;
class SmokeHoverPoints;

class SmokeHoverPoint : public QGraphicsEllipseItem
{
public:
    explicit SmokeHoverPoint(qreal x,
            qreal y,
            qreal w,
            qreal h,
            SmokeHoverPoints* pointGroup,
            QGraphicsItem *parent
            );

    QVariant
    itemChange(
            QGraphicsItem::GraphicsItemChange change,
            const QVariant &value
            );
private:
    SmokeHoverPoints* m_pointGroup;

};

class SmokeHoverPoints
{
public:
    explicit SmokeHoverPoints(
            SmokeGraphicsItem *parent = 0
            );
    
    void
    show();

    void
    hide();

    bool
    isSelected();

    QGraphicsLineItem*
    connectionLine()
    {
        return m_connectionLine;
    }

    SmokeHoverPoint*
    anchorPoint()
    {
        return m_anchorPoint;
    }

    SmokeHoverPoint*
    rotatePoint()
    {
        return m_rotatePoint;
    }

private:
    SmokeGraphicsItem* m_parent;
    SmokeHoverPoint* m_anchorPoint;
    SmokeHoverPoint* m_rotatePoint;
    QGraphicsLineItem* m_connectionLine;

signals:
    
public slots:
    
};

#endif // HOVERPOINTS_H
