#include "main.h"
#include "bsp_clk.h"
#include "bsp_delay.h"
#include"bsp_led.h"
#include "bsp_beep.h"

int main(void)
{
    /*使能外设时钟*/
    clk_enable();

    /*初始化LED*/
    led_init();

    //初始化蜂鸣器
    beep_init();

    /* 设置LED闪烁*/
    while(1)
    {
        led_on();
        beep_switch(ON);
        delay(500);

        led_off();
        beep_switch(OFF);
        delay(500);
    }
    return 0;
}