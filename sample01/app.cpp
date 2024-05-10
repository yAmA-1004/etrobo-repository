#include "app.h"
#include "util.h"

#include "Motor.h"
#include "Clock.h"

using namespace ev3api;

class Walker {
public:
  Walker();
  void run();

private:
  Motor leftWheel;              // <1>
  Motor rightWheel;             // <1>
  Clock clock;                  // <1>

#ifndef MAKE_RASPIKE
  const int8_t pwm = (Motor::PWM_MAX) / 6;
#else
  const int8_t pwm = 60;
#endif
  const uint32_t duration = 2000*1000;
};

Walker::Walker():               // <2>
  leftWheel(PORT_C), rightWheel(PORT_B) {
}

void Walker::run() {
  init_f(__FILE__);
  while(1) {
    msg_f("Forwarding...", 1);
    leftWheel.setPWM(pwm);
    rightWheel.setPWM(pwm);
    clock.sleep(duration);

    msg_f("Backwarding...", 1);
    leftWheel.setPWM(-pwm);
    rightWheel.setPWM(-pwm);
    clock.sleep(duration);

    // 左ボタンを長押し、それを捕捉する
    if (ev3_button_is_pressed(LEFT_BUTTON)) {
      break;
    }
  }

  msg_f("Stopped.", 1);
  leftWheel.stop();
  rightWheel.stop();
  while(ev3_button_is_pressed(LEFT_BUTTON)) {
    ;
  }
}

void main_task(intptr_t unused) {

  Walker walker;                // <3>

  walker.run();                 // <4>

  ext_tsk();
}
