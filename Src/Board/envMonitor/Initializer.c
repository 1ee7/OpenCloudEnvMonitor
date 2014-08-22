#include "Initializer.h"

extern MODULE_INIT_FUNC Scheduler_Init;
extern MODULE_INIT_FUNC I2CDriver_Init;
extern MODULE_INIT_FUNC ADCDriver_Init;
extern MODULE_INIT_FUNC SPIDriver_Init;
extern MODULE_INIT_FUNC GPIODriver_Init;
extern MODULE_INIT_FUNC UARTDriver_Init;
extern MODULE_INIT_FUNC BLEServices_Init;
extern MODULE_INIT_FUNC OneWireDriver_Init;
extern MODULE_INIT_FUNC ROMDriver_Init;
extern MODULE_INIT_FUNC SPIFlashDriver_Init;
extern MODULE_INIT_FUNC DataStorage_Init;
extern MODULE_INIT_FUNC Interpreter_Init;
extern MODULE_INIT_FUNC ConfigParser_Init;
extern MODULE_INIT_FUNC BoardManager_Init;
extern MODULE_INIT_FUNC SensorManager_Init;
extern MODULE_INIT_FUNC SensorCapture_Init;
extern MODULE_INIT_FUNC SensorUploader_Init;
extern MODULE_INIT_FUNC SensorQuery_Init;

extern MODULE_DEINIT_FUNC Scheduler_Deinit;
extern MODULE_DEINIT_FUNC I2CDriver_Deinit;
extern MODULE_DEINIT_FUNC ADCDriver_Deinit;
extern MODULE_DEINIT_FUNC SPIDriver_Deinit;
extern MODULE_DEINIT_FUNC GPIODriver_Deinit;
extern MODULE_DEINIT_FUNC UARTDriver_Deinit;
extern MODULE_DEINIT_FUNC BLEServices_Deinit;
extern MODULE_DEINIT_FUNC OneWireDriver_Deinit;
extern MODULE_DEINIT_FUNC ROMDriver_Deinit;
extern MODULE_DEINIT_FUNC SPIFlashDriver_Deinit;
extern MODULE_DEINIT_FUNC DataStorage_Deinit;
extern MODULE_DEINIT_FUNC Interpreter_Deinit;
extern MODULE_DEINIT_FUNC ConfigParser_Deinit;
extern MODULE_DEINIT_FUNC BoardManager_Deinit;
extern MODULE_DEINIT_FUNC SensorManager_Deinit;
extern MODULE_DEINIT_FUNC SensorCapture_Deinit;
extern MODULE_DEINIT_FUNC SensorUploader_Deinit;
extern MODULE_DEINIT_FUNC SensorQuery_Deinit;

static MODULE_INIT_FUNC Initializer_initFuncTable[] = {
  NULL,                     //0 - Bootloader
  NULL,                     //1 - Main
  SystemDebug_Init,         //2 - SystemDebug
  SettingManager_Init,      //3 - SettingManager
  Initializer_Init,         //4 - Initializer
  Scheduler_Init,           //5 - Scheduler
  I2CDriver_Init,           //6 - I2CDriver
  ADCDriver_Init,           //7 - ADCDriver
  SPIDriver_Init,           //8 - SPI Driver
  GPIODriver_Init,          //9 - GPIO Driver
  UARTDriver_Init,          //10 - UART Driver
  BLEServices_Init,         //11 - BLE Services Driver
  OneWireDriver_Init,       //12 - One Wire Driver
  ROMDriver_Init,           //13 - ROM Driver
  SPIFlashDriver_Init,      //14 - SPI Flash Driver
  DataStorage_Init,         //15 - Data Storage 
  Interpreter_Init,         //16 - Interpreter
  ConfigParser_Init,        //17 - Config Parser
  BoardManager_Init,        //18 - Board Manager
  SensorManager_Init,       //19 - Sensor Manager
  SensorCapture_Init,       //20 - Sensor Capture
  SensorUploader_Init,      //21 - Sensor Uploader
  SensorQuery_Init,         //22 - Sensor Query
};

static MODULE_DEINIT_FUNC Initializer_deinitFuncTable[] = {
  NULL,                       //0 - Bootloader
  NULL,                       //1 - Main
  SystemDebug_Deinit,         //2 - SystemDebug
  SettingManager_Deinit,      //3 - SettingManager
  Initializer_Deinit,         //4 - Initializer
  Scheduler_Deinit,           //5 - Scheduler
  I2CDriver_Deinit,           //6 - I2CDriver
  ADCDriver_Deinit,           //7 - ADCDriver
  SPIDriver_Deinit,           //8 - SPI Driver
  GPIODriver_Deinit,          //9 - GPIO Driver
  UARTDriver_Deinit,          //10 - UART Driver
  BLEServices_Deinit,         //11 - BLE Services Driver
  OneWireDriver_Deinit,       //12 - One Wire Driver
  ROMDriver_Deinit,           //13 - ROM Driver
  SPIFlashDriver_Deinit,      //14 - SPI Flash Driver
  DataStorage_Deinit,         //15 - Data Storage 
  Interpreter_Deinit,         //16 - Interpreter
  ConfigParser_Deinit,        //17 - Config Parser
  BoardManager_Deinit,        //18 - Board Manager
  SensorManager_Deinit,       //19 - Sensor Manager
  SensorCapture_Deinit,       //20 - Sensor Capture
  SensorUploader_Deinit,      //21 - Sensor Uploader
  SensorQuery_Deinit,         //22 - Sensor Query
};

#define INITIALIZER_MODULE_NUM (sizeof(Initializer_initFuncTable)/sizeof(MODULE_INIT_FUNC))

int Initializer_Init(void)
{
  SystemDebug_DEBUG(UEC(0,MID_INITIALIZER,UEC_FUNC_INITIALIZER_INIT,UEC_CODE_FUNC_ENTER));
  
  SystemDebug_DEBUG(UEC(0,MID_INITIALIZER,UEC_FUNC_INITIALIZER_INIT,UEC_CODE_FUNC_EXIT));
  return 0;
}

void Initializer_Deinit(void)
{
  SystemDebug_DEBUG(UEC(0,MID_INITIALIZER,UEC_FUNC_INITIALIZER_DEINIT,UEC_CODE_FUNC_ENTER));
  
  SystemDebug_DEBUG(UEC(0,MID_INITIALIZER,UEC_FUNC_INITIALIZER_DEINIT,UEC_CODE_FUNC_EXIT));
  return;
}

int Initializer_modInit(int id)
{
  int err = 0;
  int enable = 0;
  
  SystemDebug_DEBUG(UEC(0,MID_INITIALIZER,UEC_FUNC_INITIALIZER_MODINIT,UEC_CODE_FUNC_ENTER));
  
  if (id < 0 || id >= INITIALIZER_MODULE_NUM) {
    err = UEC(1,MID_INITIALIZER,UEC_FUNC_INITIALIZER_MODINIT,UEC_CODE_PARAM_1);
    SystemDebug_ERROR(err);
    return err;
  }

  if (Initializer_initFuncTable[id] == NULL) {
    err = UEC(1,MID_INITIALIZER,UEC_FUNC_INITIALIZER_MODINIT,UEC_CODE_INITIALIZER_INITFUNC_NULL|id);
    SystemDebug_ERROR(err);
    return err;
  }

  err = SettingManager_Read(MODULE_EN_SETID, &enable, sizeof(enable));
  if (err) {
    return err;
  }
  if (enable & (1<<id)) {
    err = Initializer_initFuncTable[id]();
    if (err) {
      return err;
    }
  }

  err = 0;
  SystemDebug_DEBUG(UEC(0,MID_INITIALIZER,UEC_FUNC_INITIALIZER_MODINIT,UEC_CODE_FUNC_EXIT));
  
  return err;
}

int Initializer_allModInit(void)
{
  int i;
  int err = 0;
  int ret=0;
  
  SystemDebug_DEBUG(UEC(0,MID_INITIALIZER,UEC_FUNC_INITIALIZER_ALLMODINIT,UEC_CODE_FUNC_ENTER));
  
  for (i=5; i<INITIALIZER_MODULE_NUM; i++) {
    err = Initializer_modInit(i);
    if (err) {
      ret = UEC(1,MID_INITIALIZER,UEC_FUNC_INITIALIZER_ALLMODINIT,UEC_CODE_INITIALIZER_MODINIT_ERR|i);
      SystemDebug_ERROR(ret);
      return ret;
    }
  }
  
  SystemDebug_DEBUG(UEC(0,MID_INITIALIZER,UEC_FUNC_INITIALIZER_ALLMODINIT,UEC_CODE_FUNC_EXIT));
  
  return 0;
}

int Initializer_modDeinit(int id)
{
  int err = 0;
  
  SystemDebug_DEBUG(UEC(0,MID_INITIALIZER,UEC_FUNC_INITIALIZER_MODDEINIT,UEC_CODE_FUNC_ENTER));

  if (id < 0 || id >= INITIALIZER_MODULE_NUM) {
    err = UEC(1,MID_INITIALZER,UEC_FUNC_INITIALIZER_MODDEINIT,UEC_CODE_PARAM_1);
    SystemDebug_ERROR(err);
    return err;
  }
  if (Initializer_deinitFuncTable[id] == NULL) {
    err = UEC(1,MID_INITIALIZER,UEC_FUNC_INITIALIZER_MODDEINIT,UEC_CODE_INITIALIZER_DEINITFUNC_NULL|id);
    SystemDebug_ERROR(err);
    return err;
  }
  
  Initializer_deinitFuncTable[id]();
  
  SystemDebug_DEBUG(UEC(0,MID_INITIALIZER,UEC_FUNC_INITIALIZER_MODDEINIT,UEC_CODE_FUNC_EXIT));
  return 0;
}
