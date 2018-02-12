
ENTRY(start)
OUTPUT_FORMAT (elf32-i386)

SECTIONS
{
    .= 0x0100000;
    .text :
    {
        *(.mboot)
        *(.text)
        *(.rodata)
    }

    .data :
    {
        start_ctors = .;
        KEEP(*( .init_array ));
        end_ctors = .;

        *(.data)
    }

    .bss :
    {
        *(.bss)
    }

    /DISCARD/ :
    {
        *(.fini_array*)
        *(.comment)
    }
}
