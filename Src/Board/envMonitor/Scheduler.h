#include "nordic_common.h"
#include "nrf.h"
#include "nrf51.h"
#include "app_scheduler.h"
#include "app_timer.h"

#include "SystemDebug.h"
#include "SettingManager.h"


typedef void (*SCHEDULER_HANDLER)(void * p_context);

bool Scheduler_Init(void);

void Scheduler_Deinit(void)

int Scheduler_Register(int timeout, SCHEDULER_HANDLER handler);

bool Scheduler_Unregister(int id);

int Scheduler_Run(void);

