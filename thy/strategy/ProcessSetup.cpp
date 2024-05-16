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
  Action* line_trace_curve_action = new LineTraceAction(25, 25, 1, 0.15, 0.75, 0.015);

  // 監視
  Monitor* black_line_monitor = new BlackLineMonitor();
  Monitor* blue_line_monitor = new BlueLineMonitor();
  Monitor* red_line_monitor = new RedLineMonitor();

  // シーン
  Scene* stop_scene = new Scene(stop_action, nullptr, nullptr);
	// Scene* curve_scene = new Scene(line_trace_curve_action,new DistanceMonitor(2500),stop_scene)
  Scene* start_scene = new Scene(line_trace_right_action, new DistanceMonitor(2000), stop_scene);
  // 開始シーン
  // scene_ = block_entry_scene;
  // ブロックdeトレジャーから始める場合
  scene_ = start_scene;
}
