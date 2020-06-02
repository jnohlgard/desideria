add_library(deri_dev_sifive_uart STATIC
  sifive_uart.cpp
  include/deri/dev/sifive_uart.h
  )

target_include_directories(deri_dev_sifive_uart PUBLIC include)
target_link_libraries(deri_dev_sifive_uart PRIVATE deri_dev_common)
