deri_add_library(deri_bsp STATIC
  include/deri/bsp/memory_map.h
  include/deri/bsp/devices.h
  )
target_include_directories(deri_bsp INTERFACE include)
deri_target_depends(deri_bsp PUBLIC
  deri_core
  deri_arch
  deri_soc
  deri_dev_uart_sifive
  )

add_subdirectory(${DERI_BSP_BASEDIR}/common/sifive ${CMAKE_CURRENT_BINARY_DIR}/common)
deri_target_depends(deri_bsp PUBLIC deri_bsp_sifive_common)
deri_target_depends(deri_bsp PUBLIC deri_libc)
