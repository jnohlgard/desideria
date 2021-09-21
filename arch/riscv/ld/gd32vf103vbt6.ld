/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */
OUTPUT_ARCH( "riscv" )

MEMORY
{
  rom (rxai!w) : ORIGIN = 0x08000000, LENGTH = 128K
  ram (wxa!ri) : ORIGIN = 0x20000000, LENGTH = 32K
}

INCLUDE deri-base.ld
INCLUDE global_pointer.ld
INCLUDE gd32vf103-periph.ld
