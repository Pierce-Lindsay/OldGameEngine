
#include <iostream>
#include <chrono>
#include <sstream>
#include <thread>
#include "Game.h"


float Xp;
float Yp;
int viewWidth = 1920;
int viewHeight = 1080;
unsigned int character = 0;


void framebuffer_size_callback(GLFWwindow* window, int w, int h)
{
	glViewport(0, 0, w, h);
	viewWidth = w;
	viewHeight = h;
}

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	Xp = static_cast <float>(xpos);
	Yp = static_cast <float>(ypos);
}

void character_callback(GLFWwindow* window, unsigned int codepoint)
{
	character = codepoint;
}



int main()
{
	//graphics and window initialization
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(1920, 1080, "Actualize", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << '\n';
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);


	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << '\n';
		return -1;
	}

	//callbacks(used for polling)
	glfwSetCursorPosCallback(window, cursor_position_callback);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetCharCallback(window, character_callback);
	glViewport(0, 0, 1920, 1080);

	//instantiate game and renderer

	Game GAME;
	std::thread inputThread(IN::pollInputs);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	while (!glfwWindowShouldClose(window))
	{
		double newx = Xp - (double(viewWidth) / 2.0);
		double newy = double(viewHeight) - double(Yp) - (double(viewHeight) / 2.0);
		IN::cursorPos = { newx, newy };
		//updating
		/////////////////////////////////////////////////////////////////////////////////////////////////
		GAME.update();

		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		//////////////////////////////////////////////////////////////////////////////////////////
		//rendering
		GAME.render();

		////////////////////////////////////////////////////////////////////////
		//clean up
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	IN::polling = false;
	inputThread.join();
	glfwTerminate();
	return 0;
}
