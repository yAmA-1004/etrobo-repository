#include "Action.cpp"
#include "Device.h"

class WheelAction : public Action {
public:
    WheelAction(int leftPWM, int rightPWM);
    void run();

private:
    int leftPWM_;
    int rightPWM_;
};
