#include "Tracer.h" // <1>
#include <stdio.h> 
#include <ColorSensor.h>

static FILE *bt = NULL;
int abc;

Tracer::Tracer():
  leftWheel(PORT_C), rightWheel(PORT_B), colorSensor(PORT_2) { // <2>
}

void Tracer::init() {
  init_f("Tracer");
  bt = ev3_serial_open_file(EV3_SERIAL_BT);
}

void Tracer::terminate() {
  msg_f("Stopped.", 1);
  leftWheel.stop();  // <1>
  rightWheel.stop();
}

void Tracer::run() {
  msg_f("running...", 1);
  abc = colorSensor.getColorNumber();
  if(colorSensor.getColorNumber() >= 6) { // <1>　白の場合
    leftWheel.setPWM(5);
    rightWheel.setPWM(37);
  } 
  else{
    leftWheel.setPWM(37);
    rightWheel.setPWM(5);
  }
    fprintf(bt,"color:%d\r\n",colorSensor.getColorNumber());
}
