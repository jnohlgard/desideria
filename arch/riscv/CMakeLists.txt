deri_add_library(deri_arch STATIC
  startup.S
  reset.S
  include/deri/arch/impl/irq_impl.h
  trap.cpp
  )
target_include_directories(deri_arch PUBLIC include)
target_include_directories(deri_arch PUBLIC vendor/include)
deri_target_depends(deri_arch PUBLIC deri_arch_common deri_core)
