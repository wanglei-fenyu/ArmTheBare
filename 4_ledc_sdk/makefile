CROSS_OMPILE    ?= arm-linux-gnueabihf-
NAME			?= ledc

CC				:= $(CROSS_OMPILE)gcc
LD 				:= $(CROSS_OMPILE)ld 
OBJCOPY			:= $(CROSS_OMPILE)objcopy 
OBJDUMP 		:= $(CROSS_OMPILE)objdump

OBJS  			:= start.o main.o

$(NAME).bin : $(OBJS)
	$(LD) -Timx6u.lds -o $(NAME).elf $^
	$(OBJCOPY) -O binary -S $(NAME).elf $@
	$(OBJDUMP) -D -m arm $(NAME).elf > $(NAME).dis

%.o : %.c 
	$(CC) -Wall -nostdlib -c $< -o $@ 
%.o : %.s
	$(CC) -Wall -nostdlib -c $< -o $@	

.PHONY :clean
clean:
	rm -rf $(NAME).* *.o

	