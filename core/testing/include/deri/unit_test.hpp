/*
 * Copyright (c) 2022 Joakim Nohlgård
 */

#pragma once

#include "deri/function.hpp"

#include <algorithm>
#include <string_view>
#include <concepts>
#include <type_traits>
#include <functional>

namespace deri::test {

struct Location {
  const void *ptr;

  [[gnu::always_inline]] inline static Location my_caller() {
    return {__builtin_extract_return_addr(__builtin_return_address(0))};
  }
};

class Test;
class Subcase;

struct Stats {
  int failed{};
  int passed{};
  int skipped{};
};

class Runner {
 public:
  // Maximum number of recorded test check failure locations
  static constexpr auto max_locations = 10;
  // Maximum number of nested test cases.
  static constexpr auto max_levels = 8;

  using SubcaseLocator = std::array<int, max_levels>;

  static void checkFailed(Location location);
  static void checkPassed(Location location);
  static void checkSkipped(Location) { ++checks.skipped; }

  static void runTest(Test &test, Function<void()>);

 private:
  static inline std::array<Location, max_locations> locations{};
  static inline size_t location_count{};
  static inline SubcaseLocator next_subcase{};
  static inline Stats cases{};
  static inline Stats checks{};
  static inline int level{};
  static inline Test *current_test{nullptr};
  static inline bool found_leaf{};
  static inline int failed_before_current_iteration{};
};

class Test {
 public:
  explicit Test(std::string_view name) : name{name} {}

  template <class Callable>
  inline void operator=(Callable &&callable) {
    Runner::runTest(*this, [&callable]() { callable(); });
  }

  std::string_view name{"<unnamed>"};

 private:
  int subcase_counter{};
  Test *parent{nullptr};
  friend Runner;
};

struct Expression {};

class Check;
template <typename Contained>
class Value;

template <typename Left, typename Right, class Operation>
inline constexpr auto binaryOp(Operation operation, Left &&lhs, Right &&rhs);

template <typename Left, typename Right, class Operation, typename Result>
class BinaryOp;
template <typename Left, typename Right, class Operation, typename Result>
std::ostream &operator<<(std::ostream &,
                         const BinaryOp<Left, Right, Operation, Result> &);
template <typename Contained>
std::ostream &operator<<(std::ostream &, const Value<Contained> &);

namespace {
template <class Operation>
static inline constexpr std::string_view as_string;
template <>
[[maybe_unused]] inline constexpr std::string_view as_string<std::plus<>>{"+"};
template <>
[[maybe_unused]] inline constexpr std::string_view as_string<std::minus<>>{"-"};
template <>
[[maybe_unused]] inline constexpr std::string_view as_string<std::multiplies<>>{
    "*"};
template <>
[[maybe_unused]] inline constexpr std::string_view as_string<std::divides<>>{
    "/"};
template <>
[[maybe_unused]] inline constexpr std::string_view as_string<std::modulus<>>{
    "%"};
template <>
[[maybe_unused]] inline constexpr std::string_view as_string<std::negate<>>{
    "-"};
template <>
[[maybe_unused]] inline constexpr std::string_view
    as_string<std::logical_and<>>{"&&"};
template <>
[[maybe_unused]] inline constexpr std::string_view as_string<std::logical_or<>>{
    "||"};
template <>
[[maybe_unused]] inline constexpr std::string_view
    as_string<std::logical_not<>>{"!"};
template <>
[[maybe_unused]] inline constexpr std::string_view as_string<std::equal_to<>>{
    "=="};
template <>
[[maybe_unused]] inline constexpr std::string_view
    as_string<std::not_equal_to<>>{"!="};
template <>
[[maybe_unused]] inline constexpr std::string_view as_string<std::less<>>{"<"};
template <>
[[maybe_unused]] inline constexpr std::string_view as_string<std::less_equal<>>{
    "<="};
template <>
[[maybe_unused]] inline constexpr std::string_view as_string<std::greater<>>{
    ">"};
template <>
[[maybe_unused]] inline constexpr std::string_view
    as_string<std::greater_equal<>>{">="};
}  // namespace

namespace {
template <typename Value>
inline constexpr auto evaluated(Value &&value) requires(requires(Value value) {
  value.evaluate();
}) {
  return value.evaluate();
}

inline constexpr auto evaluated(auto &&value) { return value; }
}  // namespace

class Check {
 public:
  template <typename Snatched>
  constexpr auto operator%(Snatched expression_beginning) const {
    // root_expression = nullptr;
    // std::cout << "Check " << expression_beginning << std::endl;
    return Value<Snatched>{expression_beginning};
  }

  static constexpr void updateRoot(const auto &new_root) {
    root_expression = static_cast<const void *>(&new_root);
  }
  static constexpr void completeIfRoot(auto &expression) {
    if (isThisRoot(expression)) {
      if (auto result = evaluated(expression)) [[likely]] {
        Runner::checkPassed(Location::my_caller());
      } else [[unlikely]] {
        Runner::checkFailed(Location::my_caller());
      }
      root_expression = nullptr;
    }
  }

 private:
  static constexpr bool isThisRoot(const auto &expression) {
    return root_expression == static_cast<const void *>(&expression);
  }

  static inline const void *root_expression{};
};

template <typename Left, typename Right, class Operation, typename Result>
class BinaryOp {
 public:
  constexpr BinaryOp(const BinaryOp &other)
      : lhs{other.lhs}, rhs{other.rhs}, value{other.value}, op{other.op} {
    Check::updateRoot(*this);
    // std::cout << this << " C- " << &other << ":" << other << std::endl;
  };
  // BinaryOp(const BinaryOp &) = delete;
  constexpr BinaryOp(Operation op, auto &&lhs, auto &&rhs)
      : lhs(lhs), rhs(rhs), op(op) {
    Check::updateRoot(*this);
    // std::cout << this << " @- " << &lhs << ":" << lhs << " " << to_string(op)
    // << " " << &rhs << ":" << rhs << std::endl;
  }
  constexpr ~BinaryOp() {
    // std::cout << this << " ~- " << &lhs << ":" << lhs << " " << to_string(op)
    // << " " << &rhs << ":" << rhs << std::endl;
    Check::completeIfRoot(*this);
  }

  constexpr Result evaluate() const {
    return op(evaluated(lhs), evaluated(rhs));
  }

  constexpr auto operator+(auto rhs) const {
    return binaryOp(std::plus(), *this, rhs);
  }
  constexpr auto operator-(auto rhs) const {
    return binaryOp(std::minus(), *this, rhs);
  }
  constexpr auto operator*(auto rhs) const {
    return binaryOp(std::multiplies(), *this, rhs);
  }
  constexpr auto operator/(auto rhs) const {
    return binaryOp(std::divides(), *this, rhs);
  }
  constexpr auto operator%(auto rhs) const {
    return binaryOp(std::modulus(), *this, rhs);
  }

  constexpr auto operator==(auto rhs) const {
    return binaryOp(std::equal_to(), *this, rhs);
  }
  constexpr auto operator!=(auto rhs) const {
    return binaryOp(std::not_equal_to(), *this, rhs);
  }
  constexpr auto operator<(auto rhs) const {
    return binaryOp(std::less(), *this, rhs);
  }
  constexpr auto operator<=(auto rhs) const {
    return binaryOp(std::less_equal(), *this, rhs);
  }
  constexpr auto operator>(auto rhs) const {
    return binaryOp(std::greater(), *this, rhs);
  }
  constexpr auto operator>=(auto rhs) const {
    return binaryOp(std::greater_equal(), *this, rhs);
  }

  constexpr auto operator||(auto rhs) const {
    return binaryOp(std::logical_or(), *this, rhs);
  }
  constexpr auto operator&&(auto rhs) const {
    return binaryOp(std::logical_and(), *this, rhs);
  }

 private:
  Left lhs;
  Right rhs;
  Result value;
  [[no_unique_address]] Operation op;

  friend std::ostream &operator<<<>(std::ostream &, const BinaryOp &);
};

template <typename Left, typename Right, class Operation>
constexpr auto binaryOp(Operation operation, Left &&lhs, Right &&rhs) {
  using Return = decltype(operation(evaluated(lhs), evaluated(rhs)));
  return BinaryOp<std::remove_reference_t<Left>,
                  std::remove_reference_t<Right>,
                  std::remove_reference_t<Operation>,
                  Return>(operation, lhs, rhs);
}

template <std::integral Contained>
class Value<Contained> {
 public:
  constexpr Value(const Value &other) : value(other.value) {
    Check::updateRoot(*this);
    // std::cout << this << " C " << &other << " " << value << std::endl;
  }
  // Value(const Value&) = delete;
  constexpr Value(Contained value) : value(value) {
    Check::updateRoot(*this);
    // std::cout << this << " @ " << std::boolalpha << value << std::endl;
  }
  constexpr ~Value() {
    // std::cout << this << " ~ " << std::boolalpha << value << std::endl;
    Check::completeIfRoot(*this);
  }

  constexpr Contained evaluate() const { return value; }

  constexpr auto operator+(auto rhs) const {
    return binaryOp(std::plus(), *this, rhs);
  }
  constexpr auto operator-(auto rhs) const {
    return binaryOp(std::minus(), *this, rhs);
  }
  constexpr auto operator*(auto rhs) const {
    return binaryOp(std::multiplies(), *this, rhs);
  }
  constexpr auto operator/(auto rhs) const {
    return binaryOp(std::divides(), *this, rhs);
  }
  constexpr auto operator%(auto rhs) const {
    return binaryOp(std::modulus(), *this, rhs);
  }

  constexpr auto operator==(auto rhs) const {
    return binaryOp(std::equal_to(), *this, rhs);
  }
  constexpr auto operator!=(auto rhs) const {
    return binaryOp(std::not_equal_to(), *this, rhs);
  }
  constexpr auto operator<(auto rhs) const {
    return binaryOp(std::less(), *this, rhs);
  }
  constexpr auto operator<=(auto rhs) const {
    return binaryOp(std::less_equal(), *this, rhs);
  }
  constexpr auto operator>(auto rhs) const {
    return binaryOp(std::greater(), *this, rhs);
  }
  constexpr auto operator>=(auto rhs) const {
    return binaryOp(std::greater_equal(), *this, rhs);
  }
  constexpr auto operator||(auto rhs) const {
    return binaryOp(std::logical_or(), *this, rhs);
  }
  constexpr auto operator&&(auto rhs) const {
    return binaryOp(std::logical_and(), *this, rhs);
  }

 private:
  Contained value;
  friend Check;
  friend std::ostream &operator<<<>(std::ostream &, const Value &);
};

template <typename Left, typename Right, class Operation, typename Result>
std::ostream &operator<<(std::ostream &os,
                         const BinaryOp<Left, Right, Operation, Result> &bin) {
  os << "(" << bin.lhs << " " << as_string<Operation> << " " << bin.rhs << ")";
  return os;
}

template <typename Contained>
std::ostream &operator<<(std::ostream &os, const Value<Contained> &val) {
  os << val.value;
  return os;
}

constexpr static Check check;

}  // namespace deri::test

namespace deri::literals {
template <typename LiteralType, std::size_t literal_length>
struct TestCaseLiteral {
  LiteralType name[literal_length];
  constexpr TestCaseLiteral(LiteralType const (&literal)[literal_length]) {
    std::copy_n(literal, literal_length - 1, name);
  };

  constexpr auto test() const {
    return test::Test{.name{name, literal_length - 1}};
  }
};
template <TestCaseLiteral literal>
constexpr auto operator""_test() {
  return literal.test();
}

}  // namespace deri::literals
