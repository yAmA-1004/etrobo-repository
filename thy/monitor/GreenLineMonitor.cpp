#include "GreenLineMonitor.h"

GreenLineMonitor::GreenLineMonitor() {
}

bool GreenLineMonitor::check() {
    // G値がR値よりも20、かつG値がB値よりも20大きくなったら緑ラインとみなす
    int r = Device::get_r();
    int g = Device::get_g();
    int b = Device::get_b();
    return g - r > 20 && g - b > 15;
}
