#pragma once

#include "deri/bitwise_enums.hpp"

#include <atomic>
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
          typename StorageType = std::underlying_type_t<BitsType>,
          typename RawStorageType = StorageType>
class Register {
 public:
  // These objects are hardware constructs, a constructor in software does not
  // make sense in the general case.
  Register() = delete;
  Register(const Register &) = delete;
  Register(Register &&) noexcept = delete;
  Register &operator=(const Register &) = delete;
  Register &operator=(Register &&) noexcept = delete;

  // operators when StorageType has atomic operations:
  [[nodiscard]] BitsType load() const
      requires(requires(StorageType bits) { bits.load(); }) {
    return BitsType{bits.load()};
  }
  void store(const BitsType op) requires(requires(StorageType bits,
                                                  RawStorageType value) {
    bits.store(value);
  }) {
    bits.store(static_cast<RawStorageType>(op));
  }
  void operator|=(const BitsType op) requires(requires(StorageType bits) {
    fetch_or(bits);
  }) {
    fetch_or(op);
  }
  void operator&=(const BitsType op) requires(requires(StorageType bits) {
    fetch_and(bits);
  }) {
    fetch_and(op);
  }
  void operator^=(const BitsType op) requires(requires(StorageType bits) {
    fetch_xor(bits);
  }) {
    fetch_xor(op);
  }
  BitsType fetch_or(const BitsType op) requires(requires(StorageType bits,
                                                         RawStorageType value) {
    bits.fetch_or(value);
  }) {
    return BitsType{bits.fetch_or(static_cast<RawStorageType>(op))};
  }
  BitsType fetch_and(const BitsType op) requires(requires(
      StorageType bits, RawStorageType value) { bits.fetch_and(value); }) {
    return BitsType{bits.fetch_and(static_cast<RawStorageType>(op))};
  }
  BitsType fetch_xor(const BitsType op) requires(requires(
      StorageType bits, RawStorageType value) { bits.fetch_xor(value); }) {
    return BitsType{bits.fetch_xor(static_cast<RawStorageType>(op))};
  }

  // Default operators when StorageType does not provide atomic access methods:
  [[nodiscard]] BitsType load() const { return BitsType{bits}; }
  void store(const BitsType op) { bits = static_cast<StorageType>(op); }
  void operator|=(const BitsType op) {
    auto value = bits;
    value |= static_cast<StorageType>(op);
    bits = value;
  }
  void operator&=(const BitsType op) {
    auto value = bits;
    value &= static_cast<StorageType>(op);
    bits = value;
  }
  void operator^=(const BitsType op) {
    auto value = bits;
    value ^= static_cast<StorageType>(op);
    bits = value;
  }

  bool any(const BitsType mask) { return !!(load() & mask); }

 private:
  volatile StorageType bits;
};

static_assert(sizeof(Register<std::byte>) == sizeof(std::uint8_t));
static_assert(sizeof(Reserved<std::byte>) == sizeof(std::uint8_t));

/**
 * Hardware register that can be accessed using atomic operations
 */
template <typename BitsType>
using AtomicRegister = Register<
    BitsType,
    volatile std::atomic<std::underlying_type_t<BitsType>>,
    typename std::atomic<std::underlying_type_t<BitsType>>::value_type>;

static_assert(sizeof(AtomicRegister<std::byte>) == sizeof(std::uint8_t));
}  // namespace deri::mmio
