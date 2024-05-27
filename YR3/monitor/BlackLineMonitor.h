#include "Monitor.cpp"
#include "Device.h"

class BlackLineMonitor : public Monitor {
public:
    BlackLineMonitor();
    bool check();
};
