#ifndef __BSP_BEEP_H
#define __BSP_BEEP_H

#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "MCIMX6Y2.h"

/* 函数声明 */
//beep初始化亚
void beep_init(void);

//beep控制
void beep_switch(int status);

#endif // !__BSP_BEEP_H