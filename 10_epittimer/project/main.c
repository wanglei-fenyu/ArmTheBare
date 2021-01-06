#include "main.h"
#include "bsp_clk.h"
#include "bsp_delay.h"
#include "bsp_led.h"
#include "bsp_beep.h"
#include "bsp_key.h"
#include "bsp_int.h"
#include "bsp_exti.h"

int main(void)
{
    unsigned char led_state = OFF;

    //中断初始化
     int_init();
    //初始化系统时钟
    imx6u_clkinit();

    /*使能外设时钟*/
    clk_enable();

    //外部中断初始化
    exti_init();

    /*初始化L*/
    led_init();
    beep_init();
    key_init();

    /* 设置LED闪烁*/
    while(1)
    {
        
        led_state = !led_state;
        led_switch(LED0,led_state);
        delay(500);
    }
    return 0;
}