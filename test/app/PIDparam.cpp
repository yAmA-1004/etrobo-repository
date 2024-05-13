#include "PIDparam.h"

PIDparam::PIDparam(int _target, float _kp,float _ki,float _kd){
    target = _target;
    kp = _kp;
    ki = _ki;
    kd = _kd;
}