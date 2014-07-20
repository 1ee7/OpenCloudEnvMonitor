//@+leo-ver=4-thin
//@+node:gan0ling.20140625132223.3261:@shadow Scheduler.c
//@@language c
//@@tabwidth -2
//@+others
//@+node:gan0ling.20140720110024.3512:模块介绍
/*
 *  该模块实现系统调度和系统时间功能。
 */
//@nonl
//@-node:gan0ling.20140720110024.3512:模块介绍
//@+node:gan0ling.20140720110024.3511:IncludeFiles

#include "Scheduler.h"

//@-node:gan0ling.20140720110024.3511:IncludeFiles
//@+node:gan0ling.20140720110024.3520:变量定义


//@-node:gan0ling.20140720110024.3520:变量定义
//@+node:gan0ling.20140720110024.3505:Scheduler_Init
bool Scheduler_Init(void)
{
  //@  <<局部变量>>
  //@+node:gan0ling.20140720110024.8522:<<局部变量>>
  int rtcPrescaler = 327;

  //@-node:gan0ling.20140720110024.8522:<<局部变量>>
  //@nl
  //@  << app_timer初始化 >>
  //@+node:gan0ling.20140720110024.3522:<<app_timer初始化>>
  //调用APP_TIMER_INIT宏初始化app_timer模块。PERSCLAER为327，≈100Hz
  rtcPrescaler = SettingManager_Read(SETTINGMAMAGER_ID(MID_SCHEDULER,SID_SCHEDULER_RTC_PRESCALER))

  APP_TIMER_INIT(rtcPrescaler, SCHEDULER_MAX_TIMERS, SCHEDULER_TIMER_OPSIZE, true);

  //@-node:gan0ling.20140720110024.3522:<<app_timer初始化>>
  //@nl
  
  return true;
}
//@nonl
//@-node:gan0ling.20140720110024.3505:Scheduler_Init
//@+node:gan0ling.20140720110024.3507:Scheduler_Deinit
void Scheduler_Deinit(void)
{
  //@  <<停止所有timer>>
  //@+node:gan0ling.20140720110024.8526:<<停止所有timer>>
  app_timer_stop_all();
  //@nonl
  //@-node:gan0ling.20140720110024.8526:<<停止所有timer>>
  //@nl
  
  return ;
}
//@nonl
//@-node:gan0ling.20140720110024.3507:Scheduler_Deinit
//@+node:gan0ling.20140720110024.3508:Scheduler_Register
int Scheduler_Register(uint32_t timeout, SCHEDLUER_HANDLER handler)
{
  //@  <<局部变量>>
  //@+node:gan0ling.20140720110024.8527:<<局部变量>>
  int ret = -1;

  //@-node:gan0ling.20140720110024.8527:<<局部变量>>
  //@nl
  //@  <<参数检查>>
  //@+node:gan0ling.20140720110024.8528:<<参数检查>>
  if (timeout ==  0 || handler == NULL) {
      
  }
  //@nonl
  //@-node:gan0ling.20140720110024.8528:<<参数检查>>
  //@nl
  //@  <<创建timer>>
  //@+node:gan0ling.20140720110024.8529:<<创建timer>>
  //@-node:gan0ling.20140720110024.8529:<<创建timer>>
  //@nl
}
//@nonl
//@-node:gan0ling.20140720110024.3508:Scheduler_Register
//@+node:gan0ling.20140720110024.3509:Scheduler_Unregister
//@-node:gan0ling.20140720110024.3509:Scheduler_Unregister
//@+node:gan0ling.20140720110024.3510:Scheduler_Run
//@-node:gan0ling.20140720110024.3510:Scheduler_Run
//@-others
//@nonl
//@-node:gan0ling.20140625132223.3261:@shadow Scheduler.c
//@-leo
