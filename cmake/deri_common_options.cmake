set(CMAKE_EXECUTABLE_SUFFIX .elf)
add_link_options(LINKER:--gc-sections -specs=nosys.specs)
