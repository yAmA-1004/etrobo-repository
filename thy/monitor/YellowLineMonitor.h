#include "Monitor.cpp"
#include "Device.h"

class YellowLineMonitor : public Monitor {
public:
    YellowLineMonitor();
    bool check();
};
