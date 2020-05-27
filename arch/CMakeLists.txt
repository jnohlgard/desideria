if(NOT ARCH)
  message(FATAL_ERROR "ARCH is not defined")
endif()
set(DERI_ARCH_DIR ${CMAKE_CURRENT_SOURCE_DIR}/${ARCH})

add_library(deri_arch_iface INTERFACE)
target_sources(deri_arch_iface INTERFACE
  ${CMAKE_CURRENT_SOURCE_DIR}/include/deri/arch/asm.h
  ${CMAKE_CURRENT_SOURCE_DIR}/include/deri/arch/irq.h
  )
target_include_directories(deri_arch_iface INTERFACE include)

add_subdirectory(${DERI_ARCH_DIR})
