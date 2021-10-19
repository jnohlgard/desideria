deri_add_library(deri_arch STATIC
  startup.S
  reset.S
  include/deri/arch/impl/irq_impl.h
  trap.cpp
  )
target_include_directories(deri_arch PUBLIC include)
target_include_directories(deri_arch PUBLIC vendor/include)
deri_target_depends(deri_arch PUBLIC deri_arch_common deri_core)
target_link_options(deri_arch_flags INTERFACE
  "LINKER:--defsym=_ram_origin=${RISCV_RAM_ORIGIN}"
  "LINKER:--defsym=_ram_length=${RISCV_RAM_LENGTH}"
  "LINKER:--defsym=_rom_origin=${RISCV_ROM_ORIGIN}"
  "LINKER:--defsym=_rom_length=${RISCV_ROM_LENGTH}"
  )
