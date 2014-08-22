//@+leo-ver=4-thin
//@+node:gan0ling.20140625145623.3311:@shadow Scheduler.h
//@@language c
//@@tabwidth -2
//@+others
//@+node:gan0ling.20140819205828.3583:多重文件包含保护
#ifndef _SCHEDULER_H_
#define _SCHEDULER_H_

//@-node:gan0ling.20140819205828.3583:多重文件包含保护
//@+node:gan0ling.20140720110024.3513:NordicSDK通用头文件
#include "nrf_soc.h"
#include "nordic_common.h"
#include "nrf.h"
#include "nrf51.h"
#include "nrf51_bitfields.h"

//@-node:gan0ling.20140720110024.3513:NordicSDK通用头文件
//@+node:gan0ling.20140817072332.3563:头文件
#include "app_scheduler.h"
#include "app_timer.h"
#include "ble_stack_handler_types.h"

#include "SystemDebug.h"
#include "SettingManager.h"
//@-node:gan0ling.20140817072332.3563:头文件
//@+node:gan0ling.20140720110024.3519:变量声明

typedef void (*SCHEDULER_HANDLER)(void * p_context);

#define SCHEDULER_TIMER_OPSIZE   (10)
#define SCHEDULER_MAX_TIMERS     (5)

#define SCHED_MAX_EVENT_DATA_SIZE       MAX(APP_TIMER_SCHED_EVT_SIZE,BLE_STACK_HANDLER_SCHED_EVT_SIZE)       /**< Maximum size of scheduler events. */
#define SCHED_QUEUE_SIZE                30                                          /**< Maximum number of events in the scheduler queue. */

typedef struct {
  char year;
  char month;
  char day;
  char hour;
  char minute;
  char second;
  char msecond;
  char reserve;
} time_val;

#define SYSTIME_SAVE_CNT      (80)

//@<<UEC函数码>>
//@+node:gan0ling.20140803162743.3580:<<UEC函数码>>
#define UEC_FUNC_SCHEDULER_INIT        (1)
#define UEC_FUNC_SCHEDULER_DEINIT      (2)
#define UEC_FUNC_SCHEDULER_REG         (3)
#define UEC_FUNC_SCHEDULER_UNREG       (4)
#define UEC_FUNC_SCHEDULER_RUN         (5)
#define UEC_FUNC_SCHEDULER_SYSTIME     (6)

//@-node:gan0ling.20140803162743.3580:<<UEC函数码>>
//@nl
//@<<UEC错误码>>
//@+node:gan0ling.20140803162743.3581:<<UEC错误码>>
#define UEC_CODE_SCHEDULER_APP_TIMER_CREATE     (1<<10)
#define UEC_CODE_SCHEDULER_APP_TIMER_START      (2<<10)
#define UEC_CODE_SCHEDULER_APP_TIMER_STOP       (3<<10)
#define UEC_CODE_SCHEDULER_SD_APP_EVT_WAIT      (4<<10)

#define UEC_SCHEDULER_SETTINGMANAGER_READ       (1)

// 调用Scheduler_Register函数注册system timer处理函数失败。
#define UEC_SCHEDULER_SYSTIME_REG            (2)  

//@-node:gan0ling.20140803162743.3581:<<UEC错误码>>
//@nl

//@-node:gan0ling.20140720110024.3519:变量声明
//@+node:gan0ling.20140720110024.3514:Scheduler_Init声明

int Scheduler_Init(void);

//@-node:gan0ling.20140720110024.3514:Scheduler_Init声明
//@+node:gan0ling.20140720110024.3515:Scheduler_Deinit声明
void Scheduler_Deinit(void);

//@-node:gan0ling.20140720110024.3515:Scheduler_Deinit声明
//@+node:gan0ling.20140720110024.3516:Scheduler_Register声明
int Scheduler_Register(uint32_t timeout, SCHEDULER_HANDLER handler);

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
//@+node:gan0ling.20140807165228.3553:Scheduler_sysTimeHandler声明
static void Scheduler_sysTimeHandler(void *pContext);

//@-node:gan0ling.20140807165228.3553:Scheduler_sysTimeHandler声明
//@+node:gan0ling.20140819205828.3584:结束保护
#endif
//@-node:gan0ling.20140819205828.3584:结束保护
//@-others
//@nonl
//@-node:gan0ling.20140625145623.3311:@shadow Scheduler.h
//@-leo
