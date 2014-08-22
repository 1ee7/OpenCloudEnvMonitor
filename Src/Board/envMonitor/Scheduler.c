/*
 *  该模块实现系统调度和系统时间功能。
 *  系统时间是系统的TICK数。
 */

#include "Scheduler.h"

time_val        g_system_time;
int             g_rtcTimerID    = 0;
static char     g_save_time_cnt = SYSTIME_SAVE_CNT;


/*
 *  初始化Scheduler模块，由Initializer模块调用。
 */
int Scheduler_Init(void)
{
  int   rtcPrescaler = 327;
  char *pTime        = NULL;
  int   err          = 0;

  
  SystemDebug_DEBUG(UEC(0,MID_SCHEDULER,UEC_FUNC_SCHEDULER_INIT,UEC_CODE_FUNC_ENTER));
  
  //调用APP_TIMER_INIT宏初始化app_timer模块。PERSCLAER为327，≈100Hz
  err = SettingManager_Read(SETTINGMANAGER_ID(MID_SCHEDULER,SID_SCHEDULER_RTC_PRESCALER),(char*)&rtcPrescaler, sizeof(rtcPrescaler));
  if (err != 0) {
    return err;
  }

  APP_TIMER_INIT(rtcPrescaler, SCHEDULER_MAX_TIMERS, SCHEDULER_TIMER_OPSIZE, true);
  APP_SCHED_INIT(SCHED_MAX_EVENT_DATA_SIZE, SCHED_QUEUE_SIZE);

  err = SettingManager_Read(SYSTIME_SETID,(char*)&g_system_time, sizeof(time_val));
  if (err) {
    return err;
  }

  g_rtcTimerID = Scheduler_Register(1,Scheduler_sysTimeHandler);
  if (g_rtcTimerID < 0) {
    err = UEC(1,MID_SCHEDULER, UEC_FUNC_SCHEDULER_INIT, UEC_SCHEDULER_SYSTIME_REG);
    SystemDebug_ERROR(err);
    return err;
  }

  
  SystemDebug_DEBUG(UEC(0,MID_SCHEDULER,UEC_FUNC_SCHEDULER_INIT,UEC_CODE_FUNC_EXIT));
  return 0;
}
void Scheduler_Deinit(void)
{
  SystemDebug_DEBUG(UEC(0,MID_SCHEDULER,UEC_FUNC_SCHEDULER_DEINIT,UEC_CODE_FUNC_ENTER));
  
  app_timer_stop_all();
  
  SystemDebug_DEBUG(UEC(0,MID_SCHEDULER,UEC_FUNC_SCHEDULER_DEINIT,UEC_CODE_FUNC_EXIT));
  return ;
}
int Scheduler_Register(uint32_t timeout, SCHEDULER_HANDLER handler)
{
  int ret = 0;
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
    int err = UEC(1,MID_SCHEDULER,UEC_FUNC_SCHEDULER_REG,(ret|UEC_CODE_SCHEDULER_APP_TIMER_START));
    SystemDebug_ERROR(err);
    return err;
  }
  ret = id;

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
      SystemDebug_ERROR(UEC(1, MID_SCHEDULER, UEC_FUNC_SCHEDULER_RUN, (err|UEC_CODE_SCHEDULER_SD_APP_EVT_WAIT)));
    }

  }

  SystemDebug_DEBUG(UEC(0,MID_SCHEDULER,UEC_FUNC_SCHEDULER_RUN,UEC_CODE_FUNC_EXIT));
}
static void Scheduler_sysTimeHandler(void *pContext)
{
  SystemDebug_DEBUG(UEC(0,MID_SCHEDULER,UEC_FUNC_SCHEDULER_SYSTIME,UEC_CODE_FUNC_ENTER));
  
  if (g_system_time.msecond < 99) {
    //毫秒数还未达到1秒的边界
    ++g_system_time.msecond;
  } else {
    //毫秒数达到1秒的边界，秒数增加1，并判断是否达到分钟的边界。
    g_system_time.msecond = 0;
    ++g_system_time.second;
    if (g_system_time.second == 60) {
      g_system_time.second = 0;
      ++g_system_time.minute;
      if ( g_system_time.minute == 60) {
        g_system_time.minute = 0;
        ++g_system_time.hour;
        if (g_system_time.hour == 24) {
          g_system_time.hour = 0;
          ++g_system_time.day;
          if (g_system_time.month == 2) {
            if (g_system_time.day == 28) {
              g_system_time.day = 0;
              ++g_system_time.month;
            }
          } else if (g_system_time.month == 1 || g_system_time.month == 3 ||
                     g_system_time.month == 5 || g_system_time.month == 7    ||
                     g_system_time.month == 8 || g_system_time.month == 10  ||
                     g_system_time.month == 12) {
             if (g_system_time.day == 31) {
               g_system_time.day = 0;
               ++g_system_time.month;
               if (g_system_time.month == 13) {
                 g_system_time.month = 1;
                 ++g_system_time.year;
               }
             } 
          } else {
            if (g_system_time.day == 30) {
              g_system_time.day = 0;
              ++g_system_time.month;
            }
          }
        }
      }
    }
  }
  --g_save_time_cnt;
  if (g_save_time_cnt == 0) {
    g_save_time_cnt = SYSTIME_SAVE_CNT;
    SettingManager_Write(SYSTIME_SETID, (char*)&g_system_time, sizeof(time_val));
  }

  SystemDebug_DEBUG(UEC(0,MID_SCHEDULER,UEC_FUNC_SCHEDULER_SYSTIME,UEC_CODE_FUNC_EXIT));
}
