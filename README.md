# Raspberry Pi Zero Bare Metal C Example
This project demonstrates how to blink LED using bare metal C, no SD card with preinstaled OS
required. Kernel image should be also compatible with other BCM2835 boards such as Raspberry Pi A, A+, B, B+, Zero W.

## Prerequisites

You have to have installed `make`, `arm-none-eabi-gcc` and `arm-none-eabi-binutils` on your host machine. E.g. for Debian based distributions

```sh
	sudo apt install make gcc-arm-none-eabi binutils-arm-none-eabi
```
Optionally you would also need `fdisk` for formating the SD card manually.

## Format the SD card using Imager

Friendly way of formating SD card is using [Raspberry Pi Imager](https://www.raspberrypi.com/software/) with Raspberry Pi OS image and then just deleting all the files from the SD card. Afterwards, when you run `fdisk -l /dev/mmcblk0` you should see similar output to this
```
fdisk -l /dev/mmcblk0
	Disk /dev/mmcblk0: 29,3 GiB, 31460950016 bytes, 61447168 sectors
	Units: sectors of 1 * 512 = 512 bytes
	Sector size (logical/physical): 512 bytes / 512 bytes
	I/O size (minimum/optimal): 512 bytes / 512 bytes
	Disklabel type: dos
	Disk identifier: 0x50bf78c4

	Device         Boot   Start      End  Sectors  Size Id Type
	/dev/mmcblk0p1         8192  1056767  1048576  512M  c W95 FAT32 (LBA)
	/dev/mmcblk0p2      1056768 61447167 60390400 28,8G 83 Linux
```   

## Build

Build is managed via make
```sh
	make
	make DIR=/path/to/mountpoint install
```

`make install` is an optional command which copies new kernel (`kernel.img`) and firmware files to the SD card. Mount have to be specified using `DIR=` variable

## Documentation

[BCM2835 Documentation](https://www.raspberrypi.com/documentation/computers/processors.html)

[BCM2835 Peripheral Documentation](https://datasheets.raspberrypi.com/bcm2835/bcm2835-peripherals.pdf)