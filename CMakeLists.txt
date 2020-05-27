cmake_minimum_required(VERSION 3.14)

project(desideria LANGUAGES C CXX)

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

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CTest)

add_subdirectory(arch)
add_subdirectory(core)
