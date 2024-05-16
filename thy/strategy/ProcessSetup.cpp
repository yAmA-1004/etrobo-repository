#include "Process.h"
#include "WheelAction.h"
#include "LineTraceAction.h"
#include "ArmAction.h"
#include "DistanceMonitor.h"
#include "BlackLineMonitor.h"
#include "BlueLineMonitor.h"
#include "ArmMonitor.h"
#include "AngleMonitor.h"

// void Process::setup() {
//   // 動作
//  	Action* line_trace_right_action = new LineTraceAction(63, 63, 1, 0.0966, 0.01, 0.0387);//直線GPT これつかえばよいのでは
//   Action* line_trace_right_action2 = new LineTraceAction(25, 25, 1, 0.15, 0.75, 0.015);

// 	Action* line_trace_left_action = new LineTraceAction(63, 63, -1, 0.0966, 0.01, 0.0387);
// 	Action* line_trace_left_action2 = new LineTraceAction(25, 25, -1, 0.15, 0.75, 0.015);
// 	Action* line_trace_rightcurve_action = new LineTraceAction(50, 50, 1, 0.45, 0.01, 0.055);//右ライントレースカーブgptゴールまでだけ
//   // ダブルループNEO
// 	Action* line_trace_rightloop_action = new LineTraceAction(30, 30, 1, 0.15, 0.75, 0.015);//大円　gptの値　右
// 	Action* line_trace_leftloop_action = new LineTraceAction(30, 30, -1, 0.15, 0.75, 0.015);//大円　左ライントレース
// 	Action* line_trace_rightloopslow_action = new LineTraceAction(15, 15, 1, 0.15, 0.75, 0.015);//ゆっくり右
// 	Action* line_trace_leftloopslow_action = new LineTraceAction(15, 15, -1, 0.15, 0.75, 0.015);//ゆっくり左
// 	Action* line_trace_smallloop_action = new LineTraceAction(20, 20, -1, 0.12, 0.01, 0.02);//小円　右 nazo

// 	Action* line_trace_superslowsmallloop_action = new LineTraceAction(15, 15, -1, 0.15, 0.75, 0.0015);//小円　右
// 	Action* straight_pwm20_action = new WheelAction(20, 20);
// 	Action* straight_pwm40_action = new WheelAction(40, 40);
// 	Action* right_turn_action = new WheelAction(5, -5);
// 	Action* left_turn_action = new WheelAction(-5, 5);
// 	Action* kirikae_action = new WheelAction(20, 16);
// 	Action* kirikae_action2 = new WheelAction(4, 20);
// 	Action* stop_action = new WheelAction(0, 0);
// 	// Action* arm_up_action = new ArmAction(10);
// 	// Action* arm_down_action = new ArmAction(-10);
//   Scene* stop_scene = new Scene(stop_action, nullptr, nullptr);

//   // 監視
//   Monitor* black_line_monitor = new BlackLineMonitor();
//   Monitor* blue_line_monitor = new BlueLineMonitor();
//   Monitor* red_line_monitor = new RedLineMonitor();

//   // シーン
//   Scene* block_entry_scene = new Scene(line_trace_right_action2, red_line_monitor, getScenePattern3());
//   // ↑new Sceneの第３引数にパターンに応じてgetScenePattern1～5を指定

//   Scene* right_turn_scene = new Scene(right_turn_action, new AngleMonitor(75), block_entry_scene);//ここでライントレースに戻る
// 	Scene* straight_scene3 = new Scene(straight_pwm20_action, black_line_monitor, right_turn_scene);
// 	Scene* straight_scene2 = new Scene(straight_pwm20_action, new DistanceMonitor(30), straight_scene3);
// 	Scene* straight_scene1 = new Scene(straight_pwm20_action, black_line_monitor, straight_scene2);
//   Scene* straight_hosei = new Scene(straight_pwm20_action, new DistanceMonitor(20), straight_scene1);
// 	Scene* left_turn_scene = new Scene(left_turn_action, new AngleMonitor(-75), straight_scene1);//180度回った後
// 	//抜け出し
// 	Scene* big_loop_scene3 = new Scene(line_trace_rightloopslow_action, new AngleMonitor(165), left_turn_scene);//4ゲート通過まで//ここがうまくいかない
// 	// Scene* turn_scene3 = new Scene(straight_pwm20_action, new DistanceMonitor(50) , big_loop_scene3);//エッジを切り替える時に切り替えやすいように試験
// 	Scene* small_loop_scene3 = new Scene(line_trace_rightloopslow_action, black_line_monitor, big_loop_scene3);//小円あとの青 kokohaii
// 	Scene* small_loop_scene2 = new Scene(line_trace_smallloop_action, blue_line_monitor, small_loop_scene3);//交差部から小円
// 	Scene* small_loop_scene1 = new Scene(line_trace_smallloop_action, new DistanceMonitor(50), small_loop_scene2);//紙だと内側にずれる試走会でもずれるなら検討
//   //下のやつがうまくいったとして

  
//   //----------------ライントレースver
// 	// Scene* chousei_scene2 = new Scene(left_turn_action,  new AngleMonitor(30), stop_scene);//うまく実装出来たら
// 	Scene* chousei_scene1 = new Scene(straight_pwm20_action, black_line_monitor, small_loop_scene1);//今ループにいなかったら黒を見つけに行く
// 	Scene* cross_scene1 = new Scene(line_trace_smallloop_action, black_line_monitor, chousei_scene1);//交差の黒
// 	Scene* big_loop_scene2 = new Scene(line_trace_leftloop_action, blue_line_monitor, cross_scene1);//ここが青見たら外はしる
// 	Scene* big_loop_scene1 = new Scene(line_trace_rightloop_action, black_line_monitor, big_loop_scene2);
// 	//------------------------
// //ここからダブルループ


//   // Scene* curve_scene2 = new Scene(kyokuritu_lap_action2, new DistanceMonitor(500), big_loop_entry_scene);
//   // Scene* straightlap = new Scene(line_trace_left_action, new DistanceMonitor(1500), curve_scene2);
//   // Scene* curve_scene = new Scene(kyokuritu_lap_action, new DistanceMonitor(500), straightlap);
//   //^^^^^^^^^^^^全国こんなかんじかな
// 	Scene* big_loop_entry_scene = new Scene(line_trace_right_action, blue_line_monitor, big_loop_scene1);//uchinimodoritai
// 	Scene* curve2_scene = new Scene(line_trace_rightcurve_action, new AngleMonitor(80), big_loop_entry_scene);//ラップ前curve曲率走行に
// 	Scene* strait2_scene = new Scene(line_trace_right_action, new DistanceMonitor(1640), curve2_scene);//２つ目の直線//全国では外側走行にしたい。soto
// 	Scene* curve_scene = new Scene(line_trace_rightcurve_action, new AngleMonitor(80), strait2_scene);//curve全国では曲率走行に
// 	Scene* start_scene = new Scene(line_trace_right_action, new DistanceMonitor(2780), curve_scene);//直線//uchi
  
//   // ブロックdeトレジャーから始める場合
//   // scene_ = block_entry_scene;
//   // 開始シーン
//   scene_ = start_scene;
// }

void Process::setup() {
  // 動作
 	Action* line_trace_right_action = new LineTraceAction(63, 63, 1, 0.0966, 0.01, 0.0387);
  Action* line_trace_right_action2 = new LineTraceAction(25, 25, 1, 0.15, 0.75, 0.015);
	Action* line_trace_left_action = new LineTraceAction(63, 63, -1, 0.0966, 0.01, 0.0387);
	Action* line_trace_left_action2 = new LineTraceAction(25, 25, -1, 0.15, 0.75, 0.015);
	Action* stop_action = new WheelAction(0, 0);
  
  // 監視
  Monitor* black_line_monitor = new BlackLineMonitor();
  Monitor* blue_line_monitor = new BlueLineMonitor();
  Monitor* red_line_monitor = new RedLineMonitor();

  // シーン
  Scene* stop_scene = new Scene(stop_action, nullptr, nullptr);
	Scene* start_scene = new Scene(line_trace_right_action2, new BlueLineMonitor, stop_scene);
  
  scene_ = start_scene;
}