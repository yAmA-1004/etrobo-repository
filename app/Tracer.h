#include "Motor.h"       // <1>
#include "ColorSensor.h" // <2>
#include "util.h"        // <3>
#include "PIDparam.h"
#include "PIDCalc.h"
#include "TouchSensor.h"
using namespace ev3api;  // <4>
class Tracer {  // <1>
public:
  Tracer();
  void run();       // <2>
  void init();
  void terminate();
private:
  Motor leftWheel;
  Motor rightWheel;
  ColorSensor colorSensor; // <3>
  TouchSensor touchSensor;
  int  diff;
  int  brightness;
  const int8_t mThreshold = 20;  // <4>
  int32_t lCount;
  int32_t rCount;
   char buf[128];
   bool isStart = false;
#ifndef MAKE_RASPIKE
  const int8_t pwm = 40;
#else
  const int8_t pwm = 100;
#endif
  PIDparam * param1 = new PIDparam(20,0.17, 0, 0.33);
  PIDparam * param2 = new PIDparam(20,0.4, 0, 0.5);
};

