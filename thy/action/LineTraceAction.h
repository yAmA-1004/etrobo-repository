#include "Action.cpp"
#include "Device.h"
//#include "WheelAction.h" //henkou

class LineTraceAction : public Action {
public:
    LineTraceAction(float currentPWM, float targetPWM, int edge, float p, float i, float d);
    void run();

private:
    float currentPWM_;
    float targetPWM_;
    int pre_diff_;
    int total_diff_;
    int edge_;
    float p_;
    float i_;
    float d_;
    //WheelAction* wheelAction_;
};
