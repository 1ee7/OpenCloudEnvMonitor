#include "nordic_common.h"
#include "nrf.h"
#include "nrf51.h"
#include "stdlib.h"
#include "stdio.h"

bool SystemDebug_Init(void);

void SystemDebug_Deinit(void);

int SystemDebug_debugString(char *str, ...);

