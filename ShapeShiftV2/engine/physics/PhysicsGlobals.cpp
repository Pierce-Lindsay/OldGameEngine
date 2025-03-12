#include "PhysicsGlobals.h"

float phys::deltaTimeConstant = 1.0f;
//within a frame of referance the gravity everything experineces(like people on Earth)
float phys::frameGravity = 0.0f;

//determines whether bodies experience universalGravity, if on,
// activates in handleBodyInteractions function(collisions, universal gravity, etc)
bool phys::universalGravity = false;

//this is BIG G, so is applicable if using universal Gravity
float phys::universalGravityConstant = 0.0f;