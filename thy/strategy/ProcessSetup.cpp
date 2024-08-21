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


void Process::setup() {
  // 動作
 	Action* line_trace_right_action = new LineTraceAction(70, 70, 1, 0.09505, 0.03, 0.0387);//直線GPT これつかえばよいのでは
  Action* line_trace_right_action2 = new LineTraceAction(40, 34, 1, 0.1, 0.75, 0.015);
  Action* line_trace_right_action3 = new LineTraceAction(30, -30, 1, 0, 0, 0);
  Action* line_trace_right_action4 = new LineTraceAction(42, 42, 1, 0.3, 0.01, 0.055);//0.28
  Action* line_trace_right_action5 = new LineTraceAction(45, 45, 1, 0.62, 0.007, 0.065);//0.42
  Action* line_trace_right_action6 = new LineTraceAction(70, 70, 1, 0.15, 0.01, 0.0387);
  Action* line_trace_right_action7 = new LineTraceAction(67, 67, 1, 0.0986, 0.01, 0.0387);//0.0586
  Action* line_trace_right_action8 = new LineTraceAction(63, 63, 1, 0.092, 0.01, 0.055);
  Action* line_trace_right_action9 = new LineTraceAction(42, 42, 1, 0.052, 0.01, 0.055);
  //Action* line_trace_right_action7 = new LineTraceAction(63, 63, -1, 0.0726, 0.01, 0.0667);//0.14325
	Action* line_trace_left_action = new LineTraceAction(63, 63, -1, 0.0966, 0.01, 0.0387);//63,63,-1,0.0966,0.01,0.0387
	Action* line_trace_left_action2 = new LineTraceAction(25, 25, -1, 0.15, 0.75, 0.015);
  Action* line_trace_left_action3 = new LineTraceAction(50, 50, -1, 0.052, 0.01, 0.055);//50,50
  Action* line_trace_left_action4 = new LineTraceAction(40, 40, -1, 0.052, 0.01, 0.055);
	Action* line_trace_rightcurve_action = new LineTraceAction(50, 50, 1, 0.43, 0.01, 0.055);//右ライントレースカーブgptゴールまでだけ
  //難所
	Action* line_trace_rightloop_action = new LineTraceAction(45, 45, -1, 0.2, 0.075, 0.18);//大円　gptの値　右 0.4,0.005,0.1   P:0.28
	Action* line_trace_rightloop_action2 = new LineTraceAction(40, 40, -1, 0.3, 0.05, 0.1);//0.25
  Action* line_trace_rightloop_action3 = new LineTraceAction(40, 50, -1, 0.3, 0.75, 0.015);//40,40
  Action* line_trace_leftloop_action = new LineTraceAction(40, 40, 1, 0.5, 0.0082, 0.055);//大円　左ライントレース
	Action* line_trace_leftloop_action2 = new LineTraceAction(45, 45, 1, 0.6, 0.006, 0.07);//0.6
  Action* line_trace_leftloop_action3 = new LineTraceAction(40, 40, 1, 0.4, 0.006, 0.07);
  Action* line_trace_leftloop_action4 = new LineTraceAction(30, 30, 1, 0.28, 0.03, 0.12);//43
  //Action* line_trace_leftloop_action5 = new LineTraceAction(45, 45, 1, 0.28, 0.075, 0.18);
  Action* line_trace_leftloop_action6 = new LineTraceAction(35, 35, 1, 0.38, 0.075, 0.18);
  Action* line_trace_rightloopslow_action = new LineTraceAction(15, 15, 1, 0.15, 0.75, 0.015);//ゆっくり右
	Action* line_trace_leftloopslow_action = new LineTraceAction(15, 15, -1, 0.15, 0.75, 0.015);//ゆっくり左
	Action* line_trace_smallloop_action = new LineTraceAction(20, 20, -1, 0.12, 0.01, 0.02);//小円　右 nazo
	Action* line_trace_superslowsmallloop_action = new LineTraceAction(15, 15, -1, 0.15, 0.75, 0.0015);//小円　右
	Action* straight_pwm30_action = new WheelAction(30, 30);
	Action* straight_pwm40_action = new WheelAction(40, 40);
  Action* straight_pwm50_action = new WheelAction(50, 50);
	Action* right_turn_action = new WheelAction(45, -45);
	Action* left_turn_action = new WheelAction(-45, 45);
	Action* kirikae_action = new WheelAction(56, 36);
	Action* kirikae_action2 = new WheelAction(65, 30);
  Action* kirikae_action3 = new WheelAction(36, 56);//migi,hidari
  Action* kirikae_action4 = new WheelAction(30, 75);
	Action* stop_action = new WheelAction(0, 0);
  Action* arm_up_action = new ArmAction(-20);//-10
  Action* arm_down_action = new ArmAction(20);
  Action* arm_stop_action = new ArmAction(0);
  Action* back_pwm30_action = new WheelAction(-30, -30);
  Action* shortcut_action = new WheelAction(42, 62);//30,50 29,50
	// Action* arm_up_action = new ArmAction(10);
	// Action* arm_down_action = new ArmAction(-10);
  
  //test
  Action* edgechange = new WheelAction(35, -35);
  Action* linetrace_loop = new LineTraceAction(45, 45, 1, 0.0986, 0.03, 0.0387);
  Action* pwm40action = new WheelAction(40, 40);
  Action* pwm45action = new WheelAction(45, 45);
  Action* pwm50action = new WheelAction(60, 60);
  
  Scene* stop_scene = new Scene(stop_action, nullptr, nullptr);
  // 監視
  Monitor* black_line_monitor = new BlackLineMonitor();
  Monitor* blue_line_monitor = new BlueLineMonitor();
  Monitor* arm_up_monitor = new ArmMonitor(40 , -1);//43,-1
  Monitor* arm_down_monitor = new ArmMonitor(0, 1);//0,1
  // シーン
  //Scene* block_entry_scene = new Scene(line_trace_left_action4, blue_line_monitor, getScenePattern1());
  // ↑new Sceneの第３引数にパターンに応じてgetScenePattern1～5を指定
  //Scene* loop_scene12 = new Scene(straight_pwm40_action, blue_line_monitor, stop_scene);
  //Scene* loop_scene11 = new Scene(straight_pwm40_action, new DistanceMonitor(300), loop_scene12);
  //Scene* loop_scene10 = new Scene(line_trace_leftloop_action4, new DistanceMonitor(40), loop_scene11);
  //直線走行
  //Scene* loop_scene12 = new Scene(kirikae_action3, new AngleMonitor(-20), stop_scene);
  //Scene* loop_scene11 = new Scene(line_trace_leftloop_action4, new DistanceMonitor(140), loop_scene12);
  //Scene* loop_scene10 = new Scene(line_trace_leftloop_action4, black_line_monitor, loop_scene11);
  //外側ライントレース
  //Scene* loop_scene21 = new Scene(line_trace_left_action3, blue_line_monitor, block_entry_scene);
  Scene* loop_scene18 = new Scene(line_trace_left_action3, new DistanceMonitor(400), stop_scene);
  //Scene* loop_scene19 = new Scene(line_trace_rightloop_action, new DistanceMonitor(100), loop_scene20);
  Scene* loop_scene17 = new Scene(kirikae_action, new AngleMonitor(7), loop_scene18);
  Scene* loop_scene16 = new Scene(line_trace_rightloop_action, new DistanceMonitor(160), loop_scene17);
  Scene* loop_scene15 = new Scene(line_trace_rightloop_action, black_line_monitor, loop_scene16);
  Scene* loop_scene14 = new Scene(line_trace_rightloop_action, blue_line_monitor, loop_scene15);
  Scene* loop_scene13 = new Scene(line_trace_rightloop_action, new DistanceMonitor(450), loop_scene14);
  Scene* loop_scene12 = new Scene(line_trace_rightloop_action3, new DistanceMonitor(50), loop_scene13);
  Scene* loop_scene11 = new Scene(line_trace_leftloop_action4, new DistanceMonitor(40), loop_scene12);
  Scene* loop_scene10 = new Scene(line_trace_leftloop_action4, black_line_monitor, loop_scene11);
  //内側ライントレース
  
  //deg
  Scene* deg90_3 = new Scene(edgechange, new AngleMonitor(-70), stop_scene);
  Scene* deg90_2 = new Scene(pwm45action, new DistanceMonitor(1000), deg90_3);
  Scene* deg90_1 = new Scene(linetrace_loop, new DistanceMonitor(500), deg90_2);
  //straight
  Scene* straight_3 = new Scene(edgechange, new AngleMonitor(-50), stop_scene);
  Scene* straight_2 = new Scene(pwm50action, new DistanceMonitor(700), stop_scene);
  Scene* straight_1 = new Scene(linetrace_loop, new DistanceMonitor(200), straight_2);
  
  Scene* loop_scene9 = new Scene(line_trace_leftloop_action4, blue_line_monitor, straight_1);
  Scene* loop_scene6 = new Scene(line_trace_leftloop_action3, new DistanceMonitor(1400), loop_scene9);
  Scene* loop_scene5 = new Scene(kirikae_action2, new AngleMonitor(18), loop_scene6);//楕円進入
  Scene* loop_scene4 = new Scene(line_trace_rightloop_action2, new DistanceMonitor(50), loop_scene5);
  Scene* loop_scene3 = new Scene(line_trace_rightloop_action2, black_line_monitor, loop_scene4);
  Scene* loop_scene2 = new Scene(line_trace_rightloop_action2, blue_line_monitor, loop_scene3);
  Scene* loop_scene = new Scene(line_trace_rightloop_action, new DistanceMonitor(1500), loop_scene2);
  Scene* loop_entry_scene3 = new Scene(kirikae_action3, new AngleMonitor(-20), loop_scene);//円進入 試走会:-30
  Scene* loop_entry_scene2 = new Scene(line_trace_right_action9, new DistanceMonitor(50), loop_entry_scene3);//80  試走会:50
  Scene* loop_entry_scene = new Scene(line_trace_right_action4, black_line_monitor, loop_entry_scene2);//210
  Scene* line_trace_scene4 = new Scene(line_trace_right_action4, blue_line_monitor, loop_entry_scene);
  Scene* line_trace_scene3 = new Scene(line_trace_right_action7, new DistanceMonitor(390), line_trace_scene4);
  Scene* curve_after_scene2 = new Scene(line_trace_right_action5, new DistanceMonitor(70), line_trace_scene3);
  Scene* curve_scene2 = new Scene(line_trace_right_action5, new AngleMonitor(-75), curve_after_scene2);
  Scene* straight_scene = new Scene(line_trace_right_action7, new DistanceMonitor(1550), curve_scene2);//1570
  Scene* curve_after_scene1 = new Scene(line_trace_right_action5, new DistanceMonitor(70), straight_scene);
  Scene* curve_scene1 = new Scene(line_trace_right_action5, new AngleMonitor(-70), curve_after_scene1);
  Scene* start_scene = new Scene(line_trace_right_action7, new DistanceMonitor(2750), curve_scene1);//2730
  //korehaorpokqkunnninnuou
  //Scene* RGB_scene = new Scene(stop_action, new DistanceMonitor(9999), stop_scene);//2730
  //Scene* arm_stop_scene = new Scene(arm_stop_action, nullptr, stop_scene);
  //Scene* arm_down_scene = new Scene(arm_down_action, arm_down_monitor, arm_stop_scene);
  //Scene* arm_up_scene = new Scene(arm_up_action, arm_up_monitor, arm_down_scene);
  //Scene* start_scene1 = new Scene(stop_action, blue_line_monitor, arm_up_scene);//直線//uchi
  // 開始シーン
  //scene_ = block_entry_scene;
  // ブロックdeトレジャーから始める場合
  //scene_ = start_scene;
  //scene_ = line_trace_scene3;
  //scene_ = arm_down_scene;
  //scene_ = RGB_scene;
  scene_ = loop_scene9;
}
