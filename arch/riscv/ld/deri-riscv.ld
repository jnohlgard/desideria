/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */
OUTPUT_ARCH( "riscv" )

/* _rom_origin, _rom_length, _ram_origin, _ram_length should be provided on the linker command line
 * Example: --defsym=_ram_origin=0x8000000
 */

MEMORY
{
  rom (rxai!w) : ORIGIN = _rom_origin, LENGTH = _rom_length
  ram (wxa!ri) : ORIGIN = _ram_origin, LENGTH = _ram_length
}

INCLUDE deri-base.ld
INCLUDE global_pointer.ld
