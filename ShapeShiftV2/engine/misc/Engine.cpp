#include "Engine.h"

std::vector <Object*> objectVector;

void engine::add(Object* ptr)
{
	objectVector.push_back(ptr);
}

void engine::updateObjects()
{

	//updating
	for (auto e : objectVector)
	{
		e->update();
	}

	//handle collision
	for (int i = 0; i < int(objectVector.size()); i++)
	{
		for (int j = i + 1; j < int(objectVector.size()); j++)
		{
			objectVector[i]->collisionHandle(objectVector[j]);
			//		objectVector[j]->collisionHandle(objectVector[i]);

		}
	}

}
