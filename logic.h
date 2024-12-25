#pragma once

#include "graphics.h"


class Logic {
public:

	Logic();
	~Logic();

	float getMouseX() { return this->_mouseX;  }
	float getMouseY() { return this->_mouseY;  }

	void draw(Graphics &p_graphics);
	void parseMousePos(float p_dt);
	void drawGrid(Graphics &p_graphics);
	void update(float p_dt);
	void addDensity(float p_dt);

private:
	float _mouseX = NULL;
	float _mouseY = NULL;
	float _grid[globals::N * globals::N] = { 0.0f };
	float _opacity = 0.0f;
};