#pragma once
#include "rendererInclude.h"
#include "random"
#include "chrono"






namespace Ptcl
{
	struct Particle
	{
		Renderable r;
		glm::vec2 v;
		glm::vec2 a;
		glm::vec4 originalColor;

		void update();
		Particle(glm::vec2 pos, glm::vec2 size, glm::vec4 color, glm::vec2 v, float expirationTime);
		float expirationTime = 10.0f;
		float currentTime = 0.0f;
	};


	//a flow of particles eminating froma source
	struct Rain
	{
		glm::vec2 pos;
		glm::vec4 color;
		glm::vec2 v;
		float intensity;
		float coverage;
		float rainSpeed;
		glm::vec2 rainSize;
		float rainDirection;
		float duration;

		float currentTime = 0.0f;
		float timeTracker = 0.0f;


		void update();
		std::vector <Particle> batch;
		bool doneDrawing = false;


	};




	void update();

	void generateExplosion(float density, float particleSize, glm::vec4 color, float speed, float duration, float gravity);
	void generateRain(glm::vec2 pos, glm::vec4 color, glm::vec2 cloudV, float intensity, float coverage, float rainSpeed, glm::vec2 rainSize, float rainDirection, float duration);
}

int generateRandomNum(int min, int max);
