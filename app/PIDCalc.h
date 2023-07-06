#ifndef PIDCALC_H_
#define PIDCALC_H_

#include "PIDparam.h"

class PIDCalc{
    public:
        static float calc(PIDparam* pidParam,float brightness);
    private:
        PIDCalc();
        static int diff_val[2];
        static float cumulative_Val;
        static float DELTA_T;
};

#endif