#include "Input.h"


glm::vec2 IN::cursorPos = { 0.0, 0.0 };
bool IN::polling = true;
std::vector <Input> inputStack{};

 bool q = false;
 bool w = false;
 bool e = false;
 bool r = false;
 bool a = false;
 bool s = false;
 bool d = false;
 bool f = false;
 bool x = false;
 bool space = false;
 bool esc = false;
 bool rc = false;
 bool lc = false;

 Bind::Bind(Input i, bool h) : input{ i }, holdable{ h }
 {

 }


void IN::pollInputs()
{
	while (polling)
	{
		//registers input changes

		unsigned int x;
		x = glfwGetKey(window, GLFW_KEY_Q);
		if (x == GLFW_PRESS && !q)
		{
			inputStack.push_back(Input::Q);
			q = true;
		}
		else if(x == GLFW_RELEASE && q)
		{
			q = false;
			inputStack.push_back(Input::Q_R);

		}
			

		x = glfwGetKey(window, GLFW_KEY_W);
		if (x == GLFW_PRESS && !w)
		{
			w = true;
			inputStack.push_back(Input::W);
		}
			
		else if (x == GLFW_RELEASE && w)
		{
			w = false;
			inputStack.push_back(Input::W_R);
		}
			

		x = glfwGetKey(window, GLFW_KEY_E);
		if (x == GLFW_PRESS && !e)
		{
			e = true;
			inputStack.push_back(Input::E);
		}
			
		else if (x == GLFW_RELEASE && e)
		{
			e = false;
			inputStack.push_back(Input::E_R);
		}
			

		x = glfwGetKey(window, GLFW_KEY_R);
		if (x == GLFW_PRESS && !r)
		{
			r = true;
			inputStack.push_back(Input::R);
		}
			
		else if (x == GLFW_RELEASE && r)
		{
			r = false;
			inputStack.push_back(Input::R_R);
		}
			

		x = glfwGetKey(window, GLFW_KEY_A);
		if (x == GLFW_PRESS && !a)
		{
			a = true;
			inputStack.push_back(Input::A);
		}
			
		else if (x == GLFW_RELEASE && a)
		{
			a = false;
			inputStack.push_back(Input::A_R);
		}
			

		x = glfwGetKey(window, GLFW_KEY_S);
		if (x == GLFW_PRESS && !s)
		{
			s = true;
			inputStack.push_back(Input::S);
		}
			
		else if (x == GLFW_RELEASE && s)
		{
			s = false;
			inputStack.push_back(Input::S_R);
		}
			

		x = glfwGetKey(window, GLFW_KEY_D);
		if (x == GLFW_PRESS && !d)
		{
			d = true;
			inputStack.push_back(Input::D);
		}
			
		else if (x == GLFW_RELEASE && d)
		{
			d = false;
			inputStack.push_back(Input::D_R);
		}
			

		x = glfwGetKey(window, GLFW_KEY_F);
		if (x == GLFW_PRESS && !f)
		{
			f = true;
			inputStack.push_back(Input::F);
		}
			
		else if (x == GLFW_RELEASE && f)
		{
			f = false;
			inputStack.push_back(Input::F_R);
		}
			

		x = glfwGetKey(window, GLFW_KEY_X);
		if (x == GLFW_PRESS && !x)
		{
			x = true;
			inputStack.push_back(Input::X);
		}
			
		else if (x == GLFW_RELEASE && x)
		{
			x = false;
			inputStack.push_back(Input::X_R);
		}
			

		x = glfwGetKey(window, GLFW_KEY_SPACE);
		if (x == GLFW_PRESS && !space)
		{
			space = true;
			inputStack.push_back(Input::SPACE);
		}
			
		else if (x == GLFW_RELEASE && space)
		{
			space = false;
			inputStack.push_back(Input::SPACE_R);
		}
			

		x = glfwGetKey(window, GLFW_KEY_ESCAPE);
		if (x == GLFW_PRESS && !esc)
		{
			esc = true;
			inputStack.push_back(Input::ESC);
		}
			
		else if (x == GLFW_RELEASE && esc)
		{
			esc = false;
			inputStack.push_back(Input::ESC_R);
		}
			

		x = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT);
		if (x == GLFW_PRESS && !rc)
		{
			rc = true;
			inputStack.push_back(Input::RC);
		}
			
		else if (x == GLFW_RELEASE && rc)
		{
			rc = false;
			inputStack.push_back(Input::RC_R);
		}
			

		x = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);
		if (x == GLFW_PRESS && !lc)
		{
			lc = true;
			inputStack.push_back(Input::LC);
		}
			
		else if (x == GLFW_RELEASE && lc)
		{
			lc = false;
			inputStack.push_back(Input::LC_R);
		}
			

	}
}

bool IN::pressed(Bind &b)
{
	if (b.holdable)
	{
		if (findIn(b.input))
			return true;
		else
			return false;
	}
	else
	{
		bool returnVal = false;
		Input release = Input((int(b.input) + 1));
		std::vector <Input> temp = inputStack;
		for (auto e : temp)
		{
			if (b.input == e && b.pressed == false  && !returnVal)
			{
		
				returnVal = true;
				b.pressed = true;
			}
			else if (release == e && b.pressed)
			{
				b.pressed = false;
		
			}
		}

		return returnVal;
	}
}

bool IN::findIn(Input i)
{
	for (auto e : inputStack)
	{
		if (i == e)
			return true;
	}
	return false;
}



void IN::updateInputs()
{
	inputStack.clear();
	//reset stuff
	q = false;
	w = false;
	e = false;
	r = false;
	a = false;
	s = false;
	d = false;
	f = false;
	x = false;
	space = false;
    esc = false;
	rc = false;
	lc = false;
}