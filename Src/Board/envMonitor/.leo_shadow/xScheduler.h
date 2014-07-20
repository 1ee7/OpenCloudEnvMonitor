//@+leo-ver=4-thin
//@+node:gan0ling.20140625145623.3311:@shadow Scheduler.h
//@@language c
//@@tabwidth -2
//@+others
//@+node:gan0ling.20140720110024.3513:头文件
#include "nordic_common.h"
#include "nrf.h"
#include "nrf51.h"
#include "app_scheduler.h"
#include "app_timer.h"

#include "SystemDebug.h"
#include "SettingManager.h"

//@-node:gan0ling.20140720110024.3513:头文件
//@+node:gan0ling.20140720110024.3519:变量声明及定义

typedef void (*SCHEDULER_HANDLER)(void * p_context);
//@-node:gan0ling.20140720110024.3519:变量声明及定义
//@+node:gan0ling.20140720110024.3514:Scheduler_Init声明

bool Scheduler_Init(void);

//@-node:gan0ling.20140720110024.3514:Scheduler_Init声明
//@+node:gan0ling.20140720110024.3515:Scheduler_Deinit声明
void Scheduler_Deinit(void)

//@-node:gan0ling.20140720110024.3515:Scheduler_Deinit声明
//@+node:gan0ling.20140720110024.3516:Scheduler_Register声明
int Scheduler_Register(int timeout, SCHEDULER_HANDLER handler);

//@-node:gan0ling.20140720110024.3516:Scheduler_Register声明
//@+node:gan0ling.20140720110024.3517:Scheduler_Unregister声明
bool Scheduler_Unregister(int id);

//@-node:gan0ling.20140720110024.3517:Scheduler_Unregister声明
//@+node:gan0ling.20140720110024.3518:Scheduler_Run声明
int Scheduler_Run(void);

//@-node:gan0ling.20140720110024.3518:Scheduler_Run声明
//@-others
//@nonl
//@-node:gan0ling.20140625145623.3311:@shadow Scheduler.h
//@-leo
