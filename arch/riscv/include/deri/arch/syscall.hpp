/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/syscall.hpp"

#include <cstdint>
#include <type_traits>

namespace deri::arch {
#pragma GCC diagnostic push
// Return value will be set by the ecall handler
#pragma GCC diagnostic ignored "-Wreturn-type"
// I have not been able to figure out how to turn this into a variadic template
// while reliably matching ABI with trap.S
inline uintptr_t syscall(Syscall syscall_number) {
  auto register syscall_number_reg asm("a7") =
      static_cast<std::underlying_type_t<Syscall>>(syscall_number);
  asm volatile("ecall" ::"r"(syscall_number_reg) : "memory");
}
#pragma GCC diagnostic pop
}  // namespace deri::arch
