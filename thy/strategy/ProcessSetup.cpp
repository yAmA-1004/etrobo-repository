#include "Process.h"
#include "WheelAction.h"
#include "LineTraceAction.h"
#include "ArmAction.h"
#include "DistanceMonitor.h"
#include "BlackLineMonitor.h"
#include "BlueLineMonitor.h"
#include "YellowLineMonitor.h"
#include "GreenLineMonitor.h"
#include "RedLineMonitor.h"
#include "RedBlockMonitor.h"
#include "ArmMonitor.h"
#include "AngleMonitor.h"
#include "StraightAction.h"

Scene* Process::getScenePattern1() {//完成
  //Action* line_trace_right_action = new LineTraceAction(40, 40, 1, 0.165, 0.01, 0.0155);//いいかも
  Action* line_trace_right_action = new LineTraceAction(35, 35, 1, 0.38, 0.01, 0.055);//0.28
  Action* line_trace_left_action = new LineTraceAction(35, 35, -1, 0.38, 0.01, 0.055);
  Action* line_trace_right_action2 = new LineTraceAction(60, 60, 1, 0.0966, 0.01, 0.0387);
  Action* stop_action = new WheelAction(0, 0);
  Action* right_turn_action = new WheelAction(-40, 40);
  Action* left_turn_action = new WheelAction(-10, 10);
  Action* left_turn_action2 = new WheelAction(-5, 20);
  Action* right_turn_action2 = new WheelAction(20, -5);
  Action* straight_pwm40_action = new WheelAction(40, 40);
  Action* straight_pwm35_action = new WheelAction(35, 35);
  Action* straight_pwm30_action = new WheelAction(30, 30);
  Action* straight_pwm20_action = new WheelAction(20, 20);
  Action* straight_pwm10_action = new WheelAction(10, 10);
  Action* back_pwm40_action = new WheelAction(-40, -40);
  Action* arm_up_action = new ArmAction(-20);
  Action* arm_down_action = new ArmAction(20);
  Action* arm_stop_action = new ArmAction(0);
  Action* left_curve_action = new WheelAction(50, -5);
  Action* right_curve_action = new WheelAction(-5, 50);
  Action* straight40_action = new StraightAction(40.0, 40.0);

  Monitor* red_line_monitor = new RedLineMonitor();
  Monitor* blue_line_monitor = new BlueLineMonitor();
  Monitor* black_line_monitor = new BlackLineMonitor();
  Monitor* yellow_line_monitor = new YellowLineMonitor();
  Monitor* green_line_monitor = new GreenLineMonitor();
  Monitor* red_block_monitor = new RedBlockMonitor();
  Monitor* arm_up_monitor = new ArmMonitor(45 , -1);//45,-1
  Monitor* arm_down_monitor = new ArmMonitor(0, 1);

  Scene* stop_scene = new Scene(stop_action, nullptr, nullptr);
  
  
  Scene* block_scene1 = new Scene(straight40_action, blue_line_monitor, stop_scene);
  
  Scene* straight_scene4 = new Scene(straight40_action, new DistanceMonitor(100), block_scene1);
  Scene* line_trace_scene6 = new Scene(line_trace_right_action, yellow_line_monitor, stop_scene);
  //右上黄直進
  
  Scene* straight_scene3 = new Scene(straight40_action, new DistanceMonitor(100), line_trace_scene6);
  Scene* line_trace_scene5 = new Scene(line_trace_right_action, yellow_line_monitor, straight_scene3);
  //左上黄直進
  
  Scene* curve_scene3_1 = new Scene(right_curve_action, black_line_monitor, line_trace_scene5);//new AngleMonitor(-75)
  Scene* curve_scene3 = new Scene(right_curve_action, new AngleMonitor(-70), curve_scene3_1);
  Scene* line_trace_scene4 = new Scene(line_trace_right_action, red_line_monitor, curve_scene3);
  //右上赤右回転
  
  Scene* curve_scene2_1 = new Scene(right_curve_action, black_line_monitor, line_trace_scene4);
  Scene* curve_scene2 = new Scene(left_curve_action, new AngleMonitor(70), curve_scene2_1);//new AngleMonitor(75)
  Scene* line_trace_scene3 = new Scene(line_trace_right_action, red_line_monitor, curve_scene2);
  //右下赤左回転
  
  Scene* curve_scene1_1 = new Scene(right_curve_action, black_line_monitor, line_trace_scene3);
  Scene* curve_scene1 = new Scene(right_curve_action, new AngleMonitor(-70), curve_scene1_1);//new AngleMonitor(-75)
  Scene* line_trace_scene2 = new Scene(line_trace_left_action, red_line_monitor, curve_scene1);
  //左下赤右回転
  
  Scene* straight_scene2 = new Scene(straight40_action, new DistanceMonitor(110), line_trace_scene2);
  Scene* line_trace_scene1 = new Scene(line_trace_left_action, blue_line_monitor, straight_scene2);
  //左上青直進
  
  Scene* straight_scene1 = new Scene(straight40_action, new DistanceMonitor(100), line_trace_scene1);
  //Scene* straight_scene1 = new Scene(straight_pwm40_action, black_line_monitor, line_trace_scene1);
  //左下青直進
  
  Scene* blue_scene = new Scene(line_trace_left_action, blue_line_monitor, straight_scene1);
  //Scene* neo_straight_scene2 = new Scene(straight40_action, blue_line_monitor, stop_scene);
  //Scene* neo_straight_scene1 = new Scene(straight40_action, new DistanceMonitor(50), neo_straight_scene2);
  //Scene* turn_scene = new Scene(right_turn_action, new AngleMonitor(-35), neo_straight_scene1);
  //Scene* straight_scene = new Scene(straight_pwm35_action, new DistanceMonitor(50), turn_scene);
  //Scene* blue_scene = new Scene(line_trace_left_action, blue_line_monitor, straight_scene);
  //return blue_stop_scene1;
  //return right_turn_scene1;
  return blue_scene;
}








//2222222222222222222222222222222222222222222222222222222222222222222222222222
Scene* Process::getScenePattern2() {//kansei


  Monitor* red_line_monitor = new RedLineMonitor();
  Monitor* blue_line_monitor = new BlueLineMonitor();
  Monitor* black_line_monitor = new BlackLineMonitor();
  Monitor* yellow_line_monitor = new YellowLineMonitor();
  Monitor* green_line_monitor = new GreenLineMonitor();
  Monitor* red_block_monitor = new RedBlockMonitor();
  Monitor* arm_up_monitor = new ArmMonitor(43 , -1);
  Monitor* arm_down_monitor = new ArmMonitor(0, 1);//ｌここかえてる

  Scene* stop_scene = new Scene(stop_action, nullptr, nullptr);



  return right_turn_scene1;
  
}



//3333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333
Scene* Process::getScenePattern3() {//完成
  //Action* line_trace_right_action = new LineTraceAction(40, 40, 1, 0.165, 0.01, 0.0155);//いいかも
  Action* line_trace_right_action = new LineTraceAction(40, 40, 1, 0.28, 0.01, 0.055);
  Action* line_trace_left_action = new LineTraceAction(40, 40, -1, 0.28, 0.01, 0.055);
  Action* line_trace_right_action2 = new LineTraceAction(60, 60, 1, 0.0966, 0.01, 0.0387);
  Action* stop_action = new WheelAction(0, 0);
  Action* right_turn_action = new WheelAction(-40, 40);
  Action* left_turn_action = new WheelAction(-10, 10);
  Action* left_turn_action2 = new WheelAction(-5, 20);
  Action* right_turn_action2 = new WheelAction(20, -5);
  Action* straight_pwm40_action = new WheelAction(40, 40);
  Action* straight_pwm35_action = new WheelAction(35, 35);
  Action* straight_pwm30_action = new WheelAction(30, 30);
  Action* straight_pwm20_action = new WheelAction(20, 20);
  Action* straight_pwm10_action = new WheelAction(10, 10);
  Action* back_pwm40_action = new WheelAction(-40, -40);
  Action* arm_up_action = new ArmAction(-20);
  Action* arm_down_action = new ArmAction(20);
  Action* arm_stop_action = new ArmAction(0);
  Action* left_curve_action = new WheelAction(50, 0);
  Action* right_curve_action = new WheelAction(0, 50);

  Monitor* red_line_monitor = new RedLineMonitor();
  Monitor* blue_line_monitor = new BlueLineMonitor();
  Monitor* black_line_monitor = new BlackLineMonitor();
  Monitor* yellow_line_monitor = new YellowLineMonitor();
  Monitor* green_line_monitor = new GreenLineMonitor();
  Monitor* red_block_monitor = new RedBlockMonitor();
  Monitor* arm_up_monitor = new ArmMonitor(45 , -1);//45,-1
  Monitor* arm_down_monitor = new ArmMonitor(0, 1);


  Scene* stop_scene = new Scene(stop_action, nullptr, nullptr);
  
  
  Scene* block_scene1 = new Scene(straight_pwm35_action, blue_line_monitor, stop_scene);
  
  Scene* curve_scene5 = new Scene(right_curve_action, new AngleMonitor(-75), block_scene1);
  Scene* line_trace_scene6 = new Scene(line_trace_left_action, yellow_line_monitor, curve_scene5);
  //右上黄右回転
  Scene* straight_scene2 = new Scene(straight_pwm35_action, new DistanceMonitor(90), line_trace_scene6);
  Scene* line_trace_scene5 = new Scene(line_trace_left_action, yellow_line_monitor, straight_scene2);
  //右下黄直進
  Scene* curve_scene4 = new Scene(left_curve_action, new AngleMonitor(75), line_trace_scene5);
  Scene* line_trace_scene4 = new Scene(line_trace_left_action, green_line_monitor, curve_scene4);
  //右上緑左回転
  Scene* curve_scene3 = new Scene(right_curve_action, new AngleMonitor(-75), line_trace_scene4);
  Scene* line_trace_scene3 = new Scene(line_trace_left_action, green_line_monitor, curve_scene3);
  //左上緑右回転
  Scene* curve_scene2 = new Scene(left_curve_action, new AngleMonitor(75), line_trace_scene3);
  Scene* line_trace_scene2 = new Scene(line_trace_left_action, green_line_monitor, curve_scene2);
  //左下緑左回転
  Scene* straight_scene1 = new Scene(straight_pwm35_action, new DistanceMonitor(90), line_trace_scene2);
  Scene* line_trace_scene1 = new Scene(line_trace_left_action, blue_line_monitor, straight_scene1);
  //右下青直進
  Scene* curve_scene1 = new Scene(right_curve_action, new AngleMonitor(-75), line_trace_scene1);
  //左下青右回転
  return curve_scene1;
}







//44444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444
Scene* Process::getScenePattern4() {//完成
 
  Action* arm_up_action = new ArmAction(-20);
  Action* arm_down_action = new ArmAction(20);
  Action* arm_stop_action = new ArmAction(0);

  Monitor* red_line_monitor = new RedLineMonitor();
  Monitor* blue_line_monitor = new BlueLineMonitor();
  Monitor* black_line_monitor = new BlackLineMonitor();
  Monitor* yellow_line_monitor = new YellowLineMonitor();
  Monitor* green_line_monitor = new GreenLineMonitor();
  Monitor* red_block_monitor = new RedBlockMonitor();
  Monitor* arm_up_monitor = new ArmMonitor(43, -1);
  Monitor* arm_down_monitor = new ArmMonitor(0, 1);

  Scene* stop_scene = new Scene(stop_action, nullptr, nullptr);


  
  Scene pattern4_scene = new Scene();
  return pattern4_scene;
}


//5555555555555555555555555555555555555555555555555555555555555555555555//
Scene* Process::getScenePattern5() {
 //Action* line_trace_right_action = new LineTraceAction(40, 40, 1, 0.165, 0.01, 0.0155);//いいかも
  Action* line_trace_right_action = new LineTraceAction(40, 40, 1, 0.28, 0.01, 0.055);
  Action* line_trace_left_action = new LineTraceAction(40, 40, -1, 0.28, 0.01, 0.055);
  Action* line_trace_right_action2 = new LineTraceAction(60, 60, 1, 0.0966, 0.01, 0.0387);
  Action* stop_action = new WheelAction(0, 0);
  Action* right_turn_action = new WheelAction(-40, 40);
  Action* left_turn_action = new WheelAction(-10, 10);
  Action* left_turn_action2 = new WheelAction(-5, 20);
  Action* right_turn_action2 = new WheelAction(20, -5);
  Action* straight_pwm40_action = new WheelAction(40, 40);
  Action* straight_pwm35_action = new WheelAction(35, 35);
  Action* straight_pwm30_action = new WheelAction(30, 30);
  Action* straight_pwm20_action = new WheelAction(20, 20);
  Action* straight_pwm10_action = new WheelAction(10, 10);
  Action* back_pwm40_action = new WheelAction(-40, -40);
  Action* arm_up_action = new ArmAction(-20);
  Action* arm_down_action = new ArmAction(20);
  Action* arm_stop_action = new ArmAction(0);
  Action* left_curve_action = new WheelAction(50, 0);
  Action* right_curve_action = new WheelAction(0, 50);

  Monitor* red_line_monitor = new RedLineMonitor();
  Monitor* blue_line_monitor = new BlueLineMonitor();
  Monitor* black_line_monitor = new BlackLineMonitor();
  Monitor* yellow_line_monitor = new YellowLineMonitor();
  Monitor* green_line_monitor = new GreenLineMonitor();
  Monitor* red_block_monitor = new RedBlockMonitor();
  Monitor* arm_up_monitor = new ArmMonitor(45 , -1);//45,-1
  Monitor* arm_down_monitor = new ArmMonitor(0, 1);


  Scene* stop_scene = new Scene(stop_action, nullptr, nullptr);
  
  
  Scene* block_scene1 = new Scene(straight_pwm35_action, blue_line_monitor, stop_scene);
  
  Scene* straight_scene4 = new Scene(straight_pwm35_action, new DistanceMonitor(90), block_scene1);
  Scene* line_trace_scene6 = new Scene(line_trace_right_action, yellow_line_monitor, straight_scene4);
  //右上黄直進
  Scene* straight_scene3 = new Scene(straight_pwm35_action, new DistanceMonitor(90), line_trace_scene6);
  Scene* line_trace_scene5 = new Scene(line_trace_right_action, yellow_line_monitor, straight_scene3);
  //左上黄直進
  Scene* curve_scene3 = new Scene(right_curve_action, new AngleMonitor(-75), line_trace_scene5);
  Scene* line_trace_scene4 = new Scene(line_trace_right_action, red_line_monitor, curve_scene3);  
  //右上赤右回転
  Scene* straight_scene2 = new Scene(straight_pwm35_action, new DistanceMonitor(90), line_trace_scene4);
  Scene* line_trace_scene3 = new Scene(line_trace_right_action, red_line_monitor, straight_scene2);  
  //右下赤直進
  Scene* curve_scene2 = new Scene(left_curve_action, new AngleMonitor(75), line_trace_scene3);  
  Scene* line_trace_scene2 = new Scene(line_trace_left_action, blue_line_monitor, curve_scene2);
  //右上青左回転
  Scene* curve_scene1 = new Scene(right_curve_action, new AngleMonitor(-75), line_trace_scene2);
  Scene* line_trace_scene1 = new Scene(line_trace_left_action, blue_line_monitor, curve_scene1);
  //左上青右回転
  Scene* straight_scene1 = new Scene(straight_pwm35_action, new DistanceMonitor(90), line_trace_scene1);
  //左下青直進
  return straight_scene1;

}



void Process::setup() {
  // 動作
  //Lcourse...1 | -1 
  //Wheel...right | left
  Action* linetrace_st = new LineTraceAction(60, 60, 1, 0.0986, 0.01, 0.0387);
  Action* linetrace_st_reedge = new LineTraceAction(60, 60, -1, 0.0986, 0.01, 0.0387);
  Action* curve = new LineTraceAction(40, 40, 1, 0.43, 0.01, 0.055);
  Action* curve_reedge = new LineTraceAction(40, 40, -1, 0.43, 0.01, 0.055);
  Action* big = new LineTraceAction(44, 44, -1, 0.18, 0.03, 0.14);
  Action* bigslow = new LineTraceAction(40, 40, -1, 0.18, 0.03, 0.14);
  Action* small = new LineTraceAction(43,43, 1, 0.38, 0.03, 0.12);
  Action* debsma = new LineTraceAction(45, 45, 1, 0.0986, 0.01, 0.0387);
  Action* linetrace_st_50 = new LineTraceAction(50, 50, 1, 0.0986, 0.01, 0.0387);
  
	Action* stop_action = new WheelAction(0, 0);
  
  Action* arm_up_action = new ArmAction(-20);//-10
  Action* arm_down_action = new ArmAction(20);
  Action* arm_stop_action = new ArmAction(0);
  
  Action* Lturn = new WheelAction(40, -40);//angle=+
  Action* Rturn = new WheelAction(-40, 40);//angle=-
  Action* pwm40action = new WheelAction(40, 40);
  Action* pwm45action = new WheelAction(45, 45);
  Action* pwm60action = new WheelAction(60, 60);
  Action* straight_action = new StraightAction(40.0, 40.0);
  Action* straight_action_60 = new StraightAction(60.0, 60.0);
  
  Scene* stop = new Scene(stop_action, nullptr, nullptr);
  // 監視
  Monitor* black_line_monitor = new BlackLineMonitor();
  Monitor* blue_line_monitor = new BlueLineMonitor();
  Monitor* red_line_monitor = new RedLineMonitor();
  Monitor* arm_up_monitor = new ArmMonitor(40, -1);//43,-1
  Monitor* arm_down_monitor = new ArmMonitor(0, 1);//0,1

  
  //deg
  //Scene* deg90_3 = new Scene(edgechange, new AngleMonitor(-70), stop_scene);
  //Scene* deg90_2 = new Scene(pwm45action, new DistanceMonitor(1000), deg90_3);
  //Scene* deg90_1 = new Scene(linetrace_loop, new DistanceMonitor(500), deg90_2);
  //straight
  //Scene* straight_3 = new Scene(edgechange, new AngleMonitor(-50), stop_scene);
  //Scene* straight_2 = new Scene(pwm50action, new DistanceMonitor(700), stop_scene);
  //Scene* straight_1 = new Scene(linetrace_loop, new DistanceMonitor(200), straight_2);
  
  //test_blueline
  //Scene* smallloop = new Scene(small, new DistanceMonitor(2300), stop_scene);
  //Scene* smallloopEntry = new Scene(Lturn, new AngleMonitor(10), smallloop);
  //Scene* bigloop = new Scene(big, new DistanceMonitor(1800), smallloopEntry);
  //Scene* bigloopEntry4 = new Scene(Rturn, new AngleMonitor(-10), bigloop);
  //Scene* bigloopEntry3 = new Scene(big, new DistanceMonitor(180), bigloopEntry4);//
  //Scene* bigloopEntry2 = new Scene(big, black_line_monitor, bigloopEntry3);
  //Scene* bigloopEntry1 = new Scene(linetrace_st_50, blue_line_monitor, bigloopEntry2);
  //Scene* straight3 = new Scene(linetrace_st, new DistanceMonitor(600), bigloopEntry1);
  //Scene* curve2 = new Scene(curve, new AngleMonitor(-70), straight3);
  //Scene* straight2 = new Scene(linetrace_st, new DistanceMonitor(1700), curve2);
  //Scene* curve1 = new Scene(curve, new AngleMonitor(-70), straight2);
  //Scene* start_B = new Scene(linetrace_st, new DistanceMonitor(2750), curve1);
  //scene_ = bigloopEntry2;
  
  //test_distance
  //Scene* smallloop = new Scene(small, new DistanceMonitor(2500), stop);
  //Scene* smallloopEntry = new Scene(Lturn, new AngleMonitor(10), smallloop);
  //Scene* bigloop = new Scene(big, new DistanceMonitor(1700), smallloopEntry);
  //Scene* bigloopEntry3 = new Scene(bigslow, new DistanceMonitor(100), bigloop);
  //Scene* bigloopEntry2 = new Scene(Rturn, new AngleMonitor(-1), bigloopEntry3);
  //Scene* bigloopEntry1 = new Scene(linetrace_st_50, new DistanceMonitor(720), bigloopEntry2);
  //Scene* straight3 = new Scene(linetrace_st, new DistanceMonitor(300), bigloopEntry1);//stop
  //Scene* curve2 = new Scene(curve, new AngleMonitor(-70), straight3);
  //Scene* straight2 = new Scene(linetrace_st, new DistanceMonitor(1700), curve2);
  //Scene* curve1 = new Scene(curve, new AngleMonitor(-70), straight2);
  //Scene* start_D = new Scene(linetrace_st, new DistanceMonitor(2750), curve1);
  
  //scene_ = start_D;//start_D or start_B
  
  //test_utigawa
  Scene* straight3 = new Scene(linetrace_st_reedge, new DistanceMonitor(1000), stop);
  Scene* curve2 = new Scene(curve_reedge, new AngleMonitor(-70), straight3);
  Scene* straight2_3 = new Scene(linetrace_st_reedge, new DistanceMonitor(770), curve2);
  Scene* straight2_2 = new Scene(straight_action_60, new DistanceMonitor(380), straight2_3);
  Scene* straight2_1 = new Scene(linetrace_st_reedge, new DistanceMonitor(550), straight2_2);
  Scene* curve1 = new Scene(curve_reedge, new AngleMonitor(-70), straight2_1);
  Scene* start_U = new Scene(linetrace_st_reedge, new DistanceMonitor(2700), curve1);
  //scene_ = start_U;
  
  Scene* straight_scene = new Scene(straight_action_60, new DistanceMonitor(800), stop);
  Scene* blue_blue = new Scene(debsma, new DistanceMonitor(180), straight_scene);
  Scene* curve_blue = new Scene(Rturn, new AngleMonitor(-70), blue_blue);
  Scene* blue_curve = new Scene(debsma, new DistanceMonitor(230), curve_blue);
  Scene* red_blue = new Scene(straight_action, new DistanceMonitor(100), blue_curve);
  Scene* blue_red = new Scene(debsma, red_line_monitor, red_blue);//new DistanceMonitor(180)
  //scene_ = blue_red;
  
  Scene* block_scene = new Scene(debsma, new DistanceMonitor(200), stop);getScenePattern4()
  scene_ = block_scene
  
  //Scene* test = new Scene(straight_action, new DistanceMonitor(800), stop);
  //scene_ = test;
}
