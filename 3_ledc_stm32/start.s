.global _start

_start:
    /* 设置处理器进去SVC模式 */
    mrs r0,cpsr 
    bic r0,r0,#0x1f    /*bit4-0 清零 */
    orr r0,r0,#0x13    /* 后五位设置为SVC对应到码*/
    msr cpsr,r0


    ldr sp, =0x80200000
    b main

