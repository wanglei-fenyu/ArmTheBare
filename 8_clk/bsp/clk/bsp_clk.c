#include "bsp_clk.h"
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


//初始化时钟
void imx6u_clkinit()
{

    unsigned int reg = 0;
    //初始化主频为528MHz
    if(((CCM->CCSR >> 2) & 0x1) == 0) // 当时钟使用pll1_main_clk时(PLL)
    {
        CCM->CCSR &= ~(1 << 8);  //设置step_clk=osc_clk=24MHz
        CCM->CCSR |= (1 << 2);   //设置 pll1_sw_clk = step_clk=24`

        //设置PLL=1056MHz
        CCM_ANALOG->PLL_ARM = (1 << 13) | ((88 << 0) & 0x7f);
        CCM->CACRR = 1;  //设置为2分频

        //切换回pll1_main_clk
        CCM->CCSR &= ~(1 << 2);  //pll1_sw_clssssk = pll1_main_clk
   
        //PLL2 固定为528MHz
        reg = CCM_ANALOG->PFD_528;
        reg &= ~(0x3f3f3f3f);
        reg |= (32 << 24);
        reg |= (24 << 16);
        reg |= (16 << 8);
        reg |= (27 << 0);
        CCM_ANALOG->PFD_528 = reg;
        //PLL3 固定为480MHz
        reg = 0;
        reg = CCM_ANALOG->PFD_480;
        reg &= ~(0x3f3f3f3f);
        reg |= (19 << 24);
        reg |= (17 << 16);
        reg |= (16 << 8);
        reg |= (12 << 0);
        CCM_ANALOG->PFD_480 = reg;

        //其他外设时钟源配置
        //设置AHB_CLK_ROOT=312MHz
        CCM->CBCMR &= ~(3 << 18);
        CCM->CBCMR |= (1 << 18);
        CCM->CBCDR &= ~(1 << 25);
        while(CCM->CDHIPR & (1 << 5));
    #if 0
        CCM->CBCDR &= ~(7 << 10);
        CCM->CBCDR |= (2 << 10);
        while(CCM->CDHIPR & (1 << 1));
    #endif
        //IPG——CLK——ROOT = 66MHz
        CCM->CBCDR &= ~(3 << 8);
        CCM->CBCDR |= (1 << 8);

        CCM->CSCMR1 &= ~(1 << 6);
        CCM->CSCMR1 &= ~(7 << 0);;
    }
}