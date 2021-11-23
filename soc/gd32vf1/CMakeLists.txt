deri_add_library(deri_soc_obj OBJECT
  )
deri_add_library(deri_soc STATIC
  soc_init.cpp
  )
target_link_directories(deri_soc PUBLIC ld)
target_link_libraries(deri_soc PUBLIC deri_soc_obj $<TARGET_OBJECTS:deri_soc_obj>)
target_include_directories(deri_soc_obj PUBLIC include)
target_include_directories(deri_soc PUBLIC include)
if (SOC_MODEL MATCHES "gd32vf103")
  target_link_libraries(deri_soc INTERFACE
    "${CMAKE_CURRENT_SOURCE_DIR}/ld/gd32vf103_dev.ld"
    "${CMAKE_CURRENT_SOURCE_DIR}/ld/gd32vf103_mmio.ld"
    )
  target_include_directories(deri_soc_obj PUBLIC gd32vf103/include)
  target_sources(deri_soc_obj PRIVATE
    gd32vf103/gpio_dev.cpp
    gd32vf103/timer_dev.cpp
    gd32vf103/vectors.cpp
    gd32vf103/include/deri/soc/clock_dev.hpp
    gd32vf103/include/deri/soc/gpio_dev.hpp
    gd32vf103/include/deri/soc/irq_dev.hpp
    gd32vf103/include/deri/soc/timer_dev.hpp
    gd32vf103/include/deri/soc/vectors.hpp
    )
  deri_target_depends(deri_soc_obj PUBLIC deri_dev_common deri_arch)
endif()
deri_target_depends(deri_soc PUBLIC deri_bsp_periph)
