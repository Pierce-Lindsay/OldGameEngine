#include "Collision.h"



//collisionDataHandler::collisionDataHandler(SimpleBody& b1, SimpleBody& b2)
//	:this->b1{b1}, this->b2{b2}
//{
//
//}












bool passAreaCheck(std::vector <glm::vec2> points, std::vector <math::line> lines)
{
	bool collision = false;
	//lg::printL("Pass area called");
	//first phase, obj1 as points and obj2 as lines
	for (auto e : points)
	{
		bool inArea = true;
		for (auto k : lines)
		{
			if (math::pointOnInequality(e, k))
			{
				//lg::printL("Point passes an inequality");
				continue;
			}

			else
			{
				//lg::printL("Point failed an inequality");
				inArea = false;
				break;
			}
		}

		if (inArea) //a collision
		{
			collision = true;
			break;
		}

	}

	return collision;
}


glm::vec2 findCollisionOverLap(std::vector <glm::vec2> points, std::vector <math::line> lines, glm::vec2 lastPos, glm::vec2 pos)
{
	glm::vec2 v = lastPos - pos;
	std::vector <math::line> rays;
	for (auto e : points)
	{
		rays.push_back(math::line(e + v, e));
	}

	std::vector <collisionDataStruct> collisions;

	for (auto ray : rays)
	{
		std::vector <collisionDataStruct> possibles;
		for (auto side : lines)
		{
			math::intersection inter = math::intersectionPoint(ray, side);
			if (inter.exists && !inter.sameLine )
			{
				collisionDataStruct cds;
				cds.intersectionPoint = inter.point;
				cds.intersectedFace = side;
				//its 1 cause up above thats the one with the added v
				cds.overlapPoint = ray.endPoint1;
				possibles.push_back(cds);
			}
				
		}

		if (possibles.size() == 2 && (possibles[0].overlapPoint == possibles[1].overlapPoint))
		{
			glm::vec2 center = possibles[0].intersectedFace.endPoint1 + possibles[0].intersectedFace.endPoint2;
			center.x /= 2.0f;
			center.y /= 2.0f;
			glm::vec2 center2 = possibles[1].intersectedFace.endPoint1 + possibles[1].intersectedFace.endPoint2;
			center2.x /= 2.0f;
			center2.y /= 2.0f;
			if (math::findDistance(center, lastPos) < math::findDistance(center2, lastPos))
				possibles.pop_back();
			else
				possibles.erase(possibles.begin());
		}
		for (auto poss : possibles)
		{
			collisions.push_back(poss);
		}
	}

	//now find cds that is closets to lastPos
	if (collisions.size() > 0)
	{
		collisionDataStruct closest = collisions[0];
		float leastValue = 1000000000000000;
		for (auto e : collisions)
		{
			float delta = math::findDistance(e.overlapPoint, e.intersectionPoint);

			//if (delta == leastValue)
			//{
				//float delta2 = math::findDistance(lastPos, e.intersectionPoint);
				//float wouldBeLowestDelta2 = math::findDistance(lastPos, closest.intersectionPoint);

				///if (delta2 < wouldBeLowestDelta2)
				//{
				//	closest = e;
				//	leastValue = math::findDistance(e.overlapPoint, e.intersectionPoint);
				//}
			//}
			 if (delta < leastValue)
			{
				closest = e;
				leastValue = math::findDistance(e.overlapPoint, e.intersectionPoint);
			}
		}


		//now create line with slope of perpindicular and find inter section point with the face
		math::line perpendicular = getPerpendicularAtPoint(closest.intersectedFace, closest.overlapPoint);
		math::line newGuy(closest.intersectedFace);

		if (!newGuy.verticalLine)
		{
			newGuy.Xbounds = glm::vec2(-1000000000, 1000000000);
		}
		newGuy.Ybounds = glm::vec2(-1000000000, 1000000000);

		math::intersection inter = math::intersectionPoint(perpendicular, newGuy);

		if (inter.exists && !inter.sameLine)
		{
			//now we have our vector 
			glm::vec2 displacement = (closest.overlapPoint- inter.point) * 1.1f;
			//glm::vec2 displacement2 = glm::vec2(displacement.x * 1.01f, displacement.y * 1.01f);
			std::cout << "Displacement: " << displacement.x << ", " << displacement.y << '\n';
			//std::cout << "Displacement2: " << displacement2.x << ", " << displacement2.y << '\n';
			return displacement;
		}
		else
		{
			std::cout << "error";
			return glm::vec2(0.0f, 0.0f);
		}
			

	



	}
	else
		return glm::vec2(0.0f, 0.0f);


	//math::getParrallelAtPoint()




	


}



/*
void collisionProccessor(Object* obj1, Object* obj2)
{
	//if both objects have no v, they can't collide
	//only exception is spawning

	if (obj1->instantaneousVelocity() != glm::vec2(0.0f, 0.0f) ||
		obj2->instantaneousVelocity() != glm::vec2(0.0f, 0.0f))
	{





	}
		










	// create a zone of inequality(the shape) then quary points
	
	//first phase, obj1 as points and obj2 as lines
	//bool collision = passAreaCheck(obj2->HB.getPoints(), obj1->HB.getLines());

	//if (!collision) //there was no collision with first test so check second
	//{
	//	collision = passAreaCheck(obj1->HB.getPoints(), obj2->HB.getLines());
	//}

	//if (collision)
	//{
	//	obj1->collisionHandle(obj2);
	//	obj2->collisionHandle(obj1);
		//lg::printL("collision!");	
	//}
}


void quickTest()
{
	glm::vec2 p1(-10.0f, 10.0f);
	glm::vec2 p2(10.0f, 10.0f);
	glm::vec2 p3(-10.0f, -10.0f);
	glm::vec2 p4(10.0f, -10.0f);

	HBox HB1(p1, p2, p3, p4);

	glm::vec2 v(10.0f, 10.0f);
	p1 += v;
	p2 += v;
	p3 += v;
	p4 += v;

	HBox HB2(p1, p2, p3, p4);
	// create a zone of inequality(the shape) then quary points

	//first phase, obj1 as points and obj2 as lines
	bool collision = passAreaCheck(HB1.getPoints(), HB2.getLines());

	if (!collision) //there was no collision with first test so check second
	{
		collision = passAreaCheck(HB2.getPoints(), HB1.getLines());
	}

	if (collision)
	{
		lg::printL("collision!");
	}
}

*/