#include "Monitor.cpp"
#include "Device.h"

class AngleMonitor : public Monitor {
public:
    AngleMonitor(float target, int from);
    bool check();

private:
    bool init_flg_ = false;
    float target_;
    int from_;
    float angle_ = 0.0;
    float last_left_angle_;
    float last_right_angle_;
};
