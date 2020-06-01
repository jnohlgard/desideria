cmake_minimum_required(VERSION 3.14)

project(desideria LANGUAGES C CXX ASM)

if(NOT BOARD)
  message(FATAL_ERROR "Define BOARD to select platform: cmake -DBOARD=foo")
endif()
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/bsp/${BOARD}/cmake" "${CMAKE_MODULE_PATH}")
include(deri_platform)

if (MSVC)
  # warning level 4 and all warnings as errors
  add_compile_options(/W4 /WX)
else()
  # lots of warnings and all warnings as errors
  add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

add_compile_options(-ffreestanding -nostdlib -fno-common)
add_link_options(-nostdlib)

set(CMAKE_EXECUTABLE_SUFFIX .elf)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CTest)

set(DERI_ARCH_BASEDIR ${CMAKE_CURRENT_SOURCE_DIR}/arch)
set(DERI_BSP_BASEDIR ${CMAKE_CURRENT_SOURCE_DIR}/bsp)

add_library(deri INTERFACE)
add_subdirectory(arch)
add_subdirectory(bsp)
add_subdirectory(core)
target_link_libraries(deri INTERFACE
  deri_arch_${ARCH}
  deri_bsp_${BOARD}
  deri_core
  )

add_subdirectory(drivers)

add_subdirectory(examples)
