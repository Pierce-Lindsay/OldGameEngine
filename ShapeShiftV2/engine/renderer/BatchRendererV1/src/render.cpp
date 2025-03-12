#include "render.h"


//Global helper vars
/////////////////////////////////////////////
const int MAXLIGHTS = 100;

//universal vars for renderer
int elapsedDrawCallCount = 0;
std::vector <Texture> textures{};
std::vector <Shad> shaders{};
std::vector <Batch> batches;


std::vector <std::array<float, 3>>  lightPoses;
std::vector <std::array<float, 3>>  lightColors;
std::vector <float>  lightBrights;
int lightSize = 0;


//Renderable
///////////////////////////////////////////////////////////////////////////

//this constructer is so much work, uggggggg
Renderable::Renderable(glm::vec2 pos, glm::vec2 size, glm::vec4 color, TexCoordTrans tct, std::string tex, std::string shad, bool shouldDraw)
	: t(pos, size), color{ color }, tct{ tct }, tex{ tex }, shad{ shad }
{
	willDraw(shouldDraw);
};


//this must be called every frame to get predictable behavior
void Renderable::update(glm::vec2 v)
{
	//if we gonna delete, do nothing
	if (shouldDelete)
		return;
	//this renderable is actually being used, 


	if (drawing)
	{ //we drawing, so in the stack, so gotta fix id if need be
		fixId();
	}


		move(v);

		if (drawing)
		{
			updateVertexes();
			if (isLight && lightOn)
				updateLightLogic();
		}
			
	

	if (drawingChanged)
	{
		if (!drawing)
			drawing = true;
		else
			drawing = false;

		if (drawing)
		{
			addThisRenderabletoBatch();
		}
		else
		{
			remove();
		}
		drawingChanged = false;
	}

	bool verticiesAltered = false;
	bool colorsAltered = false;
	bool texCoordsAltered = false;
}


std::vector <float> Renderable::createQuadVerts()
{
	std::vector <float> v;
	for (int i = 0; i < 6; i++)
	{
		v.insert(v.begin(), {t.sqVerticies[i].x, t.sqVerticies[i].y, t.sqVerticies[i].z,
							tct.sqTexCoords[i].x, tct.sqTexCoords[i].y,
							color.x, color.y, color.z, color.w
			});
	}
	return v;
}

//if true, resets the batches vertices every frame, else assume everything is only moved as a group and individuals cant be updated
void Renderable::addThisRenderabletoBatch()
{
	//this is the auto add, will not add to custom batches

	std::vector <float> v = createQuadVerts();
	bool found = false;

	int i = 0;
	for (auto& e : batches)
	{

		if (shad == e.shad.name && tex == e.tex.name && !e.custom)
		{
			b_id = i;
			id = e.adresses.size();

			
			e.vertices.insert(e.vertices.end(), v.begin(), v.end());
			e.adresses.push_back(id);
			found = true;
			break;
		}
		i++;
	}

	if (found == false)
	{
		Batch b;
		for (auto e : shaders)
		{
			if (e.name == shad)
			{
				b.shad.program = e.program;
				b.shad.name = e.name;
			}
		}

		for (auto e : textures)
		{
			if (e.name == tex)
			{
				b.tex.id = e.id;
				b.tex.name = e.name;
			}
		}

		b_id = batches.size();
		id = 0;
		b.vertices = v; //we can use assginment, cause first
		b.adresses.push_back(id);
		batches.push_back(b);
	}
}


void Renderable::updateVertexes()
{

	//assumes id is correct, it should be fixed in update
	int loc = id;

	if (verticiesAltered)
	{
		glm::vec4 temp;
		for (int i = 0; i < 6; i++)
		{
			temp = t.sqVerticies[5 - i];
			int pos = i * 8 + i + loc * 54;
			batches[b_id].vertices[pos] = temp.x;
			batches[b_id].vertices[pos + 1] = temp.y;
		}
	}

	if (texCoordsAltered)
	{
		glm::vec2 temp;
		for (int i = 0; i < 6; i++)
		{
			temp = tct.sqTexCoords[5 - i];
			int pos = i * 8 + i + loc * 54;
			batches[b_id].vertices[pos + 3] = temp.x;
			batches[b_id].vertices[pos + 4] = temp.y;
		}
	}

	if (colorsAltered)
	{
		for (int i = 0; i < 6; i++)
		{
			int pos = i * 8 + i + loc * 54;
			batches[b_id].vertices[pos + 5] = color.x;
			batches[b_id].vertices[pos + 6] = color.y;
			batches[b_id].vertices[pos + 7] = color.z;
			batches[b_id].vertices[pos + 8] = color.w;
		}
	}
}


void Renderable::updateLightLogic()
{
	if (lightSize < MAXLIGHTS)
	{
		lightColors.push_back({ lightColor.x, lightColor.y, lightColor.z });
		lightPoses.push_back({ t.getPos().x, t.getPos().y, 0.0f });
		lightBrights.push_back(lightBrightness);
		lightSize += 1;
	}
	else
	{
		std::cout << "Light Max Reached, over 100" << '\n';
	}
	
}

void Renderable::fixId()
{

		if (batches[b_id].offsetPoses.size() >0 && whenIDLastUpdated != elapsedDrawCallCount)
		{
			//figure out if this id was offset and if so fix it
			for (int i = batches[b_id].offsetPoses.size() - 1; i > -1; i--)
			{
				if (batches[b_id].offsetPoses[i] <= id)
				{
					id -= 1;

				}

			}
			whenIDLastUpdated = elapsedDrawCallCount;
		}
}

void Renderable::remove()
{
	batches[b_id].idsToDelete.push_back(id);
}

void Renderable::willDraw(bool b, int n)
{

	if (n != -1 && b && !drawing)
	{
		//adding to custom batch
		b_id = n;
		id = batches[n].adresses.size();
		batches[n].adresses.push_back(id);
		std::vector <float> v = createQuadVerts();
		batches[n].vertices.insert(batches[n].vertices.end(), v.begin(), v.end());
		drawing = true;
	}
	 else if (b != drawing)
		drawingChanged = true;


}

//note: shader is decided by user, reccomended to use a different shader for objects that are intended to be lights
void Renderable::makeIntoLight(float brightness, bool on)
{
	isLight = true;
	lightBrightness = brightness;
	lightOn = on;
}

void Renderable::changeLightBrightness(float brightness)
{
	lightBrightness = brightness;
}


void Renderable::changeLightColor(glm::vec3 lightColor)
{
	this->lightColor = lightColor;
}

//note:alpha has no affect here, vec4 overload for QOL
void Renderable::changeLightColor(glm::vec4 lightColor)
{
	this->lightColor = glm::vec3(lightColor.x, lightColor.y, lightColor.z);
}

void Renderable::del()
{
	shouldDelete = true;
	if (drawing)
	{
		fixId();
		remove();
	}
}

void Renderable::move(glm::vec2 v)
{
	if (v.x != 0.0f || v.y != 0.0f)
	{
		t.move(v, 0.0f);
		verticiesAltered = true;
	}
}

void Renderable::setColor(glm::vec4 c)
{
	color = c;
	colorsAltered = true;
}
void Renderable::setTexCoords(glm::vec2 mag, glm::vec2 offset)
{
	tct.mag = mag;
	tct.offset = offset;
	tct.createCurrentCoords();
	texCoordsAltered = true;
}

std::string Renderable::getTexture()
{
	return tex;
}
std::string Renderable::getShader()
{
	return shad;
}

glm::vec4& Renderable::getColor()
{
	return color;
}

bool Renderable::isDrawing()
{
	return drawing;
}





//batch
////////////////////////////////////////////////////////////////////

unsigned int generateCustomBatch(std::string texture, std::string shader, bool usesGlobalVM, glm::mat4 modelmat)
{
	Batch b;
	for (auto e : shaders)
	{
		if (e.name == shader)
		{
			b.shad.program = e.program;
			b.shad.name = e.name;
		}
	}

	for (auto e : textures)
	{
		if (e.name == texture)
		{
			b.tex.id = e.id;
			b.tex.name = e.name;
		}
	}
	b.custom = true;
	b.usesGlobalViewMat = usesGlobalVM;
	b.batchmat = modelmat;
	batches.push_back(b);

	return batches.size() - 1;

}


void Batch::handleDeletes()
{
	offsetPoses.clear();

	std::sort(idsToDelete.begin(), idsToDelete.end());
	offsetPoses = idsToDelete;
	//these shoulda been handled last cycle
	for (int i = idsToDelete.size() - 1; i > -1; i--)
	{
		unsigned int loc = idsToDelete[i];
		//we valid
		if (loc == adresses[loc])
		{
			//std::cout << "deleted at: " << loc << '\n';
			vertices.erase(vertices.begin() + (loc * 54), vertices.begin() + (loc * 54) + 54);
			adresses.erase(adresses.begin() + loc);
			for (int j = loc; j < adresses.size(); j++)
			{
				adresses[j] = j;
			}
		}
		else
		{
			throw "id displacment error";
		}
	}



	idsToDelete.clear();
}



//Render
///////////////////////////////////////////////////////////////////////////////////////////////////////////

Render Render::s_Instance;

Render& Render::Get()
{
	return s_Instance;
}


void Render::init(std::vector <std::string> shadPaths, std::vector <std::string> texPaths)
{
	for (int i = 0; i < shadPaths.size(); i++)
	{
		addShader(shadPaths[i]);
	}

	for (int i = 0; i < texPaths.size(); i++)
	{
		addTexture(texPaths[i]);
	}

}


void Render::addTexture(std::string path)
{
	int width{}, height{}, nrChannels{};
	unsigned char* data{};
	GLuint TEX;
	glGenTextures(1, &TEX);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, TEX);



	//perameters for currently bound texture
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
		GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	//load and generate texture
	stbi_set_flip_vertically_on_load(GL_TEXTURE_2D);
	data = stbi_load(path.c_str(), &width, &height, &nrChannels, 4);



	if (data)
	{
		std::cout << "Texture good" << '\n';
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

	}
	else
		std::cout << "Texture failed to load" << '\n';

	Texture t;
	t.id = TEX;
	t.name = path;
	textures.push_back(t);

	glGenerateMipmap(GL_TEXTURE_2D);
	stbi_image_free(data);
	glBindTexture(GL_TEXTURE_2D, 0);

}
void Render::addShader(std::string path)
{
	Shader shad(path);
	Shad s;
	s.program = shad.getProgram();
	s.name = path;
	shaders.push_back(s);
}



void Render::draw()
{
//	lightPoses[0][0] -= 0.5f;

	for (auto& e : batches)
	{
		e.handleDeletes();

		unsigned int VAO{};
		unsigned int VBO{};

		//creates object
		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);


		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);

		int vsize = e.vertices.size();
		verts = e.vertices.data();

		glBufferData(GL_ARRAY_BUFFER, 4 * vsize, verts, GL_DYNAMIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(5 * sizeof(float)));
		glEnableVertexAttribArray(2);

		glBindVertexArray(0);

		


		GLuint TEX = e.tex.id;

		glUseProgram(e.shad.program);

	

		//note: model mat is custom for a batch wide application

		unsigned int modelLoc = glGetUniformLocation(e.shad.program, "model");
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(e.batchmat));


		glm::mat4 pm = projm;
		if (!e.usesGlobalViewMat)
			glm::mat4 pm = glm::mat4(1.0f);
		
		unsigned int projLoc = glGetUniformLocation(e.shad.program, "projection");
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(pm));


		unsigned int viewLoc = glGetUniformLocation(e.shad.program, "view");
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

		//for lighting shaders
		unsigned int sizeLoc = glGetUniformLocation(e.shad.program, "size");
		unsigned int lightPosLoc = glGetUniformLocation(e.shad.program, "lightPos");
		unsigned int lightColorLoc = glGetUniformLocation(e.shad.program, "lightColor");
		unsigned int lightBrightnessLoc = glGetUniformLocation(e.shad.program, "lightBrightness");

	

		glUniform1i(sizeLoc, lightSize);
		glUniform3fv(lightPosLoc, lightSize, lightPoses.data()->data());
		glUniform3fv(lightColorLoc, lightSize, lightColors.data()->data());
		glUniform1fv(lightBrightnessLoc, lightSize,lightBrights.data());


		glUniform1i(glGetUniformLocation(e.shad.program, "texture1"), 0);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, TEX);

		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, int(vsize/9));

		glUseProgram(0);
		glBindVertexArray(0);
		glBindTexture(GL_TEXTURE_2D, 0);
		glDeleteBuffers(1, &VBO);
		glDeleteVertexArrays(1, &VAO);

	}
	elapsedDrawCallCount += 1;
	//have to clear out lights every frame with current version
	lightBrights.clear();
	lightColors.clear();
	lightPoses.clear();
	lightSize = 0;
}

