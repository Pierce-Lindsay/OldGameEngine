#include "Object.h"


Object::Object(glm::vec2 pos, glm::vec2 baseSize, glm::vec4 color, Sprite sp, glm::vec2 v) 
	: baseSize{ baseSize }, velocity{ v }, baseColor(color), pos(pos), lastPos(pos),
	HB(pos, baseSize), lastHB(pos, baseSize),
	primary(genRenderable(pos, baseSize, color, sp, true))
{

}


void Object::defaultUpdate()
{
	primary.update(velocity);
	lastHB = HB;
	HB.update(velocity);
	lastPos = pos;
	pos = primary.t.getPos();
}

void Object::defaultCollisionHandle(Object* other)
{
	//math::line l1(glm::vec2(0.0f, 0.0f), glm::vec2(5.0f, 0.0f));
	//math::line l2(glm::vec2(3.0f, 3.0f), glm::vec2(3.0f, -10.0f));

	//math::intersection p = math::intersectionPoint(l1, l2);

	//std::cout << "x: " << p.point.x << ", " << p.point.y << '\n';


//if (instantaneousVelocity() != glm::vec2(0.0f, 0.0f))
	//{

	
	glm::vec2 overlap = findCollisionOverLap(HB.getPoints(), other->HB.getLines(), lastPos, pos);

	if (overlap.x != 0.0f || overlap.y != 0.0f)
	{
			//lg::printL("collision 1");
			lastHB = HB;
			HB.update(overlap);
			lastPos = pos;
			primary.move(overlap);
			pos = primary.t.getPos();

			

	}
	//if (collisionPoints.size() != 0)
	//{
		//collision!!!!!
	//	lg::printL("collision 1");
	//}

	//}
	//else if (other->instantaneousVelocity() != glm::vec2(0.0f, 0.0f))
	//{
	//collisionPoints = findCollisionPoints(other->HB.getPoints(), HB.getLines(), other->instantaneousVelocity());
	//if (collisionPoints.size() != 0)
	//{
		//collision!!!!!
	//	lg::printL("collision 2");
	//}
	//}

	//if(other->instantaneousVelocity() != glm::vec2(0.0f, 0.0f))

	





}