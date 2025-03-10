ENTRY(_start)

SECTIONS
{
	. = 0x8000;
	.text :
	{
		KEEP(*(.text.boot))
		*(.text .text.*)
	}
	. = ALIGN(4096);

	.rodata :
	{
		*(.rodata .rodata.*)
	}
	. = ALIGN(4096);

	.data :
	{
		*(.data .data.*)
	}
	. = ALIGN(4096);

	__bss_start = .;
	.bss :
	{
		*(.bss)
		__bss_end = .;
	}
	. = ALIGN(4096);
	__bss_end = .;
	__bss_size = __bss_end - __bss_start;
	__end = .;

}

OUTPUT(kernel.elf)