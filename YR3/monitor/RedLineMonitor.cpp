#include "RedLineMonitor.h"

RedLineMonitor::RedLineMonitor() {
}

bool RedLineMonitor::check() {
    // R値がB値よりも40大きくなったら赤ラインとみなす
    int r = Device::get_r();
    int b = Device::get_b();
    return r - b > 40;
}
