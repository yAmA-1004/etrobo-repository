#include "util.h"
#include "BlackLineMonitor.h"

BlackLineMonitor::BlackLineMonitor() {
}

bool BlackLineMonitor::check() {
    // RGB値の合計が50に満たなければ黒ラインとみなす
    return Device::get_r() + Device::get_g() + Device::get_b() < 50;
}
