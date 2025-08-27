#pragma once

#include <SDL2/SDL.h>

class Window {
public:
    Window(const char* title, int width, int height);
    ~Window();

private:
    SDL_Window* window;

    bool running;
};