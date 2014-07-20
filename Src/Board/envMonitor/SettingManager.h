
#define SETTINGMANAGER_ID(MID,SID)   ((MID<<24) | (SID&0xFFFFFF))

#define MID_BOOTLOADER          (0)
#define MID_MAIN                (1)
#define MID_INITIALIZER         (2)
#define MID_SCHEDULER           (3)
#define MID_SETTINGMANAGER      (4)
#define MID_SYSTEMDEBUG         (5)
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

int SetingManager_Read(int id);

