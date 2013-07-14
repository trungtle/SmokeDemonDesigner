#include "SmokeGameObjectComponent.h"
#include "SmokeGameObject.h"

SmokeGameObjectComponent::SmokeGameObjectComponent(
        QString name,
        SmokeGraphicsItem *graphicsItem,
        SmokeGameObject* parent)
{
    m_name = name;
    m_object = parent;
    m_graphicsItem = graphicsItem;

    //
    // Initialize the inspector item for this component
    //

    m_inspectorItem = new QStandardItem(name);
    m_inspectorItem->setSelectable(false);
    m_inspectorItem->setEditable(false);

}

void SmokeGameObjectComponent::createInspectorItem()
{
    foreach (QString key, m_properties.keys()) {

        QStandardItem* propertyName = new QStandardItem(key);

        propertyName->setSelectable(false);
        propertyName->setEditable(false);

        QStandardItem* propertyValue =
                new QStandardItem(m_properties[key].toString());

        QList<QStandardItem*> row;
        row << propertyName << propertyValue;

        m_inspectorItem->appendRow(row);
    }
}

void
SmokeGameObjectComponent::updateInspectorItem(QString property)
{
    int i = m_properties.keys().indexOf(property);

    if (i == -1) {
        // No item matched
        return;
    }

    //
    // Column 1 is the property value
    //

    m_inspectorItem->child(i, SMOKE_PROPERTY_VALUE)
            ->setData(m_properties[property], Qt::EditRole);

}

void
SmokeGameObjectComponent::setProperty(
        const QString property,
        const QVariant value
        )
{
    if (this == NULL) {
        return;
    }

    if (m_properties.contains(property)) {
        m_properties[property] = value;
    }
}

