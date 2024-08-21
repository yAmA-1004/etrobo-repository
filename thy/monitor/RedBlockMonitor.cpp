#include "util.h"
#include "RedBlockMonitor.h"

RedBlockMonitor::RedBlockMonitor() {
}

bool RedBlockMonitor::check() {
    int r = Device::get_r();
    int b = Device::get_b();
    if (r > b) {
        Env::red_block_found = true;
        msg_f("RED", 5);
    } else {
        msg_f("BLUE", 5);
    }
    return true;
}
