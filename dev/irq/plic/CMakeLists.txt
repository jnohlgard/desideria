deri_add_library(deri_dev_irq_plic STATIC
  irq_plic.cpp
  ../../include/deri/dev/irq_plic.hpp
  )

target_include_directories(deri_dev_irq_plic PUBLIC ../../include)
deri_target_depends(deri_dev_irq_plic PUBLIC deri_soc)
