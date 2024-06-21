#include "BlueLineMonitor.h"

BlueLineMonitor::BlueLineMonitor() {
}

bool BlueLineMonitor::check() {
    // B値がR値よりも35大きくなったら青ラインとみなす
    int b = Device::get_b();
    int r = Device::get_r();
    int g = Device::get_g();
    printf("blue!");
    
    return (b - r > 28);
    //return (b - r > 25) && (b - g > 10);
};
