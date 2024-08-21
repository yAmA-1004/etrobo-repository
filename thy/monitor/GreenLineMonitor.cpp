#include "GreenLineMonitor.h"

GreenLineMonitor::GreenLineMonitor() {
}

bool GreenLineMonitor::check() {
    // G値がR値よりも20、かつG値がB値よりも20大きくなったら緑ラインとみなす
    int r = Device::get_r();
    int g = Device::get_g();
    int b = Device::get_b();
    printf("R:%d G:%d B:%d\n", r, g, b);
    return g - r > 15 && g - b > 8;
}
