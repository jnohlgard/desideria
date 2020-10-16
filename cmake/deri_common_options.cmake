if (NOT ARCH STREQUAL hosted)
  set(CMAKE_EXECUTABLE_SUFFIX .elf)
endif ()

if (NOT ARCH STREQUAL hosted OR NOT CMAKE_SYSTEM_NAME STREQUAL Darwin)
  # Xcode linker does not support --gc-sections
  add_link_options(LINKER:--gc-sections)
endif ()

add_link_options(-nostartfiles)

add_compile_options($<$<COMPILE_LANGUAGE:CXX>:-fno-use-cxa-atexit>)
add_compile_options($<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>)
add_compile_options($<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>)
add_compile_options(-fno-common)
add_compile_options(-fdata-sections -ffunction-sections)
if (CMAKE_C_COMPILER_ID STREQUAL GNU)
  add_compile_options(-fstack-usage)
  add_compile_options(-findirect-inlining)
  add_compile_options(-finline-small-functions)
endif ()
