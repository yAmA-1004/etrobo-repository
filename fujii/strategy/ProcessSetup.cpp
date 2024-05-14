#include "Process.h"
#include "WheelAction.h"
#include "LineTraceAction.h"
#include "ArmAction.h"
#include "DistanceMonitor.h"
#include "BlackLineMonitor.h"
#include "BlueLineMonitor.h"
#include "ArmMonitor.h"
#include "AngleMonitor.h"

void Process::setup() {
  // 動作
  Action* line_trace_right_action = new LineTraceAction(60, 60, 1, 0.83, 0.1, 0.36);
  Action* line_trace_left_action = new LineTraceAction(60, 60, -1, 0.83, 0.1, 0.36);
  // Action* straight_pwm20_action = new WheelAction(20, 20);
  // Action* straight_pwm40_action = new WheelAction(40, 40);
  // Action* right_turn_action = new WheelAction(5, -5);
  // Action* left_turn_action = new WheelAction(-5, 5);
  Action* stop_action = new WheelAction(0, 0);
  // Action* arm_up_action = new ArmAction(10);
  // Action* arm_down_action = new ArmAction(-10);

  // 監視
  // Monitor* arm_up_monitor = new ArmMonitor(50, -1);
  // Monitor* arm_down_monitor = new ArmMonitor(0, 1);
  Monitor* black_line_monitor = new BlackLineMonitor();
  Monitor* blue_line_monitor = new BlueLineMonitor();

  // シーン
  // Scene* arm_down_scene = new Scene(arm_down_action, arm_down_monitor, line_trace_scene);
  // Scene* arm_up_scene = new Scene(arm_up_action, arm_up_monitor, arm_down_scene);

  Scene* stop_scene = new Scene(stop_action, nullptr, nullptr);
  Scene* big_loop_scene4 = new Scene(line_trace_right_action, new AngleMonitor(180, -1), stop_scene);
  Scene* small_loop_scene2 = new Scene(line_trace_right_action, black_line_monitor, big_loop_scene4);
  Scene* small_loop_scene1 = new Scene(line_trace_left_action, blue_line_monitor, small_loop_scene2);
  // Scene* black_search_scene1 = new Scene(straight_pwm20_action, black_line_monitor, small_loop_scene);
  // Scene* straight_scene1 = new Scene(straight_pwm20_action, new DistanceMonitor(300, -1), black_search_scene1);
  Scene* big_loop_scene3 = new Scene(line_trace_left_action, black_line_monitor, small_loop_scene1);
  Scene* big_loop_scene2 = new Scene(line_trace_right_action, blue_line_monitor, big_loop_scene3);
  Scene* big_loop_scene1 = new Scene(line_trace_right_action, black_line_monitor, big_loop_scene2);
  Scene* entry_scene = new Scene(line_trace_right_action, blue_line_monitor, big_loop_scene1);

  // 開始シーン
  scene_ = entry_scene;
}
