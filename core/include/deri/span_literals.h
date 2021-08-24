#pragma once

#include <span>

constexpr std::span<const char> operator""_span(const char *literal,
                                                std::size_t length) {
  return std::span<const char>{literal, length};
}
constexpr std::span<const wchar_t> operator""_span(const wchar_t *literal,
                                                   std::size_t length) {
  return std::span<const wchar_t>{literal, length};
}
constexpr std::span<const char8_t> operator""_span(const char8_t *literal,
                                                   std::size_t length) {
  return std::span<const char8_t>{literal, length};
}
constexpr std::span<const char16_t> operator""_span(const char16_t *literal,
                                                    std::size_t length) {
  return std::span<const char16_t>{literal, length};
}
constexpr std::span<const char32_t> operator""_span(const char32_t *literal,
                                                    std::size_t length) {
  return std::span<const char32_t>{literal, length};
}
