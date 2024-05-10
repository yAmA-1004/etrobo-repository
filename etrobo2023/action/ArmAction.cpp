#include "ArmAction.h"

ArmAction::ArmAction(int armPWM) : armPWM_(armPWM) {
}

void ArmAction::run() {
  Device::up(armPWM_);
}
