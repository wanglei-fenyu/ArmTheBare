#ifndef __BSP_DELAY_H__
#define __BSP_DELAY_H__
#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "MCIMX6Y2.h"

void delay_short(volatile unsigned int n);
void delay(volatile unsigned int n);

#endif /* __BSP_DELAY_H__ */