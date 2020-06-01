add_library(deri_bsp_${BOARD} STATIC
  sifive_uart.cpp
  )
target_include_directories(deri_bsp_${BOARD} PUBLIC include)
target_link_libraries(deri_bsp_${BOARD} PUBLIC deri_core)
target_link_libraries(deri_bsp_${BOARD} PUBLIC deri_arch_riscv)
