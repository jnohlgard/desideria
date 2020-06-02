add_library(deri_bsp_${BOARD} STATIC
  include/deri/bsp/memory_map.h
  include/deri/bsp/console.h
  console.cpp
  bsp_init.cpp
  )
target_include_directories(deri_bsp_${BOARD} PUBLIC include)
target_link_libraries(deri_bsp_${BOARD} PUBLIC
  deri_core
  deri_arch_${ARCH}
  deri_bsp
  deri_dev_sifive_uart
  )

add_subdirectory(testing)
