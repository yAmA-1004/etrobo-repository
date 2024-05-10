#include "YellowLineMonitor.h"

YellowLineMonitor::YellowLineMonitor() {
}

bool YellowLineMonitor::check() {
    // G値がB値よりも60大きくなったら黄ラインとみなす
    int g = Device::get_g();
    int b = Device::get_b();
    return g - b > 60;
}