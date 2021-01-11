#include"bsp_led.h"
#include "cc.h"

//初始化LED
void led_init()
{
   // IOMUX_SW_MUX->GPIO1_IO03 = 0x5;     //复用为GPIO
   // IOMUX_SW_PAD->GPIO1_IO03 = 0x10b0;  //设置GPIO_03电气属性
    IOMUXC_SetPinMux(IOMUXC_GPIO1_IO03_GPIO1_IO03,0);
    IOMUXC_SetPinConfig(IOMUXC_GPIO1_IO03_GPIO1_IO03,0x10b0);
    GPIO1->GDIR = 0x8;     //设置为输出
    GPIO1->DR &= (1 << 3);	       //关闭LED灯
    
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

//led控制函数
void led_switch(int led,int status)
{
    
    switch(led)
    {
        case LED0:
            if(status == ON)
                GPIO1->DR &= ~(1<<3);  //bit3清零  
            else if (status == OFF)
                GPIO1->DR |= (1<<3);  //bit3置1
            break;
    }   
}
