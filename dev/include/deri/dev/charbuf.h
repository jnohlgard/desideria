/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#include <concepts>
#include <cstddef>
#include <span>

template <class T>
concept Writable = requires(T a, std::span<const std::byte> buffer) {
  { a.write(buffer) } -> std::convertible_to<decltype(buffer)>;
};

namespace deri::dev {
template <Writable Device>
class BlockingDevice {
  Device &dev;

 public:
  explicit constexpr BlockingDevice(Device &dev) : dev{dev} {}

  void write(std::span<const std::byte> buffer) {
    while (!buffer.empty()) {
      buffer = dev.write(buffer);
    }
  }
};
}  // namespace deri::dev
