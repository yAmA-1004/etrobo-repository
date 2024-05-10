#include "RedLineMonitor.h"

RedLineMonitor::RedLineMonitor() {
}

bool RedLineMonitor::check() {
    // R値がB値よりも50大きくなったら赤ラインとみなす
    int r = Device::get_r();
    int b = Device::get_b();
    return r - b > 50;
}
