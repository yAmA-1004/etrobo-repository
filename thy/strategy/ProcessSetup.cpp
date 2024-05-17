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
 	Action* line_trace_right_action = new LineTraceAction(63, 63, 1, 0.0966, 0.01, 0.0387);//直線GPT これつかえばよいのでは
  Action* line_trace_right_action2 = new LineTraceAction(25, 25, 1, 0.15, 0.75, 0.015);

	Action* line_trace_left_action = new LineTraceAction(63, 63, -1, 0.0966, 0.01, 0.0387);
	Action* line_trace_left_action2 = new LineTraceAction(25, 25, -1, 0.15, 0.75, 0.015);
	Action* line_trace_rightcurve_action = new LineTraceAction(50, 50, 1, 0.45, 0.01, 0.055);//右ライントレースカーブgptゴールまでだけ

	Action* line_trace_superslowsmallloop_action = new LineTraceAction(15, 15, -1, 0.15, 0.75, 0.0015);//小円　右
	Action* straight_pwm20_action = new WheelAction(20, 20);
	Action* straight_pwm40_action = new WheelAction(40, 40);
	Action* right_turn_action = new WheelAction(5, -5);
	Action* left_turn_action = new WheelAction(-5, 5);
	Action* kirikae_action = new WheelAction(20, 16);
	Action* kirikae_action2 = new WheelAction(4, 20);
	Action* stop_action = new WheelAction(0, 0);
	// Action* arm_up_action = new ArmAction(10);
	// Action* arm_down_action = new ArmAction(-10);
  

  // 監視
  Monitor* black_line_monitor = new BlackLineMonitor();
  Monitor* blue_line_monitor = new BlueLineMonitor();
  Monitor* red_line_monitor = new RedLineMonitor();

  // シーン
  Scene* stop_scene = new Scene(stop_action, nullptr, nullptr);
	// Scene* curve_scene = new Scene(,new DistanceMonitor(),stop_scene)
  Scene* start_scene = new Scene(line_trace_right_action, new DistanceMonitor(2000), stop_scene);//直線//uchi
  // 開始シーン
  // scene_ = block_entry_scene;
  // ブロックdeトレジャーから始める場合
  scene_ = start_scene;
}
