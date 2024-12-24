#pragma once

#include "graphics.h"
#include "input.h"
#include "globals.h"

class Fluid {
public:
	Fluid();
	~Fluid();
private:
	void gameLoop();

	void draw(float p_currentFPS, int p_elapsedTime);

	void update(float p_elapsedTime);

	void handleInput(Input &p_input);

	Graphics _graphics;
	bool _running;
};