deri_add_library(deri_dev_usart_gd32 STATIC
  usart_gd32.cpp
  ../../include/deri/dev/uart_gd32.hpp
  )

target_include_directories(deri_dev_usart_gd32 PUBLIC ../../include)
deri_target_depends(deri_dev_usart_gd32 PUBLIC deri_soc)
