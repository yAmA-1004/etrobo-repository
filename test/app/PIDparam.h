#ifndef PIDPARAM_H_
#define PIDPARAM_H_

class PIDparam{
    public:
        PIDparam(int _target, float _kp,float _ki,float _kd);
    public:
        int target;
        float kp;
        float ki;
        float kd;
};
#endif
