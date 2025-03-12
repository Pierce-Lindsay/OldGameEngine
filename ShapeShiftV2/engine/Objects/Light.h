#pragma once
#include "Terrain.h"

class Light :
    public Terrain
{
    bool flicker = false;
    float flickerTracker =0.0f;
    float flickerSpeed = 0.05f;
    glm::vec4 baseColor;
    glm::vec4 baseLightColor;

public:
    Light(glm::vec2 pos, glm::vec2 baseSize, glm::vec4 color, Sprite sp, glm::vec2 v, float brightness, bool on);
    void update();
};

