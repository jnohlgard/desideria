deri_add_library(deri_dev_gpio_gd32 STATIC
  gpio_gd32.cpp
  ../../include/deri/dev/gpio/gd32.h
  )

target_include_directories(deri_dev_gpio_gd32 PUBLIC ../../include)
deri_target_depends(deri_dev_gpio_gd32 PUBLIC deri_soc)
