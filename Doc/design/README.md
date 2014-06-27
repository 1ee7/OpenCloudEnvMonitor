# 本目录主要存放一些设计方面的文档资料。

## 系统框图.xlsx
  保存整个系统硬件方面的详细设计框图。包括如下内容：
  - 系统整体简略示意图                  （已作成）
  - EnvMonitor系统框图                  （已作成）
  - EnvMonitor的详细设计图              （TODO）
  - 各个Sensor board的系统框图          （TODO）
    1. 粉尘传感器Module框图              (TODO)
  - 各个Sensor board的详细设计图        （TODO）

## nRF51822硬件设计相关分析.xlsx
  保存硬件设计时的一些检讨资料。比如电源方案的探讨，外部通信接口的探讨等一些在设计时讨论资料。
  目前有如下内容：
  - 电源方案选择
  - 硬件模块化探讨
  - 增加USB功能的探讨：讨论与上位机USB通信的方法

## 软件框图.xlsx
   保存软件前期设计中的一些检讨资料。
   目前有如下内容：
   - EnvMonitor整体功能拆分
   - Sequence Diagram: 系统比较典型的一些序列图
   - BootLoader模型详细设计
   - Main模块详细设计
   - Initializer模块详细设计
   - Scheduler模块详细设计
   - SensorManager模块详细设计
   - SensorCapture模块详细设计
   - SensorUpload模块详细设计
   - SensorQuery模块详细设计
   - ConfigParser模块详细设计
   - BoardManager模块详细设计
   - OneWire Driver模块设计
   - I2C Driver模块设计
   - ADC Driver模块设计
   - DataCapture模块设计
   - SPI FlashDriver模块详细设计
   - SPI Driver模块详细设计
   - GPIO Driver模块详细设计
   - UART Driver模块详细设计
   - SystemDebug模块详细设计
   - PinMuxCfg模块详细设计
   - BLE Service Driver模块详细设计

## envMonitor.asta
  系统UML设计图表,保存系统软件设计相关的UML图纸。
  - System overview
  - 用户升级序列图(sequence diagram)
  - 固件启动序列图(sequence diagram)
  - System Detail Design

## memory_layout.xlsx
  内部Flash和外部SPI Flash数据布局设计文件。标明数据在Flash中的摆放顺序。
  - 内部Flash Layout
  - 外部SPI Flash Layout
  - 1-Wire EEPROM Layout

## EnvMonitor原理图分析.docx
  关于原理图设计的一些简单分析。后期会提供比较详尽的电路分析资料
  
## 原理图Review记录.md
  EnvMonitor MainBoard原理图Review记录。保存Review过程中的一些问题。
