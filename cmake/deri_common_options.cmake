set(CMAKE_EXECUTABLE_SUFFIX .elf)
add_link_options(-nostdlib LINKER:--gc-sections)
