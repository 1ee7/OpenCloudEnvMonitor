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
  //@  << app_timer初始化 >>
  //@+node:gan0ling.20140720110024.3522:<<app_timer初始化>>
  //调用APP_TIMER_INIT宏初始化app_timer模块。PERSCLAER为327，≈100Hz
  APP_TIMER_INIT();
  //@nonl
  //@-node:gan0ling.20140720110024.3522:<<app_timer初始化>>
  //@nl
}
//@nonl
//@-node:gan0ling.20140720110024.3505:Scheduler_Init
//@+node:gan0ling.20140720110024.3507:Scheduler_Deinit
//@-node:gan0ling.20140720110024.3507:Scheduler_Deinit
//@+node:gan0ling.20140720110024.3508:Scheduler_Register
//@-node:gan0ling.20140720110024.3508:Scheduler_Register
//@+node:gan0ling.20140720110024.3509:Scheduler_Unregister
//@-node:gan0ling.20140720110024.3509:Scheduler_Unregister
//@+node:gan0ling.20140720110024.3510:Scheduler_Run
//@-node:gan0ling.20140720110024.3510:Scheduler_Run
//@-others
//@nonl
//@-node:gan0ling.20140625132223.3261:@shadow Scheduler.c
//@-leo
