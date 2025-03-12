#include "SimpleBody.h"



/*
* default constructor, default HBox: is created as a rectangle with given pos and size
*/
SimpleBody::SimpleBody(glm::vec2 pos, glm::vec2 size)
:HB(pos, size), lastHB(HB)
{
	gravityAcceleration.y = phys::frameGravity * frameGravityMultiplier;
}

/*
* polygon constructor, HBox created with polygon and then moved to pos, size is a scalar based on the given polygon
*/
//SimpleBody::SimpleBody(glm::vec2 pos, math::polygon)
//{

//}

/*
* a point based constructor, HBox created with polygon and then moved to pos, size is a scalar based on the given polygon
*/
//SimpleBody::SimpleBody(glm::vec2 pos, std::vector <glm::vec2> points)
//{

//}



/*
* Updates with current velocities, accelerations, etc.
*/
void SimpleBody::update()
{
	gravityAcceleration.y = phys::frameGravity * frameGravityMultiplier;
	velocity += (acceleration + gravityAcceleration) * phys::deltaTimeConstant;
	pos += velocity * phys::deltaTimeConstant;

	KE = 0.5 * mass * math::findVectorValue(velocity);
	momentum = velocity * mass;


	angularVelocity += angularAcceleration * phys::deltaTimeConstant;
	rotation += angularVelocity * phys::deltaTimeConstant;

	angularMomentum = angularVelocity * mass;

}














//setters and getters



void SimpleBody::setMass(float m)
{
	mass = m;
}

float SimpleBody::getMass()
{
	return mass;
}

void SimpleBody::setVelocity(glm::vec2 v)
{
	velocity = v;
}
void SimpleBody::setAcceleration(glm::vec2 a)
{
	acceleration = a;
}
void SimpleBody::setPos(glm::vec2 pos)
{
	this->pos = pos;
}

void SimpleBody::setAngularVelocity(float v)
{
	angularVelocity = v;
}
void SimpleBody::setAngularAcceleration(float a)
{
	angularAcceleration = a;
}
void SimpleBody::setRotation(float r)
{
	rotation = r;
}


glm::vec2 SimpleBody::getVelocity()
{
	return velocity;
}
glm::vec2 SimpleBody::getAcceleration()
{
	return acceleration;
}
glm::vec2 SimpleBody::getPos()
{
	return pos;
}

float SimpleBody::getAngularVelocity()
{
	return angularVelocity;
}
float SimpleBody::getAngularAcceleration()
{
	return angularAcceleration;
}
float SimpleBody::getRotation()
{
	return rotation;
}


float SimpleBody::getKineticEnergy()
{
	return KE;
}
float SimpleBody::getPotentialEnergy()
{
	return PE;
}
glm::vec2 SimpleBody::getMomentum()
{
	return momentum;
}
float SimpleBody::getAngularMomentum()
{
	return angularMomentum;
}

bool SimpleBody::isIntangable()
{
	return intangable;
}

void  SimpleBody::setIntangable(bool b)
{
	intangable = b;
}




/*
* determines the multiplier for how this object is affected by gravity within the scene
*/
float SimpleBody::getFrameGravityMultiplier()
{
	return frameGravityMultiplier;
}

/*
* sets the multiplier for how this object is affected by gravity within the scene
*/
void SimpleBody::setFrameGravityMultiplier(float x)
{
	frameGravityMultiplier = x;
}