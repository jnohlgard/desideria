add_library(deri_arch_riscv STATIC
  startup.c
  include/deri/arch/impl/irq_impl.h
  )
target_include_directories(deri_arch_riscv PUBLIC include)
target_include_directories(deri_arch_riscv PUBLIC vendor/include)
target_link_libraries(deri_arch_riscv PUBLIC deri_arch_iface)
