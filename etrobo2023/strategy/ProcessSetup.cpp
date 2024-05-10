#include "Process.h"
#include "WheelAction.h"
#include "LineTraceAction.h"
#include "ArmAction.h"
#include "DistanceMonitor.h"
#include "BlackLineMonitor.h"
#include "BlueLineMonitor.h"
#include "RedLineMonitor.h"
#include "RedBlockMonitor.h"
#include "ArmMonitor.h"
#include "AngleMonitor.h"
#include "YellowLineMonitor.h"
#include "GreenLineMonitor.h"

void Process::setupPattern1() {
  Action* line_trace_right_action = new LineTraceAction(15, 15, 1, 0.15, 0.75, 0.015);
  Action* line_trace_left_action = new LineTraceAction(15, 15, -1, 0.15, 0.75, 0.015);
  Action* stop_action = new WheelAction(0, 0);
  Action* right_turn_action = new WheelAction(5, -5);
  Action* straight_pwm20_action = new WheelAction(20, 20);
  Action* straight_pwm10_action = new WheelAction(10, 10);
  Action* straight_pwm_10_action = new WheelAction(-10, -10);
  Action* left_turn_action = new WheelAction(-5, 5);
  Action* arm_up_action = new ArmAction(5);
  Action* arm_down_action = new ArmAction(-5);
  Action* arm_stop_action = new ArmAction(0);

  Monitor* red_line_monitor = new RedLineMonitor();
  Monitor* blue_line_monitor = new BlueLineMonitor();
  Monitor* black_line_monitor = new BlackLineMonitor();
  Monitor* green_line_monitor = new GreenLineMonitor();
  Monitor* yellow_line_monitor = new YellowLineMonitor();
  Monitor* red_block_monitor = new RedBlockMonitor();
  Monitor* arm_up_monitor = new ArmMonitor(35, -1);
  Monitor* arm_down_monitor = new ArmMonitor(0, 1);

  Scene* stop_scene = new Scene(stop_action, nullptr, nullptr);
  // Scene* test3scene = new Scene(straight_pwm10_action, new DistanceMonitor(100), stop_scene);//susumu
  Scene* test2scene = new Scene(straight_pwm10_action, green_line_monitor, stop_scene);//susumu
  Scene* testscene = new Scene(straight_pwm10_action, new DistanceMonitor(100), test2scene);//susumu

  Scene* push_scene2 = new Scene(straight_pwm10_action, new DistanceMonitor(100), stop_scene);//susumu
  Scene* line_trace_scene5 = new Scene(line_trace_right_action, blue_line_monitor, stop_scene);//青見る
  Scene* circle_scene3 = new Scene(straight_pwm10_action, new DistanceMonitor(100), line_trace_scene5);//進んで
  Scene* line_trace_scene4 = new Scene(line_trace_right_action, red_line_monitor, circle_scene3);//あか
  Scene* straight_scene5 = new Scene(straight_pwm10_action, black_line_monitor, line_trace_scene4);//黒みるまで直進
  Scene* right_turn_scene3 = new Scene(right_turn_action, new AngleMonitor(90), straight_scene5);//回転
  Scene* straight_scene4 = new Scene(straight_pwm20_action, new DistanceMonitor(50), right_turn_scene3);//円の真ん中に
  Scene* straight_scene3 = new Scene(line_trace_left_action, red_line_monitor, straight_scene4);//赤見るまで
  Scene* straight_scene2 = new Scene(straight_pwm10_action, black_line_monitor, straight_scene3);//黒みるまで直進
  Scene* right_turn_scene2 = new Scene(right_turn_action, new AngleMonitor(110), straight_scene2);//もつ
  Scene* back_scene1 = new Scene(straight_pwm_10_action, new DistanceMonitor(-10), right_turn_scene2);//
  Scene* push_scene1 = new DivergentScene(straight_pwm10_action, new DistanceMonitor(100), back_scene1, right_turn_scene2);//赤ならせんかい青ならバック

  Scene* arm_stop_scene = new Scene(arm_stop_action, nullptr, push_scene1);

  Scene* arm_down_scene1 = new Scene(arm_down_action, arm_down_monitor, arm_stop_scene);//さがったら
  Scene* block_color_get_scene1 = new Scene(stop_action, red_block_monitor, arm_down_scene1);//いろみて
  Scene* arm_up_scene1 = new Scene(arm_up_action, arm_up_monitor, block_color_get_scene1);//あーむあげ
  Scene* line_trace_stop_scene1 = new Scene(stop_action, nullptr, arm_up_scene1);//tomatte
  Scene* line_trace_scene3 = new Scene(line_trace_left_action, red_line_monitor, line_trace_stop_scene1);//あかみて

  Scene* circle_scene2 = new Scene(straight_pwm10_action, new DistanceMonitor(100), line_trace_scene3);//すすんで
  Scene* line_trace_scene2 = new Scene(line_trace_left_action, red_line_monitor, circle_scene2);//あかみて
  Scene* circle_scene1 = new Scene(straight_pwm10_action, new DistanceMonitor(100), line_trace_scene2);//進んで
  Scene* line_trace_scene1 = new Scene(line_trace_left_action, blue_line_monitor, circle_scene1);//青見て
  Scene* left_turn_scene = new Scene(left_turn_action, new AngleMonitor(-60), line_trace_scene1);//旋回
  Scene* straight_scene1 = new Scene(straight_pwm20_action, black_line_monitor, left_turn_scene);//黒みたら
  Scene* right_turn_scene1 = new Scene(right_turn_action, new AngleMonitor(60), straight_scene1);//旋回して
  Scene* entry_scene = new Scene(line_trace_right_action, red_line_monitor, right_turn_scene1);//akamitara

  // 開始シーン
   scene_ = testscene;
  // scene_ = entry_scene;
  // scene_ = line_trace_scene3;
}

void Process::setupDoubleLoopOnly() {
  // 動作
  Action* line_trace_right_action = new LineTraceAction(15, 15, 1, 0.15, 0.75, 0.015);
  Action* line_trace_left_action = new LineTraceAction(15, 15, -1, 0.15, 0.75, 0.015);
  Action* straight_pwm20_action = new WheelAction(20, 20);
  Action* right_turn_action = new WheelAction(5, -5);
  Action* left_turn_action = new WheelAction(-5, 5);
  Action* stop_action = new WheelAction(0, 0);

  // 監視
  Monitor* black_line_monitor = new BlackLineMonitor();
  Monitor* blue_line_monitor = new BlueLineMonitor();

  // シーン
  Scene* stop_scene = new Scene(stop_action, nullptr, nullptr);
  Scene* block_entry_scene = new Scene(line_trace_right_action, new DistanceMonitor(500), stop_scene);
  Scene* right_turn_scene = new Scene(right_turn_action, new AngleMonitor(90), block_entry_scene);
  Scene* straight_scene3 = new Scene(straight_pwm20_action, black_line_monitor, right_turn_scene);
  Scene* straight_scene2 = new Scene(straight_pwm20_action, new DistanceMonitor(30), straight_scene3);
  Scene* straight_scene1 = new Scene(straight_pwm20_action, black_line_monitor, straight_scene2);
  Scene* left_turn_scene = new Scene(left_turn_action, new AngleMonitor(-90), straight_scene1);
  Scene* big_loop_scene4 = new Scene(line_trace_right_action, new AngleMonitor(180),
   left_turn_scene); // 本番環境は180, 練習環境はゆらぎあり
  Scene* small_loop_scene2 = new Scene(line_trace_right_action, black_line_monitor, big_loop_scene4);
  Scene* small_loop_scene1 = new Scene(line_trace_left_action, blue_line_monitor, small_loop_scene2);
  Scene* big_loop_scene3 = new Scene(line_trace_left_action, black_line_monitor, small_loop_scene1);
  Scene* big_loop_scene2 = new Scene(line_trace_right_action, blue_line_monitor, big_loop_scene3);
  Scene* big_loop_scene1 = new Scene(line_trace_right_action, black_line_monitor, big_loop_scene2);
  Scene* entry_scene = new Scene(line_trace_right_action, blue_line_monitor, big_loop_scene1);

  // 開始シーン
  scene_ = entry_scene;
}

// テスト用
void Process::setupLineTrace() {
  Action* stop_action = new WheelAction(0, 0);
  Action* line_trace_right_action = new LineTraceAction(15, 15, 1, 0.15, 0.75, 0.015);
  // Monitor* blue_line_monitor = new BlueLineMonitor();
  Scene* stop_scene = new Scene(stop_action, nullptr, nullptr);
  Scene* entry_scene = new Scene(line_trace_right_action, new AngleMonitor(180), stop_scene);

  // 開始シーン
  scene_ = entry_scene;
}

void Process::setup() {
	// 動作
	// Action* line_trace_right_action = new LineTraceAction(15, 15, 1, 0.15, 0.75, 0.015); //初期値
	// Action* line_trace_left_action = new LineTraceAction(15, 15, -1, 0.15, 0.75, 0.015);//初期値
	//ゴールまで
	Action* line_trace_right_action = new LineTraceAction(60, 60, 1, 0.0966, 0.01, 0.0387);//直線GPT
	Action* line_trace_left_action = new LineTraceAction(60, 60, -1, 0.0966, 0.01, 0.0387);
	Action* line_trace_rightcurve_action = new LineTraceAction(50, 50, 1, 0.45, 0.01, 0.055);//右ライントレースカーブgptゴールまでだけ
  //難所
	Action* line_trace_rightloop_action = new LineTraceAction(30, 30, 1, 0.15, 0.75, 0.015);//大円　gptの値　右
	Action* line_trace_leftloop_action = new LineTraceAction(30, 30, -1, 0.15, 0.75, 0.015);//大円　左ライントレース
	Action* line_trace_rightloopslow_action = new LineTraceAction(15, 15, 1, 0.15, 0.75, 0.015);//ゆっくり右
	Action* line_trace_leftloopslow_action = new LineTraceAction(15, 15, -1, 0.15, 0.75, 0.015);//ゆっくり左
	Action* line_trace_smallloop_action = new LineTraceAction(20, 20, -1, 0.12, 0.01, 0.03);//小円　右 nazo

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
	// Monitor* arm_up_monitor = new ArmMonitor(50, -1);
	// Monitor* arm_down_monitor = new ArmMonitor(0, 1);
	Monitor* black_line_monitor = new BlackLineMonitor();
	Monitor* blue_line_monitor = new BlueLineMonitor();

	// シーン 
	// Scene* arm_down_scene = new Scene(arm_down_action, arm_down_monitor, line_trace_scene);
	// Scene* arm_up_scene = new Scene(arm_up_action, arm_up_monitor, arm_down_scene);

	Scene* stop_scene = new Scene(stop_action, nullptr, nullptr);


	// Scene* black_search_scene1 = new Scene(straight_pwm20_action, black_line_monitor, small_loop_scene);
	// Scene* straight_scene1 = new Scene(straight_pwm20_action, new DistanceMonitor(300), black_search_scene1);
	Scene* block_entry_scene = new Scene(line_trace_right_action, new DistanceMonitor(500), stop_scene);
	Scene* right_turn_scene = new Scene(right_turn_action, new AngleMonitor(90), stop_scene);
	Scene* straight_scene3 = new Scene(straight_pwm20_action, black_line_monitor, right_turn_scene);
	Scene* straight_scene2 = new Scene(straight_pwm20_action, new DistanceMonitor(30), straight_scene3);
	Scene* straight_scene1 = new Scene(straight_pwm20_action, black_line_monitor, straight_scene2);
	Scene* left_turn_scene = new Scene(left_turn_action, new AngleMonitor(-90), straight_scene1);
	//抜け出し
	Scene* big_loop_scene3 = new Scene(line_trace_leftloopslow_action, new AngleMonitor(180), stop_scene);//4ゲート通過まで//ここがうまくいかない
	// Scene* turn_scene3 = new Scene(straight_pwm20_action, new DistanceMonitor(50) , big_loop_scene3);//エッジを切り替える時に切り替えやすいように試験
	Scene* small_loop_scene3 = new Scene(line_trace_rightloopslow_action, black_line_monitor, stop_scene);//小円あとの青
	Scene* small_loop_scene2 = new Scene(line_trace_smallloop_action, blue_line_monitor, small_loop_scene3);//交差部から小円
	Scene* small_loop_scene1 = new Scene(line_trace_smallloop_action, new DistanceMonitor(50), small_loop_scene2);//紙だと内側にずれる試走会でもずれるなら検討
  //下のやつがうまくいったとして

  //---------------------決め打ち走行ver
	// Scene* kirikawari_scene4 = new Scene(straight_pwm20_action, black_line_monitor, small_loop_scene1);
	// Scene* kirikawari_scene3 = new Scene(kirikae_action2, new DistanceMonitor(100), kirikawari_scene4);
	// Scene* kirikawari_scene2 = new Scene(straight_pwm20_action, new DistanceMonitor(250), kirikawari_scene3);
	// Scene* kirikawari_scene1 = new Scene(kirikae_action, new DistanceMonitor(200), kirikawari_scene2);
	// Scene* big_loop_scene2 = new Scene(line_trace_leftloop_action, blue_line_monitor, kirikawari_scene1);//ここで青判定がドンピシャなら成功する。はず。
	// Scene* big_loop_scene1 = new Scene(line_trace_rightloop_action, black_line_monitor, big_loop_scene2);
  //----------------------------------------------

  //----------------ライントレースver
	// Scene* chousei_scene2 = new Scene(left_turn_action,  new AngleMonitor(30), stop_scene);//うまく実装出来たら
	Scene* chousei_scene1 = new Scene(straight_pwm20_action, black_line_monitor, small_loop_scene1);//今ループにいなかったら黒を見つけに行く
	Scene* cross_scene1 = new Scene(line_trace_smallloop_action, black_line_monitor, chousei_scene1);//交差の黒
	Scene* big_loop_scene2 = new Scene(line_trace_leftloop_action, blue_line_monitor, cross_scene1);//ここが青見たら外は知る
	Scene* big_loop_scene1 = new Scene(line_trace_rightloop_action, black_line_monitor, big_loop_scene2);
	//------------------------


	  //ここからダブルループ
	Scene* big_loop_entry_scene = new Scene(line_trace_right_action, blue_line_monitor, big_loop_scene1);//
	Scene* curve2_scene = new Scene(line_trace_rightcurve_action, new AngleMonitor(90), big_loop_entry_scene);//ラップ前curve
	Scene* strait2_scene = new Scene(line_trace_right_action, new DistanceMonitor(1640), curve2_scene);//２つ目の直線
	Scene* curve_scene = new Scene(line_trace_rightcurve_action, new AngleMonitor(90), strait2_scene);//curve
	Scene* start_scene = new Scene(line_trace_right_action, new DistanceMonitor(2780), curve_scene);//直線

	// 開始シーン
	scene_ = big_loop_entry_scene;
}

