#include "Transformer.h"


float frameRateConstant = 1.0f;


void setTransformableFrameRateConstant(float c)
{
	frameRateConstant = c;
}

glm::vec2 baseSquareTexCoords[6]
{
	glm::vec2(0.0f, 1.0f),
	glm::vec2(0.0f, 0.0f),
	glm::vec2(1.0f, 0.0f),
	glm::vec2(0.0f, 1.0f),
	glm::vec2(1.0f, 0.0f),
	glm::vec2(1.0f, 1.0f)
};



TexCoordTrans::TexCoordTrans(glm::vec2 mag, glm::vec2 offset) : mag{ mag }, offset{ offset }
{
	createCurrentCoords();
}

void TexCoordTrans::createCurrentCoords()
{
	for (int i = 0; i < 6; i++)
	{
		sqTexCoords[i] = glm::vec2(baseSquareTexCoords[i].x * mag.x, baseSquareTexCoords[i].y * mag.y) + offset;
	}
}






Transformable::Transformable(glm::vec2 pos, glm::vec2 size) : pos{ pos }, size{ size }
{
	dialationDiff = glm::vec4(size.x / 2.0, size.y / 2.0, 0.0f, 1.0f);
	translationalDiff = glm::vec4(pos.x, pos.y, 0.0f, 0.0f);
	HB = (glm::vec4(-0.5f * size.x, -0.5f * size.y, 0.5f * size.x, 0.5f * size.y));
	HB.x += pos.x;
	HB.y += pos.y;
	HB.z += pos.x;
	HB.w += pos.y;

	dialate();
	translate();
}


void Transformable::dialate()
{
	dialationDiff = glm::vec4(size.x / 2.0, size.y / 2.0, 0.0f, 1.0f);
	for (int i = 0; i < 6; i++)
	{
		float dialdx = dialationDiff.x;
		float dialdy = dialationDiff.y;

		if (i == 0 || i == 1 || i == 3)
			dialdx *= -1;

		if (i == 1 || i == 2 || i == 4)
			dialdy *= -1;

		sqVerticies[i] = glm::vec4(dialdx, dialdy, 0.0f, 1.0f);
	}
}
void Transformable::rotate()
{
	//rotation next
/////////////////////////
	for (int i = 0; i < 6; i++)
	{
		float rotdx = rotationalDiff.x;
		float rotdy = rotationalDiff.y;

		if (i == 1 || i == 5)
		{
			rotdx = rotationalDiff.y;
			rotdy = rotationalDiff.x;
		}

		if (i == 0 || i == 3 || i == 5)
			rotdx *= -1;

		if (i == 0 || i == 3 || i == 1)
			rotdy *= -1;

		sqVerticies[i] = sqVerticies[i] - glm::vec4(rotdx, rotdy, 0.0f, 1.0f);
	}
}
void Transformable::translate()
{
	translationalDiff = glm::vec4(pos.x, pos.y, 0.0f, 0.0f);
	for (int i = 0; i < 6; i++)
	{
		//translation phase
		sqVerticies[i] = sqVerticies[i] + translationalDiff;
	}

}


void Transformable::move(glm::vec2 speed, float rot)
{

	
	HB.x += speed.x;
	HB.y += speed.y;
	HB.z += speed.x;
	HB.w += speed.y;

	pos.x += speed.x;
	pos.y += speed.y;

	if (rot != 0)
	{
		rotation += rot;
		rotMat = glm::rotate(rotMat, glm::radians(rot), glm::vec3(0.0f, 0.0f, 1.0f));
		//now reset the vertices
		dialate();
		rotationalDiff = sqVerticies[4] - (rotMat * sqVerticies[4]);
		rotate();
		translate();	
	}
	else
	{
		if (speed.x != 0.0f || speed.y != 0.0f)
		{
			for (int i = 0; i < 6; i++)
			{
				sqVerticies[i] += glm::vec4(speed.x, speed.y, 0.0f, 0.0f);
			}
		}
	}

}


const float Transformable::getRot()
{
	return rotation;
}
const glm::vec2& Transformable::getSize()
{
	return size;
}



const glm::vec4& Transformable::getHitBox()
{
	return HB;
}

const glm::vec2& Transformable::getPos()
{
	return pos;
}


