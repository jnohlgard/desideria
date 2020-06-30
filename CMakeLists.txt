enable_language(C)
enable_language(CXX)
enable_language(ASM)
# This internal cache variable is required to pass the list of object library files to the top level CMakeLists
set(DERI_STARTFILES "" CACHE INTERNAL "Linker dependencies that must be explicitly linked with any executable")

if (MSVC)
  # warning level 4 and all warnings as errors
  add_compile_options(/W4 /WX)
else()
  # lots of warnings and all warnings as errors
  #-Wshadow -Wundef
  add_compile_options(-Wall -Wextra -pedantic -Werror)
  add_compile_options(-Wdouble-promotion -Wconversion)
  add_compile_options(-Wswitch-enum)
  add_compile_options(-Wuninitialized -Winit-self)
  add_compile_options(-Wformat=2 -Wformat-truncation -Wformat-signedness)
endif()

add_compile_options(-ffreestanding -nostdlib)
add_compile_options(-fno-common -fdata-sections -ffunction-sections)
add_compile_options(-fstack-usage)
add_compile_options($<$<COMPILE_LANGUAGE:CXX>:-fno-use-cxa-atexit>)
add_compile_options($<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>)
add_compile_options($<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>)
add_compile_options(-finline-small-functions -findirect-inlining)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(arch)
add_library(desideria INTERFACE)
add_subdirectory(bsp)
add_subdirectory(core)
target_link_libraries(desideria INTERFACE
  deri_arch_${ARCH}
  deri_bsp_${BOARD}
  deri_core
  )

add_library(deri_testing INTERFACE)
target_link_libraries(deri_testing INTERFACE
  deri_bsp_${BOARD}_testing
  deri_core_testing
  )

add_subdirectory(dev)
add_subdirectory(lib)
