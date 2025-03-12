#include "Globals.h"

//external
glm::vec2 glb::cameraPos{ 0.0f, 0.0f };
float glb::cameraMag{ 1.0f };
float glb::deltaTime{ 1.0 / 60.0f };
float glb::elapsedTime{ 0.0f };
float glb::maxFPS{ 60.0f };
float glb::currentFPS{ maxFPS };
bool glb::running{ true };


//internal

double lastTime = 0.0f;
double thisTime = 0.0f;
double extraTime = 0.0f;
auto start = std::chrono::steady_clock::now();

//void initTime()
//{
//
//}

void glb::updateTime()
{
	auto now = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed = now - start;
	lastTime = thisTime;
	thisTime = elapsed.count();
	deltaTime = thisTime - lastTime;
	extraTime += (1.0f / maxFPS) - deltaTime;
	elapsedTime = elapsed.count();

	currentFPS = 1.0 / deltaTime;
}
void glb::FPSFix()
{
	auto startTimer = std::chrono::steady_clock::now();
	double timerThis = 0.0f;

	while (extraTime > timerThis)
	{
		//keeps frame rate to max fps 
		auto current = std::chrono::steady_clock::now();
		std::chrono::duration<double> passed = current - startTimer;
		timerThis = passed.count();
	}
}