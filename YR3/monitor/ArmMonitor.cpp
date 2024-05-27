#include "util.h"
#include "ArmMonitor.h"

ArmMonitor::ArmMonitor(float target, int from) {
    target_ = target;
    from_ = from;
}

bool ArmMonitor::check() {
    // 比較の方向が1ならば上から比較(下回ったら到達)、-1ならば下から比較(上回ったら到達)
    int count = armMotor_.getCount();
    return count * from_ < target_ * from_;
}
