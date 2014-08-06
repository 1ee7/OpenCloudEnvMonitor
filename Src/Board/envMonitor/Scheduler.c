/*
 *  该模块实现系统调度和系统时间功能。
 *  系统时间是系统的TICK数。
 */

#include "Scheduler.h"


/*
 *  初始化Scheduler模块，由Initializer模块调用。
 */
bool Scheduler_Init(void)
{
  int rtcPrescaler = 327;

  SystemDebug_DEBUG(UEC(0,MID_SCHEDULER,UEC_FUNC_SCHEDULER_INIT,UEC_CODE_FUNC_ENTER));
  
  //调用APP_TIMER_INIT宏初始化app_timer模块。PERSCLAER为327，≈100Hz
  rtcPrescaler = SettingManager_Read(SETTINGMAMAGER_ID(MID_SCHEDULER,SID_SCHEDULER_RTC_PRESCALER))

  APP_TIMER_INIT(rtcPrescaler, SCHEDULER_MAX_TIMERS, SCHEDULER_TIMER_OPSIZE, true);
  APP_SCHED_INIT(SCHED_MAX_EVENT_DATA_SIZE, SCHED_QUEUE_SIZE);

  
  SystemDebug_DEBUG(UEC(0,MID_SCHEDULER,UEC_FUNC_SCHEDULER_INIT,UEC_CODE_FUNC_EXIT));
  return true;
}
void Scheduler_Deinit(void)
{
  SystemDebug_DEBUG(UEC(0,MID_SCHEDULER,UEC_FUNC_SCHEDULER_DEINIT,UEC_CODE_FUNC_ENTER));
  
  app_timer_stop_all();
  
  SystemDebug_DEBUG(UEC(0,MID_SCHEDULER,UEC_FUNC_SCHEDULER_DEINIT,UEC_CODE_FUNC_EXIT));
  return ;
}
int Scheduler_Register(uint32_t timeout, SCHEDLUER_HANDLER handler)
{
  int ret = -1;
  app_timer_id_t id = 0;

  SystemDebug_DEBUG(UEC(0,MID_SCHEDULER,UEC_FUNC_SCHEDULER_REG,UEC_CODE_FUNC_ENTER));
  
  if (timeout ==  0) {
    ret = UEC(1,MID_SCHEDULER,UEC_FUNC_SCHEDULER_REG,UEC_CODE_PARAM_1);
    SystemDebug_ERROR(ret);
    return ret;
  }
  if (handler == NULL) {
    ret = UEC(1,MID_SCHEDULER,UEC_FUNC_SCHEDULER_REG,UEC_CODE_PARAM_2);
    SystemDebug_ERROR(ret);
    return ret;
  }

  ret = app_timer_create(&id, APP_TIMER_MODE_REPEATED, handler);
  if (ret != NRF_SUCCESS) {
    int err = UEC(1,MID_SCHEDULER,UEC_FUNC_SCHEDULER_REG,(ret|UEC_CODE_SCHEDULER_APP_TIMER_CREATE));
    SystemDebug_ERROR(err);
    return err;
  }

  ret = app_timer_start(id, timeout, NULL);
  if (ret != NRF_SUCCESS) {
    int err = UEC(1,MID_SCHEDULER,UEC_FUNC_SCHEDULER_REG,(ret|UEC_CODE_SCHEDULER_APP_TIMER_START);
    SystemDebug_ERROR(err);
    return err;
  }
  ret = id

  SystemDebug_DEBUG(UEC(0,MID_SCHEDULER,UEC_FUNC_SCHEDULER_REG,UEC_CODE_FUNC_EXIT));
  return ret;  
}
bool Scheduler_Unregister(int id)
{
  int ret = 0;
  
  SystemDebug_DEBUG(UEC(0,MID_SCHEDULER,UEC_FUNC_SCHEDULER_UNREG,UEC_CODE_FUNC_ENTER));

  if (id < 0) {
    int err = UEC(1,MID_SCHEDULER,UEC_FUNC_SCHEDULER_UNREG,UEC_CODE_PARAM_1);
    SystemDebug_ERROR(err);
    return err;
  }

  ret = app_timer_stop(id);
  if (ret != NRF_SUCCESS) {
    int err = UEC(1, MID_SCHEDULER, UEC_FUNC_SCHEDULER_UNREG, (ret|UEC_CODE_SCHEDULER_APP_TIMER_STOP));
    SystemDebug_ERROR(err);
    return err;
  }

  
  SystemDebug_DEBUG(UEC(0,MID_SCHEDULER,UEC_FUNC_SCHEDULER_UNREG,UEC_CODE_FUNC_EXIT));
  
  return ret;
}
int Scheduler_Run(void)
{
  int err = 0;

  SystemDebug_DEBUG(UEC(0,MID_SCHEDULER,UEC_FUNC_SCHEDULER_RUN,UEC_CODE_FUNC_ENTER));

  while (1) {
    app_sched_execute();

    err = sd_app_evt_wait();
    if (err != NRF_SUCCESS) {
      SystemDebug_ERROR(UEC(1, MID_SCHEDULER, MID_FUNC_SCHEDULER_RUN, (err|UEC_CODE_SCHEDULER_SD_APP_EVT_WAIT)););
    }

  }

  SystemDebug_DEBUG(UEC(0,MID_SCHEDULER,UEC_FUNC_SCHEDULER_RUN,UEC_CODE_FUNC_EXIT));
}
