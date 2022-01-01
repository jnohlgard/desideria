/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/mmio/PLIC.hpp"
#include "deri/mmio/interrupts.hpp"

#include <atomic>

namespace deri::dev::irq {

class IrqPlic {
 public:
  using IRQ = mmio::IRQ;
  void init();
  void enable(IRQ irq);
  void disable(IRQ irq);

  /**
   * Called from CLINT when the "External" IRQ occurs
   */
  static void external_handler();

  /**
   * Set the PLIC interrupt vector table address
   *
   * @note This table should contain pointers to regular functions, using @c ret
   * for return, not @c mret.
   *
   * @param vector_table address of the table
   */
  static void setVectorTable(isr_func *const *vector_table);

  [[nodiscard]] static bool isInIrq() { return Claim::ongoing() != 0; }

 private:
  class Claim {
   public:
    Claim();
    ~Claim();

    [[nodiscard]] uint32_t num() const;

    [[nodiscard]] static unsigned ongoing() { return ongoing_claims.load(); }

   private:
    mmio::PLIC_regs::claim_bits bits;
    static inline std::atomic_uint ongoing_claims{};
  };

  static void handleInterrupt(IRQ irq);

  static inline isr_func *const *vector_table{nullptr};

  mmio::PLIC_regs PLIC;
};

static_assert(sizeof(IrqPlic) == sizeof(mmio::PLIC_regs));
}  // namespace deri::dev::irq
