#ifndef DEVICE_H_
#define DEVICE_H_

#include "util.h"
#include "Env.h"
#include "Motor.h"
#include "ColorSensor.h"

using namespace ev3api;

class Device {
public:
    static Motor leftMotor_;
    static Motor rightMotor_;
    static Motor armMotor_;
    static ColorSensor colorSensor_;
    static float get_left_count();
    static float get_right_count();
    static float get_arm_count();
    static int get_r();
    static int get_g();
    static int get_b();
    static void move(int leftPWM, int rightPWM);
    static void up(int armPWM);
};

#endif
