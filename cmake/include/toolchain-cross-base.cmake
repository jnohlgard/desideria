list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}")
set(CMAKE_SYSTEM_NAME Desideria)
set(CMAKE_SYSTEM_VERSION 1)

set(CMAKE_CROSSCOMPILING true)

# never look in the target sysroot for programs and tools
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
# look for libraries and headers on the target sysroot only
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
