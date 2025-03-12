#pragma once
#include "PhysicsGlobals.h"
#include "SimpleBody.h"
#include "collision.h"

namespace phys
{
	bool handleBodyInteractions(SimpleBody* b1, SimpleBody* b2);
}