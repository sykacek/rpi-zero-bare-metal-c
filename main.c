#include "BCM2835.h"

void delay_blocking_ticks(uint32_t ticks){
	for(uint32_t i = 0; i < ticks; ++i)
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

void main(uint32_t r0, uint32_t r1, uint32_t r2){
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