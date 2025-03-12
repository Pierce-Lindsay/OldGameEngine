#include "Entity.h"


Entity::Entity(glm::vec2 pos, glm::vec2 baseSize, glm::vec4 color, Sprite sp, glm::vec2 v) : Object(pos, baseSize, color, sp, v)
{

}


ObjectType Entity::getObjectType()
{
	return ObjectType::ENTITY;
}


void Entity::collisionHandle(Object* other)
{
	defaultCollisionHandle(other);
}

void Entity::update()
{
	defaultUpdate();
}
