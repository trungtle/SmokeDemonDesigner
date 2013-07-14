#ifndef SMOKEGAMEOBJECTCOMPONENT_H
#define SMOKEGAMEOBJECTCOMPONENT_H

#include <QStandardItem>
#include "SmokeGraphicsItem.h"

class SmokeGameObject;

typedef enum {
    SMOKE_PROPERTY_NAME,
    SMOKE_PROPERTY_VALUE
} SmokeInspectorItemColumn_t;


//
// Base class for all smoke game object components
//

class SmokeGameObjectComponent
{
public:
    explicit SmokeGameObjectComponent(
            QString name = "Default component",
            SmokeGraphicsItem* graphicsItem = NULL,
            SmokeGameObject* parent = NULL
            );

    void
    setProperty(
            const QString property,
            const QVariant value
            );

    void
    updateInspectorItem(QString property);

    //
    // Interface that subclass must implement
    //

    virtual
    void
    updateGraphicsItem(
            const QString property
            ) = 0;

    //
    // Accessors
    //

    QStandardItem* inspectorItem()
    {
        return m_inspectorItem;
    }

protected:

    QString m_name;
    QMap<QString, QVariant> m_properties;

    //
    // @tle_todo:
    // These items are not required to be deleted.
    // They will be cleaned up by their parents
    //

    SmokeGameObject* m_object;
    SmokeGraphicsItem* m_graphicsItem;
    QStandardItem* m_inspectorItem;

    //
    // Helpers
    //

    void
    createInspectorItem();

};

#endif // SMOKEGAMEOBJECTCOMPONENT_H
