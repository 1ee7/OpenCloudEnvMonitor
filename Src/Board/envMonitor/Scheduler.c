/*
 *  该模块实现系统调度和系统时间功能。
 */

#include "Scheduler.h"



bool Scheduler_Init(void)
{
  int rtcPrescaler = 327;

  //调用APP_TIMER_INIT宏初始化app_timer模块。PERSCLAER为327，≈100Hz
  rtcPrescaler = SettingManager_Read(SETTINGMAMAGER_ID(MID_SCHEDULER,SID_SCHEDULER_RTC_PRESCALER))

  APP_TIMER_INIT(rtcPrescaler, SCHEDULER_MAX_TIMERS, SCHEDULER_TIMER_OPSIZE, true);

  
  return true;
}
void Scheduler_Deinit(void)
{
  app_timer_stop_all();
  
  return ;
}
int Scheduler_Register(uint32_t timeout, SCHEDLUER_HANDLER handler)
{
  int ret = -1;

  if (timeout ==  0 || handler == NULL) {
      
  }
}
