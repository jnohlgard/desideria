deri_add_library(deri_dev_uart_sifive STATIC
  uart_sifive.cpp
  ../../include/deri/dev/uart_sifive.hpp
  )

target_include_directories(deri_dev_uart_sifive PUBLIC ../../include)
