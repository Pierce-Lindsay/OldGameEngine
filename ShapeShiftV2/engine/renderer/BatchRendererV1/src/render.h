#pragma once
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "shader.h"
#include "stb_image.h"
#include "Transformer.h"
#include <vector>
#include <string>
#include <algorithm>
#include <array>

//#include "rendererNeccesary.h"


//singleton

//colors
static const inline glm::vec4 black{ 0.0f, 0.0f, 0.0f, 1.0f };
static const inline glm::vec4 grey{ 0.2f, 0.2f, 0.2f, 1.0f };
static const inline glm::vec4 white{1.0f, 1.0f, 1.0f, 1.0f };
static const inline glm::vec4 green{ 0.1f, 1.0f, 0.2f, 1.0f };
static const inline glm::vec4 blue{ 0.0f, 0.2f, 0.6f, 1.0f };
static const inline  glm::vec4 red{ 1.0f, 0.0f, 0.0f, 1.0f };
static const inline glm::vec4 darkGreen{ 0.0f, 0.3f, 0.0f, 1.0f };


struct Texture
{
	GLuint id;
	std::string name;
};

struct Shad
{
	GLuint program;
	std::string name;
};

//being lazy for lighting for v1, light info is remade every frame



struct Batch
{
	bool custom = false;
	bool usesGlobalViewMat = true;
	//a custom batch can be a duplicate of another batch(with respect to shader and texture) but might have special properties
	Texture tex;
	Shad shad;
	std::vector <float> vertices;
	std::vector <unsigned int> adresses;
	std::vector <unsigned int> offsetPoses;
	std::vector <unsigned int> idsToDelete;
	glm::mat4 batchmat = glm::mat4(1.0f);
	void handleDeletes();
};

//creates a custom batch and returns the batch is, renderables can call will draw with the id as an added perameter to be forced into the custom batch,
//id also may allow access to the batch in teh future
unsigned int generateCustomBatch(std::string texture, std::string shader, bool usesGlobalVM, glm::mat4 modelmat);

//note, must call delete_() when ever erasing or removing Renderable permenently

class Renderable
{
private:
	bool drawing = false;
	bool drawingChanged = false;
	bool shouldDelete = false;
	int whenIDLastUpdated; //makes sure id isnt updated twice in one frme


	bool verticiesAltered = false;
	bool colorsAltered = false;
	bool texCoordsAltered = false;


	unsigned int id = 0; //-> position in vertices
	unsigned int b_id = 0; //->position in batches
	std::string tex;
	std::string shad;

	glm::vec4 color;
	TexCoordTrans tct;


	//light vars
	bool isLight = false;
	bool lightOn = false;
	glm::vec3 lightColor = glm::vec3(color.x, color.y, color.z);
	float lightBrightness = 0.0f;

	void updateLightLogic();

	void fixId();
	void updateVertexes();
	void remove();
	void addThisRenderabletoBatch();
	std::vector <float> createQuadVerts();

	public:

	Renderable(glm::vec2 pos, glm::vec2 size, glm::vec4 color, TexCoordTrans tct, std::string tex, std::string shad, bool shouldDraw);
	void update(glm::vec2 v);
	void willDraw(bool b, int n = -1);
	void del();

	bool isDrawing();

	void setColor(glm::vec4 c);
	void setTexCoords(glm::vec2 mag, glm::vec2 offset);
	void move(glm::vec2 v);

	void makeIntoLight(float brightness, bool on);
	void changeLightBrightness(float brightness);
	void changeLightColor(glm::vec3 lightColor);
	void changeLightColor(glm::vec4 lightColor);

	std::string getTexture();
	std::string getShader();
	glm::vec4& getColor();


	Transformable t;

};






class Render
{
private:
	static Render s_Instance;

	Render() {}
	float* verts = NULL;

public:
	static Render& Get();
	Render(const Render&) = delete;
	void init(std::vector <std::string> shadPaths, std::vector <std::string> texPaths);
	void addTexture(std::string path);
	void addShader(std::string path);

	void draw();
	glm::mat4 projm = glm::ortho(-960.0f, 960.0f, -540.0f, 540.0f);
	glm::mat4 view = glm::mat4(1.0f);

};

