#include "HBox.h"

bool HBox::vertical(glm::vec2 p1, glm::vec2 p2)
{
	return p1.x == p2.x;
}


void HBox::buildQuad(glm::vec2 p1, glm::vec2 p2, glm::vec2 p3, glm::vec2 p4)
{
	points.push_back(p1);
	points.push_back(p2);
	points.push_back(p3);
	points.push_back(p4);

	std::string highInequality = "<=";
	std::string lowInequality = ">=";
	std::string highVariant = "<=";
	std::string lowVariant = ">=";

	if (vertical(p1, p3))
		highVariant = math::swapInequality(highVariant);


	if (vertical(p2, p4))
		lowVariant = math::swapInequality(lowVariant);

		lines.push_back(math::line(p1, p2, highInequality));

		lines.push_back(math::line(p1, p3, highVariant));

		lines.push_back(math::line(p2, p4, lowVariant));

		lines.push_back(math::line(p3, p4, lowInequality));


	
}

HBox::HBox(glm::vec2 p1, glm::vec2 p2, glm::vec2 p3, glm::vec2 p4)
{
	buildQuad(p1, p2, p3, p4);
}
HBox::HBox(glm::vec2 pos, glm::vec2 size)
{
	glm::vec2 p1{- size.x / 2.0f, size.y / 2.0f };
	p1 += pos;
	//topright
	glm::vec2 p2{ size.x / 2.0f, size.y / 2.0f };
	p2 += pos;
	//bottomleft
	glm::vec2 p3{- size.x / 2.0f,- size.y / 2.0f };
	p3 += pos;
	//bottomright
	glm::vec2 p4{size.x / 2.0f,- size.y / 2.0f };
	p4 += pos;

	buildQuad(p1, p2, p3, p4);
}
HBox::HBox(glm::vec2 p1, glm::vec2 p2, glm::vec2 p3)
{

	points.push_back(p1);
	points.push_back(p2);
	points.push_back(p3);

	std::string alternate = "<=";
	if (p1.y && p2.y > p3.y) //upside down triangle
		alternate = ">=";

	std::string highPoint = "<=";
	std::string lowPoint = ">=";

	if (vertical(p1, p2))
		highPoint = math::swapInequality(highPoint);

	if (vertical(p1, p3))
		alternate = math::swapInequality(alternate);

	if (vertical(p2, p3))
		lowPoint = math::swapInequality(lowPoint);

		lines.push_back(math::line(p1, p2, highPoint));

		lines.push_back(math::line(p1, p3, alternate));

		lines.push_back(math::line(p2, p3, lowPoint));
}




void HBox::update(glm::vec2 v)
{
	for (glm::vec2& e : points)
	{
		e += v;
	}

	for (math::line& e : lines)
	{
		e.translate(v);
	}
}