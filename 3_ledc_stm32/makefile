objs 	:= start.o main.o;
ld 		:= arm-linux-gnueabihf-ld
gcc		:= arm-linux-gnueabihf-gcc
objcopy := arm-linux-gnueabihf-objcopy
objdump := arm-linux-gnueabihf-objdump


ledc.bin:$(objs)
		$(ld) -Timx6u.lds $^ -o ledc.elf
		$(objcopy) -O binary -S ledc.elf $@
		$(objdump) -D -m arm ledc.elf > ledc.dis

%.o:%.c
		$(gcc) -c $< -o $@ -Wall -nostdlib -O2 

%.o:%.s
		$(gcc) -c $< -o $@ -Wall -nostdlib -O2 

clean:
		rm -rf *.o ledc.elf ledc.dis ledc.bin