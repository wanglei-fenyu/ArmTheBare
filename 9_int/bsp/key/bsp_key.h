#ifndef __BSP_KEY_H__
#define __BSP_KEY_H__

#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "MCIMX6Y2.h"

/* 按键 */
enum keyvaluety{
    KEY_NONE = 0,
    KEY0_VALUE ,
};

void key_init(void);
int read_key();
int key_getvalue();



#endif  