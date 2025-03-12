#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <vector>




struct TexCoordTrans
{
	glm::vec2 sqTexCoords[6];
	glm::vec2 mag;
	glm::vec2 offset;
	TexCoordTrans(glm::vec2 mag, glm::vec2 offset);
	void createCurrentCoords();
};



//keeps track of every object on screen(static so that it can keep track of objects from anywhere that can interact with eachother)
//singleton

//this is all in the camera(screen) coordinates, all data going into the functions must be in screen coordinates
class Transformable
{
private:

	glm::mat4 rotMat{ glm::mat4(1.0f) };
	glm::vec4 HB{ 0.0f,0.0f,0.0f,0.0f };
	glm::vec2 pos{ 0.0f,0.0f };
	float rotation = 0.0f; //in degrees
	glm::vec2 size {0.0f, 0.0f };
	glm::vec4 rotationalDiff{ 0.0f,0.0f, 0.0f, 0.0f };
	glm::vec4 dialationDiff{ 0.0f,0.0f, 0.0f, 0.0f };
	glm::vec4 translationalDiff{ 0.0f,0.0f, 0.0f, 0.0f };
	
	void dialate();
	void rotate();
	void translate();


public:
	Transformable(glm::vec2 pos, glm::vec2 size);
	//const glm::mat4& getRotMatrix();
	const glm::vec4& getHitBox();
	const glm::vec2& getPos();
	const float getRot();
	const glm::vec2& getSize();
	void move(glm::vec2 speed, float rot);


	glm::vec4 sqVerticies[6]; // final points ready for rendering with dial, then rot, and then translation mats applied

	
};


void setTransformableFrameRateConstant(float c);