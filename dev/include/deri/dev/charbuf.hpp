/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#include <concepts>
#include <cstddef>
#include <span>

template <class Device>
concept SpanWritable = requires(Device device,
                                std::span<const std::byte> buffer) {
  { device.write(buffer) } -> std::convertible_to<decltype(buffer)>;
};

namespace deri::dev {
template <SpanWritable LowlevelDevice>
class BlockingDevice {
  LowlevelDevice &dev;

 public:
  explicit constexpr BlockingDevice(LowlevelDevice &dev) : dev{dev} {}

  void write(std::span<const std::byte> buffer) {
    while (!buffer.empty()) {
      buffer = dev.write(buffer);
    }
  }
};
}  // namespace deri::dev
