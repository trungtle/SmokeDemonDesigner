#ifndef SMOKEGAMEOBJECTCOMPONENT_H
#define SMOKEGAMEOBJECTCOMPONENT_H

#include <QStandardItem>

#include "smokegraphicsitem.h"

//
// Base class for all smoke game object components
//

class SmokeGameObjectComponent
{
public:
    explicit SmokeGameObjectComponent();

protected:

    //
    // These items are not required to be deleted.
    // They will be cleaned up by their parents
    //

    SmokeGraphicsItem* m_graphicsItem;
    QStandardItem* m_inspectorItem;

    //
    // Helpers
    //

    QStandardItem*
    createLabelEditRow(QString label,
            QString value);
};

#endif // SMOKEGAMEOBJECTCOMPONENT_H
