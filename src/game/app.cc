#include "game/app.hh"

Application::Application() {
    this->engine = std::make_unique<Engine>(800, 600);
}

Application::~Application() {
    // auto cleanup
    // praise the smart pointers!
}

void Application::run() {
    this->engine->run();
}