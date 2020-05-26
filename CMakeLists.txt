cmake_minimum_required(VERSION 3.14)

project(desideria LANGUAGES C CXX)

if(NOT BOARD)
  message(FATAL_ERROR "Define BOARD to select platform: cmake -DBOARD=foo")
endif()
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/bsp/${BOARD}/cmake" "${CMAKE_MODULE_PATH}")
include(deri_platform)

SET(BARE_METAL_FLAGS "-ffreestanding -nostdlib -fno-common")
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${BARE_METAL_FLAGS}" CACHE STRING "" FORCE)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${BARE_METAL_FLAGS}" CACHE STRING "" FORCE)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CTest)

add_subdirectory(arch)
add_subdirectory(core)
