#include "AngleMonitor.h"

AngleMonitor::AngleMonitor(float target, int from) {
    target_ = target;
    from_ = from;
}

bool AngleMonitor::check() {
    // 初回に取得したモータ回転数を初期値とする
    if (init_flg_ == false) {
        last_left_angle_ = Device::get_left_count();
        last_right_angle_ = Device::get_right_count();
        init_flg_ = true;
    }

    // 前回からの走行角度差分を計算し、累積角度に蓄積
    float left_angle = Device::get_left_count();
    float right_angle = Device::get_right_count();
    angle_ += DM / (2.0 * WI) * ((left_angle - last_left_angle_) - (right_angle - last_right_angle_));

    // 今回のモータ回転数を前回とする
    last_left_angle_  = left_angle;
    last_right_angle_ = right_angle;

    // 走行角度が目標値に達したら真を返す
    // 比較の方向が1ならば上から比較(下回ったら到達)、-1ならば下から比較(上回ったら到達)
    return angle_ * from_ < target_ * from_;
}
