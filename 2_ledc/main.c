#include"main.h"
//使能外设时钟
void clk_enable(void)
{
    CCM_CCGR0 = 0xffffffff;
    CCM_CCGR1 = 0xffffffff;
    CCM_CCGR2 = 0xffffffff;
    CCM_CCGR3 = 0xffffffff;
    CCM_CCGR4 = 0xffffffff;
    CCM_CCGR5 = 0xffffffff;
    CCM_CCGR6 = 0xffffffff;
}

//初始化LED
void led_init()
{
    SW_MUX_GPIO1_IO03 = 0x5;     //复用为GPIO
    SW_PAD_GPIO1_IO03 = 0x10b0;  //设置GPIO_03电气属性

    GPIO1_DR = 0x0;       //打开LED灯
    GPIO1_GDIR = 0x8;     //设置为输出
}

//短延时
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

//开灯
void led_on(void)
{
    GPIO1_DR &= ~(1<<3);  //bit3清零
}

//关灯
void led_off(void)
{
    GPIO1_DR |= (1<<3);  //bit3置1

}

int main(void)
{
    /*使能外设时钟*/
    clk_enable();

    /*初始化LED*/
    led_init();

    /* 设置LED闪烁*/
    while(1)
    {
        led_on();
        delay(500);

        led_off();
        delay(500);
    }
    return 0;
}