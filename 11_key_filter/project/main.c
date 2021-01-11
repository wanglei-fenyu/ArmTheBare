#include "main.h"
#include "bsp_clk.h"
#include "bsp_delay.h"
#include "bsp_led.h"
#include "bsp_beep.h"
#include "bsp_key.h"
#include "bsp_int.h"
#include "bsp_exti.h"
#include "bsp_epit.h"
#include "bsp_keyfilter.h"

int main(void)
{
    unsigned char state = OFF;
    int_init();         //中断初始化
    imx6u_clkinit();    //初始化系统时钟
    clk_enable();       //使能外设时钟
    //exti_init();        //外部中断初始化


    /*初始化L*/
    led_init();
    beep_init();
    key_init();
    //epit_init(0,66000000/2);  //周期500ms
    keyfilter_init();

    while(1)
    {
        state = !state;
        led_switch(LED0,state);
        delay(500);
    }
    return 0;
}