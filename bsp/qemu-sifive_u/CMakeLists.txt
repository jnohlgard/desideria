add_library(deri_bsp_${BOARD} STATIC
  include/deri/bsp/memory_map.h
  include/deri/bsp/devices.h
  dev/uart0.cpp
  dev/uart1.cpp
  )
target_include_directories(deri_bsp_${BOARD} PUBLIC include)
target_link_libraries(deri_bsp_${BOARD} PUBLIC
  deri_core
  deri_arch_${ARCH}
  deri_bsp
  deri_dev_sifive_uart
  )

add_subdirectory(${DERI_BSP_BASEDIR}/common/sifive ${CMAKE_CURRENT_BINARY_DIR}/common)
target_link_libraries(deri_bsp_${BOARD} PUBLIC deri_bsp_sifive_common)
