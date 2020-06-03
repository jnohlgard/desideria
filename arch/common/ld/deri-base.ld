/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

ENTRY( _reset_trampoline )

PHDRS
{
  text PT_LOAD;
  data PT_LOAD;
  bss PT_LOAD;
}

SECTIONS
{
  .text : {
    *(.reset_trampoline)
    *(.text .text.* .gnu.linkonce.t.*)
    . = ALIGN(128);
    *(.vectors_array)
  } >rom AT>rom :text

  .preinit_array : {
    PROVIDE_HIDDEN (__preinit_array_start = .);
    KEEP (*(.preinit_array))
    PROVIDE_HIDDEN (__preinit_array_end = .);
  } >rom AT>rom :text

  .init_array : {
    PROVIDE_HIDDEN (__init_array_start = .);
    KEEP (*(SORT_BY_INIT_PRIORITY(.init_array.*) SORT_BY_INIT_PRIORITY(.ctors.*)))
    KEEP (*(.init_array EXCLUDE_FILE (*crtbegin.o *crtbegin?.o *crtend.o *crtend?.o ) .ctors))
    PROVIDE_HIDDEN (__init_array_end = .);
  } >rom AT>rom :text

  .fini_array : {
    PROVIDE_HIDDEN (__fini_array_start = .);
    KEEP (*(SORT_BY_INIT_PRIORITY(.fini_array.*) SORT_BY_INIT_PRIORITY(.dtors.*)))
    KEEP (*(.fini_array EXCLUDE_FILE (*crtbegin.o *crtbegin?.o *crtend.o *crtend?.o ) .dtors))
    PROVIDE_HIDDEN (__fini_array_end = .);
  } >rom AT>rom :text

  .ctors : {
    /* gcc uses crtbegin.o to find the start of
       the constructors, so we make sure it is
       first.  Because this is a wildcard, it
       doesn't matter if the user does not
       actually link against crtbegin.o; the
       linker won't look for a file to match a
       wildcard.  The wildcard also means that it
       doesn't matter which directory crtbegin.o
       is in.  */
    KEEP (*crtbegin.o(.ctors))
    KEEP (*crtbegin?.o(.ctors))
    /* We don't want to include the .ctors section from
       the crtend.o file until after the sorted ctors.
       The .ctors section from the crtend file contains the
       end of ctors marker and it must be last */
    KEEP (*(EXCLUDE_FILE (*crtend.o *crtend?.o ) .ctors))
    KEEP (*(SORT(.ctors.*)))
    KEEP (*(.ctors))
  } >rom AT>rom :text

  .dtors : {
    KEEP (*crtbegin.o(.dtors))
    KEEP (*crtbegin?.o(.dtors))
    KEEP (*(EXCLUDE_FILE (*crtend.o *crtend?.o ) .dtors))
    KEEP (*(SORT(.dtors.*)))
    KEEP (*(.dtors))
  } >rom AT>rom :text

  .rodata : {
    *(.srodata .srodata.*)
    *(.rodata .rodata* .gnu.linkonce.r.*)
  } >rom AT>rom :text

  .data : {
    . = ALIGN(8);
    _data_begin = .;
    *(.data .data.*)
    _sdata_begin = .;
    *(.sdata .sdata.*)
    _data_end = .;
    . = ALIGN(8);
  } >ram AT>rom :data
  _edata = .;
  _data_load = LOADADDR(.data) + (_data_begin - ADDR(.data));

  /* keeping .sdata and .sbss close together */
  .bss (NOLOAD) : {
    . = ALIGN(8);
    _bss_begin = .;
    *(.sbss .sbss.*)
    *(.bss .bss.*)
    _bss_end = .;
    . = ALIGN(8);
  } >ram AT>ram :bss
  _end = .;

  PROVIDE(_memory_begin = ORIGIN(ram));
  PROVIDE(_memory_end = ORIGIN(ram) + LENGTH(ram));
  PROVIDE(_stack_end = _memory_end);
}
