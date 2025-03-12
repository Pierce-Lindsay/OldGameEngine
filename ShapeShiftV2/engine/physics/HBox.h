#pragma once
#include "misc/mathStuff.h"
#include "misc/Logger.h"



class HBox
{
private:
	//we need someway to represnt the shape(equation, bounds, points)
	//once its defined, just moves and may change size
	std::vector <glm::vec2> points;
	std::vector <math::line> lines;


	void buildQuad(glm::vec2 p1, glm::vec2 p2, glm::vec2 p3, glm::vec2 p4);
	bool vertical(glm::vec2 p1, glm::vec2 p2);

public:



	std::vector <glm::vec2> getPoints()
	{
		return points;
	}

	std::vector <math::line> getLines()
	{
		return lines;
	}

	//might add dial and rot later
	//void move(glm::vec2 v);
	//void rot(float rot);
	//void dialate(glm::vec2 dialDelta);

	void update(glm::vec2 v);

	//points must be ordered top left to bottom right
	//for example:   p1 p2
	//                []
	//               p3 p4
	HBox(glm::vec2 p1, glm::vec2 p2, glm::vec2 p3, glm::vec2 p4);
	HBox(glm::vec2 pos, glm::vec2 size);
	//points must be ordered top left to bottom right
//for example:    p1 
//                /\
// 			  p2 ---- p3
//               p3 p4
	HBox(glm::vec2 p1, glm::vec2 p2, glm::vec2 p3);
};
