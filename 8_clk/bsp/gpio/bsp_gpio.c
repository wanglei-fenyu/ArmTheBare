#include "bsp_gpio.h"


void gpio_init(GPIO_Type *base,int pin,gpio_pin_config_t *config)
{
    if(config->direction == KGPIO_DigitalInput)
    {
        base->GDIR &= ~(1 << pin);
    }
    else
    {
        base->GDIR |= (1 << pin);

        //设置电平输入
        gpio_pinwrite(base,pin,config->outputLogic);
    }
    
}


//控制GPIO高低电平
void gpio_pinwrite(GPIO_Type *base,int pin,int value)
{
    if(value == 0)
    {
        base->DR &= ~(1 << pin);
    }
    else
    {
        base->DR |= (1 << pin);
    }
    
}
//读取指定IO电平
int gpio_pinread(GPIO_Type *base,int pin)
{
    return (((base->DR) >> pin) & 0x1);
}