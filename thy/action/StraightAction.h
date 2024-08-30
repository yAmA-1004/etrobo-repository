//#include "Action.cpp"
//#include "Device.h"

//class StraightAction : public Action {
//public:
//    StraightAction(float leftPWM, float rightPWM);
//    void run();

//private:
//    float leftPWM_;
//    float rightPWM_;
//};


#include "Action.cpp"
#include "Device.h"

class StraightAction : public Action {
public:
    StraightAction(float leftPWM, float rightPWM);
    void run();

private:
    float leftPWM_;
    float rightPWM_;
    float previous_left_count_;  // 前回の左モーター回転数を保持
    float previous_right_count_; // 前回の右モーター回転数を保持
};
