#include "Monitor.cpp"
#include "Device.h"
#include "Env.h"

class RedBlockMonitor : public Monitor {
public:
    RedBlockMonitor();
    bool check();
};
