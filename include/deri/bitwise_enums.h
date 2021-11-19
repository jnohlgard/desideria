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

template <Bitmask Enum>
bool operator!(Enum operand) {
  return operand == static_cast<Enum>(0);
}

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

template <typename Enum>
concept Bitshift = requires(Enum shift) {
  IsBitShift(shift);
};

template <Bitmask Mask, Bitshift Shift>
constexpr std::underlying_type_t<Mask> operator>>(const Mask lhs,
                                                  const Shift rhs) {
  return static_cast<std::underlying_type_t<Mask>>(lhs) >>
         static_cast<unsigned>(rhs);
}
