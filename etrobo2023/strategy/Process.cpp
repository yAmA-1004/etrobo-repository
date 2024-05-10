#include "util.h"
#include "Process.h"
#include "Env.h"
#include "ColorSensor.h"

Process::Process() {
}

void Process::init() {
  init_f("ETROBO2023");

  // キャリブレーション
  calibrate();

  // インスタンスの生成
  //  setup();
  // setupDoubleLoopOnly();
  // setupLineTrace();
  setupPattern1();

  // タッチセンサーでスタート
  msg_f("Touch to start", 5);
  while(!touchSensor_.isPressed()) {
  }
  msg_f("Start!", 1);
  msg_f("", 2);
  msg_f("", 3);
  msg_f("", 4);
  msg_f("", 5);
}

void Process::exec() {
  // シーン終了に達した場合
  if (scene_ == nullptr) {
    msg_f("Finish", 1);
    return;
  }

  // シーンの実行
  if (scene_->exec()) {
      // シーンが終了したら次のシーンをセット
      ev3_speaker_play_tone(NOTE_D4, 100);  // 音で知らせる
      scene_ = scene_->getNext();
  }
}

void Process::calibrate() {
  ColorSensor colorSensor = ColorSensor(PORT_2);

  // コース選択
  msg_f("L or R Course", 1);
  while(true) {
    if (ev3_button_is_pressed(LEFT_BUTTON)){
      msg_f("Left course", 2);
      Env::course = 1;
      break;
    }
    if (ev3_button_is_pressed(RIGHT_BUTTON)){
      msg_f("Right course", 2);
      Env::course = 0;
      break;
    }
  }
  msg_f("Push touch sensor", 3);
  while(!touchSensor_.isPressed()) {
  }

  // 白地カラー値取得
  msg_f("White (R:Default)", 1);
  msg_f("", 2);
  msg_f("", 3);
  while(true) {
    if (ev3_button_is_pressed(LEFT_BUTTON)){
      rgb_raw_t rgb_val;
      colorSensor.getRawColor(rgb_val);
      msg_f(rgb_val.r, 2);
      msg_f(rgb_val.g, 3);
      msg_f(rgb_val.b, 4);
      Env::white_r = rgb_val.r;
      Env::white_g = rgb_val.g;
      Env::white_b = rgb_val.b;
      break;
    }

    // 白地デフォルト値
    if (ev3_button_is_pressed(RIGHT_BUTTON)){
      msg_f(Env::white_r, 2);
      msg_f(Env::white_g, 3);
      msg_f(Env::white_b, 4);
      break;
    }
  }
  msg_f("Push touch sensor", 5);
  while(!touchSensor_.isPressed()) {
  }

  // 黒ラインカラー値取得
  msg_f("Black (R:Default)", 1);
  msg_f("", 2);
  msg_f("", 3);
  msg_f("", 4);
  msg_f("", 5);
  while(true) {
    if (ev3_button_is_pressed(LEFT_BUTTON)){
      rgb_raw_t rgb_val;
      colorSensor.getRawColor(rgb_val);
      msg_f(rgb_val.r, 2);
      msg_f(rgb_val.g, 3);
      msg_f(rgb_val.b, 4);
      Env::black_r = rgb_val.r;
      Env::black_g = rgb_val.g;
      Env::black_b = rgb_val.b;
      break;
    }

    // 黒ラインデフォルト値
    if (ev3_button_is_pressed(RIGHT_BUTTON)){
      msg_f(Env::black_r, 2);
      msg_f(Env::black_g, 3);
      msg_f(Env::black_b, 4);
      break;
    }
  }
}
