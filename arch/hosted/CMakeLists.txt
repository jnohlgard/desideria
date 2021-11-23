deri_add_library(deri_arch INTERFACE
  include/deri/arch/impl/irq_impl.hpp
  trap.cpp
  )
target_include_directories(deri_arch INTERFACE include)
deri_target_depends(deri_arch INTERFACE deri_arch_common deri_core)
