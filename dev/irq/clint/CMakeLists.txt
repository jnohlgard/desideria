deri_add_library(deri_dev_irq_clint STATIC
  irq_clint.cpp
  ../../include/deri/dev/irq_clint.hpp
  )

target_include_directories(deri_dev_irq_clint PUBLIC ../../include)
deri_target_depends(deri_dev_irq_clint PUBLIC deri_soc)
