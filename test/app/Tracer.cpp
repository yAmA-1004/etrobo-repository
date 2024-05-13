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
  sprintf(buf, "rCount=%d", rCount);
  _log(buf);
  brightness = colorSensor.getBrightness();
  diff = (brightness - mThreshold) * 1.1;

  if(rCount < 3470){//直線～最初のカーブ
    diff = PIDCalc::calc(param1,brightness); 
    leftWheel.setPWM(60-diff);
    rightWheel.setPWM(60+diff);  
  }
  else if(rCount < 3800){//最初のカーブ～二つ目の直線
    diff = PIDCalc::calc(param1,brightness); 
    leftWheel.setPWM(50-diff);
    rightWheel.setPWM(30+diff);
  }
  else if(rCount < 5100){//二つ目の直線⑴～重なり
    diff = PIDCalc::calc(param1,brightness); 
    leftWheel.setPWM(55-diff);
    rightWheel.setPWM(55+diff);    
  }
  else if(rCount < 5400){//重なり～二つ目の直線⑵
    // diff = PIDCalc::calc(param1,brightness); 
    leftWheel.setPWM(40);
    rightWheel.setPWM(40);    
  }
  else if(rCount < 5700){
  diff = PIDCalc::calc(param1,brightness); 
  leftWheel.setPWM(60-diff);
  rightWheel.setPWM(60+diff);
  }
  else if(rCount < 6000){//二つ目のカーブ～三つ目の短い直線
    diff = PIDCalc::calc(param1,brightness);
    leftWheel.setPWM(50-diff);
    rightWheel.setPWM(30+diff);
    // leftWheel.setPWM(35-diff);
    // rightWheel.setPWM(30+diff);        
  }

  else if(rCount < 8320){//ダブルループ進入～一回目の青線
    diff = PIDCalc::calc(param1,brightness); 
    leftWheel.setPWM(40-diff);
    rightWheel.setPWM(40+diff);    
  }
  else if(rCount < 8400){//8400
    // diff = PIDCalc::calc(param1,brightness);
    leftWheel.setPWM(5);
    rightWheel.setPWM(30);
  }
  else if(rCount < 10960){//エッジ切り替え8480,8450
  diff = PIDCalc::calc(param1,brightness);
  leftWheel.setPWM(20-diff);
  rightWheel.setPWM(40+diff);
  }
  else if(rCount < 11050){//
    // diff = PIDCalc::calc(param1,brightness);
    leftWheel.setPWM(30);
    rightWheel.setPWM(30);
  }
  else if(rCount < 11170){//
  diff = PIDCalc::calc(param1,brightness); 
  leftWheel.setPWM(5-diff);
  rightWheel.setPWM(30+diff);
  }
  else if(rCount < 12260){//
    diff = PIDCalc::calc(param1,brightness);
    leftWheel.setPWM(35-diff);
    rightWheel.setPWM(35+diff);
  } 
  else if(rCount < 13000){//
    // diff = PIDCalc::calc(param1,brightness);
    leftWheel.setPWM(30);
    rightWheel.setPWM(30);  
  }
  else if(rCount < 13070){
    diff = PIDCalc::calc(param2,brightness);
    leftWheel.setPWM(30-diff);
    rightWheel.setPWM(10+diff);
  }
  else if(rCount < 14000){//
    diff = PIDCalc::calc(param1,brightness);
    leftWheel.setPWM(40-diff);
    rightWheel.setPWM(40+diff);
  }
//ブロック
  // if(rCount < 250){//
  //   // diff = PIDCalc::calc(param1,brightness);
  //   leftWheel.setPWM(0);
  //   rightWheel.setPWM(20);
  // }
  // else if(rCount < 2500){//
  //   // diff = PIDCalc::calc(param1,brightness);
  //   leftWheel.setPWM(20);
  //   rightWheel.setPWM(20);
  // }
  else{
    leftWheel.stop();
    rightWheel.stop();
  }
}