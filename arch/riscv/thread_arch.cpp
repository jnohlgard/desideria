/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#include "deri/log.hpp"
#include "deri/arch/thread.hpp"

#include <string_view>

#define DECLARE_CAUSE(description, label) \
  static constexpr auto DESC_##label = std::string_view(description);

#include "riscv/csr/encoding.h"

namespace deri::log {
struct Kernel;
}

namespace deri::arch {

constexpr std::array mcause_descriptions = {
    DESC_CAUSE_MISALIGNED_FETCH,
    DESC_CAUSE_FETCH_ACCESS,
    DESC_CAUSE_ILLEGAL_INSTRUCTION,
    DESC_CAUSE_BREAKPOINT,
    DESC_CAUSE_MISALIGNED_LOAD,
    DESC_CAUSE_LOAD_ACCESS,
    DESC_CAUSE_MISALIGNED_STORE,
    DESC_CAUSE_STORE_ACCESS,
    DESC_CAUSE_USER_ECALL,
    DESC_CAUSE_SUPERVISOR_ECALL,
    DESC_CAUSE_HYPERVISOR_ECALL,
    DESC_CAUSE_MACHINE_ECALL,
    DESC_CAUSE_FETCH_PAGE_FAULT,
    DESC_CAUSE_LOAD_PAGE_FAULT,
    DESC_CAUSE_STORE_PAGE_FAULT,
};

[[gnu::naked, gnu::used]] void saveContext(SavedContext &context) {
  asm volatile(
      ".equ REG_SIZE, 4\n\t"
      // save sp first
      "sw sp,   2 * REG_SIZE(a0)\n\t"
      // Use sp instead of a0 to reduce code size when compiling with compressed
      // instructions
      "mv sp, a0\n\t"
      "sw gp,   3 * REG_SIZE(sp)\n\t"
      "sw tp,   4 * REG_SIZE(sp)\n\t"
      "sw t0,   5 * REG_SIZE(sp)\n\t"
      "sw t1,   6 * REG_SIZE(sp)\n\t"
      "sw t2,   7 * REG_SIZE(sp)\n\t"
      "sw s0,   8 * REG_SIZE(sp)\n\t"
      "sw s1,   9 * REG_SIZE(sp)\n\t"
      // skip a0, used for passing function argument
      "sw a1,  11 * REG_SIZE(sp)\n\t"
      "sw a2,  12 * REG_SIZE(sp)\n\t"
      "sw a3,  13 * REG_SIZE(sp)\n\t"
      "sw a4,  14 * REG_SIZE(sp)\n\t"
      "sw a5,  15 * REG_SIZE(sp)\n\t"
      "sw a6,  16 * REG_SIZE(sp)\n\t"
      "sw a7,  17 * REG_SIZE(sp)\n\t"
      "sw s2,  18 * REG_SIZE(sp)\n\t"
      "sw s3,  19 * REG_SIZE(sp)\n\t"
      "sw s4,  20 * REG_SIZE(sp)\n\t"
      "sw s5,  21 * REG_SIZE(sp)\n\t"
      "sw s6,  22 * REG_SIZE(sp)\n\t"
      "sw s7,  23 * REG_SIZE(sp)\n\t"
      "sw s8,  24 * REG_SIZE(sp)\n\t"
      "sw s9,  25 * REG_SIZE(sp)\n\t"
      "sw s10, 26 * REG_SIZE(sp)\n\t"
      "sw s11, 27 * REG_SIZE(sp)\n\t"
      "sw t3,  28 * REG_SIZE(sp)\n\t"
      "sw t4,  29 * REG_SIZE(sp)\n\t"
      "sw t5,  30 * REG_SIZE(sp)\n\t"
      "sw t6,  31 * REG_SIZE(sp)\n\t"
      "csrr t0, mepc\n\t"
      "sw t0,  0 * REG_SIZE(sp)\n\t"
      "csrr t0, mstatus\n\t"
      "csrr t1, mtval\n\t"
      "csrr t2, mcause\n\t"
      "sw t0,  32 * REG_SIZE(sp)\n\t"
      "sw t1,  33 * REG_SIZE(sp)\n\t"
      "sw t2,  34 * REG_SIZE(sp)\n\t"
      "lw sp,   2 * REG_SIZE(sp)\n\t"
      "ret");
}

[[gnu::used]] void dumpContext(const SavedContext &context) {
  using Logger = log::Logger<log::Kernel>;
  bool do_ebreak = true;
  auto hartid = read_csr(mhartid);
  if (context.pc != 0) {
    long mcause = read_csr(mcause);
    if (mcause < 0) {
      Logger::critical << "Unhandled interrupt on hart " << hartid << "\n";
    } else {
      auto description = std::string_view("unknown");
      if ((mcause & 0xff) == CAUSE_BREAKPOINT) {
        do_ebreak = false;
      }
      if ((mcause & 0xff) < mcause_descriptions.size()) {
        description = mcause_descriptions[mcause & 0xff];
      }
      Logger::critical << "Exception on hart " << hartid << ": " << description << "\n";
    }
  }
  Logger::critical << "Context dump on hart " << hartid << ":\n";
  auto saved_registers = reinterpret_cast<const void *const *>(&context);
  for (unsigned k = 0; k < SavedContext::register_names.size(); ++k) {
    Logger::critical(
        "%8s: %p\n", SavedContext::register_names[k], saved_registers[k]);
  }
  Logger::critical("mscratch: %p\n",
                   reinterpret_cast<const void *>(read_csr(mscratch)));
  if (do_ebreak) {
    Logger::critical << "Break for debugger...\n";
    asm volatile("ebreak" ::: "memory");
  }
}
}  // namespace deri::arch
