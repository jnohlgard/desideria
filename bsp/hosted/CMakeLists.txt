deri_add_library(deri_bsp STATIC
  dev/console.cpp
  )
target_include_directories(deri_bsp PUBLIC include)
deri_target_depends(deri_bsp PUBLIC
  deri_core
  deri_arch
  )
add_subdirectory(testing)
