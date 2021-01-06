led.bin:led.s
		arm-linux-gnueabihf-gcc -c led.s -o led.o -g
		arm-linux-gnueabihf-ld -Ttext 0x87800000 led.o -o led.elf
		arm-linux-gnueabihf-objcopy -O binary -S -g led.elf led.bin
		arm-linux-gnueabihf-objdump -D led.elf > led.disk

clean:
		rm -rf *.o led.bin led.elf led.dis
