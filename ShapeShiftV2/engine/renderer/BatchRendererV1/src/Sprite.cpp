#include "Sprite.h"

 
Renderable genRenderable(glm::vec2 pos, glm::vec2 size, glm::vec4 color, Sprite s, bool shouldDraw)
{
	return Renderable(pos, size, color, s.tct, s.tex, s.shad, shouldDraw);
}