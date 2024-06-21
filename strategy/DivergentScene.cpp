#include "util.h"
#include "DivergentScene.h"

DivergentScene::DivergentScene(Action* action, Monitor* monitor, Scene* next, Scene* proxy):
    Scene(action, monitor, next) {
    action_ = action;
    monitor_ = monitor;
    next_ = next;
    proxy_ = proxy;
}

bool DivergentScene::exec() {
    action_->run();
    if (monitor_ == nullptr) {
        return true;
    }
    return monitor_->check();
}

Scene* DivergentScene::getNext() {
    if (Env::red_block_found) {
        msg_f("REDBLOCK_FOUND", 0);
        return proxy_;
    }
    msg_f("BLUEBLOCK_FOUND", 0);
    return next_;
}
