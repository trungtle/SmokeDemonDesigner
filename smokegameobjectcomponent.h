#ifndef SMOKEGAMEOBJECTCOMPONENT_H
#define SMOKEGAMEOBJECTCOMPONENT_H

typedef enum {
    GAMEOBJ_TRANSFORMATION,
    GAMEOBJ_TEXTURE
} SmokeGameObjectComponentType_t;

class SmokeGameObjectComponent
{
public:
    SmokeGameObjectComponent(SmokeGameObjectComponentType_t);
    ~SmokeGameObjectComponent();
};

#endif // SMOKEGAMEOBJECTCOMPONENT_H
