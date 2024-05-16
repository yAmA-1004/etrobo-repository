#include "app.h"
#include "Process.h"

static Process *process;

void main_task(intptr_t unused) {
  // 攻略処理(process)の初期化
  process = new Process();
  process->init();

  // 周期的に攻略(proc_task)を実行
  sta_cyc(CYC_ACT);
  slp_tsk();
  
  // 攻略処理(process)の終了
  stp_cyc(CYC_ACT);
  ext_tsk();
}

void proc_task(intptr_t exinf) {
  if (ev3_button_is_pressed(BACK_BUTTON)) {
    // バックボタンが押されたらmain_taskに制御を移す
    wup_tsk(MAIN_TASK);
  } else {
    // 攻略処理(process)の実行
    process->exec();
  }
  ext_tsk();
}
