#include "Action.cpp"
#include "Monitor.cpp"
#include "Scene.h"
#include "Env.h"

class DivergentScene : public Scene {
public:
    DivergentScene(Action* action, Monitor* monitor, Scene* next, Scene* proxy);
    bool exec();
    Scene* getNext();

private:
    Action* action_;
    Monitor* monitor_;
    Scene* next_;
    Scene* proxy_;
};
