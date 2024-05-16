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

// Scene* Process::getScenePattern1() {//完成
//   Action* line_trace_right_action = new LineTraceAction(15, 15, 1, 0.165, 0.01, 0.0155);//いいかも
//   Action* line_trace_left_action = new LineTraceAction(15, 15, -1, 0.165, 0.01, 0.0155);
//   Action* line_trace_right_action2 = new LineTraceAction(60, 60, 1, 0.0966, 0.01, 0.0387);
//   Action* stop_action = new WheelAction(0, 0);
//   Action* right_turn_action = new WheelAction(10, -10);
//   Action* left_turn_action = new WheelAction(-10, 10);
//   Action* left_turn_action2 = new WheelAction(-5, 20);
//   Action* right_turn_action2 = new WheelAction(20, -5);
//   Action* straight_pwm20_action = new WheelAction(20, 20);
//   Action* straight_pwm10_action = new WheelAction(10, 10);
//   Action* back_pwm10_action = new WheelAction(-10, -10);
//   Action* arm_up_action = new ArmAction(10);
//   Action* arm_down_action = new ArmAction(-10);
//   Action* arm_stop_action = new ArmAction(0);

//   Monitor* red_line_monitor = new RedLineMonitor();
//   Monitor* blue_line_monitor = new BlueLineMonitor();
//   Monitor* black_line_monitor = new BlackLineMonitor();
//   Monitor* yellow_line_monitor = new YellowLineMonitor();
//   Monitor* green_line_monitor = new GreenLineMonitor();
//   Monitor* red_block_monitor = new RedBlockMonitor();
//   Monitor* arm_up_monitor = new ArmMonitor(45 , -1);
//   Monitor* arm_down_monitor = new ArmMonitor(0, 1);

//   Scene* stop_scene = new Scene(stop_action, nullptr, nullptr);

//   Scene* line_trace_scene100 = new Scene(line_trace_right_action, blue_line_monitor, stop_scene);//aohannteiyabai
//   Scene* left_turn_scene100 = new Scene(left_turn_action2, new AngleMonitor(-80), line_trace_scene100);
//   Scene* blackfindrun2 = new Scene(straight_pwm20_action, black_line_monitor, left_turn_scene100);
//   Scene* straight3434 = new Scene(straight_pwm20_action, new DistanceMonitor(100), blackfindrun2);





//   Scene* turngoall = new Scene(left_turn_action2, new AngleMonitor(-45), left_turn_scene100);
//   Scene* blackfindgoal = new Scene(straight_pwm20_action, black_line_monitor, turngoall);
//   Scene* turnrr = new Scene(right_turn_action2, new AngleMonitor(40), blackfindgoal);
//   Scene* straightmochinaosi = new Scene(straight_pwm20_action, new DistanceMonitor(100), turnrr);
//   Scene* linetl = new Scene(line_trace_right_action, yellow_line_monitor, straightmochinaosi);//もつとこ
//   Scene* turnr = new Scene(right_turn_action, new AngleMonitor(30), linetl);
//   Scene* blackfindee = new Scene(straight_pwm20_action, black_line_monitor, turnr); 
//   Scene* straightkk = new Scene(straight_pwm20_action, new DistanceMonitor(50), blackfindee);
//   Scene* turnyy = new Scene(right_turn_action, new AngleMonitor(35), straightkk);
//   Scene* back8888 = new Scene(back_pwm10_action, new DistanceMonitor(-60), turnyy);
//   Scene* linetraceccc = new Scene(line_trace_right_action, yellow_line_monitor, back8888);
//   Scene* turng = new Scene(left_turn_action, new AngleMonitor(-80), linetraceccc);
//   Scene* blackmituke = new Scene(straight_pwm20_action, black_line_monitor, turng);
//   Scene* straightnagai = new Scene(straight_pwm20_action, new DistanceMonitor(300), blackmituke);
//   Scene* turnttt = new Scene(right_turn_action, new AngleMonitor(15), straightnagai);//kikenkamo


//   // Scene* balckfinduu = new Scene(straight_pwm20_action, black_line_monitor, stop_scene);
//   // Scene* straighttuu = new Scene(straight_pwm20_action, new DistanceMonitor(60), balckfinduu);
//   // Scene* turngogo = new Scene(left_turn_action, new AngleMonitor(80), straighttuu);
//   // Scene* blackfinddddd = new Scene(straight_pwm20_action, black_line_monitor, turngogo);
//   // Scene* straightikou = new Scene(straight_pwm20_action, new DistanceMonitor(50), blackfinddddd);

//   // Scene* turnttt = new Scene(right_turn_action, new AngleMonitor(30), straightikou);
//   Scene* back = new Scene(back_pwm10_action, new DistanceMonitor(-30), turnttt);
//   Scene* linetrace = new Scene(line_trace_right_action, red_line_monitor, back);
//   Scene* turn8 = new Scene(right_turn_action, new AngleMonitor(20), linetrace);
//   Scene* blackfinddd = new Scene(straight_pwm20_action, black_line_monitor, turn8);
//   Scene* straight778 = new Scene(straight_pwm20_action, new DistanceMonitor(50), blackfinddd);
//   Scene* turn11 = new Scene(right_turn_action, new AngleMonitor(40), straight778);
//   Scene* back_scenedayo = new Scene(back_pwm10_action, new DistanceMonitor(-130), turn11);//２こめあお


//   Scene* blackfindrun32 = new Scene(left_turn_action2, new AngleMonitor(-20), straight3434);
//   Scene* straight343 = new Scene(straight_pwm20_action, new DistanceMonitor(100), blackfindrun32);
//   Scene* turnact = new Scene(right_turn_action, new AngleMonitor(20), straight343);
//   Scene* blackfindrun1 = new Scene(straight_pwm20_action, black_line_monitor, turnact);
//   Scene* straight1111 = new Scene(straight_pwm20_action, new DistanceMonitor(50), blackfindrun1);
//   Scene* leftturn112 = new Scene(left_turn_action, new AngleMonitor(-18), straight1111);
//   Scene* blackfind12 = new Scene(straight_pwm20_action, black_line_monitor, leftturn112);
//   Scene* straight1212 = new Scene(straight_pwm20_action, new DistanceMonitor(100), blackfind12);
//   Scene* turnright = new Scene(right_turn_action, new AngleMonitor(18), straight1212);
//   Scene* straight12 = new Scene(straight_pwm20_action, new DistanceMonitor(120), turnright);
//   Scene* straight_scene33 = new Scene(line_trace_left_action, red_line_monitor, straight12);
//   Scene* straight_scene333 = new Scene(left_turn_action, new AngleMonitor(-15), straight_scene33);
//   Scene* straight_scene22 = new Scene(straight_pwm10_action, black_line_monitor, straight_scene333);
//   Scene* turn_scene34 = new Scene(right_turn_action2, new AngleMonitor(115), straight_scene22);//2komeaka

//   Scene* push_scene11 = new DivergentScene(straight_pwm10_action, new DistanceMonitor(110), back_scenedayo, turn_scene34);//みる
//   Scene* arm_stop_scene11 = new Scene(arm_stop_action, nullptr, push_scene11);
//   Scene* arm_down_scene11 = new Scene(arm_down_action, arm_down_monitor, arm_stop_scene11);
//   Scene* block_color_get_scene11 = new Scene(stop_action, red_block_monitor, arm_down_scene11);
//   Scene* arm_up_scene11 = new Scene(arm_up_action, arm_up_monitor, block_color_get_scene11);
//   Scene* line_trace_stop_scene2 = new Scene(stop_action, nullptr, arm_up_scene11);//a-mu
//   Scene* linetrace9 = new Scene(line_trace_right_action, red_line_monitor, line_trace_stop_scene2);//2komeblock
//   Scene* turnright1 = new Scene(right_turn_action, new AngleMonitor(30), linetrace9);
//   Scene* blackfindrun = new Scene(straight_pwm20_action, black_line_monitor, turnright1);
//   Scene* straight7 = new Scene(straight_pwm20_action, new DistanceMonitor(50), blackfindrun);
//   Scene* turn = new Scene(right_turn_action, new AngleMonitor(30), straight7);
//   Scene* back_scene4 = new Scene(back_pwm10_action, new DistanceMonitor(-80), turn);
//   Scene* left_line_trace_scene2 = new Scene(line_trace_left_action, red_line_monitor, back_scene4);
//   Scene* turn_right_scene1 = new Scene(left_turn_action, new AngleMonitor(-30), left_line_trace_scene2);
//   Scene* blackfindrunn = new Scene(straight_pwm20_action, black_line_monitor, turn_right_scene1);
//   Scene* straight_scene5 = new Scene(straight_pwm20_action, new DistanceMonitor(50), blackfindrunn);
//   Scene* right_turn_scene22 = new Scene(left_turn_action, new AngleMonitor(-30), straight_scene5);
//   Scene* back_scene2 = new Scene(back_pwm10_action, new DistanceMonitor(-50), right_turn_scene22);
//   Scene* line_trace_scene3 = new Scene(line_trace_left_action, red_line_monitor, back_scene2);//最初の赤
//   Scene* left_turn_scene = new Scene(left_turn_action, new AngleMonitor(-25), line_trace_scene3);
//   Scene* blackfind_scene = new Scene(straight_pwm20_action, black_line_monitor, left_turn_scene);
//   Scene* straight_scene = new Scene(straight_pwm20_action, new DistanceMonitor(50), blackfind_scene);
//   Scene* turn_left_scene = new Scene(left_turn_action, new AngleMonitor(-30), straight_scene);
//   Scene* back_scene = new Scene(back_pwm10_action, new DistanceMonitor(-140), turn_left_scene);//１個めあお

//   Scene* line_trace_scene1001 = new Scene(line_trace_right_action, blue_line_monitor, stop_scene);//aohannteiyabai
//   Scene* left_turn_scene1001 = new Scene(left_turn_action2, new AngleMonitor(-85), line_trace_scene1001);
//   Scene* blackfindrun21 = new Scene(straight_pwm20_action, black_line_monitor, left_turn_scene1001);
//   Scene* straight343422 = new Scene(straight_pwm20_action, new DistanceMonitor(100), blackfindrun21);
//   Scene* blackfind22 = new Scene(straight_pwm20_action, black_line_monitor, straight343422);//ここが最後kuroのところkansei
//   Scene* straight1155 = new Scene(left_turn_action2, new AngleMonitor(-15), blackfind22);
//   Scene* blackfindrun67 = new Scene(straight_pwm20_action, black_line_monitor, straight1155);
//   Scene* linetrace66 = new Scene(straight_pwm20_action, new DistanceMonitor(160), blackfindrun67);
//   Scene* turn_scene344 = new Scene(right_turn_action, new AngleMonitor(25), linetrace66);
//   Scene* redhold_scene = new Scene(straight_pwm20_action, new DistanceMonitor(50),turn_scene344);//1komeakanotoki持ち直し的な

//   Scene* push_scene1 = new DivergentScene(straight_pwm10_action, new DistanceMonitor(110), back_scene, redhold_scene);//みる
//   Scene* arm_stop_scene1 = new Scene(arm_stop_action, nullptr, push_scene1);
//   Scene* arm_down_scene1 = new Scene(arm_down_action, arm_down_monitor, arm_stop_scene1);
//   Scene* block_color_get_scene1 = new Scene(stop_action, red_block_monitor, arm_down_scene1);
//   Scene* arm_up_scene1 = new Scene(arm_up_action, arm_up_monitor, block_color_get_scene1);
//   Scene* line_trace_stop_scene1 = new Scene(stop_action, nullptr, arm_up_scene1);//a-mu
//   Scene* right_linetrace_scene = new Scene(line_trace_right_action, blue_line_monitor, line_trace_stop_scene1);//青見るまでライントレース
//   Scene* right_turn_scene2 = new Scene(right_turn_action, new AngleMonitor(40), right_linetrace_scene);//旋回
//   Scene* find_blackline_scene = new Scene(straight_pwm20_action, black_line_monitor, right_turn_scene2);//黒まで
//   Scene* straight_scene1 = new Scene(straight_pwm20_action, new DistanceMonitor(50), find_blackline_scene);//黒を見ないように
//   Scene* left_turn_scene1 = new Scene(left_turn_action, new AngleMonitor(-20), straight_scene1);//ちょっと左に回転
//   Scene* straight1 = new Scene(straight_pwm20_action, black_line_monitor, left_turn_scene1); //黒まで直進
//   Scene* right_turn_scene1 = new Scene(right_turn_action, new AngleMonitor(60), straight1);//これが赤から脱出

//   return right_turn_scene1;
// }








// //2222222222222222222222222222222222222222222222222222222222222222222222222222
// Scene* Process::getScenePattern2() {//kansei
//   Action* line_trace_right_action = new LineTraceAction(15, 15, 1, 0.155, 0.01, 0.0155);//いいかも
//   Action* line_trace_left_action = new LineTraceAction(15, 15, -1, 0.155, 0.01, 0.0155);
//   Action* stop_action = new WheelAction(0, 0);
//   Action* right_turn_action = new WheelAction(10, -10);
//   Action* left_turn_action = new WheelAction(-10, 10);
//   Action* left_turn_action2 = new WheelAction(-5, 20);
//   Action* right_turn_action2 = new WheelAction(20, -5);
//   Action* straight_pwm40_action = new WheelAction(40, 40);
//   Action* straight_pwm20_action = new WheelAction(20, 20);
//   Action* straight_pwm10_action = new WheelAction(10, 10);
//   Action* back_pwm10_action = new WheelAction(-10, -10);
//   Action* arm_up_action = new ArmAction(15);
//   Action* arm_down_action = new ArmAction(-15);
//   Action* arm_stop_action = new ArmAction(0);

//   Monitor* red_line_monitor = new RedLineMonitor();
//   Monitor* blue_line_monitor = new BlueLineMonitor();
//   Monitor* black_line_monitor = new BlackLineMonitor();
//   Monitor* yellow_line_monitor = new YellowLineMonitor();
//   Monitor* green_line_monitor = new GreenLineMonitor();
//   Monitor* red_block_monitor = new RedBlockMonitor();
//   Monitor* arm_up_monitor = new ArmMonitor(43 , -1);
//   Monitor* arm_down_monitor = new ArmMonitor(0, 1);//ｌここかえてる

//   Scene* stop_scene = new Scene(stop_action, nullptr, nullptr);


//   Scene* line_trace_scene100 = new Scene(line_trace_right_action, blue_line_monitor, stop_scene);
//   Scene* left_turn_scene100 = new Scene(left_turn_action2, new AngleMonitor(-80), line_trace_scene100);
//   Scene* blackfindrun2 = new Scene(straight_pwm20_action, black_line_monitor, left_turn_scene100);
//   Scene* straight3434 = new Scene(straight_pwm20_action, new DistanceMonitor(50), blackfindrun2);

//   Scene* turngoal = new Scene(left_turn_action2, new AngleMonitor(-30), straight3434);
//   Scene* straight667 = new Scene(straight_pwm20_action, new DistanceMonitor(130), turngoal);
//   Scene* linetrace989 = new Scene(line_trace_left_action, green_line_monitor, straight667);
//   Scene* turnscene338 = new Scene(left_turn_action, new AngleMonitor(-75), linetrace989);
//   Scene* blackfind333 = new Scene(straight_pwm20_action, black_line_monitor, turnscene338);
//   Scene* straight778 = new Scene(straight_pwm20_action, new DistanceMonitor(50), blackfind333);
//   Scene* blackfind33 = new Scene(straight_pwm20_action, black_line_monitor, straight778);
//   Scene* straight998 = new Scene(straight_pwm20_action, new DistanceMonitor(50), blackfind33);

//   Scene* goalmouchoi = new Scene(straight_pwm20_action, new DistanceMonitor(200), blackfindrun2);
//   Scene* linetraceleft = new Scene(line_trace_left_action, green_line_monitor, goalmouchoi);
//   Scene* turn90 = new Scene(left_turn_action, new AngleMonitor(-90), linetraceleft);
//   Scene* blackfindddd = new Scene(straight_pwm20_action, black_line_monitor, turn90);
//   Scene* gogogogo = new Scene(straight_pwm20_action, new DistanceMonitor(50), blackfindddd);
//   Scene* turn45 = new Scene(right_turn_action, new AngleMonitor(45), gogogogo);
//   Scene* blackfinddd = new Scene(straight_pwm20_action, black_line_monitor, turn45);
//   Scene* goooo = new Scene(straight_pwm20_action, new DistanceMonitor(50), blackfinddd);
//   Scene* turngoo = new Scene(left_turn_action, new AngleMonitor(-45), goooo);
//   Scene* backfooo = new Scene(back_pwm10_action, new DistanceMonitor(-50), turngoo);
//   Scene* straight9986 = new Scene(line_trace_right_action, green_line_monitor, backfooo);
//   Scene* turn55 = new Scene(right_turn_action, new AngleMonitor(20), straight9986);
//   Scene* findbl = new Scene(straight_pwm20_action, black_line_monitor, turn55);
//   Scene* straightike = new Scene(straight_pwm20_action, new DistanceMonitor(50), findbl);
//   Scene* straight888 = new Scene(right_turn_action, new AngleMonitor(50), straightike);
//   Scene* backgo = new Scene(back_pwm10_action, new DistanceMonitor(-20), straight888);
//   Scene* linetrace00 = new Scene(line_trace_right_action, yellow_line_monitor, backgo);
//   Scene* turnscene332 = new Scene(right_turn_action, new AngleMonitor(30), linetrace00);
//   Scene* blackfindrun99 = new Scene(straight_pwm20_action, black_line_monitor, turnscene332);
//   Scene* straight_scene33 = new Scene(straight_pwm20_action, new DistanceMonitor(50), blackfindrun99);
//   Scene* turnturn = new Scene(right_turn_action, new AngleMonitor(35), straight_scene33);
//   Scene* back_scene9 = new Scene(back_pwm10_action, new DistanceMonitor(-140), turnturn);//２こめあお


//   Scene* turnlefff = new Scene(left_turn_action, new AngleMonitor(-20), straight3434);//iketa
//   Scene* blackfindwawawa = new Scene(straight_pwm20_action, black_line_monitor, turnlefff);
//   Scene* straightstraght = new Scene(straight_pwm20_action, new DistanceMonitor(200), blackfindwawawa);
//   Scene* turnrightgo = new Scene(right_turn_action2, new AngleMonitor(20), straightstraght);
//   Scene* rightlinetrace = new Scene(line_trace_right_action, yellow_line_monitor, turnrightgo);
//   Scene* turnleft = new Scene(left_turn_action, new AngleMonitor(-20), rightlinetrace);
//   Scene* blackfindhaha = new Scene(straight_pwm20_action, black_line_monitor, turnleft);
//   Scene* nikomeaka = new Scene(right_turn_action2, new AngleMonitor(120), blackfindhaha);//に※赤

//   Scene* push_scene11 = new DivergentScene(straight_pwm20_action, new DistanceMonitor(110), back_scene9, nikomeaka);
//   Scene* arm_stop_scene11 = new Scene(arm_stop_action, nullptr, push_scene11);
//   Scene* arm_down_scene11 = new Scene(arm_down_action, arm_down_monitor, arm_stop_scene11);
//   Scene* block_color_get_scene11 = new Scene(stop_action, red_block_monitor, arm_down_scene11);
//   Scene* arm_up_scene11 = new Scene(arm_up_action, arm_up_monitor, block_color_get_scene11);
//   Scene* line_trace_stop_scene11 = new Scene(stop_action, nullptr, arm_up_scene11);


//   Scene* linet = new Scene(line_trace_left_action, red_line_monitor, line_trace_stop_scene11);
//   Scene* lturn = new Scene(left_turn_action, new AngleMonitor(-30), linet);
//   Scene* bmituke = new Scene(straight_pwm20_action, black_line_monitor, lturn);
//   Scene* straightu = new Scene(straight_pwm20_action, new DistanceMonitor(50), bmituke);
//   Scene* chotomage = new Scene(right_turn_action, new AngleMonitor(70), straightu);
//   Scene* blackfindhe = new Scene(straight_pwm20_action, black_line_monitor, chotomage);
//   Scene* straightbb = new Scene(straight_pwm20_action, new DistanceMonitor(50), blackfindhe);
//   Scene* turnlfe = new Scene(left_turn_action, new AngleMonitor(-30), straightbb);
//   Scene* backfj = new Scene(back_pwm10_action, new DistanceMonitor(-30), turnlfe);
//   Scene* line = new Scene(line_trace_left_action, blue_line_monitor, backfj);
//   Scene* turnlef = new Scene(left_turn_action, new AngleMonitor(-30), line);
//   Scene* blackfindoop = new Scene(straight_pwm20_action, black_line_monitor, turnlef);
//   Scene* straightg = new Scene(straight_pwm20_action, new DistanceMonitor(50), blackfindoop);
//   Scene* turnscene2 = new Scene(left_turn_action, new AngleMonitor(-35), straightg);
//   Scene* back_scene122= new Scene(back_pwm10_action, new DistanceMonitor(-30), turnscene2);
//   Scene* leftlinetrace3 = new Scene(line_trace_left_action, blue_line_monitor, back_scene122 );//iketa! 2列目あおした
//   Scene* leftturn3 = new Scene(left_turn_action, new AngleMonitor(-30), leftlinetrace3);
//   Scene* blackfind4 = new Scene(straight_pwm20_action, black_line_monitor, leftturn3);
//   Scene* straight2 = new Scene(straight_pwm20_action, new DistanceMonitor(50), blackfind4);
//   Scene* turn_scene = new Scene(left_turn_action, new AngleMonitor(-45), straight2);
//   Scene* back_scene1 = new Scene(back_pwm10_action, new DistanceMonitor(-150), turn_scene);//青の時




//   Scene* push_scene1 = new Scene(straight_pwm20_action, new DistanceMonitor(110), back_scene1);//はんてい  もしかしたら赤でも青でも押す？ほうがいいかも

//   Scene* line_trace1 = new Scene(line_trace_right_action, blue_line_monitor,push_scene1);
//   Scene* right_turn_scene = new Scene(right_turn_action, new AngleMonitor(110), line_trace1);
//   Scene* straight1 = new Scene(straight_pwm20_action, black_line_monitor, right_turn_scene); //黒まで直進
//   Scene* right_turn_scene1 = new Scene(right_turn_action, new AngleMonitor(56), straight1);//これが赤から脱出

//   return right_turn_scene1;
  
// }



// //3333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333
// Scene* Process::getScenePattern3() {//完成
//   Action* line_trace_right_action = new LineTraceAction(15, 15, 1, 0.155, 0.01, 0.018);//いいかも
//   Action* line_trace_left_action = new LineTraceAction(15, 15, -1, 0.155, 0.01, 0.018);
//   Action* stop_action = new WheelAction(0, 0);
//   Action* right_turn_action = new WheelAction(10, -10);
//   Action* left_turn_action = new WheelAction(-10, 10);
//   Action* left_turn_action2 = new WheelAction(-5, 20);
//   Action* right_turn_action2 = new WheelAction(20, -5);
//   Action* straight_pwm40_action = new WheelAction(40, 40);
//   Action* straight_pwm20_action = new WheelAction(20, 20);
//   Action* straight_pwm10_action = new WheelAction(10, 10);
//   Action* back_pwm10_action = new WheelAction(-10, -10);
//   Action* arm_up_action = new ArmAction(10);
//   Action* arm_down_action = new ArmAction(-10);
//   Action* arm_stop_action = new ArmAction(0);

//   Monitor* red_line_monitor = new RedLineMonitor();
//   Monitor* blue_line_monitor = new BlueLineMonitor();
//   Monitor* black_line_monitor = new BlackLineMonitor();
//   Monitor* yellow_line_monitor = new YellowLineMonitor();
//   Monitor* green_line_monitor = new GreenLineMonitor();
//   Monitor* red_block_monitor = new RedBlockMonitor();
//   Monitor* arm_up_monitor = new ArmMonitor(43 , -1);
//   Monitor* arm_down_monitor = new ArmMonitor(0, 1);

//   Scene* stop_scene = new Scene(stop_action, nullptr, nullptr);
//   // Scene* blackfind116 = new Scene(straight_pwm20_action, black_line_monitor, stop_scene);
//   // Scene* straight115 = new Scene(straight_pwm20_action, new DistanceMonitor(130), blackfind116);
//   // Scene* line_trace113 = new Scene(line_trace_left_action , yellow_line_monitor, straight115);
//   // Scene* straight112 = new Scene(straight_pwm20_action, new DistanceMonitor(110), line_trace113);
//   // Scene* line_trace111 = new Scene(line_trace_right_action, yellow_line_monitor, straight112);

//   Scene* line_trace_scene100 = new Scene(line_trace_right_action, blue_line_monitor, stop_scene);
//   Scene* left_turn_scene100 = new Scene(left_turn_action2, new AngleMonitor(-90), line_trace_scene100);
//   Scene* blackfindrun2 = new Scene(straight_pwm20_action, black_line_monitor, left_turn_scene100);
//   Scene* straight3434 = new Scene(straight_pwm20_action, new DistanceMonitor(50), blackfindrun2);

//   Scene* turnact = new Scene(right_turn_action, new AngleMonitor(20), straight3434);
//   Scene* blackfindrun1 = new Scene(straight_pwm20_action, black_line_monitor, turnact);
//   Scene* straight1111 = new Scene(straight_pwm20_action, new DistanceMonitor(50), blackfindrun1);
//   Scene* leftturn112 = new Scene(left_turn_action, new AngleMonitor(-25), straight1111);
//   Scene* blackfind12 = new Scene(straight_pwm20_action, black_line_monitor, leftturn112);
//   Scene* straight1212 = new Scene(straight_pwm20_action, new DistanceMonitor(50), blackfind12);
//   Scene* turnright = new Scene(right_turn_action, new AngleMonitor(20), straight1212);
//   Scene* straight12 = new Scene(straight_pwm20_action, new DistanceMonitor(110), turnright);
//   Scene* straight_scene33 = new Scene(line_trace_left_action, red_line_monitor, straight12);
//   Scene* straight_scene22 = new Scene(straight_pwm10_action, black_line_monitor, straight_scene33);
//   Scene* turn_scene34 = new Scene(right_turn_action2, new AngleMonitor(115), straight_scene22);//otosu
//   Scene* push_scene34 = new Scene(straight_pwm20_action, new DistanceMonitor(100), turn_scene34);


//   Scene* right_linetrace_scene2 = new Scene(line_trace_right_action, red_line_monitor, push_scene34);//akamotu
//   Scene* turn_scene33 = new Scene(right_turn_action, new AngleMonitor(80), right_linetrace_scene2);
//   Scene* find_blackline_scene5 = new Scene(straight_pwm20_action, black_line_monitor, turn_scene33);
//   Scene* straight3 = new Scene(straight_pwm20_action, new DistanceMonitor(50), find_blackline_scene5);
//   Scene* rightturn_scene = new Scene(right_turn_action, new AngleMonitor(30), straight3);
//   Scene* find_blackline_scene4 = new Scene(straight_pwm20_action, black_line_monitor, rightturn_scene);
//   Scene* straight_scene = new Scene(straight_pwm20_action, new DistanceMonitor(50), find_blackline_scene4);
//   Scene* left_turn_scene4 = new Scene(left_turn_action, new AngleMonitor(-120),straight_scene);
//   Scene* find_blackline_scene3 = new Scene(straight_pwm20_action, black_line_monitor,left_turn_scene4);
//   Scene* straight_scene4 = new Scene(straight_pwm20_action, new DistanceMonitor(50), find_blackline_scene3);
//   Scene* left_turn_scene3 = new Scene(left_turn_action, new AngleMonitor(-90), straight_scene4);
//   Scene* back_scene3 = new Scene(back_pwm10_action, new DistanceMonitor(-110), left_turn_scene3);//nikomeao

//   Scene* turn8888 = new Scene(right_turn_action, new AngleMonitor(20), straight3434);
//   Scene* blackfind110 = new Scene(straight_pwm20_action, black_line_monitor, turn8888);
//   Scene* straight77 = new Scene(straight_pwm20_action, new DistanceMonitor(50), blackfind110);
//   Scene* turn8989 = new Scene(left_turn_action, new AngleMonitor(-20), straight77);
//   Scene* hutatumeaka = new Scene(straight_pwm20_action, new DistanceMonitor(130), turn8989);//にこめ赤の時

//   Scene* push_scene11 = new DivergentScene(straight_pwm10_action, new DistanceMonitor(100), back_scene3, hutatumeaka);//はんてい
//   Scene* arm_stop_scene11 = new Scene(arm_stop_action, nullptr, push_scene11);
//   Scene* arm_down_scene11 = new Scene(arm_down_action, arm_down_monitor, arm_stop_scene11);
//   Scene* block_color_get_scene11 = new Scene(stop_action, red_block_monitor, arm_down_scene11);
//   Scene* arm_up_scene11 = new Scene(arm_up_action, arm_up_monitor, block_color_get_scene11);
//   Scene* line_trace_stop_scene2 = new Scene(stop_action, nullptr, arm_up_scene11);//a-mu kokokara 

// //2爪のブロック前
//   Scene* left_line_trace_scene2 = new Scene(line_trace_right_action, yellow_line_monitor, line_trace_stop_scene2);
//   Scene* turn_right_scene1 = new Scene(right_turn_action, new AngleMonitor(20), left_line_trace_scene2);
//   Scene* blackfindrun = new Scene(straight_pwm20_action, black_line_monitor, turn_right_scene1);
//   Scene* straight_scene5 = new Scene(straight_pwm20_action, new DistanceMonitor(50), blackfindrun);
//   Scene* right_turn_scene22 = new Scene(right_turn_action, new AngleMonitor(40), straight_scene5);
//   Scene* back_scene4 = new Scene(back_pwm10_action, new DistanceMonitor(-50), right_turn_scene22);
//   Scene* line_trace_scene33 = new Scene(line_trace_left_action, red_line_monitor, back_scene4);
//   Scene* turn_left_scene = new Scene(left_turn_action, new AngleMonitor(-25), line_trace_scene33);
//   Scene* find_blackline_scene1 = new Scene(straight_pwm20_action, black_line_monitor, turn_left_scene);
//   Scene* straight_scene2 = new Scene(straight_pwm20_action, new DistanceMonitor(50), find_blackline_scene1);
//   Scene* left_turn_scene1 = new Scene(left_turn_action, new AngleMonitor(-40),straight_scene2);
//   Scene* back_scene1 = new Scene(back_pwm10_action, new DistanceMonitor(-120),left_turn_scene1);



//   Scene* turn888 = new Scene(right_turn_action, new AngleMonitor(5), straight3434);
//   Scene* blackfind22 = new Scene(straight_pwm20_action, black_line_monitor, turn888);//ここが最後kuroのところ
//   Scene* straight1155 = new Scene(left_turn_action2, new AngleMonitor(-28), blackfind22);
//   Scene* blackfindrun67 = new Scene(straight_pwm20_action, black_line_monitor, straight1155);
//   Scene* linetrace66 = new Scene(straight_pwm20_action, new DistanceMonitor(70), blackfindrun67);
//   Scene* turn_scene344 = new Scene(right_turn_action, new AngleMonitor(25), linetrace66);
//   Scene* redhold_scene = new Scene(straight_pwm20_action, new DistanceMonitor(30),turn_scene344);//1komeakanotoki持ち直し的な

//   Scene* push_scene1 = new DivergentScene(straight_pwm10_action, new DistanceMonitor(110), back_scene1, redhold_scene);//みる
//   Scene* arm_stop_scene1 = new Scene(arm_stop_action, nullptr, push_scene1);
//   Scene* arm_down_scene1 = new Scene(arm_down_action, arm_down_monitor, arm_stop_scene1);
//   Scene* block_color_get_scene1 = new Scene(stop_action, red_block_monitor, arm_down_scene1);
//   Scene* arm_up_scene1 = new Scene(arm_up_action, arm_up_monitor, block_color_get_scene1);
//   Scene* line_trace_stop_scene1 = new Scene(stop_action, nullptr, arm_up_scene1);//a-mu
//   Scene* right_linetrace_scene = new Scene(line_trace_right_action, blue_line_monitor, line_trace_stop_scene1);//青見るまでライントレース
//   Scene* right_turn_scene2 = new Scene(right_turn_action, new AngleMonitor(40), right_linetrace_scene);//旋回
//   Scene* find_blackline_scene = new Scene(straight_pwm20_action, black_line_monitor, right_turn_scene2);//黒まで
//   Scene* straight_scene1 = new Scene(straight_pwm20_action, new DistanceMonitor(50), find_blackline_scene);//黒を見ないように
//   Scene* left_turn_scene = new Scene(left_turn_action, new AngleMonitor(-20), straight_scene1);//ちょっと左に回転
//   Scene* straight1 = new Scene(straight_pwm20_action, black_line_monitor, left_turn_scene); //黒まで直進
//   Scene* right_turn_scene1 = new Scene(right_turn_action, new AngleMonitor(60), straight1);//これが赤から脱出

//   return right_turn_scene1;
// }







// //44444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444
// Scene* Process::getScenePattern4() {//完成
//   Action* line_trace_right_action = new LineTraceAction(15, 15, 1, 0.155, 0.01, 0.018);//いいかも
//   Action* line_trace_left_action = new LineTraceAction(15, 15, -1, 0.155, 0.01, 0.018);
//   Action* stop_action = new WheelAction(0, 0);
//   Action* right_turn_action = new WheelAction(10, -10);
//   Action* left_turn_action = new WheelAction(-10, 10);
//   Action* left_turn_action2 = new WheelAction(-5, 20);
//   Action* right_turn_action2 = new WheelAction(20, -5);
//   Action* straight_pwm40_action = new WheelAction(40, 40);
//   Action* straight_pwm20_action = new WheelAction(20, 20);
//   Action* straight_pwm10_action = new WheelAction(10, 10);
//   Action* back_pwm10_action = new WheelAction(-10, -10);
//   Action* arm_up_action = new ArmAction(10);
//   Action* arm_down_action = new ArmAction(-10);
//   Action* arm_stop_action = new ArmAction(0);

//   Monitor* red_line_monitor = new RedLineMonitor();
//   Monitor* blue_line_monitor = new BlueLineMonitor();
//   Monitor* black_line_monitor = new BlackLineMonitor();
//   Monitor* yellow_line_monitor = new YellowLineMonitor();
//   Monitor* green_line_monitor = new GreenLineMonitor();
//   Monitor* red_block_monitor = new RedBlockMonitor();
//   Monitor* arm_up_monitor = new ArmMonitor(43 , -1);
//   Monitor* arm_down_monitor = new ArmMonitor(0, 1);

//   Scene* stop_scene = new Scene(stop_action, nullptr, nullptr);

//   Scene* line_trace_scene100 = new Scene(line_trace_right_action, blue_line_monitor, stop_scene);
//   Scene* left_turn_scene100 = new Scene(left_turn_action2, new AngleMonitor(-95), line_trace_scene100);
//   Scene* blackfindrun2 = new Scene(straight_pwm20_action, black_line_monitor, left_turn_scene100);
//   Scene* straight3434 = new Scene(straight_pwm20_action, new DistanceMonitor(50), blackfindrun2);


//   Scene* straight3344 = new Scene(left_turn_action2, new AngleMonitor(-40), left_turn_scene100);
//   Scene* straight9999 = new Scene(straight_pwm20_action, black_line_monitor, straight3344);
//   Scene* straight334 = new Scene(straight_pwm20_action, new DistanceMonitor(50), straight9999);
//   Scene* chototurn = new Scene(right_turn_action, new AngleMonitor(20), straight334);
//   Scene* blackfind9 = new Scene(straight_pwm20_action, black_line_monitor, chototurn);
//   Scene* straight899 = new Scene(straight_pwm20_action, new DistanceMonitor(50), blackfind9);
//   Scene* turnright1 = new Scene(right_turn_action, new AngleMonitor(20), straight899);
//   Scene* akanotoki = new Scene(straight_pwm20_action, new DistanceMonitor(50), turnright1);
//   Scene* linetracer = new Scene(line_trace_right_action, yellow_line_monitor, akanotoki);

//   Scene* blackfind43 = new Scene(right_turn_action, new AngleMonitor(60), linetracer);
//   Scene* blackfindrun89 = new Scene(straight_pwm20_action, black_line_monitor, blackfind43);
//   Scene* straight999 = new Scene(straight_pwm20_action, new DistanceMonitor(90), blackfindrun89);
//   Scene* rightturn = new Scene(right_turn_action, new AngleMonitor(15), straight999);
//   Scene* straight99 = new Scene(straight_pwm20_action, new DistanceMonitor(130), rightturn);


//   Scene* rightturn11 = new Scene(line_trace_left_action, red_line_monitor, straight99);//?
//   Scene* turn_left_scene = new Scene(left_turn_action, new AngleMonitor(-25), rightturn11);//?
//   Scene* find_blackline_scene1 = new Scene(straight_pwm20_action, black_line_monitor, turn_left_scene);
//   Scene* straight_scene2 = new Scene(straight_pwm20_action, new DistanceMonitor(50), find_blackline_scene1);
//   Scene* left_turn_scene1 = new Scene(left_turn_action, new AngleMonitor(-40),straight_scene2);
//   Scene* back_scene1 = new Scene(back_pwm10_action, new DistanceMonitor(-120), left_turn_scene1);//青の時１


//   Scene* blackfind22 = new Scene(straight_pwm20_action, black_line_monitor, straight3434);//ここが最後kuroのところ
//   Scene* straight1155 = new Scene(straight_pwm20_action, new DistanceMonitor(50), blackfind22);
//   Scene* turn_scene34 = new Scene(left_turn_action, new AngleMonitor(-20), straight1155);
//   Scene* linetrace66 = new Scene(straight_pwm20_action, black_line_monitor, turn_scene34);
//   Scene* redhold_scene1 = new Scene(straight_pwm20_action, new DistanceMonitor(150), linetrace66);
//   Scene* turn_scene344 = new Scene(right_turn_action2, new AngleMonitor(17), redhold_scene1);//1komeakanotoki kansei

//   Scene* push_scene1 = new DivergentScene(straight_pwm10_action, new DistanceMonitor(110), back_scene1, turn_scene344);//みる
//   Scene* arm_stop_scene1 = new Scene(arm_stop_action, nullptr, push_scene1);
//   Scene* arm_down_scene1 = new Scene(arm_down_action, arm_down_monitor, arm_stop_scene1);
//   Scene* block_color_get_scene1 = new Scene(stop_action, red_block_monitor, arm_down_scene1);
//   Scene* arm_up_scene1 = new Scene(arm_up_action, arm_up_monitor, block_color_get_scene1);
//   Scene* line_trace_stop_scene1 = new Scene(stop_action, nullptr, arm_up_scene1);//a-mu
//   Scene* right_linetrace_scene = new Scene(line_trace_right_action, blue_line_monitor, line_trace_stop_scene1);//青見るまでライントレース
//   Scene* right_turn_scene2 = new Scene(right_turn_action, new AngleMonitor(40), right_linetrace_scene);//旋回
//   Scene* find_blackline_scene = new Scene(straight_pwm20_action, black_line_monitor, right_turn_scene2);//黒まで
//   Scene* straight_scene1 = new Scene(straight_pwm20_action, new DistanceMonitor(50), find_blackline_scene);//黒を見ないように
//   Scene* left_turn_scene = new Scene(left_turn_action, new AngleMonitor(-20), straight_scene1);//ちょっと左に回転
//   Scene* straight1 = new Scene(straight_pwm20_action, black_line_monitor, left_turn_scene); //黒まで直進
//   Scene* right_turn_scene1 = new Scene(right_turn_action, new AngleMonitor(60), straight1);//これが赤から脱出

//   return right_turn_scene1;
// }


// //5555555555555555555555555555555555555555555555555555555555555555555555//1個目赤判定しちゃうけどまあできる
// Scene* Process::getScenePattern5() {//２つ目ブロックの緑が判定されないこと以外できるはず
//   Action* line_trace_right_action = new LineTraceAction(15, 15, 1, 0.155, 0.01, 0.018);//いいかも
//   Action* line_trace_left_action = new LineTraceAction(15, 15, -1, 0.155, 0.01, 0.018);
//   Action* stop_action = new WheelAction(0, 0);
//   Action* right_turn_action = new WheelAction(10, -10);
//   Action* left_turn_action = new WheelAction(-10, 10);
//   Action* left_turn_action2 = new WheelAction(1, 5);
//   Action* straight_pwm40_action = new WheelAction(40, 40);
//   Action* straight_pwm20_action = new WheelAction(20, 20);
//   Action* straight_pwm10_action = new WheelAction(10, 10);
//   Action* back_pwm10_action = new WheelAction(-10, -10);
//   Action* arm_up_action = new ArmAction(10);
//   Action* arm_down_action = new ArmAction(-10);
//   Action* arm_stop_action = new ArmAction(0);

//   Monitor* red_line_monitor = new RedLineMonitor();
//   Monitor* blue_line_monitor = new BlueLineMonitor();
//   Monitor* black_line_monitor = new BlackLineMonitor();
//   Monitor* yellow_line_monitor = new YellowLineMonitor();
//   Monitor* green_line_monitor = new GreenLineMonitor();
//   Monitor* red_block_monitor = new RedBlockMonitor();
//   Monitor* arm_up_monitor = new ArmMonitor(43 , -1);
//   Monitor* arm_down_monitor = new ArmMonitor(0, 1);

//   Scene* stop_scene = new Scene(stop_action, nullptr, nullptr);

//   Scene* line_trace_scene100 = new Scene(line_trace_left_action, blue_line_monitor, stop_scene);
//   Scene* left_turn_scene100 = new Scene(left_turn_action, new AngleMonitor(-75), line_trace_scene100);//goalikuyatu yattenai
//   Scene* straight10 = new Scene(straight_pwm20_action, black_line_monitor, left_turn_scene100);//ここからゴールまで
//   Scene* straight9 = new Scene(straight_pwm20_action, new DistanceMonitor(50), straight10);
//   Scene* straight8 = new Scene(straight_pwm20_action, black_line_monitor, straight9);
//   Scene* straight7 = new Scene(straight_pwm20_action, new DistanceMonitor(50), straight8);
//   Scene* straight6 = new Scene(straight_pwm20_action, black_line_monitor, straight7);
//   Scene* straight5 = new Scene(straight_pwm20_action, new DistanceMonitor(100), straight6);//ここからゴールに
//   Scene* turn_scene5 = new Scene(left_turn_action, new AngleMonitor(-10), straight5);
// //::akanobaai↑ kansei

//   Scene* straight_scene1000 = new Scene(straight_pwm20_action, new DistanceMonitor(110), stop_scene);
//   Scene* line_trace_scene1000 = new Scene(line_trace_left_action, blue_line_monitor, straight_scene1000);
//   Scene* left_turn_scene1000 = new Scene(left_turn_action, new AngleMonitor(-70), line_trace_scene1000);
//   Scene* straight88 = new Scene(straight_pwm20_action, black_line_monitor, left_turn_scene1000);//ゴールラインいくやつyattenai
//   Scene* straight77 = new Scene(straight_pwm20_action, new DistanceMonitor(50), straight88);
//   Scene* straight66 = new Scene(straight_pwm20_action, black_line_monitor, straight77);
//   Scene* turn_scene22 = new Scene(left_turn_action, new AngleMonitor(-22),  straight66);//
//   Scene* hold_scene = new Scene(straight_pwm20_action, new DistanceMonitor(120), turn_scene22);
//   Scene* straight96 = new Scene(line_trace_right_action, green_line_monitor, hold_scene);//ここで持つhazu..未検証
//   Scene* turnrightq = new Scene(right_turn_action, new AngleMonitor(60), straight96);
//   Scene* blackfindq = new Scene(straight_pwm20_action, black_line_monitor, turnrightq);
//   Scene* straight4 = new Scene(straight_pwm20_action, new DistanceMonitor(50), blackfindq);
//   Scene* left_turn_scene3 = new Scene(left_turn_action, new AngleMonitor(-23), straight4);  
//   Scene* straight3 = new Scene(straight_pwm20_action, black_line_monitor,left_turn_scene3);
//   Scene* turn_scene4 = new Scene(left_turn_action, new AngleMonitor(-30),straight3);
//   Scene* back_scene1 = new Scene(back_pwm10_action, new DistanceMonitor(-120), turn_scene4);//青ならもどってかいてん


//   Scene* hantei_scene1 = new DivergentScene(straight_pwm20_action, new DistanceMonitor(100), back_scene1, turn_scene5);
//   Scene* arm_stop_scene1 = new Scene(arm_stop_action, nullptr, hantei_scene1);
//   Scene* arm_down_scene1 = new Scene(arm_down_action, arm_down_monitor, arm_stop_scene1);
//   Scene* block_color_get_scene1 = new Scene(stop_action, red_block_monitor, arm_down_scene1);
//   Scene* arm_up_scene1 = new Scene(arm_up_action, arm_up_monitor, block_color_get_scene1);
//   Scene* line_trace_stop_scene1 = new Scene(stop_action, nullptr, arm_up_scene1);

//   Scene* straight_scene5 = new Scene(line_trace_left_action, blue_line_monitor, line_trace_stop_scene1);
//   Scene* left_turn_scene1 = new Scene(left_turn_action, new AngleMonitor(-30), straight_scene5);
//   Scene* straight_scene4 = new Scene(straight_pwm20_action, black_line_monitor, left_turn_scene1);
//   Scene* straight_scene3 = new Scene(straight_pwm20_action, new DistanceMonitor(50), straight_scene4);
//   Scene* right_turn_scene2 = new Scene(right_turn_action, new AngleMonitor(55), straight_scene3);//最初の黒から向き変える
//   Scene* straight1 = new Scene(straight_pwm20_action, black_line_monitor, right_turn_scene2); 
//   Scene* right_turn_scene1 = new Scene(right_turn_action, new AngleMonitor(60), straight1);//これが赤から脱出

//   return right_turn_scene1;

// }

void Process::setup() {
  // 動作
 	Action* line_trace_right_action = new LineTraceAction(63, 63, 1, 0.0966, 0.01, 0.0387);//直線GPT これつかえばよいのでは
  Action* line_trace_right_action2 = new LineTraceAction(25, 25, 1, 0.15, 0.75, 0.015);

	Action* line_trace_left_action = new LineTraceAction(63, 63, -1, 0.0966, 0.01, 0.0387);
	Action* line_trace_left_action2 = new LineTraceAction(25, 25, -1, 0.15, 0.75, 0.015);
	Action* line_trace_rightcurve_action = new LineTraceAction(50, 50, 1, 0.45, 0.01, 0.055);//右ライントレースカーブgptゴールまでだけ
  //難所
	Action* line_trace_rightloop_action = new LineTraceAction(30, 30, 1, 0.15, 0.75, 0.015);//大円　gptの値　右
	Action* line_trace_leftloop_action = new LineTraceAction(30, 30, -1, 0.15, 0.75, 0.015);//大円　左ライントレース
	Action* line_trace_rightloopslow_action = new LineTraceAction(15, 15, 1, 0.15, 0.75, 0.015);//ゆっくり右
	Action* line_trace_leftloopslow_action = new LineTraceAction(15, 15, -1, 0.15, 0.75, 0.015);//ゆっくり左
	Action* line_trace_smallloop_action = new LineTraceAction(20, 20, -1, 0.12, 0.01, 0.02);//小円　右 nazo

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
  Scene* stop_scene = new Scene(stop_action, nullptr, nullptr);

  // 監視
  Monitor* black_line_monitor = new BlackLineMonitor();
  Monitor* blue_line_monitor = new BlueLineMonitor();
  Monitor* red_line_monitor = new RedLineMonitor();

  // シーン
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

//   //---------------------決め打ち走行ver
// 	// Scene* kirikawari_scene4 = new Scene(straight_pwm20_action, black_line_monitor, small_loop_scene1);
// 	// Scene* kirikawari_scene3 = new Scene(kirikae_action2, new DistanceMonitor(100), kirikawari_scene4);
// 	// Scene* kirikawari_scene2 = new Scene(straight_pwm20_action, new DistanceMonitor(250), kirikawari_scene3);
// 	// Scene* kirikawari_scene1 = new Scene(kirikae_action, new DistanceMonitor(200), kirikawari_scene2);
// 	// Scene* big_loop_scene2 = new Scene(line_trace_leftloop_action, blue_line_monitor, kirikawari_scene1);//ここで青判定がドンピシャなら成功する。はず。
// 	// Scene* big_loop_scene1 = new Scene(line_trace_rightloop_action, black_line_monitor, big_loop_scene2);
//   //----------------------------------------------

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
	Scene* start_scene = new Scene(line_trace_right_action2, blue_line_monitor, stop_scene);//直線//uchi
  // 開始シーン
  // scene_ = block_entry_scene;
  // ブロックdeトレジャーから始める場合
  scene_ = start_scene;
}
