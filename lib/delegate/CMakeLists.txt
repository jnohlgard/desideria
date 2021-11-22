deri_add_library(deri_delegate INTERFACE
  include/deri/delegate.h
  delegate/include/delegate/delegate.hpp
  )
target_include_directories(deri_delegate INTERFACE
  include
  delegate/include
  )
