#include "Monitor.cpp"
#include "Motor.h"

using namespace ev3api;

class ArmMonitor : public Monitor {
public:
    ArmMonitor(float target, int from);
    bool check();

private:
    Motor armMotor_= Motor(PORT_A);
    float target_;
    int from_;
};
