#include "SmokeTransformationComponent.h"

const
QString
SmokeTransformationComponent::NAME = "Transformation";

SmokeTransformationComponent::SmokeTransformationComponent(
        double x,
        double y,
        double z,
        double angle,
        double scale,
        SmokeGraphicsItem *graphicsItem,
        SmokeGameObject* parent
        ) :

    SmokeGameObjectComponent(NAME, graphicsItem, parent)
{
    //
    // Must define the properties for this component
    //

    m_properties["x"] = x;
    m_properties["y"] = y;
    m_properties["z"] = z;
    m_properties["angle"] = angle;
    m_properties["scale"] = scale;

    //
    // Must create inspectorItem after we defined all the properties
    //

    createInspectorItem();

    foreach (QString key, m_properties.keys()) {
        updateGraphicsItem(key);
    }
 }

void
SmokeTransformationComponent::updateGraphicsItem(
        const QString property
        )
{
    if (property.compare("x") == 0 || property.compare("y") == 0) {

        m_graphicsItem->setPos(QPointF(
                                   m_properties["x"].toFloat(),
                                   m_properties["y"].toFloat()));

    } else if (property.compare("z") == 0) {

        m_graphicsItem->setZValue(m_properties["z"].toFloat());

    } else if (property.compare("angle") == 0) {

        m_graphicsItem->setRotation(m_properties["angle"].toFloat());

    } else if (property.compare("scale") == 0) {

        m_graphicsItem->setScale(m_properties["scale"].toFloat());

    }
}
