#include "bsp_exti.h"
#include "bsp_gpio.h"
#include "bsp_int.h"
#include "bsp_delay.h"
#include "bsp_beep.h"

//初始化外部中断
void exti_init()
{
    IOMUXC_SetPinMux(IOMUXC_UART1_CTS_B_GPIO1_IO18 ,0);
    IOMUXC_SetPinConfig(IOMUXC_UART1_CTS_B_GPIO1_IO18 ,0xf080);

    gpio_pin_config_t key_config;
    key_config.direction = KGPIO_DigitalInput;
    key_config.interruptMode = kGPIO_IntFallingEdge;
    gpio_init(GPIO1,18,&key_config);

    //使能中断ID
    GIC_EnableIRQ(GPIO1_Combined_16_31_IRQn);

    system_register_irqhandler(GPIO1_Combined_16_31_IRQn,(system_irq_handler_t)gpio1_io18_irqhandler,NULL);
    
    //使能gpio中断
    gpio_enableint(GPIO1,18);
}


//中断处理函数
void gpio1_io18_irqhandler(unsigned int gicciar,void *param)
{
    static unsigned char state = 0;
    delay(10); // 中断最好不用延时，这里临时用一下，后面使用定时器中断

    if(gpio_pinread(GPIO1,18) == 0)
    {
        state = !state;
        beep_switch(state);       
    }
    //清除中断表示位
    gpio_cleanintflag(GPIO1,18);
}