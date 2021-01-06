CROSS_OMPILE    ?= arm-linux-gnueabihf-
TARGET			?= beep

CC				:=$(CROSS_OMPILE)gcc
LD				:=$(CROSS_OMPILE)ld
OBJCOPY			:=$(CROSS_OMPILE)objcopy
OBJDUMP			:=$(CROSS_OMPILE)objdump

INCUDIRS		:= imx6u     \
				   bsp/delay \
				   bsp/clk   \
				   bsp/led   \
				   bsp/beep
				   

SRCDIRS			:= project \
				   bsp/clk \
				   bsp/led \
				   bsp/delay \
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
	$(OBJDUMP) -D -m arm $(TARGET).elf > $(TARGET).disk

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