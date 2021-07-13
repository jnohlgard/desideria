set(DERI_COMMON_CFLAGS
  # Forbid common symbols to prevent accidental aliasing.
  -fno-common

  # Place data and functions into their own sections. This helps the linker
  # garbage collection to remove unused symbols when linking statically.
  -ffunction-sections -fdata-sections

  # Abort if a user-supplied include directory does not exist.
  -Werror=missing-include-dirs

  # Enable additional checks for printf/scanf format strings
  # These are not universally supported by all compiler versions, so must be tested for
  -Wformat=2
  -Wformat-overflow
  -Wformat-truncation
  -Wformat-signedness

  # Additional warnings
  #-Wuninitialized
  #-Winit-self
  #-Wswitch-enum
  #-Wdouble-promotion
  #-Wconversion

  # Compress debug info
  -gz

  # Use colored output even in Ninja
  -fdiagnostics-color=always

  )

string(JOIN " " CMAKE_C_FLAGS_INIT
  ${DERI_COMMON_CFLAGS}

  # Fast-out on old style function definitions.
  # They cause unreadable error compiler errors on missing semicolons.
  # Worse yet they hide errors by accepting wildcard argument types.
  # (These flags only have meaning in C language)
  -Werror=strict-prototypes
  -Werror=old-style-definition
  )

string(JOIN " " CMAKE_CXX_FLAGS_INIT
  ${DERI_COMMON_CFLAGS}

  # Disable global destructors and atexit stuff
  -fno-use-cxa-atexit

  # Disable RTTI and exceptions because of missing platform support
  -fno-rtti
  -fno-exceptions

  -Woverloaded-virtual
  -Weffc++
  )

string(JOIN " " CMAKE_EXE_LINKER_FLAGS_INIT
  -Wl,--gc-sections)
