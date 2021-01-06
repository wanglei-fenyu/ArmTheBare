#include "bsp_key.h"
#include "bsp_delay.h"
#include "bsp_gpio.h"

void key_init(void)
{
    IOMUXC_SetPinMux(IOMUXC_UART1_CTS_B_GPIO1_IO18 ,0);
    IOMUXC_SetPinConfig(IOMUXC_UART1_CTS_B_GPIO1_IO18 ,0xf080);

    gpio_pin_config_t key_config;
    key_config.direction = KGPIO_DigitalInput;
    gpio_init(GPIO1,18,&key_config);
    
}

//读取按键值
int read_key()
{
    int ret = 0;
    ret = gpio_pinread(GPIO1,18);

    return ret;
}


int key_getvalue()
{
    int ret = 0;
    static unsigned char release = 1;
    if((release == 1) && (gpio_pinread(GPIO1,18)== 0))
    {
        delay(10);
        release = 0;
        if(gpio_pinread(GPIO1,18) == 0)
        {
            ret = KEY0_VALUE;
        }
    }
    else if(gpio_pinread(GPIO1,18) == 1)
    {          
        ret = KEY_NONE;
        release = 1;
    }

    return ret;
}