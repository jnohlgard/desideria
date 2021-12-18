#pragma once

#include <algorithm>
#include <span>

namespace deri::literals {
template <typename ValueType, std::size_t literal_length_including_terminator>
struct SpanLiteral {
  inline static constexpr std::size_t literal_length =
      literal_length_including_terminator - 1;

  using SpanType = std::span<const ValueType, literal_length>;
  ValueType data[literal_length];

  constexpr SpanLiteral(
      ValueType const (&literal)[literal_length_including_terminator]) {
    std::copy_n(literal, literal_length, data);
  };

  constexpr SpanType span() const { return SpanType{data}; }
};
template <SpanLiteral literal>
constexpr auto operator"" _span() {
  return literal.span();
}
}  // namespace deri::literals
