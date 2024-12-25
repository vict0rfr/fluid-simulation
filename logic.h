#pragma once

#include "graphics.h"


class Logic {
public:

	Logic();
	~Logic();

	float getMouseX() { return this->_mouseX;  }
	float getMouseY() { return this->_mouseY;  }

	void draw(Graphics &p_graphics);
	void parseMousePos();
	void drawGrid(Graphics &p_graphics);

private:
	float _mouseX = NULL;
	float _mouseY = NULL;
	bool _grid[globals::N * globals::N] = { false };
};