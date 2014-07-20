/*
 *  该模块实现系统调度和系统时间功能。
 */

#include "Scheduler.h"



bool Scheduler_Init(void)
{
  //调用APP_TIMER_INIT宏初始化app_timer模块。PERSCLAER为327，≈100Hz
  APP_TIMER_INIT();
}
