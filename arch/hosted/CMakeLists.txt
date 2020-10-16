add_library(deri_arch_${ARCH} STATIC
  include/deri/arch/impl/irq_impl.h
  trap.cpp
  )
target_include_directories(deri_arch_${ARCH} PUBLIC include)
target_link_libraries(deri_arch_${ARCH} PUBLIC deri_arch_common deri_core)
