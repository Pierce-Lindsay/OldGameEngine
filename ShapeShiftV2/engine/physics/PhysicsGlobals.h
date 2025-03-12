#pragma once


namespace phys
{
	extern float deltaTimeConstant;
	//within a frame of referance the gravity everything experineces(like people on Earth)
	extern float frameGravity;

	//determines whether bodies experience universalGravity, if on,
	// activates in handleBodyInteractions function(collisions, universal gravity, etc)
	extern bool universalGravity;

	//this is BIG G, so is applicable if using universal Gravity
	extern float universalGravityConstant;


	extern bool isThereCollision;
}