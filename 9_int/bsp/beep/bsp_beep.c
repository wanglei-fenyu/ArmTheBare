#include "bsp_beep.h"
#include "bsp_gpio.h"
#include "cc.h"

//beep初始化亚
void beep_init(void)
{
    //复用为GPIO
    IOMUXC_SetPinMux(IOMUXC_SNVS_SNVS_TAMPER1_GPIO5_IO01,0);
    IOMUXC_SetPinConfig(IOMUXC_SNVS_SNVS_TAMPER1_GPIO5_IO01,0x10b0);
    gpio_pin_config_t beep_config;
    beep_config.direction = KGPIO_DigitalOutput; 

    gpio_init(GPIO5,1,&beep_config);
}

//beep控制
void beep_switch(int status)
{   
    if(status == ON)
        gpio_pinwrite(GPIO5,1,0);

    else if(status == OFF)
        gpio_pinwrite(GPIO5,1,1);    

}