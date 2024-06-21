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
  //Action* line_trace_right_action = new LineTraceAction(63, 63, -1, 0.0966, 0.01, 0.0387);
  //Action* line_trace_right_action = new LineTraceAction(63, 63, -1, 0.0966, 0.0082, 0.0245);
  
  //Action* line_trace_right_action_4 = new LineTraceAction(67, 67, -1, 0.0921, 0.01, 0.055);//second_straight
  //Action* line_trace_right_action_2 = new LineTraceAction(50, 50, -1, 0.60, 0.01, 0.055);//curve~second_straight
  //Action* line_trace_right_action_3 = new LineTraceAction(46, 46, -1, 0.50, 0.0082, 0.029);//double_loop
  //Action* line_trace_right_action_3_reedge = new LineTraceAction(46, 46, 1, 0.50, 0.0082, 0.029);//double_loop

  //test 1migi -1hidari
  Action* line_trace_right_action = new LineTraceAction(65, 65, 1, 0.0966, 0.01, 0.0387);
  Action* line_trace_right_action_2 = new LineTraceAction(50, 50, 1, 0.60, 0.01, 0.055);
  Action* line_trace_right_curve_action = new LineTraceAction(45, 45, 1, 0.4, 0.01, 0.055);
  Action* DoubleLoopAction = new LineTraceAction(46, 46, -1, 0.50, 0.0082, 0.029);
  Action* DoubleLoopAction_reedge = new LineTraceAction(46, 46, 1, 0.50, 0.0082, 0.029);

  
  //Action* line_trace_right_curve_action = new LineTraceAction(45, 45, -1, 0.4, 0.01, 0.055);//P0.5?
  //Action* straight_pwm50_action = new WheelAction(50, 50);    
  
  Action* pwm45action = new WheelAction(45,45);
  Action* right_turn_action = new WheelAction(55, 25);
  Action* left_turn_action = new WheelAction(25, 55);
  Action* stop_action = new WheelAction(0, 0);
  Action* arm_up_action = new ArmAction(-20);
  Action* arm_down_action = new ArmAction(20);
  Action* arm_stop_action = new ArmAction(0);

  

  // 監視
  Monitor* blue_line_monitor = new BlueLineMonitor();
  Monitor* black_line_monitor = new BlackLineMonitor();
  Monitor* arm_up_monitor = new ArmMonitor(40 , -1);
  Monitor* arm_down_monitor = new ArmMonitor(0, 1);
    Scene* stop_scene = new Scene(stop_action, nullptr, nullptr);
  
  //test1
  //double_loop
  //Scene* big_loop_entry_scene_2 = new Scene(left_turn_action, new DistanceMonitor(100), stop_scene);
  //Scene* small_loop_scene_1_2 = new Scene(line_trace_right_action_3_reedge, black_line_monitor, big_loop_entry_scene_2);  
  //Scene* small_loop_scene_1_1 = new Scene(line_trace_right_action_3_reedge, blue_line_monitor, small_loop_scene_1_2);
  //Scene* small_loop_entry_scene = new Scene(right_turn_action, new DistanceMonitor(200), small_loop_scene_1_1);
  //Scene* big_loop_scene_1_2 = new Scene(line_trace_right_action_3, black_line_monitor, small_loop_entry_scene);
  //Scene* big_loop_scene_1_1 = new Scene(line_trace_right_action_3, blue_line_monitor, big_loop_scene_1_2);
  //Scene* big_loop_entry_scene_1 = new Scene(left_turn_action, new DistanceMonitor(50), big_loop_scene_1_1);
  //sitanotukau
  //Scene* last_scene = new Scene(line_trace_right_action_3_reedge, blue_line_monitor, stop_scene);
  //Scene* big_loop_scene_2 = new Scene(line_trace_right_action_3_reedge, new DistanceMonitor(1900), last_scene);
  //Scene* big_loop_entry_scene_2 = new Scene(left_turn_action, new DistanceMonitor(50), big_loop_scene_2);
  //Scene* small_loop_scene_1_1 = new Scene(line_trace_right_action_3_reedge, new DistanceMonitor(2900), big_loop_entry_scene_2);
  //Scene* small_loop_entry_scene = new Scene(right_turn_action, new DistanceMonitor(150), small_loop_scene_1_1);
  //Scene* big_loop_scene_1_1 = new Scene(line_trace_right_action_3, new DistanceMonitor(2170), small_loop_entry_scene);
  //Scene* big_loop_entry_scene_1 = new Scene(left_turn_action, new DistanceMonitor(50), big_loop_scene_1_1);
  
  //start~lap
  //Scene* straight_scene_3_3 = new Scene(line_trace_right_action, black_line_monitor, big_loop_entry_scene_1);
  //Scene* straight_scene_3_2 = new Scene(line_trace_right_action, blue_line_monitor, straight_scene_3_3);
  //Scene* straight_scene_3_1 = new Scene(line_trace_right_action_2, new DistanceMonitor(100), straight_scene_3_2);//third_straight
  //Scene* curve_scene_2 = new Scene(line_trace_right_curve_action, new AngleMonitor(-50), straight_scene_3_1);//second_curve
  //Scene* straight_scene_2_2 = new Scene(line_trace_right_action_4, new DistanceMonitor(2020), curve_scene_2);//second_straight
  //Scene* straight_scene_2_1 = new Scene(line_trace_right_action_2, new DistanceMonitor(80), straight_scene_2_2);//second_straight
  
  //test2
  //DoubleLoop
  Scene* block_entry = new Scene(line_trace_right_action, blue_line_monitor, stop_scene);
  Scene* straight_scene_4 = new Scene(line_trace_right_action, black_line_monitor, block_entry);
  Scene* big_loop_2 = new Scene(DoubleLoopAction_reedge, blue_line_monitor, straight_scene_4);
  Scene* big_loop_entry = new Scene(pwm45action, new DistanceMonitor(50), big_loop_2);
  Scene* small_loop = new Scene(DoubleLoopAction_reedge, new DistanceMonitor(3000), stop_scene);
  Scene* small_loop_entry = new Scene(right_turn_action, new AngleMonitor(10), small_loop);
  Scene* big_loop = new Scene(DoubleLoopAction, new DistanceMonitor(2100), stop_scene);
  Scene* double_loop_entry = new Scene(left_turn_action, new AngleMonitor(-20), big_loop);
  //Lap
  Scene* straight_scene_3_2 = new Scene(line_trace_right_action, new DistanceMonitor(1030), double_loop_entry);
  Scene* straight_scene_3_1 = new Scene(line_trace_right_action_2, new DistanceMonitor(100), straight_scene_3_2);
  Scene* curve_scene_2 = new Scene(line_trace_right_curve_action, new AngleMonitor(-60), straight_scene_3_1);
  Scene* straight_scene_2_2 = new Scene(line_trace_right_action, new DistanceMonitor(1980), curve_scene_2);
  Scene* straight_scene_2_1 = new Scene(line_trace_right_action_2, new DistanceMonitor(100), straight_scene_2_2);
  Scene* curve_scene_1 = new Scene(line_trace_right_curve_action, new AngleMonitor(-60), straight_scene_2_1);//first_curve
	Scene* start_scene = new Scene(line_trace_right_action, new DistanceMonitor(3200), curve_scene_1);//first_straight
  
  //test3
  //DoubleLoop
  //Scene* block_entry = new Scene(line_trace_right_action, blue_line_monitor, stop_scene);
  //Scene* straight_scene_4 = new Scene(line_trace_right_action, black_line_monitor, block_entry);
  //Scene* big_loop_2 = new Scene(DoubleLoopAction_reedge, blue_line_monitor, straight_scene_4);
  //Scene* big_loop_entry = new Scene(pwm45action, new DistanceMonitor(50), big_loop_2);
  //Scene* small_loop = new Scene(DoubleLoopAction_reedge, new DistanceMonitor(3000), stop_scene);
  //Scene* small_loop_entry = new Scene(right_turn_action, new AngleMonitor(17), small_loop);
  //Scene* big_loop = new Scene(DoubleLoopAction, new DistanceMonitor(2005), small_loop_entry);
  //Scene* double_loop_entry = new Scene(left_turn_action, new AngleMonitor(-20), big_loop);
  //Lap
  //Scene* straight_scene_3_4 = new Scene(line_trace_right_action, black_line_monitor, double_loop_entry);
  //Scene* straight_scene_3_3 = new Scene(line_trace_right_action, blue_line_monitor, stop_scene);
  //Scene* straight_scene_3_2 = new Scene(line_trace_right_action, new DistanceMonitor(600), straight_scene_3_3);
  //Scene* straight_scene_3_1 = new Scene(line_trace_right_action_2, new DistanceMonitor(100), straight_scene_3_2);
  //Scene* curve_scene_2 = new Scene(line_trace_right_curve_action, new AngleMonitor(-60), straight_scene_3_1);
  //Scene* straight_scene_2_2 = new Scene(line_trace_right_action, new DistanceMonitor(1980), curve_scene_2);
  //Scene* straight_scene_2_1 = new Scene(line_trace_right_action_2, new DistanceMonitor(100), straight_scene_2_2);
  //Scene* curve_scene_1 = new Scene(line_trace_right_curve_action, new AngleMonitor(-60), straight_scene_2_1);//first_curve
	//Scene* start_scene = new Scene(line_trace_right_action, new DistanceMonitor(3200), curve_scene_1);//first_straight
  //Scene* start_scene = new Scene(stop_action, color_monitor, nullptr);
  //開始シーン
  scene_ = start_scene;
  //if double_loop_start
  //scene_ = straight_scene_3_2;
  //ブロックdeトレジャーから始める場合
  //scene_ = block_entry_scene;
}
