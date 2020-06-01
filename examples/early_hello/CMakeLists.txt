add_executable(early_hello early_hello.cpp)
target_link_libraries(early_hello PRIVATE deri deri_dev_sifive_uart)
set_target_properties(early_hello PROPERTIES LINK_DEPENDS ${LINKER_SCRIPT})
target_link_options(early_hello PRIVATE -Wl,-Map=$<TARGET_FILE_BASE_NAME:early_hello>.map)
