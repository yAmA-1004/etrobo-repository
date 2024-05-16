#include "Scene.h"
#include "DivergentScene.h"
#include "TouchSensor.h"

using namespace ev3api;

class Process {
public:
    Process();
    void init();
    void exec();
private:
    Scene* scene_ = nullptr;
    TouchSensor touchSensor_ = TouchSensor(PORT_1);
    void setup();
    Scene* getScenePattern1();
    Scene* getScenePattern2();
    Scene* getScenePattern3();
    Scene* getScenePattern4();
    Scene* getScenePattern5();
    void calibrate();
};
