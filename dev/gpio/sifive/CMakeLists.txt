deri_add_library(deri_dev_gpio_sifive STATIC
  gpio_sifive.cpp
  ../../include/deri/dev/gpio_sifive.hpp
  )

target_include_directories(deri_dev_gpio_sifive PUBLIC ../../include)
deri_target_depends(deri_dev_gpio_sifive PUBLIC deri_soc)
