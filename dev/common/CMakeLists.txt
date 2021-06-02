add_library(deri_dev_common STATIC
  charnull.cpp
  ../include/deri/dev/charnull.h
  charbuf.cpp)
target_include_directories(deri_dev_common PUBLIC ../include)
target_link_libraries(deri_dev_common PUBLIC deri_core)
