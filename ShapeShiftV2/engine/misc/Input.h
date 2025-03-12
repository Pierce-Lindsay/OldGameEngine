#pragma once
#include "rendererInclude.h"
#include <vector>

//must clear vector at the end of every game update frame so inputs are not duplicated over
enum class Input
{
	Q,
	Q_R,
	W,
	W_R,
	E,
	E_R,
	A,
	A_R,
	S,
	S_R,
	D,
	D_R,
	F,
	F_R,
	X,
	X_R,
	R,
	R_R,
	SPACE,
	SPACE_R,
	ESC,
	ESC_R,
	RC,
	RC_R,
	LC,
	LC_R,

};

class Bind
{
public:
	Bind(Input i, bool h);
	Input input{ Input::Q };
	bool holdable{ true };
	bool pressed{ false };
};


namespace IN
{
	extern glm::vec2 cursorPos;
	void pollInputs();
	bool findIn(Input i);
	extern bool polling;
	bool pressed(Bind& b);
	//call at the end of every render frame
	void updateInputs();

}


