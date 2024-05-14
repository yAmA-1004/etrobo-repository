#ifndef MY_UNTL_H_
#define MY_UNTL_H_

#include "ev3api.h"

/**
 * シミュレータかどうかの定数を定義します
 */
#if defined(MAKE_SIM)
    static const int _SIM = 1;
#elif defined(MAKE_EV3)
    static const int _SIM = 0;
#else
    static const int _SIM = 0;
#endif

extern void init_f(const char *str);
extern void msg_f(const char *str, int32_t line);
extern void msg_f(int val, int32_t line);

extern void _syslog(int level, char* text);
extern void _log(char *text);
extern void f_log_init();
extern void f_log(char *text);
extern void f_log_flush();

#endif  // MY_UNTL_H_
