#include "PIDCalc.h"

int PIDCalc::diff_val[2] = {0,0};
float PIDCalc::cumulative_Val = 0.0;
float PIDCalc::DELTA_T = 0.004;

PIDCalc::PIDCalc(){
    ;
}

float PIDCalc::calc(PIDparam *pidParam,float brightness){
    int diff = brightness - pidParam->target;

    diff_val[1] = diff_val[0];
    diff_val[0] = diff;
    cumulative_Val += ( diff_val[0] + diff_val[1]) / 2.0 * DELTA_T;

    float p = pidParam->kp * diff;
    float i = pidParam->ki * cumulative_Val;
    float d = pidParam->kd * (diff_val[0] - diff_val[1]) / DELTA_T;

    float turn = p+i+d;

    return turn;
}