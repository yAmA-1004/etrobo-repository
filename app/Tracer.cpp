#include "Tracer.h" // <1>
#include "PIDControlRun.h"

using namespace ev3api;  // <4>
Tracer::Tracer():
  leftWheel(PORT_C), rightWheel(PORT_B), colorSensor(PORT_2),touchSensor(PORT_1) { // <2>
  }
void Tracer::init() {
  init_f("Tracer");
  lCount=0;
  rCount=0;
  leftWheel.reset();
  rightWheel.reset();
}

void Tracer::terminate() {
  msg_f("Stopped.", 1);
  leftWheel.stop();  // <1>
  rightWheel.stop();
}

void Tracer::run() {
  msg_f("running...", 1);

  if(!isStart && touchSensor.isPressed()){
    isStart = true;
  }

  if(!isStart){
    return;
  }
  rCount = rightWheel.getCount();
  lCount = leftWheel.getCount();
  sprintf(buf, "rCount=%d", rCount);
  _log(buf);
  brightness = colorSensor.getBrightness();
  diff = (brightness - mThreshold) * 1.1;

  if(rCount < 3500){
    diff = PIDCalc::calc(param1,brightness); 
    leftWheel.setPWM(60-diff);
    rightWheel.setPWM(60+diff);
  }
  else if(rCount < 3750){
    diff = PIDCalc::calc(param1,brightness); 
    leftWheel.setPWM(27-diff);
    rightWheel.setPWM(14+diff);    
  }
  else if(rCount < 5800){
    diff = PIDCalc::calc(param1,brightness); 
    leftWheel.setPWM(60-diff);
    rightWheel.setPWM(60+diff);    
  }
  else if(rCount < 6100){
    diff = PIDCalc::calc(param1,brightness);
    leftWheel.setPWM(25-diff);
    rightWheel.setPWM(12+diff);    
  }
  // ここまではいい
  else if(rCount < 6490){
    diff = PIDCalc::calc(param1,brightness); 
    leftWheel.setPWM(50-diff);
    rightWheel.setPWM(50+diff);    
  }  
  else if(rCount < 6700){
    diff = PIDCalc::calc(param1,brightness); 
    leftWheel.setPWM(20-diff);
    rightWheel.setPWM(15+diff);    
  }
  else if(rCount < 8150){
    diff = PIDCalc::calc(param1,brightness); 
    leftWheel.setPWM(36-diff);
    rightWheel.setPWM(36+diff);    
  }
  else if(rCount < 8270){
    // diff = PIDCalc::calc(param1,brightness); 
    leftWheel.setPWM(60-diff);
    rightWheel.setPWM(60+diff);    
  }

  else{
    leftWheel.setPWM(0);
    rightWheel.setPWM(0); 
  }
}
