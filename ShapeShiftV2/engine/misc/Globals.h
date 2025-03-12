#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <chrono>


namespace glb
{
	extern glm::vec2 cameraPos;
	extern float cameraMag;
	extern float deltaTime;
	extern float elapsedTime;
	extern float currentFPS;
	extern float maxFPS;
	extern bool running;

	void updateTime();
	void FPSFix();
}