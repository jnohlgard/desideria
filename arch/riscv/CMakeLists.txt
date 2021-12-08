deri_add_library(deri_arch STATIC
  startup.S
  reset.S
  irq_riscv.cpp
  trap.S
  include/deri/arch/irq.hpp
  include/deri/mmio/CLIC.hpp
  include/deri/mmio/bits/CLIC_bits.hpp
  )
deri_add_library(deri_arch_obj OBJECT
  trap.cpp
  )
target_link_libraries(deri_arch PUBLIC deri_arch_obj $<TARGET_OBJECTS:deri_arch_obj>)
target_include_directories(deri_arch PUBLIC include)
target_include_directories(deri_arch PUBLIC vendor/include)
deri_target_depends(deri_arch PUBLIC deri_arch_common deri_core_include)
target_link_options(deri_arch_flags INTERFACE
  "LINKER:--defsym=_ram_origin=${RISCV_RAM_ORIGIN}"
  "LINKER:--defsym=_ram_length=${RISCV_RAM_LENGTH}"
  "LINKER:--defsym=_rom_origin=${RISCV_ROM_ORIGIN}"
  "LINKER:--defsym=_rom_length=${RISCV_ROM_LENGTH}"
  )
