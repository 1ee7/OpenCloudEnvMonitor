//@+leo-ver=4-thin
//@+node:gan0ling.20140625145623.3318:@shadow Initializer.h
//@@language c
//@@tabwidth -2
//@+others
//@+node:gan0ling.20140819205828.3577:多重文件包含保护
#ifndef _INITIALIZER_H_
#define _INITIALIZER_H_
//@nonl
//@-node:gan0ling.20140819205828.3577:多重文件包含保护
//@+node:gan0ling.20140819205828.3572:模块描述
/*
 *  模块名  ：Initializer 
 *  功能简介：负责初始化系统其他模块，除了Bootloader、Main和SettingManager模块。
 *            Initializer模块保存有各个模块的初始化和扫尾函数指针。
 *            并根据SettingManager中Initializer_enableModule变量决定是否初始化某个模块。
 *            同时，Initializer模块还可以根据指定的模块ID初始化或卸载某个模块。
 */

//@-node:gan0ling.20140819205828.3572:模块描述
//@+node:gan0ling.20140817072332.3562:头文件
//@-node:gan0ling.20140817072332.3562:头文件
//@+node:gan0ling.20140818085033.3569:UEC函数码
#define UEC_FUNC_INITIALIZER_INIT               (1)
#define UEC_FUNC_INITIALIZER_DEINIT             (2)
#define UEC_FUNC_INITIALIZER_MODINIT            (3)
#define UEC_FUNC_INITIALIZER_ALLMODINIT         (4)
#define UEC_FUNC_INITIALIZER_MODDEINIT          (5)
//@nonl
//@-node:gan0ling.20140818085033.3569:UEC函数码
//@+node:gan0ling.20140818085033.3570:UEC错误码
//低8位用于表示模块ID
#define UEC_CODE_INITIALIZER_INITFUNC_NULL    (1<<8)
#define UEC_CODE_INITIALIZER_DEINITFUNC_NULL  (2<<8)
#define UEC_CODE_INITIALIZER_MODINIT_ERR      (3<<8)

//@-node:gan0ling.20140818085033.3570:UEC错误码
//@+node:gan0ling.20140819205828.3574:初始化函数指针的声明
typedef int (*MODULE_INIT_FUNC)(void);

//@-node:gan0ling.20140819205828.3574:初始化函数指针的声明
//@+node:gan0ling.20140819205828.3575:扫尾函数指针的声明
typedef void(*MODULE_DEINIT_FUNC)(void);

//@-node:gan0ling.20140819205828.3575:扫尾函数指针的声明
//@+node:gan0ling.20140819205828.3576:最大模块数量
#define MAX_MODULE    (32)

//@-node:gan0ling.20140819205828.3576:最大模块数量
//@+node:gan0ling.20140818081647.3562:Initializer_Init声明
int Initializer_Init(void);

//@-node:gan0ling.20140818081647.3562:Initializer_Init声明
//@+node:gan0ling.20140818081647.3563:Initializer_Deinit声明
void Initializer_Deinit(void);

//@-node:gan0ling.20140818081647.3563:Initializer_Deinit声明
//@+node:gan0ling.20140818081647.3564:Initializer_modInit声明
int Initializer_modInit(int id);

//@-node:gan0ling.20140818081647.3564:Initializer_modInit声明
//@+node:gan0ling.20140818081647.3567:Initializer_allModInit声明
int Initializer_allModInit(void);

//@-node:gan0ling.20140818081647.3567:Initializer_allModInit声明
//@+node:gan0ling.20140818081647.3568:Initializer_modDeinit声明
int Initializer_modDeinit(int id);

//@-node:gan0ling.20140818081647.3568:Initializer_modDeinit声明
//@+node:gan0ling.20140819205828.3578:结束多重文件包含保护
#endif
//@-node:gan0ling.20140819205828.3578:结束多重文件包含保护
//@-others
//@nonl
//@-node:gan0ling.20140625145623.3318:@shadow Initializer.h
//@-leo
