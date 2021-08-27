deri_add_library(deri_bsp_sifive_common STATIC
  include/deri/bsp/console.h
  console.cpp
  bsp_init.cpp
  )
target_include_directories(deri_bsp_sifive_common PUBLIC include)
deri_target_depends(deri_bsp_sifive_common PUBLIC deri_bsp)
add_subdirectory(testing)
