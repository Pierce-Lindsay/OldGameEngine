#include <vector>
#include "Object.h"
#include "physics/Collision.h"
#include <memory>





namespace engine
{
	void add(Object* ptr);
	//takes in a dynamic object 
	template <typename T>
	void addToObjects(T thing)
	{
		Object* dynamicPtr = new T(thing);
		add(dynamicPtr);
	}


	void updateObjects();
}