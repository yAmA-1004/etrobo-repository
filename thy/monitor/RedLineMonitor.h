#include "Monitor.cpp"
#include "Device.h"

class RedLineMonitor : public Monitor {
public:
    RedLineMonitor();
    bool check();
};
