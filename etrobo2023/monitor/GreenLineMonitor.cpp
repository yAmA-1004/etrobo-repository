#include "GreenLineMonitor.h"

GreenLineMonitor::GreenLineMonitor() {
}

bool GreenLineMonitor::check() {
    // G値がB値とR値よりも20大きくなったら緑ラインとみなす
    int g = Device::get_g();
    int r = Device::get_r();
    int b = Device::get_b();
    return (g - r > 20) && (g - b > 20);
}
