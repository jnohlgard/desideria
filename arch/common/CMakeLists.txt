deri_add_library(deri_arch_common INTERFACE
  include/deri/arch_init.hpp
  include/deri/irq.hpp)
deri_add_library(deri_arch_atomic_impl OBJECT atomic_impl.cpp)
target_include_directories(deri_arch_common INTERFACE include)
target_link_directories(deri_arch_common INTERFACE ld)
deri_target_depends(deri_arch INTERFACE deri_arch_common)
deri_target_depends(deri_arch_atomic_impl PRIVATE deri_arch)
deri_target_depends(deri_arch_common INTERFACE deri_arch $<TARGET_OBJECTS:deri_arch_atomic_impl>)
