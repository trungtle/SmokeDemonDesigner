#ifndef SMOKEIDCOMPONENT_H
#define SMOKEIDCOMPONENT_H

#include "smokegameobjectcomponent.h"

class SmokeIDComponent : public SmokeGameObjectComponent
{
public:

    static const QString NAME;

    SmokeIDComponent(
            int ID,
            QString gameObjectName,
            SmokeGraphicsItem* graphicsItem,
            SmokeGameObject* parent
            );

    void
    updateGraphicsItem(
            const QString property
            );
};

#endif // SMOKEIDCOMPONENT_H
