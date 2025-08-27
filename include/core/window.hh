#pragma once

#include <SDL2/SDL.h>

class Window {
public:
    Window(const char* title, int width, int height);
    virtual ~Window();

    bool isRunning();
    void pollEvents();
    void clear();
    void present();

    SDL_Renderer* getRenderer() { return this->renderer; }
private:
    SDL_Window*     window;
    SDL_Renderer*   renderer;

    bool running;
    int width, height;
};