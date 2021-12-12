deri_add_library(deri_arch STATIC
  reset.S
  startup.S
  trap.S
  irq_riscv.cpp
  panic_riscv.cpp
  thread_arch.cpp
  include/deri/arch/irq.hpp
  include/deri/arch/perf.hpp
  include/deri/arch/syscall.hpp
  include/deri/arch/thread.hpp
  include/deri/mmio/CLIC.hpp
  include/deri/mmio/bits/CLIC_bits.hpp
  )
target_include_directories(deri_arch PUBLIC include)
target_include_directories(deri_arch PUBLIC vendor/include)
deri_target_depends(deri_arch PUBLIC deri_arch_common deri_core_include)
target_link_options(deri_arch_flags INTERFACE
  "LINKER:--defsym=_ram_origin=${RISCV_RAM_ORIGIN}"
  "LINKER:--defsym=_ram_length=${RISCV_RAM_LENGTH}"
  "LINKER:--defsym=_rom_origin=${RISCV_ROM_ORIGIN}"
  "LINKER:--defsym=_rom_length=${RISCV_ROM_LENGTH}"
  )
