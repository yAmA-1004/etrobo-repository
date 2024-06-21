#include "RedLineMonitor.h"

RedLineMonitor::RedLineMonitor() {
}

bool RedLineMonitor::check() {
    // R値がB値よりも40大きくなったら赤ラインとみなす
    int r = Device::get_r();
    int b = Device::get_b();
    int g = Device::get_g();
    printf("R:%d G:%d B:%d\n", r, g, b);
    return r - b > 40 && b > g;
}
