#include "YellowLineMonitor.h"

YellowLineMonitor::YellowLineMonitor() {
}

bool YellowLineMonitor::check() {
    // G値がB値よりも40大きくなったら黄ラインとみなす もともと６０
    int g = Device::get_g();
    int b = Device::get_b();
    int r = Device::get_r();
    printf("R:%d G:%d B:%d\n", r, g, b);
    return g - b > 32;
}
