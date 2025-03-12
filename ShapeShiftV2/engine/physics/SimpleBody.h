#pragma once
#include "misc/mathStuff.h"
#include "misc/Logger.h"
#include "HBox.h"
#include "PhysicsGlobals.h"
#include <string>

/*
* A class for handling the most basic physics object
*/
class SimpleBody
{
private:

	std::string name = "default";

	float mass = 1.0f;

	//2D physics
	//assume center of mass is pos
	glm::vec2 pos = { 0.0f, 0.0f };
	glm::vec2 lastPos = { 0.0f, 0.0f };

	glm::vec2 velocity = { 0.0f, 0.0f };
	glm::vec2 gravityAcceleration{ 0.0f, 0.0f };
	glm::vec2 acceleration = { 0.0f, 0.0f };
	glm::vec2 momentum{ 0.0f, 0.0f };

	float KE = 0.0f;
	float PE = 0.0f;

	//rotational physics
	//in degrees???
	float rotation = 0.0f;
	float angularVelocity = 0.0f;
	float angularAcceleration = 0.0f;
	float angularMomentum = 0.0f;


	glm::vec2 baseSize = { 0.0f, 0.0f };
	glm::vec2 sizeDelta = { 0.0f, 0.0f };

	HBox HB;
	HBox lastHB;

	bool intangable = false;
	/*
	* determines the multiplier for how this object is affected by gravity within the scene
	*/
	float frameGravityMultiplier = 1.0f;

public:

	/*
	* default constructor, default HBox: is created as a rectangle with given pos and size
	*/
	SimpleBody(glm::vec2 pos, glm::vec2 size);

	/*
	* polygon constructor, HBox created with polygon and then moved to pos, size is a scalar based on the given polygon
	*/
	//SimpleBody(glm::vec2 pos, math::Polygon poly);

	/*
	* a point based constructor, HBox created with polygon and then moved to pos, size is a scalar based on the given polygon
	*/
	SimpleBody(glm::vec2 pos, std::vector <glm::vec2> points);



	/*
	* Updates with current velocities, accelerations, etc.
	*/
	void update();









	//setters and getters


	void setMass(float m);

	float getMass();

	void setVelocity(glm::vec2 v);
	void setAcceleration(glm::vec2 a);
	void setPos(glm::vec2 pos);

	void setAngularVelocity(float v);
	void setAngularAcceleration(float v);
	void setRotation(float r);


	glm::vec2 getVelocity();
	glm::vec2 getAcceleration();
	glm::vec2 getPos();

	float getAngularVelocity();
	float getAngularAcceleration();
	float getRotation();


	float getKineticEnergy();
	float getPotentialEnergy();
	glm::vec2 getMomentum();
	float getAngularMomentum();

	/*
	* determines the whether the object experiences collisions
	*/
	bool isIntangable();
	/*
	* sets whether the object experiences collisions
	*/
	void setIntangable(bool b);


	/*
	* determines the multiplier for how this object is affected by gravity within the scene
	*/
	float getFrameGravityMultiplier();

	/*
	* sets the multiplier for how this object is affected by gravity within the scene
	*/
	void setFrameGravityMultiplier(float x);
};