deri_add_library(deri_arch_common INTERFACE
  include/deri/arch_init.hpp
  )
target_include_directories(deri_arch_common INTERFACE include)
target_link_directories(deri_arch_common INTERFACE ld)
deri_target_depends(deri_arch INTERFACE deri_arch_common)
