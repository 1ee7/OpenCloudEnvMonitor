#include "nordic_common.h"
#include "nrf.h"
#include "nrf51.h"
#include "app_scheduler.h"
#include "app_timer.h"

#include "SystemDebug.h"
#include "SettingManager.h"


typedef void (*SCHEDULER_HANDLER)(void * p_context);

#define SCHEDULER_TIMER_OPSIZE   (10)
#define SCHEDULER_MAX_TIMERS     (5)

#define SCHED_MAX_EVENT_DATA_SIZE       MAX(APP_TIMER_SCHED_EVT_SIZE,BLE_STACK_HANDLER_SCHED_EVT_SIZE)       /**< Maximum size of scheduler events. */
#define SCHED_QUEUE_SIZE                30                                          /**< Maximum number of events in the scheduler queue. */

#define UEC_FUNC_SCHEDULER_INIT        (1)
#define UEC_FUNC_SCHEDULER_DEINIT      (2)
#define UEC_FUNC_SCHEDULER_REG         (3)
#define UEC_FUNC_SCHEDULER_UNREG       (4)
#define UEC_FUNC_SCHEDULER_RUN         (5)


#define UEC_CODE_SCHEDULER_APP_TIMER_CREATE     (1<<10)
#define UEC_CODE_SCHEDULER_APP_TIMER_START      (2<<10)
#define UEC_CODE_SCHEDULER_APP_TIMER_STOP       (3<<10)
#define UEC_CODE_SCHEDULER_SD_APP_EVT_WAIT      (4<<10)

#define SID_SCHEDULER_RTC_PRESCALER (0)

bool Scheduler_Init(void);

void Scheduler_Deinit(void)

int Scheduler_Register(int timeout, SCHEDULER_HANDLER handler);

/*
 *  注销指定的定时调度函数，成功返回0，失败返回相应的UEC错误码。
 */
bool Scheduler_Unregister(int id);

int Scheduler_Run(void);

