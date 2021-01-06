	.global _start @全局标号

_start:
    /**********************************/
    /*使能所有外设时钟 */
    ldr r0,=0x020c4068  @CCGR0
    ldr r1,=0xffffffff  @向CCGR0写入到数据
    str r1,[r0]

    ldr r0,=0x020c406c  @CCGR1
    str r1,[r0]

    ldr r0,=0x020c4070  @CCGR2
    str r1,[r0]

    ldr r0,=0x020c4074  @CCGR3
    str r1,[r0]

    ldr r0,=0x020c4078  @CCGR4
    str r1,[r0]

    ldr r0,=0x020c407c  @CCGR5
    str r1,[r0]

    ldr r0,=0x020c4080  @CCGR6
    str r1,[r0]

    /**********************************/
    /*配置引脚复用为GPIO 
     *IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO03 = 5
     *IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO03地址为0x020E_0068h
    */
    ldr r0,=0x020E0068
    ldr r1,=0x5
    str r1,[r0]

    /*************************************/
    /*配置电气属性
     *IOMUXC_SW_PAD_CTL_PAD_GPIO1_IO03
     *IOMUXC_SW_PAD_CTL_PAD_GPIO1_IO03地址为20E_02F4h
     *bit0      0     低速率
     *bit5~3    110   R0/6驱动能力
     *bit7~6    10    100M速度
     *bit11     0     关闭开路输出
     *bit12     1     使能pull/kepper
     *bit13     0     kepper
     *bit15~14  00    100K下拉
     *bit16     0     关闭hys
     *最终写入 = 0x10B0
    */
    ldr r0,=0x020E02F4
    ldr r1,=0x10B0
    str r1,[r0]

    /******************************/
    /*设置GPIO功能
     *设置GPIO1_GDIR寄存器GPIO_IO03为输出
     *(GPIO1_GDIR地址为209_C004
     *GPIO_IO03  对应GPIO1_GDIR的第四位（0，1，2，3） 设为1 表输出
     */
     ldr r0,=0x0209c004
     ldr r1,=0x8
     str r1,[r0]

     /********************************/
     /*打开LED 也就是将GPIO_IO03设置为0
      *GDIO_DR寄存器地址为209_C000
      */
      ldr r0,=0x0209C000
      ldr r1,=0
      str r1,[r0]


loop:
    b loop



    









