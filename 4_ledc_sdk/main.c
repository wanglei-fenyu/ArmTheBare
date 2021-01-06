#include "MCIMX6Y2.h"
#include "fsl_common.h"
#include "fsl_iomuxc.h"
//使能外设时钟
void clk_enable(void)
{
    
    CCM->CCGR0 = 0xffffffff;
    CCM->CCGR1 = 0xffffffff;
    CCM->CCGR2 = 0xffffffff;
    CCM->CCGR3 = 0xffffffff;
    CCM->CCGR4 = 0xffffffff;
    CCM->CCGR5 = 0xffffffff;
    CCM->CCGR6 = 0xffffffff;
}

//初始化LED
void led_init()
{
   // IOMUX_SW_MUX->GPIO1_IO03 = 0x5;     //复用为GPIO
   // IOMUX_SW_PAD->GPIO1_IO03 = 0x10b0;  //设置GPIO_03电气属性
    IOMUXC_SetPinMux(IOMUXC_GPIO1_IO03_GPIO1_IO03,0);
    IOMUXC_SetPinConfig(IOMUXC_GPIO1_IO03_GPIO1_IO03,0x10b0);
    GPIO1->GDIR = 0x8;     //设置为输出
    GPIO1->DR &= ~(1 << 3);	       //打开LED灯
    
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
    GPIO1->DR &= ~(1<<3);  //bit3清零
}

//关灯
void led_off(void)
{
    GPIO1->DR |= (1<<3);  //bit3置1

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