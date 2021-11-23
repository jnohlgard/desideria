deri_add_library(deri_bsp STATIC
  bsp_init.cpp
  console.cpp
  )
deri_add_library(deri_bsp_periph INTERFACE
  include/deri/bsp/devices.hpp
  )
target_include_directories(deri_bsp_periph INTERFACE include)
target_link_libraries(deri_bsp PUBLIC
  deri_core
  deri_arch
  deri_soc
  deri_bsp_periph
  )
target_link_libraries(deri_bsp_periph INTERFACE
  deri_dev_usart_gd32
  )

target_link_libraries(deri_bsp INTERFACE deri_libc)

add_subdirectory(testing)
