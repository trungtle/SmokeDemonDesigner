#include "smokegameobjectcomponent.h"

SmokeGameObjectComponent::SmokeGameObjectComponent()
{
}


QStandardItem*
SmokeGameObjectComponent::createLabelEditRow(
        QString label,
        QString value)
{
    //
    // Label item
    //

    QStandardItem* labelItem = new QStandardItem(label);

    labelItem->setSelectable(false);
    labelItem->setEditable(false);
    labelItem->setBackground(QBrush(Qt::darkGray));

    //
    // Edit item
    //

    QStandardItem* editItem = new QStandardItem(value);

    QList<QStandardItem*> row;
    row << labelItem << editItem;

    //
    // add this to edit item
    //

    m_inspectorItem->appendRow(row);

    return editItem;
}
