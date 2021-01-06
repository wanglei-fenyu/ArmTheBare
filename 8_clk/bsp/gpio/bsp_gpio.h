#ifndef __BSP_GPIO_H
#define __BSP_GPIO_H

#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "MCIMX6Y2.h"
#include "cc.h"

//枚举类到结构体
typedef enum _gpio_pin_direction
{
    KGPIO_DigitalInput = 0U,
    KGPIO_DigitalOutput = 1U,
}gpio_pin_direction_t;

typedef struct _gpio_pin_config
{
    gpio_pin_direction_t direction;
    uint8_t outputLogic;
}gpio_pin_config_t;

void gpio_init(GPIO_Type *base,int pin,gpio_pin_config_t *config);
void gpio_pinwrite(GPIO_Type *base,int pin,int value);
int gpio_pinread(GPIO_Type *base,int pin);

#endif // !1