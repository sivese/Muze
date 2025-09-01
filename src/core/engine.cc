#include "core/engine.hh"
#include "utils/error.hh"

#include <SDL2/SDL.h>
#include <thread>

const std::string Engine::ENGINE_NAME = "Muze Engine";

Engine::Engine(int width, int height)
    : running(false), deltaTime(0.0f), fps(0.0f) {

    try {
        this->window = std::make_unique<Window>(ENGINE_NAME.c_str(), width, height);
        lastTime = std::chrono::high_resolution_clock::now();
        running = true;
    }
    catch(const std::exception& e) {
        Muze::logError("Engine initialization failed: " + std::string(e.what()));
        running = false;
    }
}

Engine::~Engine() {
    this->cleanup();
}

void Engine::run() {
    if(this->running == false) return;
    
    initialize();

    while (this->running && this->window->isRunning()) {
        calculateDeltaTime();
        
        this->update();
        this->render();
        //this->limitFrameRate();
    }
}

// game logic initialize
// no engine logic initialization
void Engine::initialize() {

}

void Engine::update() {
    // Update game logic
}

void Engine::render() {
    // Render game logic
}

void Engine::cleanup() {
    // Cleanup game logic
}

void Engine::calculateDeltaTime() {

}

void Engine::limitFrameRate() {

}
