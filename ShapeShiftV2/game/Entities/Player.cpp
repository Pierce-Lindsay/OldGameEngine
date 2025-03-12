#include "Player.h"

Bind moveR(Input::D, true);
Bind moveL(Input::A, true);
Bind moveU(Input::W, true);
Bind moveD(Input::S, true);


Player::Player(glm::vec2 pos, glm::vec2 baseSize, glm::vec4 color, Sprite sp, glm::vec2 v) : Entity( pos, baseSize, color,  sp,  v)
{
}

void Player::collisionHandle(Object* other)
{
	defaultCollisionHandle(other);
	//colliding = true;
}
void Player::update()
{
	velocity = glm::vec2(-2.0f, 0.0f);
	/*
	if (IN::pressed(moveR))
		velocity.x += 2.0f;
	if (IN::pressed(moveL))
		velocity.x -= 2.0f;
	if (IN::pressed(moveU))
		velocity.y += 2.0f;
	if (IN::pressed(moveD))
		velocity.y -= 2.0f;
		*/

	defaultUpdate();
}