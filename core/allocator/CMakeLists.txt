add_library(deri_core_allocator STATIC
  allocator.cpp)
target_link_libraries(deri_core_allocator PRIVATE deri_core)
