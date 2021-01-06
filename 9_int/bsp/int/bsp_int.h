#ifndef __BSP_INT_H__
#define __BSP_INT_H__

#include "imx6u.h"
//定义中断处理函数
typedef void (*system_irq_handler_t)(unsigned int gicciar,void *param);

//中断处理结构体
typedef struct _sys_irq_handler
{
    system_irq_handler_t irqHandler; //中断处理函数
    void *userParam;   //中断处理函数的参数
}sys_irq_handler_t;
void gic_init();

//默认中断处理函数
void default_irqhandler(unsigned int gicciar,void *userParam);

//注册中断处理函数
void system_register_irqhandler(IRQn_Type irq,system_irq_handler_t handler,void *userParam);

//具体的中断处理函数 IRQ_Handler 会调用此函数
void system_irqhandler(unsigned int gicciar,void *userParam);

#endif /* __BSP_INT_H__ */
