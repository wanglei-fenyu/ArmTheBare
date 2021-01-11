#ifndef __BSP_KEYFILTER_H__
#define __BSP_KEYFILTER_H__
#include "imx6u.h"

//keyfilter初始化
void keyfilter_init();

//初始化定时器
void filtertimer_init(unsigned int value);

//EPIT1定时器中断处理函数
void filter_irqhandle(unsigned int gicciar,void *param);

//按键中断服务函数
void gpio1_16_31_irqhandler(unsigned int gicciar,void *param);

//关闭EPIT1定时器
void filtertimer_stop();

//重启EPIT定时器
void filtertimer_restart(unsigned int value);

#endif