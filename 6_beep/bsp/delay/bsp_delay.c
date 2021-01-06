#include "bsp_delay.h"

void delay_short(volatile unsigned int n)
{
    while(n--);
}

//延时 1ms单位
void delay(volatile unsigned int n)
{
    while(n--)
    {
        delay_short(0x7ff);
    }
}