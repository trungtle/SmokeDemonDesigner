#ifndef SMOKEGAMEOBJECT_H
#define SMOKEGAMEOBJECT_H

#include <QStandardItem>
#include <QGraphicsPixmapItem>
#include <QAbstractItemModel>
#include "SmokeGraphicsItem.h"
#include "SmokeGameObjectComponent.h"

const int ROWS = 100;
const int COLS = 2;

class SmokeGameObject : public QStandardItemModel
{
    Q_OBJECT
public:
    explicit SmokeGameObject(
            QString name,
            qreal x,
            qreal y,
            qreal z = 0,
            qreal angle = 0,
            qreal scale = 1);
    ~SmokeGameObject();

    QVariant
    data(
            const QModelIndex &index,
            int role = Qt::DisplayRole
            ) const;

    //
    // Graphics change that requires model update
    //

    void
    updateModelItemPositionChange(
            const QPointF newPosition
            );

    void
    updateModelItemSelected(
            const bool isSelected
            );


    //
    // Accessors
    //

    SmokeGraphicsItem*
    getGraphicsItem();

    int
    ID() const;

    //
    // Subclass
    //

private:

    //
    // Keeps track of the next available ID
    //

    static int s_nextID;
    int m_ID;

    QString m_name;

    //
    // Do not delete this graphics item as it is added to the scene
    // and will be deleted by it
    //

    SmokeGraphicsItem* m_graphicsItem;
    QMap<QString, SmokeGameObjectComponent*> m_components;

    void
    createIDComponent();

    void
    createTransformation(
            qreal x,
            qreal y,
            qreal z,
            qreal angle,
            qreal scale
            );

    void
    emitDataChanged();

    void
    updateGraphicsComponent(
            SmokeGameObjectComponent* component,
            QString property,
            QVariant value);

    void
    updateInspectorComponent(
            SmokeGameObjectComponent* component,
            QString property,
            QVariant value);

signals:
    
private slots:

    void
    updateGraphics(
            QStandardItem* item
            );
    
};

#endif // SMOKEGAMEOBJECT_H
