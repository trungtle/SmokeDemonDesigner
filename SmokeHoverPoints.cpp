#include <QDebug>
#include "SmokeGraphicsScene.h"
#include "SmokeGraphicsItem.h"
#include "SmokeHoverPoints.h"

const int size = 20;
const int alpha = 155;

SmokeHoverPoint::SmokeHoverPoint(
        qreal x,
        qreal y,
        qreal w,
        qreal h,
        SmokeHoverPoints* group,
        QGraphicsItem* parent
        ) :
    QGraphicsEllipseItem(0, 0, w, h, parent)
{
    m_pointGroup = group;

    setPos(x, y);

    setPen(QPen(QColor(255, 100, 50, alpha)));
    setBrush(QBrush(QColor(151, 0, 0, alpha)));
}


QVariant
SmokeHoverPoint::itemChange(
        QGraphicsItem::GraphicsItemChange change,
        const QVariant &value)
{
    switch(change) {
    case ItemPositionHasChanged:
    {

        QGraphicsLineItem* connectionLine = m_pointGroup->connectionLine();
        connectionLine->setLine(
                    parentItem()->boundingRect().center().x(),
                    parentItem()->boundingRect().center().y(),
                    x() + size / 2,
                    y() + size / 2
                    );

        break;
    }
    default:
    {
        break;
    }
    }
    return QGraphicsItem::itemChange(change, value);
}

SmokeHoverPoints::SmokeHoverPoints(
        SmokeGraphicsItem *parent
        )
{
    m_parent = parent;

    m_connectionLine =
            new QGraphicsLineItem(
                parent->boundingRect().center().x() + size / 2,
                parent->boundingRect().center().y(),
                parent->boundingRect().right() + size,
                parent->boundingRect().center().y(),
                parent
                );
    m_connectionLine->setPen(QPen(QColor(247, 247, 247, 50)));

    m_anchorPoint =
            new SmokeHoverPoint(
                parent->boundingRect().center().x() - size / 2,
                parent->boundingRect().center().y() - size / 2,
                size,
                size,
                this,
                parent
                );

    m_rotatePoint =
            new SmokeHoverPoint(
                parent->boundingRect().right() + size,
                parent->boundingRect().center().y() - size / 2,
                size,
                size,
                this,
                parent
                );
    m_rotatePoint->setFlags(
                    QGraphicsItem::ItemIsMovable |
                    QGraphicsItem::ItemSendsGeometryChanges
                    );
}

void
SmokeHoverPoints::show()
{
    m_anchorPoint->show();
    m_rotatePoint->show();
    m_connectionLine->show();
}

void
SmokeHoverPoints::hide()
{
    m_anchorPoint->hide();
    m_rotatePoint->hide();
    m_connectionLine->hide();

}

bool
SmokeHoverPoints::isSelected()
{
    return m_rotatePoint->isSelected();
}
