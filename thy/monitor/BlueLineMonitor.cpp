#include "BlueLineMonitor.h"

BlueLineMonitor::BlueLineMonitor() {
}

bool BlueLineMonitor::check() {
    // B値がR値よりも40大きくなったら青ラインとみなす
    int b = Device::get_b();
    int r = Device::get_r();
    return b - r > 40;
}
