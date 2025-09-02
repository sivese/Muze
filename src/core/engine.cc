#include "core/engine.hh"
#include "utils/error.hh"

#include <SDL2/SDL.h>
#include <thread>

const std::string Engine::ENGINE_NAME = "Muze Engine";

Engine::Engine(int width, int height)
    : running(false), deltaTime(0.0f), fps(0.0f) {

    try {
        this->eventObserver = std::make_unique<EventObserver>();
        this->window        = std::make_unique<Window>(ENGINE_NAME.c_str(), width, height);
        
        //TODO
        //Add Input and Time system

        this->lastTime = std::chrono::high_resolution_clock::now();
        this->running = true;
    }
    catch(const std::exception& e) {
        Muze::logError("Engine initialization failed: " + std::string(e.what()));
        this->running = false;
    }
}

Engine::~Engine() {
    this->cleanup();
}

void Engine::run() {
    if(this->running == false) return;
    
    initialize();

    while (this->running && this->window->isRunning()) {
        pollEvents();
        publishFrameEvents();

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
    if(this->window) {
        this->window->clear();
        this->window->present();
    }
}

void Engine::cleanup() {
    if(eventObserver) eventObserver->clear();
}

void Engine::calculateDeltaTime() {

}

void Engine::limitFrameRate() {

}

void Engine::pollEvents() {
    auto event = SDL_Event();

    while(SDL_PollEvent(&event)) {
        eventObserver->publishSDLEvent(event);

        if(event.type == SDL_QUIT) {
            this->running = false;
        }
    }
}

void Engine::publishFrameEvents() {

}