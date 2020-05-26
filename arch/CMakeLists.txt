if(NOT ARCH)
message(FATAL_ERROR "ARCH is not defined")
endif()
add_subdirectory(${ARCH})
