add_library(deri_bsp_${BOARD} STATIC
  include/deri/bsp/memory_map.h
  )
target_include_directories(deri_bsp_${BOARD} PUBLIC include)
target_link_libraries(deri_bsp_${BOARD} PUBLIC deri_core)
target_link_libraries(deri_bsp_${BOARD} PUBLIC deri_arch_riscv)
