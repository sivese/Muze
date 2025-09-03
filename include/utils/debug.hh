#pragma once

#include <SDL2/SDL.h>
#include <cstdlib>
#include <string>

namespace Muze {
    struct DebugInfo {
        float fps;
        float deltaTime;
        float frameTime;

        std::size_t memoryUsage;
        int drawCalls;
        
        // Not for now, scene or whatever...
        //std::string customInfo;
    };

    class Debug {
    public:
        
    private:
        SDL_Renderer* renderer;

        bool enabled;
        int posX, posY;

        SDL_Color textColor;
        SDL_Color backgroundColor;

        DebugInfo currentInfo;
        //std::vector<std::pair<std::string, std::string>> customInfo;

        void renderText(const std::string& text, int x, int y);
        void renderBackground(int width, int height);

        static const int CHAR_WIDTH = 10;
        static const int CHAR_HEIGHT = 10;

        void renderChar(char c, int x, int y);
        void getCharBitmap(char c, bool bitmap[10][10]);

        std::string formatFloat(float value, int precision = 2);
        std::string formatMemory(std::size_t bytes);
    };
}