#include "DistanceMonitor.h"

DistanceMonitor::DistanceMonitor(float target, int from) {
    target_ = target;
    from_ = from;
}

bool DistanceMonitor::check() {
    // 初回に取得したモータ回転数を初期値とする
    if (init_flg_ == false) {
        last_left_angle_ = Device::get_left_count();
        last_right_angle_ = Device::get_right_count();
        init_flg_ = true;
    }

    // 前回からの回転数差分を計算し、累積距離に蓄積
    float left_angle = Device::get_left_count();
    float right_angle = Device::get_right_count();
    float left_distance  = ((PI * DM) / 360.0) * (left_angle - last_left_angle_);
    float right_distance = ((PI * DM) / 360.0) * (right_angle - last_right_angle_);
    distance_ += (left_distance + right_distance) / 2.0;

    // 今回のモータ回転数を前回とする
    last_left_angle_  = left_angle;
    last_right_angle_ = right_angle;

    // 走行距離が目標値に達したら真を返す
    // 比較の方向が1ならば上から比較(下回ったら到達)、-1ならば下から比較(上回ったら到達)
    return distance_ * from_ < target_ * from_; 
}
