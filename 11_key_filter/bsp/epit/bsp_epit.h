#ifndef __BSP_EPIT_H__
#define __BSP_EPIT_H__
#include "imx6u.h"
void epit_init(unsigned int frac,unsigned int value);

//中断服务函数
void epit_irqhandler(unsigned int gicciar,void *param);
#endif