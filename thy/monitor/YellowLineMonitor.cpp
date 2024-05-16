#include "YellowLineMonitor.h"

YellowLineMonitor::YellowLineMonitor() {
}

bool YellowLineMonitor::check() {
    // G値がB値よりも40大きくなったら黄ラインとみなす もともと６０
    int g = Device::get_g();
    int b = Device::get_b();
    return g - b > 40;
}
