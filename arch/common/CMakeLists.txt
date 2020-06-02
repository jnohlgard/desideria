add_library(deri_arch_common INTERFACE)
target_sources(deri_arch_common INTERFACE
  include/deri/arch/asm.h
  include/deri/arch/irq.h
  )
target_include_directories(deri_arch_common INTERFACE include)
