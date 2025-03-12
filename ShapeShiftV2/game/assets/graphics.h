#pragma once
#include "Sprite.h"

//shader constants

namespace SH
{
	static const inline std::string LIGHTSOURCE = "shaders/lightSource.txt";
	static const inline std::string LIGHTING = "shaders/2dLightingShader.txt";
	static const inline std::string BASE = "shaders/shader.shader" ;

	extern std::vector <std::string> shaderPathsToInit;
}





//texture constants

namespace TX
{
	static const inline std::string SQUARE = "textures/TestBlock1.png" ;
	static const inline std::string CIRCLE = "textures/circleTest1.png";
	static const inline std::string EROS = "textures/testFont1-01.png";

	extern std::vector <std::string> texturePathsToInit;
}



static const inline TexCoordTrans baseTCT(glm::vec2(1.0f, 1.0f), glm::vec2(0.0f, 0.0f));


namespace SP
{
	static const inline Sprite BLOCK(TX::SQUARE, SH::LIGHTING, baseTCT);
	static const inline Sprite LIGHTBLOCK(TX::SQUARE, SH::LIGHTSOURCE, baseTCT);
	static const inline Sprite CIRCLE(TX::CIRCLE, SH::LIGHTING, baseTCT);
}
