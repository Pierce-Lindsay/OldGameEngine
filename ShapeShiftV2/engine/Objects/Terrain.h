#pragma once
#include "Object.h"
class Terrain :
    public Object
{



public:

    Terrain(glm::vec2 pos, glm::vec2 baseSize, glm::vec4 color, Sprite sp, glm::vec2 v);

    ObjectType getObjectType();
    void collisionHandle(Object* other);
    void update();
};

