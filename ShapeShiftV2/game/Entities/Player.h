#pragma once
#include "Entity.h"
#include "misc/Input.h"
class Player :
    public Entity
{
private:
    bool colliding = false;

public:

    Player(glm::vec2 pos, glm::vec2 baseSize, glm::vec4 color, Sprite sp, glm::vec2 v);
    //overloads
    void collisionHandle(Object* other);
    void update();

};

