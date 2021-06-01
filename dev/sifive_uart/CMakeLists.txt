deri_add_library(deri_dev_sifive_uart STATIC
  sifive_uart.cpp
  ../include/deri/dev/sifive_uart.h
  )

target_include_directories(deri_dev_sifive_uart PUBLIC ../include)
deri_target_depends(deri_dev_sifive_uart PUBLIC deri_dev_common)
