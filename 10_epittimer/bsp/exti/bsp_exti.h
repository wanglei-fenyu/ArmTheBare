#ifndef __BSP_EXTI_H
#define __BSP_EXTI_H
#include"imx6u.h"

//初始化外部中断
void exti_init();
//中断处理函数
void gpio1_io18_irqhandler(unsigned int gicciar,void *param);

#endif