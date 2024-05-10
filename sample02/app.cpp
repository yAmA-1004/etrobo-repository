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
  Motor leftWheel;
  Motor rightWheel;
  Clock clock;

#ifndef MAKE_RASPIKE
  const int8_t pwm = (Motor::PWM_MAX) / 6;
#else
  const int8_t pwm = 60;
#endif
  const uint32_t duration = 2000*1000;

protected:             // <1>
  void forward(void);  // <2>
  void back(void);     // <2>
  void stop(void);     // <2>
};

Walker::Walker():
  leftWheel(PORT_C), rightWheel(PORT_B) {
}

void Walker::forward(void) {  // <3>
  msg_f("Forwarding...", 1);
  leftWheel.setPWM(pwm);
  rightWheel.setPWM(pwm);
}

void Walker::back(void) {  // <3>
  msg_f("Backwarding...", 1);
  leftWheel.setPWM(-pwm);
  rightWheel.setPWM(-pwm);
}

void Walker::stop(void) {  // <3>
  msg_f("Stopped.", 1);
  leftWheel.stop();
  rightWheel.stop();
}

void Walker::run() {
  init_f(__FILE__);
  while(1) {
    forward();             // <4>
    clock.sleep(duration);
    back();                // <4>
    clock.sleep(duration);

    // 左ボタンを長押し、それを捕捉する
    if (ev3_button_is_pressed(LEFT_BUTTON)) {
      break;
    }
  }

  stop();                // <4>
  while(ev3_button_is_pressed(LEFT_BUTTON)) {
    ;
  }
}

void main_task(intptr_t unused) { // <5>
  Walker walker;
  walker.run();
  ext_tsk();
}
