#pragma once

#include <SDL2/SDL.h>
#include <cstdlib>
#include <functional>
#include <map>
#include <memory>
#include <vector>

enum class EventType {
    QUIT,
    KEY_DOWN,
    KEY_UP,
    MOUSE_DOWN,
    MOUSE_UP,
    MOUSE_MOVE,
    WINDOW_EVENT,
    FRAME_START,
    FRAME_END,
    CUSTOM_START = 1000
};

struct Event {
    EventType type;
    Uint32 timestamp;

    Event(EventType type) : type(type), timestamp(SDL_GetTicks()) { }
    virtual ~Event() = default;
}; //base structure for event types

struct QuitEvent : public Event {
    QuitEvent() : Event(EventType::QUIT) { }
};

struct KeyEvent : public Event {
    SDL_KeyboardEvent keyData;
    KeyEvent(EventType type, const SDL_KeyboardEvent& keyData) : Event(type), keyData(keyData) { }
};

struct MouseButtonEvent : public Event {
    SDL_MouseButtonEvent buttonData;
    MouseButtonEvent(EventType type, const SDL_MouseButtonEvent& buttonData) : Event(type), buttonData(buttonData) { }
};

struct MouseMotionEvent : public Event {
    SDL_MouseMotionEvent motionData;
    MouseMotionEvent(const SDL_MouseMotionEvent& motionData) : Event(EventType::MOUSE_MOVE), motionData(motionData) { }
};

struct WindowEvent : public Event {
    SDL_WindowEvent windowData;
    WindowEvent(const SDL_WindowEvent& windowData) : Event(EventType::WINDOW_EVENT), windowData(windowData) { }
};

struct FrameEvent : public Event {
    float deltaTime;
    float fps;

    FrameEvent(EventType type, float deltaTime, float fps) 
        : Event(type), deltaTime(deltaTime), fps(fps) { }
};

using EventHandler = std::function<void(const Event&)>;

class EventObserver {
public:
    EventObserver() = default;
    ~EventObserver() = default;

    void subscribe();
    std::size_t subscribeWithID();
    void unsubscribe();

    void publish();
    void publishSDLEvent();
    void processEvents();
    void clear();
private:
    struct HandlerInfo {
        std::size_t id;
        EventHandler handler;
    };

    std::unordered_map<EventType, std::vector<HandlerInfo>> subscribers;
    std::vector<std::unique_ptr<Event>> eventQueue;
    std::size_t nextHandlerID = 0;
};