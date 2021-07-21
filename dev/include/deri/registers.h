#pragma once

#include "deri/bitwise_enums.h"

#include <cstddef>
#include <cstdint>
#include <type_traits>

namespace deri::dev {
template <typename BitsType,
          typename StorageType = std::underlying_type_t<BitsType>>
class Register {
  using UnderlyingBitsType = std::underlying_type_t<BitsType>;

 public:
  Register() = delete;
  Register(const Register &) = delete;
  Register(Register &&) noexcept = delete;
  Register &operator=(const Register &) = delete;
  Register &operator=(Register &&) noexcept = delete;

  BitsType load() { return static_cast<BitsType>(bits); }
  void store(const BitsType op) {
    bits = static_cast<StorageType>(op);
  }

  void operator|=(const BitsType op) { store(load() | op); }
  void operator&=(const BitsType op) { store(load() & op); }
  void operator^=(const BitsType op) { store(load() ^ op); }

  bool any(const BitsType mask) {
    return bool(static_cast<UnderlyingBitsType>(load() & mask));
  }

 private:
  volatile StorageType bits;
};

static_assert(sizeof(Register<std::byte>) == sizeof(std::uint8_t));
}  // namespace deri::dev
