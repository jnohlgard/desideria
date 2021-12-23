/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/arch/irq.hpp"
#include "deri/syscall.hpp"

#include <cstdint>
#include <type_traits>

namespace deri::arch {
// Return value will be set by the ecall handler
// I have not been able to figure out how to turn this into a variadic template
// while reliably matching ABI with trap.S
inline uintptr_t syscall(Syscall syscall_number) {
  if (isInIrq() && syscall_number == Syscall::SCHEDULER_UPDATE) {
    // If called from within an interrupt service routine we will need to
    // postpone the actual update by jacking into the interrupt handler return
    // address
    asm volatile("call deri_arch_defer_scheduler_update" /* <- trap.S */ ::
                     : "ra", "memory");
    // We can't really return a value here because we have deferred the actual
    // call
    return ~uintptr_t{0u};
  } else {
    uintptr_t register return_value asm("a0");
    asm volatile(
        "mv a7, %1\n\t"
        "ecall"
        : "=r"(return_value)
        : "r"(syscall_number)
        : "memory");
    return return_value;
  }
}
}  // namespace deri::arch
