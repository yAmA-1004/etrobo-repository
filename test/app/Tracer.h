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
  // void stop();s
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
  PIDparam * param1 = new PIDparam(20, 0.83, 0.1, 0.36);//本当の
  // PIDparam * param1 = new PIDparam(16, 0.83, 0.1, 0.36);//テスト
  PIDparam * param2 = new PIDparam(20, 1.8, 0.6, 0.36);
 };

