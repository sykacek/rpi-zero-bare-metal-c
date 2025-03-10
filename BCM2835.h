#ifndef BCM2711_H
#define BCM2711_H

#define PHYSICAL_BASE			(0x20000000)
#define BUS_BASE			(0x7e000000)
#define GPIO_PERIPHERAL_BASE		(0x7e200000)	

#define GPIO_BASE			((GPIO_PERIPHERAL_BASE - BUS_BASE) + PHYSICAL_BASE)

#define REG_GPFSEL0			(GPIO_BASE + 0x00)
#define REG_GPFSEL1			(GPIO_BASE + 0x04)
#define REG_GPFSEL2			(GPIO_BASE + 0x08)
#define REG_GPFSEL3			(GPIO_BASE + 0x0c)
#define REG_GPFSEL4			(GPIO_BASE + 0x10)
#define REG_GPFSEL5			(GPIO_BASE + 0x14)
#define REG_GPSET0			(GPIO_BASE + 0x1c)
#define REG_GPSET1			(GPIO_BASE + 0x20)
#define REG_GPCLR0			(GPIO_BASE + 0x28)
#define REG_GPCLR1			(GPIO_BASE + 0x2c)

#define CPU_FREQUENCY			(1000000000)

#include "inttypes.h"

#endif