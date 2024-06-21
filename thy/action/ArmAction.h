#include "Action.cpp"
#include "Device.h"

class ArmAction : public Action {
public:
    ArmAction(int armPWM);
    void run();

private:
    int armPWM_;
};
