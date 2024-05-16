#include "Action.cpp"
#include "Monitor.cpp"

class Scene {
public:
    Scene(Action* action, Monitor* monitor, Scene* next);
    bool exec();
    Scene* getNext();

private:
    Action* action_;
    Monitor* monitor_;
    Scene* next_;
};
