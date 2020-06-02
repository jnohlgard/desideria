add_library(deri_bsp_sifive_common STATIC
  include/deri/bsp/console.h
  console.cpp
  bsp_init.cpp
  )
target_include_directories(deri_bsp_sifive_common PUBLIC include)
target_link_libraries(deri_bsp_sifive_common PUBLIC deri_bsp_${BOARD})
add_subdirectory(testing)
