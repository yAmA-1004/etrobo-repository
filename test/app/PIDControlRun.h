#ifndef PIDCONTROLRUN_H_
#define PIDCONTROLRUN_H_


#include "PIDparam.h"
#include "PIDCalc.h"

class PIDControlRun{
    public:
        PIDControlRun();
        void SetPIDParameter(PIDparam* _param);
    protected:
        PIDparam *param;
};
#endif