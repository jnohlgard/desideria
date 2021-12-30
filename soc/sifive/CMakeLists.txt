deri_add_library(deri_soc_obj OBJECT
  )
deri_add_library(deri_soc STATIC
  soc_init.cpp
  )
target_link_directories(deri_soc PUBLIC ld)
target_link_libraries(deri_soc PUBLIC deri_soc_obj $<TARGET_OBJECTS:deri_soc_obj>)
target_include_directories(deri_soc_obj PUBLIC include)
target_include_directories(deri_soc PUBLIC include)
target_link_libraries(deri_soc INTERFACE
  "${CMAKE_CURRENT_SOURCE_DIR}/ld/fe310_mmio.ld"
  )
target_sources(deri_soc_obj PRIVATE
  #  gpio_dev.cpp
  #  timer_dev.cpp
  #  uart_dev.cpp
  vectors.cpp
  #  include/deri/soc/clock_dev.hpp
  #  include/deri/soc/gpio_dev.hpp
  #  include/deri/soc/irq_dev.hpp
  #  include/deri/soc/timer_dev.hpp
  #  include/deri/soc/uart_dev.hpp
  include/deri/soc/vectors.hpp
  )
deri_target_depends(deri_soc_obj PUBLIC deri_dev_common deri_arch)
deri_target_depends(deri_soc PUBLIC deri_bsp_periph deri_arch)
