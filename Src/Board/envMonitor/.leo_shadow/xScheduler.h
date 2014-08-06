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
//@+node:gan0ling.20140720110024.3519:变量声明

typedef void (*SCHEDULER_HANDLER)(void * p_context);

#define SCHEDULER_TIMER_OPSIZE   (10)
#define SCHEDULER_MAX_TIMERS     (5)

#define SCHED_MAX_EVENT_DATA_SIZE       MAX(APP_TIMER_SCHED_EVT_SIZE,BLE_STACK_HANDLER_SCHED_EVT_SIZE)       /**< Maximum size of scheduler events. */
#define SCHED_QUEUE_SIZE                30                                          /**< Maximum number of events in the scheduler queue. */

//@<<UEC函数码>>
//@+node:gan0ling.20140803162743.3580:<<UEC函数码>>
#define UEC_FUNC_SCHEDULER_INIT        (1)
#define UEC_FUNC_SCHEDULER_DEINIT      (2)
#define UEC_FUNC_SCHEDULER_REG         (3)
#define UEC_FUNC_SCHEDULER_UNREG       (4)
#define UEC_FUNC_SCHEDULER_RUN         (5)


//@-node:gan0ling.20140803162743.3580:<<UEC函数码>>
//@nl
//@<<UEC错误码>>
//@+node:gan0ling.20140803162743.3581:<<UEC错误码>>
#define UEC_CODE_SCHEDULER_APP_TIMER_CREATE     (1<<10)
#define UEC_CODE_SCHEDULER_APP_TIMER_START      (2<<10)
#define UEC_CODE_SCHEDULER_APP_TIMER_STOP       (3<<10)
#define UEC_CODE_SCHEDULER_SD_APP_EVT_WAIT      (4<<10)
//@-node:gan0ling.20140803162743.3581:<<UEC错误码>>
//@nl

//@-node:gan0ling.20140720110024.3519:变量声明
//@+node:gan0ling.20140720110024.8523:SettingID定义
#define SID_SCHEDULER_RTC_PRESCALER (0)
//@nonl
//@-node:gan0ling.20140720110024.8523:SettingID定义
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
/*
 *  注销指定的定时调度函数，成功返回0，失败返回相应的UEC错误码。
 */
bool Scheduler_Unregister(int id);

//@-node:gan0ling.20140720110024.3517:Scheduler_Unregister声明
//@+node:gan0ling.20140720110024.3518:Scheduler_Run声明
int Scheduler_Run(void);

//@-node:gan0ling.20140720110024.3518:Scheduler_Run声明
//@-others
//@nonl
//@-node:gan0ling.20140625145623.3311:@shadow Scheduler.h
//@-leo
