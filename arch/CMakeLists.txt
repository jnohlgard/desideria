if(NOT ARCH)
  message(FATAL_ERROR "ARCH is not defined")
endif()
set(DERI_ARCH_DIR ${CMAKE_CURRENT_SOURCE_DIR}/${ARCH})

add_subdirectory(common)
add_subdirectory(${DERI_ARCH_DIR})
