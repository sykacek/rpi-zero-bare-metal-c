all: kernel.img

boot.o: boot.s
	arm-none-eabi-gcc -mcpu=arm1176jzf-s -fpic -ffreestanding -c -o boot.o boot.s

main.o: main.c
	arm-none-eabi-gcc -c -o main.o main.c

kernel.img: boot.o main.o
	arm-none-eabi-gcc -Wall -Wextra -T linker.ld -mcpu=arm1176jzf-s -ffreestanding -fpic -O2 -nostdlib -lgcc boot.o main.o
	arm-none-eabi-objcopy -O binary kernel.elf kernel.img

copy: kernel.img
	cp kernel.img /media/mike/bootfs
	cp firmware/* /media/mike/bootfs
	sudo umount /dev/mmcblk0p1

clean:
	@rm *.elf *.o *.img

.PHONY: copy clean
