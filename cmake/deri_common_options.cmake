if (CMAKE_CROSSCOMPILING)
  set(CMAKE_EXECUTABLE_SUFFIX .elf)
endif()

add_link_options(LINKER:--gc-sections -specs=nosys.specs -nostartfiles)

add_compile_options(-fno-common)
add_compile_options(-fdata-sections -ffunction-sections)
add_compile_options(-fstack-usage)
add_compile_options($<$<COMPILE_LANGUAGE:CXX>:-fno-use-cxa-atexit>)
add_compile_options($<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>)
add_compile_options($<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>)
add_compile_options(-finline-small-functions -findirect-inlining)
