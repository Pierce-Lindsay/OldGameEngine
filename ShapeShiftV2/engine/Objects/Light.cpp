#include "Light.h"


Light::Light(glm::vec2 pos, glm::vec2 baseSize, glm::vec4 color, Sprite sp, glm::vec2 v, float brightness, bool on) : Terrain(pos, baseSize, color, sp, v)
{
	primary.makeIntoLight(brightness, on);
	baseColor = color;
	baseLightColor = color;
}


void Light::update()
{
	if (flicker)
	{
		flickerTracker += flickerSpeed;

		primary.setColor(baseColor + glm::vec4(-abs(cos(flickerTracker)) / 3.0f, 0.0, 0.0f, 0.0f));
		primary.changeLightColor(baseColor + glm::vec4(-abs(cos(flickerTracker)) / 3.0f, 0.0f, 0.0f, 0.0f));
	}
	defaultUpdate();
}