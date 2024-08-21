#include "util.h"
#include "ArmMonitor.h"

ArmMonitor::ArmMonitor(int target, int from) {
    target_ = target;
    from_ = from;
    //printf("target:%d from:%d----------\n",target_, from_ );
    
}

bool ArmMonitor::check() {
    // 比較の方向が1ならば上から比較(下回ったら到達)、-1ならば下から比較(上回ったら到達)
    int count = armMotor_.getCount();
    //printf("count:%d\n", count);
    return ((count * -1) * from_) < (target_ * from_);

}


//Monitor* arm_up_monitor = new ArmMonitor(40, -1);
//Monitor* arm_down_monitor = new ArmMonitor(0, 1);
