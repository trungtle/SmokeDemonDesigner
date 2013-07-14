#ifndef TRANSFORMATIONCOMPONENT_H
#define TRANSFORMATIONCOMPONENT_H

#include "smokegameobjectcomponent.h"

class SmokeTransformationComponent : public SmokeGameObjectComponent
{

public:
    static const QString NAME;

    SmokeTransformationComponent(
            double x,
            double y,
            double z = 0,
            double angle = 0, // in degree
            double scale = 1,
            SmokeGraphicsItem* item = 0,
            SmokeGameObject* parent = 0);

    //
    // Subclass implementation
    //

    void
    updateGraphicsItem(
            const QString property
            );

private:

};

#endif // TRANSFORMATIONCOMPONENT_H
