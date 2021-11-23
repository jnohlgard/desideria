deri_add_library(deri_bsp_common INTERFACE)
target_sources(deri_bsp_common INTERFACE
  include/deri/bsp_init.hpp
  )
target_include_directories(deri_bsp_common INTERFACE include)
deri_target_depends(deri_bsp PUBLIC deri_bsp_common)
