#include "bsp_beep.h"
#include "cc.h"
//beep初始化亚
void beep_init(void)
{
    //复用为GPIO
    IOMUXC_SetPinMux(IOMUXC_SNVS_SNVS_TAMPER1_GPIO5_IO01,0);
    IOMUXC_SetPinConfig(IOMUXC_SNVS_SNVS_TAMPER1_GPIO5_IO01,0x10b0);

    GPIO5->GDIR |= (1<<1);  //输出
    GPIO5->DR |= (1<<1);   // 默认关闭
}

//beep控制
void beep_switch(int status)
{   
    if(status == ON)
        GPIO5->DR &= ~(1<<1);

    else if(status == OFF)
        GPIO5->DR |= (1<<1);
       

}