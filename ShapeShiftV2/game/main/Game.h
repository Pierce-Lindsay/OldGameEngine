#pragma once
#include "rendererInclude.h"
#include "particle.h"
#include "text.h"
#include "Entity.h"
#include "Light.h"
#include "Entities/Player.h"
#include "misc/Engine.h"
#include "misc/Logger.h"
#include "assets/graphics.h"
#include "misc/Input.h"
#include "physics/Collision.h"

class Game
{

public:

	Game();

	void update();
	void render();

	void testBuild();
};