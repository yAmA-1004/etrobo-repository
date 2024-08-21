#ifndef SCENE_H_
#define SCENE_H_

#include "Action.cpp"
#include "Monitor.cpp"

class Scene {
public:
    Scene(Action* action, Monitor* monitor, Scene* next);
    virtual bool exec();
    virtual Scene* getNext();

private:
    Action* action_;
    Monitor* monitor_;
    Scene* next_;
};

#endif
