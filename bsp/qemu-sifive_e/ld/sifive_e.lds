/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */
OUTPUT_ARCH( "riscv" )

MEMORY
{
  rom (rxai!w) : ORIGIN = 0x20400000, LENGTH = 4M
  ram (wxa!ri) : ORIGIN = 0x80000000, LENGTH = 16K
}

INCLUDE deri-base.ld
INCLUDE global_pointer.ld
INCLUDE sifive-fe310-periph.ld
