#include "util.h"

FILE *log_fp;

void init_f(const char *str){
  // フォントの設定と0行目の表示
  ev3_lcd_set_font(EV3_FONT_MEDIUM);
  ev3_lcd_draw_string(str, 0, 0);
}

/**
 * 行単位で引数の文字列を表示
 * @param str 表示する文字列
 * @param line 20ドットごとの行番号（1から5）
 */
void msg_f(const char *str, int32_t line) {
  const int8_t line_height = 20;
  ev3_lcd_fill_rect(0, line * line_height, EV3_LCD_WIDTH, line_height, EV3_LCD_WHITE);
  ev3_lcd_draw_string(str, 0, line * line_height);
}

void msg_f(int val, int32_t line) {
  char valStr[256];
  sprintf(valStr, "%d", val);
  msg_f(valStr, line);
}

void msg_f(float val, int32_t line) {
  char valStr[256];
  sprintf(valStr, "%f", val);
  msg_f(valStr, line);
}

//*****************************************************************************
// 関数名 : _syslog
// 引数 :   int   level - SYSLOGレベル
//          char* text  - 出力文字列
// 返り値 : なし
// 概要 : SYSLOGレベルlebelのログメッセージtextを出力します。
//        SYSLOGレベルはRFC3164のレベル名をそのまま（ERRだけはERROR）
//        `LOG_WARNING`の様に定数で指定できます。
//*****************************************************************************
void _syslog(int level, char* text){
    static int _log_line = 0;
    const int8_t line_height = 20;

    if (_SIM)
    {
        syslog(level, text);
    }
    else
    {
        ev3_lcd_draw_string(text, 0, line_height*_log_line++);
        // ev3_lcd_draw_string(text, 0, CALIB_FONT_HEIGHT*_log_line++);
    }
}

//*****************************************************************************
// 関数名 : _log
// 引数 :   char* text  - 出力文字列
// 返り値 : なし
// 概要 : SYSLOGレベルNOTICEのログメッセージtextを出力します。
//*****************************************************************************
void _log(char *text){
    _syslog(LOG_NOTICE, text);
}

void f_log_init(){
  log_fp = fopen("applog.txt","a");
}
void f_log(char *text){
  if ( log_fp != NULL ){
    fputs(text,log_fp);
  }
}

void f_log_flush(){
  if ( log_fp != NULL ){
    fflush(log_fp);
  }
}
