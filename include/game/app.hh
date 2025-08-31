#include "core/engine.hh"

class Application {
public:
    Application();
    virtual ~Application();

    void run();
private:
    std::unique_ptr<Engine> engine;
};