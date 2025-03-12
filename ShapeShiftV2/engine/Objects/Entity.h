#pragma once
#include "Object.h"
class Entity :
    public Object
{





public:

    Entity(glm::vec2 pos, glm::vec2 baseSize, glm::vec4 color, Sprite sp, glm::vec2 v);

    ObjectType getObjectType();
    void collisionHandle(Object* other);
    void update();

};

