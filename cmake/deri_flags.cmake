include_guard(GLOBAL)
include(deri_config)

target_compile_definitions(deri_base_flags INTERFACE "BOARD_$<UPPER_CASE:$<MAKE_C_IDENTIFIER:${BOARD}>>=\"${BOARD}\"" "DERI_BOARD=BOARD_$<UPPER_CASE:$<MAKE_C_IDENTIFIER:${BOARD}>>")
target_compile_definitions(deri_base_flags INTERFACE "CPU_$<UPPER_CASE:$<MAKE_C_IDENTIFIER:${CPU}>>=\"${CPU}\"" "DERI_CPU=CPU_$<UPPER_CASE:$<MAKE_C_IDENTIFIER:${CPU}>>")
target_compile_definitions(deri_base_flags INTERFACE "ARCH_$<UPPER_CASE:$<MAKE_C_IDENTIFIER:${ARCH}>>=\"${ARCH}\"" "DERI_ARCH=ARCH_$<UPPER_CASE:$<MAKE_C_IDENTIFIER:${ARCH}>>")
target_compile_definitions(deri_base_flags INTERFACE "CPU_CORE_$<UPPER_CASE:$<MAKE_C_IDENTIFIER:${CPU_CORE}>>=\"${CPU_CORE}\"" "DERI_CPU_CORE=CPU_CORE_$<UPPER_CASE:$<MAKE_C_IDENTIFIER:${CPU_CORE}>>")
target_compile_definitions(deri_base_flags INTERFACE "CPU_MODEL_$<UPPER_CASE:$<MAKE_C_IDENTIFIER:${CPU_MODEL}>>=\"${CPU_MODEL}\"" "DERI_CPU_MODEL=CPU_MODEL_$<UPPER_CASE:$<MAKE_C_IDENTIFIER:${CPU_MODEL}>>")

target_link_options(deri_base_flags INTERFACE -nostartfiles)

if (DERI_DEVELHELP)
  target_compile_definitions(deri_base_flags INTERFACE DEVELHELP)
endif()

include(CheckCCompilerFlag)
include(CheckLinkerFlag)

if (MSVC)
  # enable lots of warnings
  target_compile_options(deri_base_flags INTERFACE /W4)
  if (DERI_WERROR)
    target_compile_options(deri_base_flags INTERFACE /WX)
  endif()
else() # Assume anything else is GCC/Clang compatible

  target_compile_options(deri_base_flags INTERFACE
    # Enable warnings for code relying on signed integers to overflow correctly
    # Note:         This warning is sadly not reliable, thus -fwrapv cannot be
    #               dropped in favor of this
    -Wstrict-overflow

    # Forbid common symbols to prevent accidental aliasing.
    -fno-common

    # Place data and functions into their own sections. This helps the linker
    # garbage collection to remove unused symbols when linking statically.
    -ffunction-sections -fdata-sections

    # Enable all default warnings and all extra warnings
    -Wall -Wextra

    # Warn if a user-supplied include directory does not exist.
    -Wmissing-include-dirs

    # Fast-out on old style function definitions.
    # They cause unreadable error compiler errors on missing semicolons.
    # Worse yet they hide errors by accepting wildcard argument types.
    # (These flags only have meaning in C language)
    $<$<COMPILE_LANGUAGE:C>:-Wstrict-prototypes>
    $<$<COMPILE_LANGUAGE:C>:-Wold-style-definition>
    $<$<COMPILE_LANGUAGE:CXX>:-fno-use-cxa-atexit>
    $<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>
    $<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>
  )
  set(cflags_to_try
    # Add `-fno-delete-null-pointer-checks` flag iff the compiler supports it.
    # GCC removes moves tests whether `x == NULL`, if previously `x` or even `x->y` was accessed.
    # 0x0 might be a sane memory location for embedded systems, so the test must not be removed.
    # Right now clang does not use the *delete-null-pointer* optimization, and does not understand the parameter.
    # Related issues: #628, #664.
    -fno-delete-null-pointer-checks
    # Enable additional checks for printf/scanf format strings
    # These are not universally supported by all compiler versions, so must be tested for
    -Wformat=2
    -Wformat-overflow
    -Wformat-truncation
    -Wformat-signedness

    # Additional optimizations (experimental)
    #-fstack-usage
    #-findirect-inlining
    #-finline-small-functions

    # Additional warnings
    #-Wuninitialized
    #-Winit-self
    #-Wswitch-enum
    #-Wdouble-promotion
    #-Wconversion

    # Convert __FILE__ from an absolute path to a relative path for files in the Desideria repo
    "-fmacro-prefix-map=${PROJECT_SOURCE_DIR}=."
    )
  if (DERI_COMPRESS_DEBUG)
    list(APPEND cflags_to_try -gz)
  endif()
  if (DERI_CC_COLOR)
    list(APPEND cflags_to_try -fdiagnostics-color=always)
  else()
    list(APPEND cflags_to_try -fno-diagnostics-color)
  endif()

  foreach(flag IN LISTS cflags_to_try)
    string(TOUPPER "${flag}" flag_u)
    string(MAKE_C_IDENTIFIER "${flag_u}" flag_c)
    check_c_compiler_flag("${flag}" HAS${flag_c})
    if (HAS${flag_c})
      target_compile_options(deri_base_flags INTERFACE "${flag}")
    endif()
  endforeach()

  if (DERI_WERROR)
    target_compile_options(deri_base_flags INTERFACE -Werror)
  endif()

  target_compile_options(deri_base_flags INTERFACE $<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>)
  target_compile_options(deri_base_flags INTERFACE $<$<COMPILE_LANGUAGE:CXX>:-Weffc++>)

  # Xcode linker does not support --gc-sections, but uses -dead_strip
  check_linker_flag(C "LINKER:--gc-sections" HAS_LINKER_GC_SECTIONS)
  if (HAS_LINKER_GC_SECTIONS)
    target_link_options(deri_base_flags INTERFACE "LINKER:--gc-sections")
  else()
    check_linker_flag(C "LINKER:-dead_strip" HAS_LINKER_DEAD_STRIP)
    if (HAS_LINKER_DEAD_STRIP)
      target_link_options(deri_base_flags INTERFACE "LINKER:-dead_strip")
    endif()
  endif()
endif()
