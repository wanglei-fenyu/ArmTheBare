#ifndef __BSP_LED_H
#define __BSP_LED_H
#include"fsl_common.h"
#include"fsl_iomuxc.h"
#include"MCIMX6Y2.h"
#include"cc.h"

#define ON    1
#define OFF   0
#define LED0 0

void led_init();
void led_on(void);
void led_off(void);
void led_switch(int led,int status);

#endif // DEBUG