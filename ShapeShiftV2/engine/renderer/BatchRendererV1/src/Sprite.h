#pragma once
#include "render.h"

struct Sprite
{
	std::string tex;
	std::string shad;
	TexCoordTrans tct;

	Sprite(std::string tex, std::string shad, TexCoordTrans tct)
		: tex{ tex }, shad{ shad }, tct{ tct }
	{}
};


Renderable genRenderable(glm::vec2 pos, glm::vec2 size, glm::vec4 color, Sprite s, bool shouldDraw);