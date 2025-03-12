#pragma once
#include <string>
#include "Sprite.h"
#include "misc/Globals.h"
#include "physics/collision.h"
//parent class of all objects(anything taht contains at least oen renderable, 

enum class ObjectType
{
	ENTITY,
	TERRAIN,
	ELEMENT,
};

class Object
{
protected:
	
	Renderable primary;
	std::string name = "default";
	glm::vec2 baseSize= {0.0f, 0.0f};
	glm::vec4 baseColor = white;
	//float mass = 1.0f;

	glm::vec2 pos;
	glm::vec2 lastPos;

	glm::vec2 velocity = {0.0f, 0.0f};
	glm::vec2 acceleration = { 0.0f, 0.0f };
	float rotVelocity = 0.0f;
	glm::vec4 colorDelta = { 0.0f, 0.0f, 0.0f, 0.0f };
	glm::vec2 sizeDelta = {0.0f, 0.0f};

	bool canCollide = true;


	void defaultUpdate();

public:
	HBox HB;
	HBox lastHB;
	Object(glm::vec2 pos, glm::vec2 baseSize, glm::vec4 color, Sprite sp, glm::vec2 v);
	 virtual ObjectType  getObjectType() = 0;
	 virtual void collisionHandle(Object* other) = 0;
	 void defaultCollisionHandle(Object* other);
	 virtual void update() = 0;

	 //getters
	 glm::vec2 getVelocity()
	 {
		 return velocity;
	 };

	 glm::vec2 getPos()
	 {
		 return pos;
	 };

	 //returns last frames pos - this pos
	 glm::vec2 instantaneousVelocity()
	 {
		 return lastPos - pos;
	 };

};

