#include "util.h"
#include "Device.h"

Motor Device::leftMotor_= Motor(PORT_C);
Motor Device::rightMotor_= Motor(PORT_B);
Motor Device::armMotor_= Motor(PORT_A);
ColorSensor Device::colorSensor_= ColorSensor(PORT_2);

float Device::get_left_count() {
    // Lコースならばそのまま左車輪のモータ値を取得、Rコースならば右車輪
    if (Env::course == 1) {
        return leftMotor_.getCount();
    } else {
        return rightMotor_.getCount();
    }
}

float Device::get_right_count() {
    // Lコースならばそのまま右車輪のモータ値を取得、Rコースならば左車輪
    if (Env::course == 1) {
        return rightMotor_.getCount();
    } else {
        return leftMotor_.getCount();
    }
}

float Device::get_arm_count() {
    return armMotor_.getCount();
}

int Device::get_r() {
    // 白地RGB値を各々100、黒ラインRGB値を各々0にして、現R値を0～100にマッピング(正規化)
    rgb_raw_t rgb_val;
    colorSensor_.getRawColor(rgb_val);
    msg_f(rgb_val.r, 2);
    msg_f(rgb_val.g, 3);
    msg_f(rgb_val.b, 4);
    return (rgb_val.r * 1.0 - Env::black_r) / (Env::white_r - Env::black_r) * 100.0; 
}

int Device::get_g() {
    // 白地RGB値を各々100、黒ラインRGB値を各々0にして、現G値を0～100にマッピング(正規化)
    rgb_raw_t rgb_val;
    colorSensor_.getRawColor(rgb_val);
    msg_f(rgb_val.r, 2);
    msg_f(rgb_val.g, 3);
    msg_f(rgb_val.b, 4);
    return (rgb_val.g * 1.0 - Env::black_g) / (Env::white_g - Env::black_g) * 100.0; 
}

int Device::get_b() {
    // 白地RGB値を各々100、黒ラインRGB値を各々0にして、現B値を0～100にマッピング(正規化)
    rgb_raw_t rgb_val;
    colorSensor_.getRawColor(rgb_val);
    msg_f(rgb_val.r, 2);
    msg_f(rgb_val.g, 3);
    msg_f(rgb_val.b, 4);
    return (rgb_val.b * 1.0 - Env::black_b) / (Env::white_b - Env::black_b) * 100.0; 
}

void Device::move(int leftPWM, int rightPWM) {
    // Lコースならばそのまま左右の車輪に出力、Rコースならば左右を反転
    if (Env::course == 1) {
        leftMotor_.setPWM(leftPWM);
        rightMotor_.setPWM(rightPWM);
    } else {
        leftMotor_.setPWM(rightPWM);
        rightMotor_.setPWM(leftPWM);
    }
}

void Device::up(int armPWM) {
    armMotor_.setPWM(armPWM);
}
