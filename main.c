#include "BCM2835.h"

void delay_blocking_ticks(unsigned int ticks){
	for(unsigned int i = 0; i < ticks; ++i)
		;
}

unsigned int read(void *reg){
	unsigned int *src = (unsigned int *)reg;
	return *src;
}

void write(void *reg, unsigned int val){
	unsigned int *pnt = (unsigned int *)reg;
	*pnt = val;

	return;
}

void main(unsigned int r0, unsigned int r1, unsigned int r2){
	unsigned int reg_val = read((unsigned int *)REG_GPFSEL2);
	reg_val |= 1<<3;
	write((unsigned int *)REG_GPFSEL2, reg_val);

	while(1){
		write((unsigned int *)REG_GPSET0, 1<<21);
		delay_blocking_ticks(1000000);

		write((unsigned int *)REG_GPCLR0, 1<<21);
		delay_blocking_ticks(1000000);
	}
}