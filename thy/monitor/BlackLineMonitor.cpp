#include "util.h"
#include "BlackLineMonitor.h"

BlackLineMonitor::BlackLineMonitor() {
}

bool BlackLineMonitor::check() {
    // RGB値の合計が50に満たなければ黒ラインとみなす
    //return Device::get_r() + Device::get_g() + Device::get_b() < 100;
    int b = Device::get_b();
    int r = Device::get_r();
    int g = Device::get_g();
    return b - r < 10 && g - r < 10; //&& b < 50;//10

}
