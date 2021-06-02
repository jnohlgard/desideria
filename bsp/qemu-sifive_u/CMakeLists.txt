deri_add_library(deri_bsp_${BOARD} INTERFACE
  include/deri/bsp/memory_map.h
  include/deri/bsp/devices.h
  )
target_include_directories(deri_bsp_${BOARD} INTERFACE include)
target_link_libraries(deri_bsp_${BOARD} INTERFACE
  deri_core
  deri_arch_${ARCH}
  deri_bsp
  deri_dev_uart_sifive
  )

add_subdirectory(${DERI_BSP_BASEDIR}/common/sifive ${CMAKE_CURRENT_BINARY_DIR}/common)
target_link_libraries(deri_bsp_${BOARD} INTERFACE deri_bsp_sifive_common)
target_link_libraries(deri_bsp_${BOARD} INTERFACE deri_libc)
