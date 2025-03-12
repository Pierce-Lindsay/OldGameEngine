#include "Game.h"


//Bind cameraRight(Input::D, true);
//Bind cameraLeft(Input::A, true);
//Bind tester(Input::SPACE, false);

Game::Game()
{
	//intializes the game
	Renderer.init(SH::shaderPathsToInit, TX::texturePathsToInit);
	testBuild();
}






void Game::update()
{
	//if (IN::pressed(cameraRight))
	//{
		//Renderer.view = glm::translate(Renderer.view, glm::vec3(-20.0f * glb::deltaTime, 0.0f, 0.0f));
	//}

	//if (IN::pressed(cameraLeft))
	//{
		//Renderer.view = glm::translate(Renderer.view, glm::vec3(20.0f * glb::deltaTime, 0.0f, 0.0f));
	//}

	//if (IN::pressed(tester))
	//{
	//}


	engine::updateObjects();

	glb::FPSFix();
	IN::updateInputs();
}




void Game::render()
{
	Renderer.draw();
	glb::updateTime();
	//lg::printL(glb::currentFPS);
}




void Game::testBuild()
{
	
	engine::addToObjects(Player(glm::vec2(300.0f, 0.0f), glm::vec2(50.0f, 50.0f), white, SP::LIGHTBLOCK, glm::vec2(0.0f, 0.0f)));
	engine::addToObjects(Terrain(glm::vec2(0.0f, 0.0f), glm::vec2(100.0f, 100.0f), red, SP::LIGHTBLOCK, glm::vec2(0.0f, 0.0f)));

	//engine::addToObjects(Light(glm::vec2(200.0f, 50.0f), glm::vec2(30.0f, 30.0f), red, SP::LIGHTBLOCK, glm::vec2(0.0f, 0.0f), 30.0f, true));
}