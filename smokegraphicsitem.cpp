#include "SmokeGraphicsItem.h"
#include "SmokeGameObject.h"

SmokeGraphicsItem::SmokeGraphicsItem(
        SmokeGameObject* object,
        const QPixmap & pixmap,
        QGraphicsItem * parent
        ) :
    QGraphicsPixmapItem(pixmap, parent)
{
    m_object = object;
    m_ID = object->ID();

    //
    // @tle_todo: Bogus text label
    //

    m_label =
            new QGraphicsSimpleTextItem(
                QString("%1").arg(m_ID),
                this
                );

    m_label->setPen(QPen(QColor(255, 100, 50, 115)));
    m_label->setBrush(QBrush(QColor(151, 0, 0, 115)));

    //
    // Creat points
    //

    m_hoverPoints =
            new SmokeHoverPoints(
                this
                );

    setFlags(
                QGraphicsItem::ItemIsMovable |
                QGraphicsItem::ItemIsSelectable |
                QGraphicsItem::ItemSendsGeometryChanges
    );

    //
    // Initial state
    //

    hideHoverGraphicsItems();
}

SmokeGraphicsItem::~SmokeGraphicsItem()
{
    delete m_label;
}

void
SmokeGraphicsItem::showHoverGraphicsItems()
{
    m_label->show();
    m_hoverPoints->show();
}

void
SmokeGraphicsItem::hideHoverGraphicsItems()
{
    m_label->hide();
    m_hoverPoints->hide();
}

SmokeGameObject
*SmokeGraphicsItem::gameObject()
{
    return m_object;
}

QVariant
SmokeGraphicsItem::itemChange(
        QGraphicsItem::GraphicsItemChange change,
        const QVariant &value
        )
{
    switch (change) {
    case ItemPositionChange:
    {

        // value is the new position.

        QPointF newPos = value.toPointF();
        m_object->updateModelItemPositionChange(newPos);
        break;
    }
    case ItemSelectedChange:
    {
        m_object->updateModelItemSelected(value.toBool());

        if (value.toBool()) {
            showHoverGraphicsItems();
        } else {
            hideHoverGraphicsItems();
        }
        break;
    }
    default:
    {
        break;
    }
    }

    return QGraphicsItem::itemChange(change, value);
}

int
SmokeGraphicsItem::ID()
const
{
    return m_ID;
}
