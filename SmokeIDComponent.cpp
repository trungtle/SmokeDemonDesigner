#include "SmokeIDComponent.h"

const
QString
SmokeIDComponent::NAME = "ID";

SmokeIDComponent::SmokeIDComponent(
        int /* ID */, // Not using this for now
        QString gameObjectName,
        SmokeGraphicsItem* graphicsItem,
        SmokeGameObject* parent
        ) :
    SmokeGameObjectComponent(NAME, graphicsItem, parent)
{
    //
    // Must define the properties for this component
    //

    m_properties["name"] = gameObjectName;

    //
    // Must create inspectorItem after we defined all the properties
    //

    createInspectorItem();
}

void
SmokeIDComponent::updateGraphicsItem(
        const QString /* property */
        )
{
}

