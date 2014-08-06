#include "nordic_common.h"
#include "nrf.h"
#include "nrf51.h"
#include "stdlib.h"
#include "stdio.h"

#define SYSTEMDEBUG_LEVEL_OFF    (0)
#define SYSTEMDEBUG_LEVEL_ERR    (1)
#define SYSTEMDEBUG_LEVEL_WARN   (2)
#define SYSTEMDEBUG_LEVEL_INFO   (3)
#define SYSTEMDEBUG_LEVEL_DBG    (4)



#define UEC_ERR_FLAG_SHIFT   (31)
#define UEC_ERR_FLAG_BITS    (1)
#define UEC_ERR_FLAG         (1<<UEC_ERR_FLAG_SHIFT)

#define UEC_MODULE_ID_SHIFT  (22)
#define UEC_MODULE_ID_BITS   (0x3F)
#define UEC_MODULE_ID_MASK   (~(UEC_MODULE_ID_BITS<<UEC_MODULE_ID_SHIFT))

#define UEC_FUNCTION_SHIFT   (15)
#define UEC_FUNCTION_BITS    (0x7F)
#define UEC_FUNCTION_MASK    (~(UEC_FUNCTIONN_BITS<<UEC_FUNCTION_SHIFT))

#define UEC_CODE_SHIFT       (0)
#define UEC_CODE_BITS        (0x7FFF)
#define UEC_CODE_MASK        (~(UEC_CODE_BITS<<UEC_CODE_SHIFT))

#define UEC(flag, module, func, code) （(flag & UEC_ERR_FLAG_BITS) << UEC_ERR_FLAG_SHIFT |\
                                        (module & UEC_MODULE_BITS) << UEC_MODULE_ID_SHIFT |\
                                        (func & UEC_FUNCTION_BITS) << UEC_FUNCTION_SHIFT |\
                                        (code & UEC_CODE_BITS) << UEC_CODE_SHIFT）
                                        
//--------------NRF SDK中定义的错误码---------------//
#define UEC_CODE_NRF_SVC_HANDLER_MISSING         (0x1)     ///< SVC handler is missing
#define UEC_CODE_NRF_SOFTDEVICE_NOT_ENABLED      (0x2)     ///< SoftDevice has not been enabled
#define UEC_CODE_NRF_INTERNAL                    (0x3)     ///< Internal Error
#define UEC_CODE_NRF_NO_MEM                      (0x4)     ///< No Memory for operation
#define UEC_CODE_NRF_NOT_FOUND                   (0x5)     ///< Not found
#define UEC_CODE_NRF_NOT_SUPPORTED               (0x6)     ///< Not supported
#define UEC_CODE_NRF_INVALID_PARAM               (0x7)     ///< Invalid Parameter
#define UEC_CODE_NRF_INVALID_STATE               (0x8)     ///< Invalid state, operation disallowed in this state
#define UEC_CODE_NRF_INVALID_LENGTH              (0x9)     ///< Invalid Length
#define UEC_CODE_NRF_INVALID_FLAGS               (0xa)     ///< Invalid Flags
#define UEC_CODE_NRF_INVALID_DATA                (0xb)    ///< Invalid Data
#define UEC_CODE_NRF_DATA_SIZE                   (0xc)    ///< Data size exceeds limit
#define UEC_CODE_NRF_TIMEOUT                     (0xd)    ///< Operation timed out
#define UEC_CODE_NRF_NULL                        (0xe)    ///< Null Pointer
#define UEC_CODE_NRF_FORBIDDEN                   (0xf)    ///< Forbidden Operation
#define UEC_CODE_NRF_INVALID_ADDR                (0x10)    ///< Bad Memory Address
#define UEC_CODE_NRF_BUSY                        (0x11)    ///< Busy
//--------------END---------------------------------//

#define UEC_CODE_FUNC_ENTER        (0x12)
#define UEC_CODE_FUNC_EXIT         (0x13)
#define UEC_CODE_PARAM_1           (0x14）
#define UEC_CODE_PARAM_2           (0x15)
#define UEC_CODE_PARAM_3           (0x16)
#define UEC_CODE_PARAM_4           (0x17)

#define UEC_CODE_USER              (0x65)

bool SystemDebug_Init(void);

void SystemDebug_Deinit(void);

int SystemDebug_setStatus(int moduleID, int status);

int SystemDebug_getStatus(int moduleID);

int SystemDebug_Output(int level, int msg);

#define SystemDebug_INFO(msg)  do { SystemDebug_Output(SYSTEMDEBUG_LEVEL_INFO , msg); } while(0)

#define SystemDebug_ERROR(msg)  do { SystemDebug_Output(SYSTEMDEBUG_LEVEL_ERR, msg); } while(0)

#define SystemDebug_WARNNING(msg)  do { SystemDebug_Output(SYSTEMDEBUG_LEVEL_WARN, msg); } while(0)

#define SystemDebug_DEBUG(msg)  do { SystemDebug_Output(SYSTEMDEBUG_LEVEL_DBG, msg); } while(0)

