#include "Monitor.cpp"
#include "Device.h"

class GreenLineMonitor : public Monitor {
public:
    GreenLineMonitor();
    bool check();
};
