deri_add_library(deri_dev_gpio_gd32 STATIC
  afio_gd32.cpp
  gpio_gd32.cpp
  ../../include/deri/dev/afio_gd32.hpp
  ../../include/deri/dev/gpio_gd32.hpp
  )

target_include_directories(deri_dev_gpio_gd32 PUBLIC ../../include)
deri_target_depends(deri_dev_gpio_gd32 PUBLIC deri_soc)
