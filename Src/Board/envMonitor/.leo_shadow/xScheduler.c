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
//@+node:gan0ling.20140803162743.3554:Scheduler_Init

/*
 *  初始化Scheduler模块，由Initializer模块调用。
 */
bool Scheduler_Init(void)
{
  //@  <<局部变量>>
  //@+node:gan0ling.20140803162743.3564:<<局部变量>>
  int rtcPrescaler = 327;
  //@nonl
  //@-node:gan0ling.20140803162743.3564:<<局部变量>>
  //@nl

  SystemDebug_DEBUG(UEC(0,MID_SCHEDULER,UEC_FUNC_SCHEDULER_INIT,UEC_CODE_FUNC_ENTER));
  
  //@  <<app_timer初始化>>
  //@+node:gan0ling.20140803162743.3565:<<app_timer初始化>>
  //调用APP_TIMER_INIT宏初始化app_timer模块。PERSCLAER为327，≈100Hz
  rtcPrescaler = SettingManager_Read(SETTINGMAMAGER_ID(MID_SCHEDULER,SID_SCHEDULER_RTC_PRESCALER))

  APP_TIMER_INIT(rtcPrescaler, SCHEDULER_MAX_TIMERS, SCHEDULER_TIMER_OPSIZE, true);
  //@nonl
  //@-node:gan0ling.20140803162743.3565:<<app_timer初始化>>
  //@nl
  //@  <<app_scheduler初始化>>
  //@+node:gan0ling.20140806143636.3547:<<app_scheduler初始化>>
  APP_SCHED_INIT(SCHED_MAX_EVENT_DATA_SIZE, SCHED_QUEUE_SIZE);

  //@-node:gan0ling.20140806143636.3547:<<app_scheduler初始化>>
  //@nl
  
  SystemDebug_DEBUG(UEC(0,MID_SCHEDULER,UEC_FUNC_SCHEDULER_INIT,UEC_CODE_FUNC_EXIT));
  return true;
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
int Scheduler_Register(uint32_t timeout, SCHEDLUER_HANDLER handler)
{
  //@  <<局部变量>>
  //@+node:gan0ling.20140803162743.3568:<<局部变量>>
  int ret = -1;
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
    int err = UEC(1,MID_SCHEDULER,UEC_FUNC_SCHEDULER_REG,(ret|UEC_CODE_SCHEDULER_APP_TIMER_START);
    SystemDebug_ERROR(err);
    return err;
  }
  ret = id

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
      SystemDebug_ERROR(UEC(1, MID_SCHEDULER, MID_FUNC_SCHEDULER_RUN, (err|UEC_CODE_SCHEDULER_SD_APP_EVT_WAIT)););
    }

    //@-node:gan0ling.20140806143636.3552:<<PowerManager>>
    //@nl
  }

  SystemDebug_DEBUG(UEC(0,MID_SCHEDULER,UEC_FUNC_SCHEDULER_RUN,UEC_CODE_FUNC_EXIT));
}
//@nonl
//@-node:gan0ling.20140806143636.3550:Scheduler_Run
//@-others
//@-node:gan0ling.20140625132223.3261:@shadow Scheduler.c
//@-leo
