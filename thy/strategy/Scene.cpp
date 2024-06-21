#include "Scene.h"

Scene::Scene(Action* action, Monitor* monitor, Scene* next) {
    action_ = action;
    monitor_ = monitor;
    next_ = next;
}

bool Scene::exec() {
    action_->run();
    if (monitor_ == nullptr) {
        return true;
    }
    return monitor_->check();
}

Scene* Scene::getNext() {
    return next_;
}
