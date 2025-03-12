#pragma once
#include "misc/mathStuff.h"
#include "misc/Logger.h"
#include "SimpleBody.h"

glm::vec2 findCollisionOverLap(std::vector <glm::vec2> points, std::vector <math::line> lines, glm::vec2 lastPos, glm::vec2 pos);
struct collisionDataStruct
{
	glm::vec2 intersectionPoint;
	math::line intersectedFace;
	glm::vec2 overlapPoint;
};


class collisionDataHandler
{
	const SimpleBody b1;
	const SimpleBody b2;


public:

	collisionDataHandler(SimpleBody& b1, SimpleBody& b2);

};