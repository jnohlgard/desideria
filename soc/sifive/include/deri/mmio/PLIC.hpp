/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/registers.h"

#include <cstdint>

namespace deri::mmio {
struct PLIC_regs {
  enum class priority_bits : uint32_t;
  enum class pending_bits : uint32_t;
  enum class enable_bits : uint32_t;
  enum class threshold_bits : uint32_t;
  enum class claim_bits : uint32_t;
  enum class priority_shift : unsigned;
  enum class pending_shift : unsigned;
  enum class enable_shift : unsigned;
  enum class threshold_shift : unsigned;
  enum class claim_shift : unsigned;

  Register<priority_bits> priority[53];
  const Reserved<uint32_t> reserved_0[971];
  // Base + 0x1000
  Register<pending_bits> pending[2];
  const Reserved<uint32_t> reserved_1[1022];
  // Base + 0x2000
  Register<enable_bits> enable[2];
  const Reserved<uint32_t> reserved_2[522238];
  // Base + 0x200000
  Register<threshold_bits> threshold;
  Register<claim_bits> claim;
};
}  // namespace deri::mmio
