deri_add_library(deri_dev_irq_clic STATIC
  irq_clic.cpp
  ../../include/deri/dev/irq_clic.hpp
  )

target_include_directories(deri_dev_irq_clic PUBLIC ../../include)
deri_target_depends(deri_dev_irq_clic PUBLIC deri_soc)
