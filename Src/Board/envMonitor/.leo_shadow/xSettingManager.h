//@+leo-ver=4-thin
//@+node:gan0ling.20140625145623.3317:@shadow SettingManager.h
//@@language c
//@@tabwidth -2
//@+others
//@+node:gan0ling.20140819205828.3579:多重文件包含保护
#ifndef _SETTINGMANAGER_H_
#define _SETTINGMANAGER_H_

//@-node:gan0ling.20140819205828.3579:多重文件包含保护
//@+node:gan0ling.20140720110024.3513:NordicSDK通用头文件
#include "nrf_soc.h"
#include "nordic_common.h"
#include "nrf.h"
#include "nrf51.h"
#include "nrf51_bitfields.h"

//@-node:gan0ling.20140720110024.3513:NordicSDK通用头文件
//@+node:gan0ling.20140720110024.8519:头文件
#include "Scheduler.h"

//@-node:gan0ling.20140720110024.8519:头文件
//@+node:gan0ling.20140720110024.8520:变量定义
#define SETTINGMANAGER_ID(MID,SID)   ((MID<<24) | (SID&0xFFFFFF))

#define SETTINGMANAGER_START_ADDR    (0x0003FC00)
#define SETTINGMANAGER_SIZE          (1024)

typedef struct {
  int offset;
  char size;
} SettingManager_Setting;

//@-node:gan0ling.20140720110024.8520:变量定义
//@+node:gan0ling.20140720110024.8524:ModulerID定义
#define MID_BOOTLOADER          (0)
#define MID_MAIN                (1)
#define MID_SYSTEMDEBUG         (2)
#define MID_SETTINGMANAGER      (3)
#define MID_INITIALIZER         (4)
#define MID_SCHEDULER           (5)
#define MID_I2CDRIVER           (6)
#define MID_ADCDRIVER           (7)
#define MID_SPIDRIVER           (8)
#define MID_GPIODRIVER          (9)
#define MID_UARTDRIVER          (10)
#define MID_BLESERVICES         (11)
#define MID_ONEWIREDRIVER       (12)
#define MID_ROMDRIVER           (13)
#define MID_SPIFLASHDRIVER      (14)
#define MID_DATASTORAGE         (15)
#define MID_INTERPRETER         (16)
#define MID_CONFIGPARSER        (17)
#define MID_BOARDMANAGER        (18)
#define MID_SENSORMANAGER       (19)
#define MID_SENSORCAPTURE       (20)
#define MID_SENSORUPLOADER      (21)
#define MID_SENSORQUERY         (22)

//@-node:gan0ling.20140720110024.8524:ModulerID定义
//@+node:gan0ling.20140810085610.3561:SettingID定义
#define SID_SCHEDULER_RTC_PRESCALER  (1)
#define SID_SCHEDULER_RTC_VALUE      (2)

#define SID_INITIALIZER_MOD_ENA      (1)


#define SYSTIME_SETID         SETTINGMANAGER_ID(MID_SCHEDULER,SID_SCHEDULER_RTC_VALUE)
#define MODULE_EN_SETID       SETTINGMANAGER_ID(MID_INITIALIZER, SID_INITIALIZER_MOD_ENA)

//@-node:gan0ling.20140810085610.3561:SettingID定义
//@+node:gan0ling.20140820074143.3597:UEC函数码
#define UEC_FUNC_SETTINGMANAGER_INIT    (1)
#define UEC_FUNC_SETTINGMANAGER_DEINIT  (2)
#define UEC_FUNC_SETTINGMANAGER_READ    (3)
#define UEC_FUNC_SETTINGMANAGER_WRITE   (4)

//@-node:gan0ling.20140820074143.3597:UEC函数码
//@+node:gan0ling.20140820074143.3598:UEC错误码
//@-node:gan0ling.20140820074143.3598:UEC错误码
//@+node:gan0ling.20140818081647.3565:SettingManager_Init声明
int SettingManager_Init(void);

//@-node:gan0ling.20140818081647.3565:SettingManager_Init声明
//@+node:gan0ling.20140818081647.3566:SettingManager_Deinit声明
void SettingManager_Deinit(void);

//@-node:gan0ling.20140818081647.3566:SettingManager_Deinit声明
//@+node:gan0ling.20140720110024.8521:SettingManager_Read声明
int SettingManager_Read(int id, char *buf, int size);

//@-node:gan0ling.20140720110024.8521:SettingManager_Read声明
//@+node:gan0ling.20140809152829.3560:SettingManager_Write声明
int SettingManager_Write(int id, char* buf, int len);

//@-node:gan0ling.20140809152829.3560:SettingManager_Write声明
//@+node:gan0ling.20140819205828.3580:结束保护
#endif
//@-node:gan0ling.20140819205828.3580:结束保护
//@-others
//@nonl
//@-node:gan0ling.20140625145623.3317:@shadow SettingManager.h
//@-leo
