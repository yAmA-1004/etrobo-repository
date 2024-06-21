#include "ArmAction.h"

ArmAction::ArmAction(int armPWM) : armPWM_(armPWM) {
  //printf("armac:%d============ \n", armPWM);
}

void ArmAction::run() {
  Device::up(armPWM_);
}
