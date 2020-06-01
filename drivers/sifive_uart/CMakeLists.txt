add_library(sifive_uart STATIC
  sifive_uart.cpp
  include/deri/dev/sifive_uart.h
  )

target_include_directories(sifive_uart PUBLIC include)
target_link_libraries(sifive_uart PRIVATE deri_core)
