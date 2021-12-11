/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/syscall.hpp"

#include <cstdint>
#include <type_traits>

namespace deri::arch {
// Return value will be set by the ecall handler
// I have not been able to figure out how to turn this into a variadic template
// while reliably matching ABI with trap.S
inline uintptr_t syscall(Syscall syscall_number) {
  auto register syscall_number_reg asm("a7") =
      static_cast<std::underlying_type_t<Syscall>>(syscall_number);
  uintptr_t register return_value asm("a0");
  asm volatile("ecall"
               : "=r"(return_value)
               : "r"(syscall_number_reg)
               : "memory");
  return return_value;
}
}  // namespace deri::arch
