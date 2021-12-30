/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/mmio/BACKUP.hpp"

#include <cstdint>

namespace deri::mmio {
/**
 * Bitmasks for BACKUP backup[16]
 *
 * Backup Register
 */
enum class BACKUP_regs::backup_bits : uint32_t {
  Reserved_mask = 0xffffffff  ///< All reserved bits
};
void HasBitwiseOperators(BACKUP_regs::backup_bits);

/**
 * Bit shifts for BACKUP backup[16]
 */
enum class BACKUP_regs::backup_shift : unsigned {};

static_assert(offsetof(BACKUP_regs, backup) == 0x0);
}  // namespace deri::mmio
