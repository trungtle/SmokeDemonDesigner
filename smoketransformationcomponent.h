#ifndef TRANSFORMATIONCOMPONENT_H
#define TRANSFORMATIONCOMPONENT_H

#include <QStandardItem>
#include "smokegameobjectcomponent.h"

typedef struct _SmokeCoordinate_t {
    double x;
    double y;
    double z;
} SmokeCoordinate_t;

typedef struct _SmokeTransformation_t {
    SmokeCoordinate_t coord;
    double angle;
    double scale;
} SmokeTransformation_t;

class SmokeTransformationComponent : public SmokeGameObjectComponent
{
public:
    SmokeTransformationComponent(
            SmokeGraphicsItem* item,
            double x,
            double y,
            double z = 0,
            double angle = 0, // in degree
            double scale = 1
            );

private:
    SmokeTransformation_t* m_transformation;

};

#endif // TRANSFORMATIONCOMPONENT_H
