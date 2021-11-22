add_all_subdirectories()

deri_add_library(deri_dev_common INTERFACE
  include/deri/dev/gpio.h
  include/deri/dev/timer.h
  )
target_include_directories(deri_dev_common INTERFACE include)
