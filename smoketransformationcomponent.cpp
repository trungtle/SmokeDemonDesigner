#include "smoketransformationcomponent.h"

SmokeTransformationComponent::SmokeTransformationComponent(
        SmokeGraphicsItem *item,
        double x,
        double y,
        double z,
        double angle,
        double scale
        )
{
    m_graphicsItem = item;
    m_graphicsItem->setPos(QPointF(x, y));
    m_graphicsItem->setZValue(z);
    m_graphicsItem->setRotation(angle);
    m_graphicsItem->setScale(scale);
}
