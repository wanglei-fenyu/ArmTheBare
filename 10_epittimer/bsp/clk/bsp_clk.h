#ifndef __BSP_CLK_H
#define __BSP_CLK_H
#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "MCIMX6Y2.h"
#include "cc.h"

void clk_enable(void);
void imx6u_clkinit();

#endif /* __BSP_CLK_H__ */