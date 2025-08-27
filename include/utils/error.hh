#pragma once

#include <string>
#include <iostream>
#include <SDL2/SDL.h>

namespace Muze {
    void logError(const std::string& message) {
        std::cerr << "Error: " << message << ", " << SDL_GetError() << std::endl;
    }
}