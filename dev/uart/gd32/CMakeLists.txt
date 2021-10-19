deri_add_library(deri_dev_usart_gd32 STATIC
  usart_gd32.cpp
  gd32_usart_regs.h
  ../../include/deri/dev/uart/gd32.h
  )

target_include_directories(deri_dev_usart_gd32 PUBLIC ../../include)
