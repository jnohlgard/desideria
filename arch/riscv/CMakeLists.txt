add_library(deri_arch_${ARCH} STATIC
  startup.S
  reset.S
  include/deri/arch/impl/irq_impl.h
  trap.cpp
  )
target_include_directories(deri_arch_${ARCH} PUBLIC include)
target_include_directories(deri_arch_${ARCH} PUBLIC vendor/include)
target_link_libraries(deri_arch_${ARCH} PUBLIC deri_arch_common deri_core)
