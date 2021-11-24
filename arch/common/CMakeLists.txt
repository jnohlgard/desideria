deri_add_library(deri_arch_common STATIC
  include/deri/arch_init.hpp
  include/deri/irq.hpp
  atomic_impl.cpp
  )
target_include_directories(deri_arch_common PUBLIC include)
target_link_directories(deri_arch_common INTERFACE ld)
deri_target_depends(deri_arch INTERFACE deri_arch_common)
deri_target_depends(deri_arch_common PUBLIC deri_arch)
