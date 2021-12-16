/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/irq.hpp"

#include <array>
#include <cstddef>
#include <optional>

namespace deri {

template <typename ValueType, size_t size>
class RingBuffer {
  static_assert(size > 1);
  static_assert((size & ~(size - 1)) == size,
                "RingBuffer size must be a power of two");

 public:
  [[nodiscard]] std::optional<ValueType> get() {
    if (empty()) {
      return std::nullopt;
    }
    return buffer[read_offset++ & index_mask];
  }

  [[nodiscard]] bool put(ValueType value) {
    if (!full()) {
      buffer[write_offset++ & index_mask] = value;
      return true;
    }
    return false;
  }

  [[nodiscard]] size_t available() const { return write_offset - read_offset; }
  [[nodiscard]] bool empty() const { return (available() == 0); }
  [[nodiscard]] bool full() const { return (available() == size); }

 private:
  size_t read_offset{};
  size_t write_offset{};
  std::array<ValueType, size> buffer{};

  static constexpr size_t index_mask = (size - 1);
};
}  // namespace deri
