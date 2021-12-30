deri_add_library(deri_arch STATIC
  reset.S
  startup.S
  trap.S
  irq_riscv.cpp
  panic_riscv.cpp
  include/deri/arch/irq.hpp
  include/deri/arch/perf.hpp
  include/deri/arch/syscall.hpp
  include/deri/arch/thread.hpp
  include/deri/mmio/CLIC.hpp
  include/deri/mmio/MTIME.hpp
  include/deri/mmio/bits/CLIC_bits.hpp
  )
deri_add_library(deri_arch_obj OBJECT
  thread_arch.cpp
  )
target_include_directories(deri_arch_obj PUBLIC include vendor/include)
target_include_directories(deri_arch PUBLIC include vendor/include)
deri_target_depends(deri_arch PUBLIC deri_arch_common deri_core_include $<TARGET_OBJECTS:deri_arch_obj>)
target_link_options(deri_arch_flags INTERFACE
  "LINKER:--defsym=_ram_origin=${RISCV_RAM_ORIGIN}"
  "LINKER:--defsym=_ram_length=${RISCV_RAM_LENGTH}"
  "LINKER:--defsym=_rom_origin=${RISCV_ROM_ORIGIN}"
  "LINKER:--defsym=_rom_length=${RISCV_ROM_LENGTH}"
  )
