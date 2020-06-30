cmake_minimum_required(VERSION 3.14)
project(hello_libc CXX)
set(DERI_BASEDIR ${CMAKE_CURRENT_LIST_DIR}/../.. CACHE PATH "Path to Desideria source root")
list(APPEND CMAKE_MODULE_PATH "${DERI_BASEDIR}/cmake" "${CMAKE_MODULE_PATH}")
include(desideria)

add_executable(hello_libc hello_libc.cpp)
deri_configure_target(hello_libc)
