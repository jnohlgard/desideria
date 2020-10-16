add_library(deri_bsp_${BOARD} STATIC
  dev/console.cpp
  )
target_include_directories(deri_bsp_${BOARD} PUBLIC include)
target_link_libraries(deri_bsp_${BOARD} PUBLIC deri_libc)
target_link_libraries(deri_bsp_${BOARD} PUBLIC
  deri_core
  deri_arch_${ARCH}
  deri_bsp
  )
