#include <SDL3/SDL.h>
#include <fluid.h>

namespace {
    const int FPS_TARGET = 60;
    constexpr int MAX_FRAME_TIME = 1000 / FPS_TARGET;

    unsigned int frameCount = 0;
    float currentFPS = 0.0f;
}

Fluid::Fluid() :
    _graphics(),
    _running(true)
{
    this->gameLoop();
}

Fluid::~Fluid()
{}

void Fluid::gameLoop() {
    Input input;
    Uint64 lastUpdateTime = SDL_GetTicks();
    Uint64 lastFpsUpdateTime = lastUpdateTime;

    while (this->_running) {
        input.beginNewFrame();
        this->handleInput(input);

        const Uint64 currentTimeMs = SDL_GetTicks();
        Uint64 elapsedTimeMs = currentTimeMs - lastUpdateTime;

        frameCount++;
        if (currentTimeMs - lastFpsUpdateTime >= 1000) {
            currentFPS = frameCount / ((currentTimeMs - lastFpsUpdateTime) / 1000.0f);
            frameCount = 0;
            lastFpsUpdateTime = currentTimeMs;
        }

        this->update((((static_cast<float>(elapsedTimeMs)) < (MAX_FRAME_TIME)) ? (static_cast<float>(elapsedTimeMs)) : (MAX_FRAME_TIME)));
        lastUpdateTime = currentTimeMs;

        this->draw(currentFPS, static_cast<int>(elapsedTimeMs));

        // Frame rate limiting
        Uint64 frameEndTime = SDL_GetTicks();
        int frameDuration = static_cast<int>(frameEndTime - currentTimeMs);
        if (frameDuration < MAX_FRAME_TIME) {
            SDL_Delay(MAX_FRAME_TIME - frameDuration);
        }
    }
}

void Fluid::draw(float p_currentFPS, int p_elapsedTime) {
    this->_graphics.clear();

    // Set the draw color to white
    SDL_SetRenderDrawColor(this->_graphics.getRenderer(), 255, 255, 255, 255);

    // Draw a white pixel at (x, y)

    for (int x = 0; x <= globals::SCREEN_WIDTH; x += globals::SCREEN_WIDTH / 100) { //vertical lines
        SDL_RenderLine(this->_graphics.getRenderer(), x, 0, x, globals::SCREEN_WIDTH);
    }

    for (int y = 0; y <= globals::SCREEN_HEIGHT; y += globals::SCREEN_HEIGHT / 100) { //horizontal lines
        SDL_RenderLine(this->_graphics.getRenderer(), 0, y, globals::SCREEN_HEIGHT, y);
    }


    this->_graphics.flip();
}

void Fluid::update(float p_elapsedTime) {
    //update logic
}

void Fluid::handleInput(Input &p_input) {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_EVENT_KEY_DOWN) {
            p_input.keyDownEvent(e);
        }
        else if (e.type == SDL_EVENT_KEY_UP) {
            p_input.keyUpEvent(e);
        }
        else if (e.type == SDL_EVENT_QUIT) {
            this->_running = false;
            return;
        }
    }

    if (p_input.wasKeyPressed(SDL_SCANCODE_Q)) {
        this->_running = false;
        return;
    }
}
