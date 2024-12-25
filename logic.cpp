#include "logic.h"
#include <SDL3/SDL.h>	

Logic::Logic()
{}

Logic::~Logic()
{}

void Logic::draw(Graphics &p_graphics) {
    // Set the draw color to white
    SDL_SetRenderDrawColor(p_graphics.getRenderer(), 255, 255, 255, 255);

    for (int x = 0; x <= globals::SCREEN_SIZE; x += globals::N) { //vertical lines
        SDL_RenderLine(p_graphics.getRenderer(), x, 0, x, globals::SCREEN_SIZE);
    }

    for (int y = 0; y <= globals::SCREEN_SIZE; y += globals::N) { //horizontal lines
        SDL_RenderLine(p_graphics.getRenderer(), 0, y, globals::SCREEN_SIZE, y);
    }

    if (this->_mouseX != NULL) {
        // create grid of all squares in window
        int grid[globals::N * globals::N];
        //get pos, module the width, find in which square the mouse is, make that square red.
        float j = floor(static_cast<int>(this->_mouseX) / globals::GRID_SIZE);
        float i = floor(static_cast<int>(this->_mouseY) / globals::GRID_SIZE);

    }

}

void Logic::parseMousePos() {
    SDL_GetMouseState(&this->_mouseX, &this->_mouseY);
}