#ifndef _SCHEDULER_H_
#define _SCHEDULER_H_

#include "nrf_soc.h"
#include "nordic_common.h"
#include "nrf.h"
#include "nrf51.h"
#include "nrf51_bitfields.h"

#include "app_scheduler.h"
#include "app_timer.h"
#include "ble_stack_handler_types.h"

#include "SystemDebug.h"
#include "SettingManager.h"

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

#define UEC_FUNC_SCHEDULER_INIT        (1)
#define UEC_FUNC_SCHEDULER_DEINIT      (2)
#define UEC_FUNC_SCHEDULER_REG         (3)
#define UEC_FUNC_SCHEDULER_UNREG       (4)
#define UEC_FUNC_SCHEDULER_RUN         (5)
#define UEC_FUNC_SCHEDULER_SYSTIME     (6)

#define UEC_CODE_SCHEDULER_APP_TIMER_CREATE     (1<<10)
#define UEC_CODE_SCHEDULER_APP_TIMER_START      (2<<10)
#define UEC_CODE_SCHEDULER_APP_TIMER_STOP       (3<<10)
#define UEC_CODE_SCHEDULER_SD_APP_EVT_WAIT      (4<<10)

#define UEC_SCHEDULER_SETTINGMANAGER_READ       (1)

// 调用Scheduler_Register函数注册system timer处理函数失败。
#define UEC_SCHEDULER_SYSTIME_REG            (2)  



int Scheduler_Init(void);

void Scheduler_Deinit(void);

int Scheduler_Register(uint32_t timeout, SCHEDULER_HANDLER handler);

/*
 *  注销指定的定时调度函数，成功返回0，失败返回相应的UEC错误码。
 */
bool Scheduler_Unregister(int id);

int Scheduler_Run(void);

static void Scheduler_sysTimeHandler(void *pContext);

#endif
