/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */
OUTPUT_ARCH( "riscv" )

MEMORY
{
  rom (rxai!w) : ORIGIN = 0x20000000, LENGTH = 32M
  ram (wxa!ri) : ORIGIN = 0x80000000, LENGTH = 8192M
}
INCLUDE deri-base.ld
INCLUDE global_pointer.ld
