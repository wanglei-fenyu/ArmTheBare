#include "main.h"
#include "bsp_clk.h"
#include "bsp_delay.h"
#include"bsp_led.h"
#include "bsp_beep.h"
#include "bsp_key.h"


int main(void)
{
    int i=0;
    unsigned char led_state = OFF;
    unsigned char beep_state = OFF;
    int keyvalue;
    /*使能外设时钟*/
    clk_enable();

    /*初始化L*/
    led_init();
    beep_init();
    key_init();
    imx6u_clkinit();


    /* 设置LED闪烁*/
    while(1)
    {
        //按键控制蜂鸣器
        keyvalue = key_getvalue();
        if(keyvalue)
        {
            switch(keyvalue)
            {
                case KEY0_VALUE: //
                    beep_state = !beep_state;
                    beep_switch(beep_state);
                    break;        
            }
        }

        i++;
        if(i==50)
        {
            i=0;
            led_state = !led_state;
            led_switch(LED0,led_state);

        }
        delay(10);
    }
    return 0;
}