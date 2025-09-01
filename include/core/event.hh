#pragma once

#include <SDL2/SDL.h>
#include <cstdlib>

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
};

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
