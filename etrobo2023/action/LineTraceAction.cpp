#include "util.h"
#include "LineTraceAction.h"

LineTraceAction::LineTraceAction(float currentPWM, float targetPWM, int edge, float p, float i, float d)
 : currentPWM_(currentPWM), targetPWM_(targetPWM), edge_(edge), p_(p), i_(i), d_(d) {
  pre_diff_ = 0;
  total_diff_ = 0;
}

void LineTraceAction::run() {
  // R値とG値の平均でライントレース
  float r = Device::get_r();
  float g = Device::get_g();
  float diff = (r + g) / 2.0 - 50;

  // PID制御
  total_diff_ += (pre_diff_ + diff) / 2.0 * 0.004;
  float turn = p_ * diff + i_ * total_diff_ + d_ * (diff - pre_diff_) / 0.004;
  pre_diff_ = diff;
  
  Device::move(currentPWM_ - turn * edge_, currentPWM_ + turn * edge_);
}
