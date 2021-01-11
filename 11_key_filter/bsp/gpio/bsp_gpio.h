#ifndef __BSP_GPIO_H
#define __BSP_GPIO_H

#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "MCIMX6Y2.h"
#include "cc.h"

//用来描述中断触发类型
typedef enum _gpio_interrupt_mode
{
    kGPIO_NoIntmode = 0U, 				/* 无中断功能 */
    kGPIO_IntLowLevel = 1U, 			/* 低电平触发	*/
    kGPIO_IntHighLevel = 2U, 			/* 高电平触发 */
    kGPIO_IntRisingEdge = 3U, 			/* 上升沿触发	*/
    kGPIO_IntFallingEdge = 4U, 			/* 下降沿触发 */
    kGPIO_IntRisingOrFallingEdge = 5U, 	/* 上升沿和下降沿都触发 */
}gpio_interrupt_mode_t;

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
    gpio_interrupt_mode_t interruptMode;  //中断方式
}gpio_pin_config_t;

void gpio_init(GPIO_Type *base,int pin,gpio_pin_config_t *config);
void gpio_pinwrite(GPIO_Type *base,int pin,int value);
int gpio_pinread(GPIO_Type *base,int pin);

//使能指定IO中断
void gpio_enableint(GPIO_Type *base,unsigned int pin);
//关闭指定IO中断
void gpio_disableint(GPIO_Type *base,unsigned int pin);
//清除中断标志位
void gpio_cleanintflag(GPIO_Type *base,unsigned int pin);
//GPIO中断初始化函数
void gpio_intconfig(GPIO_Type *base,unsigned int pin,gpio_interrupt_mode_t ping_int_mode);
#endif // !1