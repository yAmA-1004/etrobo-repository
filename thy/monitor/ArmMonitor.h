#include "Monitor.cpp"
#include "Motor.h"

using namespace ev3api;

class ArmMonitor : public Monitor {
public:
    ArmMonitor(int target, int from);
    bool check();

private:
    Motor armMotor_= Motor(PORT_A);
    int target_;
    int from_;
};
