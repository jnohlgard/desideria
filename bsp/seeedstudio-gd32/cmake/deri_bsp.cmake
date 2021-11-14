set(SOC gd32vf1)
set(SOC_MODEL gd32vf103vbt6)
target_link_libraries(deri_soc_flags INTERFACE "${CMAKE_CURRENT_LIST_DIR}/../ld/seeedstudio-gd32-periph.ld")
