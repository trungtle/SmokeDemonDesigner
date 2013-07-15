#include <QDebug>
#include "SmokeGameobject.h"
#include "SmokeIDComponent.h"
#include "SmokeTransformationComponent.h"

int SmokeGameObject::s_nextID = 0;

//
// @tle_todo: pass in as parameter instead
//

const QString TEXTURE_FILENAME = ":/img/LizardSquare.png";

SmokeGameObject::SmokeGameObject(
        QString name,
        qreal x,
        qreal y,
        qreal z,
        qreal angle,
        qreal scale) :
    QStandardItemModel(0, COLS)
{
    m_ID = s_nextID++;

    if (name.isEmpty() || name == NULL) {

        //
        // Default name
        //

        m_name = QString("Obj#%1").arg(m_ID);

    } else {
        m_name = name;
    }

    m_graphicsItem =
            new SmokeGraphicsItem(this, QPixmap(TEXTURE_FILENAME));

    this->createIDComponent();
    this->createTransformation(x, y, z, angle, scale);

    QObject::connect(
                this,
                SIGNAL(itemChanged(QStandardItem*)),
                this,
                SLOT(updateGraphics(QStandardItem*))
                );
}

SmokeGameObject::~SmokeGameObject()
{
}

SmokeGraphicsItem*
SmokeGameObject::getGraphicsItem(
        )
{
    return m_graphicsItem;
}

void
SmokeGameObject::createIDComponent()
{
    const QString name = SmokeIDComponent::NAME;
    m_components.insert(name,
                        new SmokeIDComponent(
                            m_ID,
                            m_name,
                            m_graphicsItem,
                            this
                            )
                        );

    invisibleRootItem()->appendRow(
                m_components[name]->inspectorItem());
}

void
SmokeGameObject::createTransformation(
        qreal x,
        qreal y,
        qreal z,
        qreal angle,
        qreal scale)
{
    const QString name = SmokeTransformationComponent::NAME;
    m_components.insert(name,
                         new SmokeTransformationComponent(
                            x,
                            y,
                            z,
                            angle,
                            scale,
                            m_graphicsItem,
                            this
                            ));

    invisibleRootItem()->appendRow(
                m_components[name]->inspectorItem());
}

void
SmokeGameObject::updateModelItemPositionChange(
        const QPointF newPos
        )
{
    const QString name = SmokeTransformationComponent::NAME;

    if (this == NULL || m_components.value((name)) == NULL) {
        return;
    }
    m_components.value(name)->setProperty("x", newPos.x());
    m_components.value(name)->updateInspectorItem("x");

    m_components.value(name)->setProperty("y", newPos.y());
    m_components.value(name)->updateInspectorItem("y");

    emitDataChanged();
}

void
SmokeGameObject::updateModelItemSelected(
        const bool isSelected
        )
{
    if (isSelected) {
        emitDataChanged();
    }
}

void
SmokeGameObject::emitDataChanged()
{
    //
    // Update the item model
    //

    emit dataChanged(index(0,1), index(rowCount(), 1));
}

void
SmokeGameObject::updateGraphicsComponent(
        SmokeGameObjectComponent* component,
        QString property,
        QVariant value
        )
{
    component->setProperty(property, value);
    component->updateGraphicsItem(property);
}

void
SmokeGameObject::updateInspectorComponent(
        SmokeGameObjectComponent *component,
        QString property,
        QVariant value
        )
{
    component->setProperty(property, value);
    component->updateInspectorItem(property);
}

int
SmokeGameObject::ID()
const
{
    return m_ID;
}

/* ----------------------------------------------------------------------------
 * SLOTS
 * ------------------------------------------------------------------------- */
void
SmokeGameObject::updateGraphics(
        QStandardItem *item
        )
{
    foreach(SmokeGameObjectComponent* component, m_components.values()) {

        //
        // Go through and check which component this item's change belong to
        //

        QStandardItem* componentInspectorItem = component->inspectorItem();

        if (item->parent() == componentInspectorItem) {

            QString property =
                    componentInspectorItem->
                    child(item->row(), 0)->
                    data(Qt::DisplayRole).toString();

            QVariant value = item->data(Qt::DisplayRole);

            component->setProperty(property, value);
            component->updateGraphicsItem(property);
        }
    }
}

QVariant
SmokeGameObject::data(
        const QModelIndex &index,
        int role
        ) const
{
    int row = index.row();
    int col = index.column();
    bool isComponentHeader = index.parent() == this->invisibleRootItem()->index();

    switch(role)
    {
    case Qt::DisplayRole:
        break;
    case Qt::FontRole:
        return QFont("Museo Slab 500", 10);
        if (col == 0)
        {
            QFont boldFont;
            boldFont.setBold(true);
            return boldFont;
        }
        break;
    case Qt::ForegroundRole:
        if (isComponentHeader) {
            return QVariant(QColor(30, 144, 255));
        }

        if (col == 0) {
            return QVariant(QColor(128, 218, 17));
        }
        break;
    case Qt::BackgroundRole:
        break;
    case Qt::TextAlignmentRole:
        break;
    case Qt::CheckStateRole:
        break;
    }

    return QStandardItemModel::data(index, role);
}
