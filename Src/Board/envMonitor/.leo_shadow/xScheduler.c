//@+leo-ver=4-thin
//@+node:gan0ling.20140625132223.3261:@shadow Scheduler.c
//@@language c
//@@tabwidth -2
//@+others
//@+node:gan0ling.20140803162743.3562:模块介绍
/*
 *  该模块实现系统调度和系统时间功能。
 *  系统时间是系统的TICK数。
 */
//@-node:gan0ling.20140803162743.3562:模块介绍
//@+node:gan0ling.20140803162743.3563:头文件

#include "Scheduler.h"

//@-node:gan0ling.20140803162743.3563:头文件
//@+node:gan0ling.20140807165228.3554:全局变量
time_val        g_system_time;
int             g_rtcTimerID    = 0;
static char     g_save_time_cnt = SYSTIME_SAVE_CNT;

//@-node:gan0ling.20140807165228.3554:全局变量
//@+node:gan0ling.20140803162743.3554:Scheduler_Init

/*
 *  初始化Scheduler模块，由Initializer模块调用。
 */
int Scheduler_Init(void)
{
  //@  <<局部变量>>
  //@+node:gan0ling.20140803162743.3564:<<局部变量>>
  int   rtcPrescaler = 327;
  char *pTime        = NULL;
  int   err          = 0;

  //@-node:gan0ling.20140803162743.3564:<<局部变量>>
  //@nl
  
  SystemDebug_DEBUG(UEC(0,MID_SCHEDULER,UEC_FUNC_SCHEDULER_INIT,UEC_CODE_FUNC_ENTER));
  
  //@  <<app_timer初始化>>
  //@+node:gan0ling.20140803162743.3565:<<app_timer初始化>>
  //调用APP_TIMER_INIT宏初始化app_timer模块。PERSCLAER为327，≈100Hz
  err = SettingManager_Read(SETTINGMANAGER_ID(MID_SCHEDULER,SID_SCHEDULER_RTC_PRESCALER),(char*)&rtcPrescaler, sizeof(rtcPrescaler));
  if (err != 0) {
    return err;
  }

  APP_TIMER_INIT(rtcPrescaler, SCHEDULER_MAX_TIMERS, SCHEDULER_TIMER_OPSIZE, true);
  //@nonl
  //@-node:gan0ling.20140803162743.3565:<<app_timer初始化>>
  //@nl
  //@  <<app_scheduler初始化>>
  //@+node:gan0ling.20140806143636.3547:<<app_scheduler初始化>>
  APP_SCHED_INIT(SCHED_MAX_EVENT_DATA_SIZE, SCHED_QUEUE_SIZE);

  //@-node:gan0ling.20140806143636.3547:<<app_scheduler初始化>>
  //@nl
  //@  <<系统时钟初始化>>
  //@+node:gan0ling.20140807165228.3552:<<系统时钟初始化>>
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

  //@-node:gan0ling.20140807165228.3552:<<系统时钟初始化>>
  //@nl
  
  SystemDebug_DEBUG(UEC(0,MID_SCHEDULER,UEC_FUNC_SCHEDULER_INIT,UEC_CODE_FUNC_EXIT));
  return 0;
}
//@-node:gan0ling.20140803162743.3554:Scheduler_Init
//@+node:gan0ling.20140803162743.3555:Scheduler_Deinit
void Scheduler_Deinit(void)
{
  SystemDebug_DEBUG(UEC(0,MID_SCHEDULER,UEC_FUNC_SCHEDULER_DEINIT,UEC_CODE_FUNC_ENTER));
  
  //@  <<停止所有timer>>
  //@+node:gan0ling.20140803162743.3566:<<停止所有timer>>
  app_timer_stop_all();
  //@nonl
  //@-node:gan0ling.20140803162743.3566:<<停止所有timer>>
  //@nl
  
  SystemDebug_DEBUG(UEC(0,MID_SCHEDULER,UEC_FUNC_SCHEDULER_DEINIT,UEC_CODE_FUNC_EXIT));
  return ;
}
//@-node:gan0ling.20140803162743.3555:Scheduler_Deinit
//@+node:gan0ling.20140803162743.3556:Scheduler_Register
int Scheduler_Register(uint32_t timeout, SCHEDULER_HANDLER handler)
{
  //@  <<局部变量>>
  //@+node:gan0ling.20140803162743.3568:<<局部变量>>
  int ret = 0;
  app_timer_id_t id = 0;

  //@-node:gan0ling.20140803162743.3568:<<局部变量>>
  //@nl
  SystemDebug_DEBUG(UEC(0,MID_SCHEDULER,UEC_FUNC_SCHEDULER_REG,UEC_CODE_FUNC_ENTER));
  
  //@  <<参数检查>>
  //@+node:gan0ling.20140803162743.3569:<<参数检查>>
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

  //@-node:gan0ling.20140803162743.3569:<<参数检查>>
  //@nl
  //@  <<创建timer>>
  //@+node:gan0ling.20140803162743.3570:<<创建timer>>
  ret = app_timer_create(&id, APP_TIMER_MODE_REPEATED, handler);
  if (ret != NRF_SUCCESS) {
    int err = UEC(1,MID_SCHEDULER,UEC_FUNC_SCHEDULER_REG,(ret|UEC_CODE_SCHEDULER_APP_TIMER_CREATE));
    SystemDebug_ERROR(err);
    return err;
  }

  //@-node:gan0ling.20140803162743.3570:<<创建timer>>
  //@nl
  //@  <<启动timer>>
  //@+node:gan0ling.20140803162743.3571:<<启动timer>>
  ret = app_timer_start(id, timeout, NULL);
  if (ret != NRF_SUCCESS) {
    int err = UEC(1,MID_SCHEDULER,UEC_FUNC_SCHEDULER_REG,(ret|UEC_CODE_SCHEDULER_APP_TIMER_START));
    SystemDebug_ERROR(err);
    return err;
  }
  ret = id;

  //@-node:gan0ling.20140803162743.3571:<<启动timer>>
  //@nl
  SystemDebug_DEBUG(UEC(0,MID_SCHEDULER,UEC_FUNC_SCHEDULER_REG,UEC_CODE_FUNC_EXIT));
  return ret;  
}
//@-node:gan0ling.20140803162743.3556:Scheduler_Register
//@+node:gan0ling.20140803162743.3567:Scheduler_Unregister
bool Scheduler_Unregister(int id)
{
  int ret = 0;
  
  SystemDebug_DEBUG(UEC(0,MID_SCHEDULER,UEC_FUNC_SCHEDULER_UNREG,UEC_CODE_FUNC_ENTER));

  //@  <<参数检查>>
  //@+node:gan0ling.20140806143636.3548:<<参数检查>>
  if (id < 0) {
    int err = UEC(1,MID_SCHEDULER,UEC_FUNC_SCHEDULER_UNREG,UEC_CODE_PARAM_1);
    SystemDebug_ERROR(err);
    return err;
  }

  //@-node:gan0ling.20140806143636.3548:<<参数检查>>
  //@nl
  //@  <<停止timer>>
  //@+node:gan0ling.20140806143636.3549:<<停止timer>>
  ret = app_timer_stop(id);
  if (ret != NRF_SUCCESS) {
    int err = UEC(1, MID_SCHEDULER, UEC_FUNC_SCHEDULER_UNREG, (ret|UEC_CODE_SCHEDULER_APP_TIMER_STOP));
    SystemDebug_ERROR(err);
    return err;
  }

  //@-node:gan0ling.20140806143636.3549:<<停止timer>>
  //@nl
  
  SystemDebug_DEBUG(UEC(0,MID_SCHEDULER,UEC_FUNC_SCHEDULER_UNREG,UEC_CODE_FUNC_EXIT));
  
  return ret;
}
//@nonl
//@-node:gan0ling.20140803162743.3567:Scheduler_Unregister
//@+node:gan0ling.20140806143636.3550:Scheduler_Run
int Scheduler_Run(void)
{
  //@  <<局部变量>>
  //@+node:gan0ling.20140806143636.3553:<<局部变量>>
  int err = 0;

  //@-node:gan0ling.20140806143636.3553:<<局部变量>>
  //@nl
  SystemDebug_DEBUG(UEC(0,MID_SCHEDULER,UEC_FUNC_SCHEDULER_RUN,UEC_CODE_FUNC_ENTER));

  while (1) {
    //@    <<遍历app_scheduler事件>>
    //@+node:gan0ling.20140806143636.3551:<<遍历app_scheduler事件>>
    app_sched_execute();

    //@-node:gan0ling.20140806143636.3551:<<遍历app_scheduler事件>>
    //@nl
    //@    <<PowerManager>>
    //@+node:gan0ling.20140806143636.3552:<<PowerManager>>
    err = sd_app_evt_wait();
    if (err != NRF_SUCCESS) {
      SystemDebug_ERROR(UEC(1, MID_SCHEDULER, UEC_FUNC_SCHEDULER_RUN, (err|UEC_CODE_SCHEDULER_SD_APP_EVT_WAIT)));
    }

    //@-node:gan0ling.20140806143636.3552:<<PowerManager>>
    //@nl
  }

  SystemDebug_DEBUG(UEC(0,MID_SCHEDULER,UEC_FUNC_SCHEDULER_RUN,UEC_CODE_FUNC_EXIT));
}
//@nonl
//@-node:gan0ling.20140806143636.3550:Scheduler_Run
//@+node:gan0ling.20140809152829.3555:Scheduler_sysTimeHandler
static void Scheduler_sysTimeHandler(void *pContext)
{
  //@  <<局部变量>>
  //@+node:gan0ling.20140809152829.3556:<<局部变量>>
  //@-node:gan0ling.20140809152829.3556:<<局部变量>>
  //@nl
  SystemDebug_DEBUG(UEC(0,MID_SCHEDULER,UEC_FUNC_SCHEDULER_SYSTIME,UEC_CODE_FUNC_ENTER));
  
  //@  <<增加系统时间>>
  //@+node:gan0ling.20140809152829.3558:<<增加系统时间>>
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
  //@nonl
  //@-node:gan0ling.20140809152829.3558:<<增加系统时间>>
  //@nl
  //@  <<定期保存系统时间>>
  //@+node:gan0ling.20140809152829.3557:<<定期保存系统时间>>
  --g_save_time_cnt;
  if (g_save_time_cnt == 0) {
    g_save_time_cnt = SYSTIME_SAVE_CNT;
    SettingManager_Write(SYSTIME_SETID, (char*)&g_system_time, sizeof(time_val));
  }

  //@-node:gan0ling.20140809152829.3557:<<定期保存系统时间>>
  //@nl
  SystemDebug_DEBUG(UEC(0,MID_SCHEDULER,UEC_FUNC_SCHEDULER_SYSTIME,UEC_CODE_FUNC_EXIT));
}
//@nonl
//@-node:gan0ling.20140809152829.3555:Scheduler_sysTimeHandler
//@-others
//@-node:gan0ling.20140625132223.3261:@shadow Scheduler.c
//@-leo
