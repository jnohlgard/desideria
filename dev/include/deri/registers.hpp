#pragma once

#include "deri/bitwise_enums.hpp"

#include <cstddef>
#include <cstdint>
#include <type_traits>

namespace deri::mmio {

/**
 * Reserved register that should not be touched by the software
 *
 * Can be used as padding between fields to map a struct onto hardware
 * registers.
 *
 * @tparam RegType Data type of the reserved field, typically some fixed-width
 * integer
 */
template <typename RegType>
class Reserved {
 public:
  Reserved() = delete;
  Reserved(const Reserved &) = delete;
  Reserved(Reserved &&) noexcept = delete;
  Reserved &operator=(const Reserved &) = delete;
  Reserved &operator=(Reserved &&) noexcept = delete;

 private:
  const RegType reserved;
};

/**
 * Hardware registers for type-safe access with explicit loads and stores
 *
 * @tparam BitsType Logical type of the data stored in the hardware register,
 * typically some enum class
 * @tparam StorageType Type of the hardware register itself, typically some
 * fixed-width integer
 * @tparam UnderlyingBitsType Underlying type of @p BitsType when @p BitsType is
 * an enum
 */
template <typename BitsType,
          typename StorageType = volatile std::underlying_type_t<BitsType>,
          typename UnderlyingBitsType = std::underlying_type_t<BitsType>>
class Register {
 public:
  // These objects are hardware constructs, a constructor in software does not
  // make sense in the general case.
  Register() = delete;
  Register(const Register &) = delete;
  Register(Register &&) noexcept = delete;
  Register &operator=(const Register &) = delete;
  Register &operator=(Register &&) noexcept = delete;

  [[nodiscard]] BitsType load() const { return static_cast<BitsType>(bits); }

  void store(const BitsType op) { bits = static_cast<StorageType>(op); }

  void operator|=(const BitsType op) { store(load() | op); }
  void operator&=(const BitsType op) { store(load() & op); }
  void operator^=(const BitsType op) { store(load() ^ op); }

  bool any(const BitsType mask) {
    return bool(static_cast<UnderlyingBitsType>(load() & mask));
  }

 private:
  StorageType bits;
};

static_assert(sizeof(Register<std::byte>) == sizeof(std::uint8_t));
static_assert(sizeof(Reserved<std::byte>) == sizeof(std::uint8_t));
}  // namespace deri::dev
