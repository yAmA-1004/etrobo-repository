#include "Scene.h"
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
    void calibrate();
};
