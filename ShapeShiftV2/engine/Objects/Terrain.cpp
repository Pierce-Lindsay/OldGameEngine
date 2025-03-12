#include "Terrain.h"


Terrain::Terrain(glm::vec2 pos, glm::vec2 baseSize, glm::vec4 color, Sprite sp, glm::vec2 v) : Object(pos, baseSize, color, sp, v)
{

}


ObjectType Terrain::getObjectType()
{
	return ObjectType::TERRAIN;
}

void Terrain::collisionHandle(Object* other)
{
	defaultCollisionHandle(other);
}

void Terrain::update()
{
	defaultUpdate();
}
