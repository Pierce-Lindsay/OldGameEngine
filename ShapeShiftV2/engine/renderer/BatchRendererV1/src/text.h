#pragma once
#include "Sprite.h"

class Text
{
private:
	glm::vec2 pos{ 0.0f, 0.0f };
	glm::vec2 size{ 0.0f, 0.0f };
	std::string string = "";
	glm::vec4 color{ white };
	std::vector <Renderable> letters;
	unsigned int b_id = 0;
	Sprite getCharSprite(char c);

public:
	Text(glm::vec2 p, std::string s, glm::vec2 sz, glm::vec4 color);
	void update();
};