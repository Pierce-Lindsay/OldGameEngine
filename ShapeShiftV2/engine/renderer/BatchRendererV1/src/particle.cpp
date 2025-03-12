#include "particle.h"

std::vector <std::vector <Ptcl::Particle>> particleBatches;
std::vector <Ptcl::Rain> rains;
std::mt19937 RNGSEED{ static_cast<unsigned int>(std::chrono::steady_clock::now().time_since_epoch().count()) };






int generateRandomNum(int min, int max)
{
	std::uniform_int_distribution die{ min, max };
	return die(RNGSEED);
}


std::string sh = "shaders/shader.shader";
std::string bl = "textures/TestBlock1.png";
TexCoordTrans TCT(glm::vec2(1.0f, 1.0f), glm::vec2(0.0f, 0.0f));

Ptcl::Particle::Particle(glm::vec2 pos, glm::vec2 size, glm::vec4 color, glm::vec2 v, float expirationTime)
	:r(pos, size, color, TCT, bl, sh, true), v{ v }, expirationTime{ expirationTime }, originalColor{ color }
{
}

void Ptcl::Particle::update()
{
	currentTime += diffTime;
	if (currentTime > expirationTime)
		r.willDraw(false);
	r.update(v);

}


//rain updates


void Ptcl::Rain::update()
{
	if (timeTracker >= (1.0f / intensity) && currentTime < duration)
	{
		timeTracker = 0.0f;
		float loc = float(generateRandomNum(-coverage * 10.0f, coverage * 10.0f)) / 10.0f;

		//if (rainDirection > 90 && rainDirection < 270)
		//	x *= -1;

		//if (rainDirection > 180 && rainDirection < 360)
		//	y *= -1;

		float vx = cos(glm::radians(rainDirection)) * rainSpeed;
		float vy = sin(glm::radians(rainDirection)) * rainSpeed;

		float posx = sin(glm::radians(rainDirection)) * loc;
		float posy = cos(glm::radians(rainDirection)) * loc;


		Particle p(glm::vec2(pos.x, pos.y) + glm::vec2(posx, posy),
			rainSize,
			color,
			glm::vec2(vx, vy),
			10.0f);
		batch.push_back(p);
	}
	currentTime += diffTime;
	timeTracker += diffTime;

	for (int j = 0; j < batch.size(); j++)
	{
		batch[j].update();
	}

	if (currentTime > duration)
	{
		for (int j = 0; j < batch.size(); j++)
		{
			if (batch[j].r.isDrawing())
				break;
			else
			{
				if (j + 1 == batch.size())
					doneDrawing = true;
			}
		}
	}
		

	//if (counter == batch.size())
	//	doneDrawing = true;
//

}


void Ptcl::update()
{
	//structless updates
	for (int i = 0; i < particleBatches.size(); i++)
	{
		int notDrawing = 0;
		for (int j = 0; j < particleBatches[i].size(); j++)
		{
			float t = particleBatches[i][j].currentTime;
			float t2 = particleBatches[i][j].expirationTime;
			if (t / t2 > 0.3f)
			{
				particleBatches[i][j].r.setColor(particleBatches[i][j].originalColor - glm::vec4(0.0f, 0.0f, 0.0f, t / (2.0f * t2)));
			}
			particleBatches[i][j].v.y += particleBatches[i][j].a.y * diffTime;
			particleBatches[i][j].update();


			if (!particleBatches[i][j].r.isDrawing())
				notDrawing += 1;
		}
		if (notDrawing == particleBatches[i].size())
		{
			particleBatches[i].clear();
			particleBatches.erase(particleBatches.begin() + i);
			i -= 1;
		}


	}


	for (int i = 0; i < rains.size(); i++)
	{
		rains[i].update();
		if (rains[i].currentTime > rains[i].duration && rains[i].doneDrawing)
		{
			std::cout << "cleared" << '\n';
			rains[i].batch.clear();
			rains.erase(rains.begin() + i);
			i -= 1;
		}
	}

}



void Ptcl::generateExplosion(float density, float particleSize, glm::vec4 color, float speed, float duration, float gravity)
{
	float p1 = float(generateRandomNum(-1000, 1000))/2.5f;
	float p2 = float(generateRandomNum(-1000, 1000))/2.5f;
	std::vector <Particle> batch;
	for (int i = 0; i < int(100 * density); i++)
	{

		float k = float(generateRandomNum(-1000, 1000))/100.0f;
		float k2 = float(generateRandomNum(-1000, 1000)) / 100.0f;
		float t = float(generateRandomNum(0, 200)) /200.0f;
		float c = float(generateRandomNum(-100, 100)) / 250.0f;
		Particle p(glm::vec2( p1 +cos(i) + k* 5.0f, p2 + sin(i) + k2 * 5.0f), 
			glm::vec2(particleSize, particleSize),
			glm::vec4(color.x + c, color.y, color.z, color.w), 
			glm::vec2(cos(i) * k * speed, sin(i) * k2 * speed), duration * t);

		p.a.y = -gravity * 100.0f;

		batch.push_back(p);
	}
	particleBatches.push_back(batch);
}

void Ptcl::generateRain(glm::vec2 pos, glm::vec4 color, glm::vec2 cloudV, float intensity, float coverage, float rainSpeed, glm::vec2 rainSize, float rainDirection, float duration)
{
	Rain r;
	r.color = color;
	r.coverage = coverage;
	r.intensity = intensity;
	r.duration = duration;
	r.pos = pos;
	r.rainSize = rainSize;
	r.rainDirection = rainDirection;
	r.rainSpeed = rainSpeed;
	r.v = cloudV;
	rains.push_back(r);
}