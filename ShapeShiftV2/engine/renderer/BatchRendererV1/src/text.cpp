#include "text.h"

std::string font = "textures/testFont1-01.png";
std::string shad = "shaders/shader.shader";
glm::vec2 mag{ 0.14286f, 0.14286f };
glm::vec2 offset{ 0.14286f, 0.14286f };


Sprite A(font, shad, TexCoordTrans(mag, glm::vec2(offset.x * 0.0f, offset.y * 6.0f)));
Sprite B(font, shad, TexCoordTrans(mag, glm::vec2(offset.x * 1.0f, offset.y * 6.0f)));
Sprite C(font, shad, TexCoordTrans(mag, glm::vec2(offset.x * 2.0f, offset.y * 6.0f)));
Sprite D(font, shad, TexCoordTrans(mag, glm::vec2(offset.x * 3.0f, offset.y * 6.0f)));
Sprite E(font, shad, TexCoordTrans(mag, glm::vec2(offset.x * 4.0f, offset.y * 6.0f)));
Sprite F(font, shad, TexCoordTrans(mag, glm::vec2(offset.x * 5.0f, offset.y * 6.0f)));
Sprite G(font, shad, TexCoordTrans(mag, glm::vec2(offset.x * 6.0f, offset.y * 6.0f)));
Sprite H(font, shad, TexCoordTrans(mag, glm::vec2(offset.x * 0.0f, offset.y * 5.0f)));
Sprite I(font, shad, TexCoordTrans(mag, glm::vec2(offset.x * 1.0f, offset.y * 5.0f)));
Sprite J(font, shad, TexCoordTrans(mag, glm::vec2(offset.x * 2.0f, offset.y * 5.0f)));
Sprite K(font, shad, TexCoordTrans(mag, glm::vec2(offset.x * 3.0f, offset.y * 5.0f)));
Sprite L(font, shad, TexCoordTrans(mag, glm::vec2(offset.x * 4.0f, offset.y * 5.0f)));
Sprite M(font, shad, TexCoordTrans(mag, glm::vec2(offset.x * 5.0f, offset.y * 5.0f)));
Sprite N(font, shad, TexCoordTrans(mag, glm::vec2(offset.x * 6.0f, offset.y * 5.0f)));
Sprite O(font, shad, TexCoordTrans(mag, glm::vec2(offset.x * 0.0f, offset.y * 4.0f)));
Sprite P(font, shad, TexCoordTrans(mag, glm::vec2(offset.x * 1.0f, offset.y * 4.0f)));
Sprite Q(font, shad, TexCoordTrans(mag, glm::vec2(offset.x * 2.0f, offset.y * 4.0f)));
Sprite R(font, shad, TexCoordTrans(mag, glm::vec2(offset.x * 3.0f, offset.y * 4.0f)));
Sprite S(font, shad, TexCoordTrans(mag, glm::vec2(offset.x * 4.0f, offset.y * 4.0f)));
Sprite T(font, shad, TexCoordTrans(mag, glm::vec2(offset.x * 5.0f, offset.y * 4.0f)));
Sprite U(font, shad, TexCoordTrans(mag, glm::vec2(offset.x * 6.0f, offset.y * 4.0f)));
Sprite V(font, shad, TexCoordTrans(mag, glm::vec2(offset.x * 0.0f, offset.y * 3.0f)));
Sprite W(font, shad, TexCoordTrans(mag, glm::vec2(offset.x * 1.0f, offset.y * 3.0f)));
Sprite X(font, shad, TexCoordTrans(mag, glm::vec2(offset.x * 2.0f, offset.y * 3.0f)));
Sprite Y(font, shad, TexCoordTrans(mag, glm::vec2(offset.x * 3.0f, offset.y * 3.0f)));
Sprite Z(font, shad, TexCoordTrans(mag, glm::vec2(offset.x * 4.0f, offset.y * 3.0f)));
Sprite _0(font, shad, TexCoordTrans(mag, glm::vec2(offset.x * 5.0f, offset.y * 3.0f)));
Sprite _1(font, shad, TexCoordTrans(mag, glm::vec2(offset.x * 6.0f, offset.y * 3.0f)));
Sprite _2(font, shad, TexCoordTrans(mag, glm::vec2(offset.x * 0.0f, offset.y * 2.0f)));
Sprite _3(font, shad, TexCoordTrans(mag, glm::vec2(offset.x * 1.0f, offset.y * 2.0f)));
Sprite _4(font, shad, TexCoordTrans(mag, glm::vec2(offset.x * 2.0f, offset.y * 2.0f)));
Sprite _5(font, shad, TexCoordTrans(mag, glm::vec2(offset.x * 3.0f, offset.y * 2.0f)));
Sprite _6(font, shad, TexCoordTrans(mag, glm::vec2(offset.x * 4.0f, offset.y * 2.0f)));
Sprite _7(font, shad, TexCoordTrans(mag, glm::vec2(offset.x * 5.0f, offset.y * 2.0f)));
Sprite _8(font, shad, TexCoordTrans(mag, glm::vec2(offset.x * 6.0f, offset.y * 2.0f)));
Sprite _9(font, shad, TexCoordTrans(mag, glm::vec2(offset.x * 0.0f, offset.y * 1.0f)));
Sprite COLON(font, shad, TexCoordTrans(mag, glm::vec2(offset.x * 1.0f, offset.y * 1.0f)));
Sprite CAMA(font, shad, TexCoordTrans(mag, glm::vec2(offset.x * 2.0f, offset.y * 1.0f)));
Sprite PERIOD(font, shad, TexCoordTrans(mag, glm::vec2(offset.x * 3.0f, offset.y * 1.0f)));
Sprite EXCLAMATION(font, shad, TexCoordTrans(mag, glm::vec2(offset.x * 4.0f, offset.y * 1.0f)));
Sprite STAR(font, shad, TexCoordTrans(mag, glm::vec2(offset.x * 5.0f, offset.y * 1.0f)));
Sprite QUESTION(font, shad, TexCoordTrans(mag, glm::vec2(offset.x * 6.0f, offset.y * 1.0f)));
Sprite FORWARDSLASH(font, shad, TexCoordTrans(mag, glm::vec2(offset.x * 0.0f, offset.y * 0.0f)));
Sprite AT(font, shad, TexCoordTrans(mag, glm::vec2(offset.x * 1.0f, offset.y * 0.0f)));
Sprite AND(font, shad, TexCoordTrans(mag, glm::vec2(offset.x * 2.0f, offset.y * 0.0f)));
Sprite MONEY(font, shad, TexCoordTrans(mag, glm::vec2(offset.x * 3.0f, offset.y * 0.0f)));
Sprite MOD(font, shad, TexCoordTrans(mag, glm::vec2(offset.x * 4.0f, offset.y * 0.0f)));
Sprite PLUS(font, shad, TexCoordTrans(mag, glm::vec2(offset.x * 5.0f, offset.y * 0.0f)));
Sprite QUOTE(font, shad, TexCoordTrans(mag, glm::vec2(offset.x * 6.0f, offset.y * 0.0f)));



Sprite Text::getCharSprite(char c)
{

	if (c >= 97 && c <= 122)
	{
		//if its a lowercase letter
		c -= 32;

	}
	//now we have all known chars, next loop through every element and switch depending 

	switch (c)
	{
	case 'A':
	{
		return(A);
		break;
	}
	case 'B':
	{
		return(B);
		break;
	}
	case 'C':
	{
		return(C);
		break;
	}
	case 'D':
	{
		return(D);
		break;
	}
	case 'E':
	{
		return(E);
		break;
	}
	case 'F':
	{
		return(F);
		break;
	}
	case 'G':
	{
		return(G);
		break;
	}
	case 'H':
	{
		return(H);
		break;
	}
	case 'I':
	{
		return(I);
		break;
	}
	case 'J':
	{
		return(J);
		break;
	}
	case 'K':
	{
		return(K);
		break;
	}
	case 'L':
	{
		return(L);
		break;
	}
	case 'M':
	{
		return(M);
		break;
	}
	case 'N':
	{
		return(N);
		break;
	}
	case 'O':
	{
		return(O);
		break;
	}
	case 'P':
	{
		return(P);
		break;
	}
	case 'Q':
	{
		return(Q);
		break;
	}
	case 'R':
	{
		return(R);
		break;
	}
	case 'S':
	{
		return(S);
		break;
	}
	case 'T':
	{
		return(T);
		break;
	}
	case 'U':
	{
		return(U);
		break;
	}
	case 'V':
	{
		return(V);
		break;
	}
	case 'W':
	{
		return(W);
		break;
	}
	case 'X':
	{
		return(X);
		break;
	}
	case 'Y':
	{
		return(Y);
		break;
	}
	case 'Z':
	{
		return(Z);
		break;
	}
	case '0':
	{
		return(_0);
		break;
	}
	case '1':
	{
		return(_1);
		break;
	}
	case '2':
	{
		return(_2);
		break;
	}
	case '3':
	{
		return(_3);
		break;
	}
	case '4':
	{
		return(_4);
		break;
	}
	case '5':
	{
		return(_5);
		break;
	}
	case '6':
	{
		return(_6);
		break;
	}
	case '7':
	{
		return(_7);
		break;
	}
	case '8':
	{
		return(_8);
		break;
	}
	case '9':
	{
		return(_9);
		break;
	}
	case ':':
	{
		return(COLON);
		break;
	}
	case ',':
	{
		return(CAMA);
		break;
	}
	case '.':
	{
		return(PERIOD);
		break;
	}
	case '!':
	{
		return(EXCLAMATION);
		break;
	}
	case '*':
	{
		return(STAR);
		break;
	}
	case '?':
	{
		return(QUESTION);
		break;
	}
	case '/':
	{
		return(FORWARDSLASH);
		break;
	}
	case '@':
	{
		return(AT);
		break;
	}
	case '&':
	{
		return(AND);
		break;
	}
	case '$':
	{
		return(MONEY);
		break;
	}
	case '%':
	{
		return(MOD);
		break;
	}
	case '+':
	{
		return(PLUS);
		break;
	}
	case '"':
	{
		return(QUOTE);
		break;
	}
	default:
	{
		return(QUOTE);
		break;
	}

	}
}

Text::Text(glm::vec2 pos, std::string s, glm::vec2 size, glm::vec4 color)
	:pos{ pos }, size{ size }, color{ color }, string{ s }
{
	for (auto e : string)
	{
		if(e!= ' ' && e!= '\n')
		letters.push_back(genRenderable(glm::vec2(0.0f, 0.0f), size, color, getCharSprite(e), false));
	}
	//first set all letters to cap and change unknown chars to spaces
	

	int letterCounter = 0;
	glm::vec2 distanceFromStart(0.0f, 0.0f);
	float xOffsetIncrease = (size.x / 1.9f);
	float yOffsetIncrease = (size.y * 1.1f);
	float maxXDistance = 0.0f;
	for (auto c : string)
	{
		if (c != '\n' && c != ' ')
		{
			letters[letterCounter].move(distanceFromStart);
		}
	
		if (c != '\n')
		{
			distanceFromStart.x += xOffsetIncrease;
			if (distanceFromStart.x > maxXDistance)
				maxXDistance = distanceFromStart.x;
		}
		else
		{
			distanceFromStart.x = 0.0f;
			distanceFromStart.y -= yOffsetIncrease;
		}

		if (c != ' ' && c != '\n')
		{
			letterCounter += 1;
		}
			
	}

	glm::mat4 m = glm::mat4(1.0f);
	glm::vec2 centermove((maxXDistance - (size.x/2.0f))/2.0f, distanceFromStart.y/2.0f);
	m = glm::translate(m, glm::vec3(pos.x - centermove.x, pos.y - centermove.y, 0.0f));

	b_id = generateCustomBatch(font, shad, true, m);

	for (int i = 0; i < letters.size(); i++)
	{
		letters[i].willDraw(true, b_id);
	}
}


void Text::update()
{
	for (int i = 0; i < letters.size(); i++)
	{
		letters[i].update(glm::vec2(0.0f, 0.0f));
	}
}
