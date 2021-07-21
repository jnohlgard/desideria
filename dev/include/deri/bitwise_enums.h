/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once
#include <type_traits>

// Use `void HasBitwiseOperators(MyEnumType);` to enable the templates in this
// file for a particular type

template <typename Enum>
concept Bitmask = requires(Enum mask) {
  HasBitwiseOperators(mask);
};

template <Bitmask Enum,
          typename IntermediateType = std::underlying_type_t<Enum>>
constexpr Enum operator|(Enum lhs, Enum rhs) {
  return static_cast<Enum>(static_cast<IntermediateType>(lhs) |
                           static_cast<IntermediateType>(rhs));
}

template <Bitmask Enum,
          typename IntermediateType = std::underlying_type_t<Enum>>
constexpr Enum operator~(Enum operand) {
  return static_cast<Enum>(~static_cast<IntermediateType>(operand));
}

template <Bitmask Enum,
          typename IntermediateType = std::underlying_type_t<Enum>>
constexpr Enum operator&(Enum lhs, Enum rhs) {
  return static_cast<Enum>(static_cast<IntermediateType>(lhs) &
                           static_cast<IntermediateType>(rhs));
}

template <Bitmask Enum,
          typename IntermediateType = std::underlying_type_t<Enum>>
constexpr Enum operator^(Enum lhs, Enum rhs) {
  return static_cast<Enum>(static_cast<IntermediateType>(lhs) ^
                           static_cast<IntermediateType>(rhs));
}

template <Bitmask Enum>
constexpr Enum &operator|=(Enum &lhs, const Enum rhs) {
  lhs = lhs | rhs;
  return lhs;
}

template <Bitmask Enum>
constexpr Enum &operator&=(Enum &lhs, const Enum rhs) {
  lhs = lhs & rhs;
  return lhs;
}

template <Bitmask Enum>
constexpr Enum &operator^=(Enum &lhs, const Enum rhs) {
  lhs = lhs ^ rhs;
  return lhs;
}
