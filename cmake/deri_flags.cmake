include_guard(GLOBAL)
include(deri_config)

target_compile_definitions(deri_base_flags INTERFACE "BOARD_$<UPPER_CASE:$<MAKE_C_IDENTIFIER:${BOARD}>>=\"${BOARD}\"" "DERI_BOARD=BOARD_$<UPPER_CASE:$<MAKE_C_IDENTIFIER:${BOARD}>>")
target_compile_definitions(deri_base_flags INTERFACE "CPU_$<UPPER_CASE:$<MAKE_C_IDENTIFIER:${CPU}>>=\"${CPU}\"" "DERI_CPU=CPU_$<UPPER_CASE:$<MAKE_C_IDENTIFIER:${CPU}>>")
target_compile_definitions(deri_base_flags INTERFACE "ARCH_$<UPPER_CASE:$<MAKE_C_IDENTIFIER:${ARCH}>>=\"${ARCH}\"" "DERI_ARCH=ARCH_$<UPPER_CASE:$<MAKE_C_IDENTIFIER:${ARCH}>>")
target_compile_definitions(deri_base_flags INTERFACE "CPU_CORE_$<UPPER_CASE:$<MAKE_C_IDENTIFIER:${CPU_CORE}>>=\"${CPU_CORE}\"" "DERI_CPU_CORE=CPU_CORE_$<UPPER_CASE:$<MAKE_C_IDENTIFIER:${CPU_CORE}>>")
target_compile_definitions(deri_base_flags INTERFACE "SOC_$<UPPER_CASE:$<MAKE_C_IDENTIFIER:${SOC}>>=\"${SOC}\"" "DERI_SOC=SOC_$<UPPER_CASE:$<MAKE_C_IDENTIFIER:${SOC}>>")
target_compile_definitions(deri_base_flags INTERFACE "SOC_MODEL_$<UPPER_CASE:$<MAKE_C_IDENTIFIER:${SOC_MODEL}>>=\"${SOC_MODEL}\"" "DERI_SOC_MODEL=SOC_MODEL_$<UPPER_CASE:$<MAKE_C_IDENTIFIER:${SOC_MODEL}>>")

target_link_options(deri_base_flags INTERFACE -nostartfiles)

if (DERI_DEVELHELP)
  target_compile_definitions(deri_base_flags INTERFACE DEVELHELP)
endif ()
