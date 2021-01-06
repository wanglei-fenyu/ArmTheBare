CROSS_OMPILE    ?= arm-linux-gnueabihf-
TARGET			?= int

CC				:=$(CROSS_OMPILE)gcc
LD				:=$(CROSS_OMPILE)ld
OBJCOPY			:=$(CROSS_OMPILE)objcopy
OBJDUMP			:=$(CROSS_OMPILE)objdump

INCUDIRS		:= imx6u     \
				   bsp/delay \
				   bsp/clk   \
				   bsp/led   \
				   bsp/beep  \
				   bsp/gpio  \
				   bsp/int  \
				   bsp/exti  \
				   bsp/key   
				   

SRCDIRS			:= project \
				   bsp/clk \
				   bsp/led \
				   bsp/delay \
				   bsp/gpio \
				   bsp/int  \
				   bsp/key   \
				   bsp/exti  \
				   bsp/beep

INCLUDE			:= $(patsubst %,-I %,$(INCUDIRS))

SFILES 			:= $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.s))
CFILES 			:= $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.c))

SFILENODIR      := $(notdir $(SFILES))
CFILENODIR      := $(notdir $(CFILES))

SOBJS           := $(patsubst %, obj/%, $(SFILENODIR:.s=.o))
COBJS           := $(patsubst %, obj/%, $(CFILENODIR:.c=.o))

OBJS      		:= $(SOBJS)$(COBJS)

VPATH 			:= $(SRCDIRS)

.PHONY:clean

$(TARGET).bin : $(OBJS)
	$(LD) $^ -Timx6u.lds -o $(TARGET).elf 
	$(OBJCOPY) -O binary -S $(TARGET).elf $@
	$(OBJDUMP) -D -m arm $(TARGET).elf > $(TARGET).dis

$(SOBJS) : obj/%.o : %.s
	$(CC) -c $(INCLUDE) $< -O2 -Wall -nostdlib -o $@ 

$(COBJS) : obj/%.o : %.c
	$(CC) -c $(INCLUDE) $< -O2 -Wall -nostdlib -o $@ 

clean:
	rm -rf $(TARGET).* $(OBJS) 

print:
	@echo INCLUDE    = $(INCLUDE)
	@echo SFILES     = $(SFILES)
	@echo CFILES     = $(CFILES)
	@echo SFILENODIR = $(SFILENODIR)
	@echo CFILENODIR = $(CFILENODIR)
	@echo SOBJS      = $(SOBJS)
	@echo COBJS      = $(COBJS)
	@echo OBJS       = $(OBJS)
