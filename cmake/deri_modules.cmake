include_guard(GLOBAL)
include(deri_functions)

deri_add_library(desideria INTERFACE)
add_library(deri::deri ALIAS desideria)

target_link_libraries(desideria INTERFACE
  deri_arch_${ARCH}
  deri_bsp_${BOARD}
  deri_core
  )

deri_add_library(deri_testing INTERFACE)
target_link_libraries(deri_testing INTERFACE
  deri_bsp_${BOARD}_testing
  deri_core_testing
  )

# Abstract interface modules to allow the user to select the stdio implementation
deri_add_library(stdio INTERFACE)
target_link_libraries(desideria INTERFACE stdio)
deri_add_library(stdin INTERFACE)
# Note that in order to reduce binary bloat, stdin must be explicitly enabled
# in each application that uses terminal input

deri_add_library(deri_libc INTERFACE)
