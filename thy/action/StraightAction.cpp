//#include "StraightAction.h"

//StraightAction::StraightAction(float leftPWM, float rightPWM) : leftPWM_(leftPWM), rightPWM_(rightPWM) {
//}

//void StraightAction::run() {
//    float left_angle = (float)(Device::get_left_count());
//    float right_angle = (float)(Device::get_right_count());
//    float delta_angle = left_angle - right_angle;

//    float kp = 1.0; // 補正が必要
//    float pwm_adjustment = kp * delta_angle; // 調整量を計算

//    float adjusted_leftPWM = leftPWM_ - pwm_adjustment;
//    float adjusted_rightPWM = rightPWM_ + pwm_adjustment;

//    Device::move((int)adjusted_leftPWM, (int)adjusted_rightPWM);
//    return;
//}


#include "StraightAction.h"

StraightAction::StraightAction(float leftPWM, float rightPWM) : leftPWM_(leftPWM), rightPWM_(rightPWM), previous_left_count_(0), previous_right_count_(0) {
}

void StraightAction::run() {
    float current_left_count = (float)(Device::get_left_count());
    float current_right_count = (float)(Device::get_right_count());

    // 現在のカウントから前回のカウントを引いてデルタを計算
   float delta_left = current_left_count - previous_left_count_;
    float delta_right = current_right_count - previous_right_count_;
   float delta_angle = delta_left - delta_right;

    float kp = 1.0; // 補正係数（必要に応じて調整）
    float pwm_adjustment = kp * delta_angle;

    // 補正されたPWM値を計算
    float adjusted_leftPWM = leftPWM_ - pwm_adjustment;
    float adjusted_rightPWM = rightPWM_ + pwm_adjustment;

    // モーターを動かす
    Device::move((int)adjusted_leftPWM, (int)adjusted_rightPWM);

    // 現在のカウントを次回に備えて保存
    previous_left_count_ = current_left_count;
    previous_right_count_ = current_right_count;
    printf("current_left:%f current_right:%f\n", current_left_count, current_right_count);
    printf("previous_left:%f previous_right:%f\n", previous_left_count_, previous_right_count_); 
    printf("delta_left:%f delta_right:%f\n", delta_left, delta_right);
    return;
}
