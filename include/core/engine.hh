#pragma once

#include <string>
#include <memory>
#include <chrono>

#include "core/window.hh"

class Engine {
public:
    Engine(int width = 800, int height = 600);
    virtual ~Engine();

    // Main life cycle
    void run();
    void shutdown();

    
    Window* getWindow() { return this->window.get();}
    
    bool isRunning()        const { return this->running; }
    float getDeltaTime()    const { return this->deltaTime; }
    float getFPS()          const { return this->fps; }
    
    static const std::string ENGINE_NAME;
    protected:
    using TimePoint = std::chrono::high_resolution_clock::time_point;
    
    std::unique_ptr<Window> window;
    bool running;
    
    //timing
    TimePoint lastTime;
    float deltaTime;
    float fps;
    
    static constexpr int    TARGET_FPS = 60;
    static constexpr float  TARGET_FRAME_TIME = 1000.0f / TARGET_FPS;
    
private:
    // Core loop management
    virtual void initialize();
    virtual void update(); //delta time?
    virtual void render();
    virtual void cleanup();

    void calculateDeltaTime();
    void limitFrameRate();
};