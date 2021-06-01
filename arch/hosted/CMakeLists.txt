add_library(deri_arch_${ARCH} INTERFACE
  include/deri/arch/impl/irq_impl.h
  trap.cpp
  )
target_include_directories(deri_arch_${ARCH} INTERFACE include)
target_link_libraries(deri_arch_${ARCH} INTERFACE deri_arch_common deri_core)
