#include "bsp_epit.h"
#include "bsp_int.h"
#include "bsp_led.h"

//初始化EPIT
void epit_init(unsigned int frac,unsigned int value)
{
    if(frac > 4095)//判断分频 如果大于最大值就将其控制在允许最大值
    {
        frac = 4095;
    }

    //配置EPIT1_CR寄存器
    EPIT1->CR = 0; 
    EPIT1->CR = (1 << 1) | (1 << 2) |(1 << 3) | (frac << 4) | (1 << 24);
    
    EPIT1->LR = value; //加载寄存器 value
    EPIT1->CMPR = 0;   //value-- ,到0中断(比较value也没有到0)

    //初始化中断
    GIC_EnableIRQ(EPIT1_IRQn);//使能这个中断

    system_register_irqhandler(EPIT1_IRQn,(system_irq_handler_t)epit_irqhandler,NULL);

    //打开EPIT1
    EPIT1->CR |= 1 << 0;
}

//EPIT1中断服务函数
void epit_irqhandler(unsigned int gicciar,void *param)
{
    static unsigned char state = 0;
    state = !state;
    /*
    if(EPIT1->SR & (1 << 0))  //判断是否中断发生
    {
        led_switch(LED0,state);
    }

    //清除中断标志位（方便下一次中断到触发）
    EPIT1->SR |= (1 << 0); 
    */
   led_switch(LED0,state);
   EPIT1->SR |= (1 << 0); 
}