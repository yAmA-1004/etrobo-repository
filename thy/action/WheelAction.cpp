#include "WheelAction.h"

WheelAction::WheelAction(int leftPWM, int rightPWM) : leftPWM_(leftPWM), rightPWM_(rightPWM) {
}

void WheelAction::run() {
  Device::move(leftPWM_, rightPWM_);
}
