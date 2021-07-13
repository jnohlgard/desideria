add_all_subdirectories()

add_library(deri_dev_common STATIC)
target_include_directories(deri_dev_common PUBLIC include)
target_link_libraries(deri_dev_common PUBLIC deri_core)
