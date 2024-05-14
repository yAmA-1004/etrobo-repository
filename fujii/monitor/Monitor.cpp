#ifndef MONITOR_H_
#define MONITOR_H_

#define PI 3.14159265358    // 円周率
#define DM 100.0    // タイヤの直径(mm)
#define WI 145.0    // 両タイヤの幅(mm)

class Monitor {
public:
    virtual bool check() = 0;
};

#endif
