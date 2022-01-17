/*
 * Copyright (c) 2022 Joakim Nohlgård
 */

#pragma once

#include "deri/function.hpp"
#include "deri/log.hpp"

#include <algorithm>
#include <concepts>
#include <functional>
#include <string_view>
#include <type_traits>

// Much inspiration for this framework was taken from Kris Jusiak's
// UT: C++20 μ(micro)/Unit Testing Framework
// https://boost-ext.github.io/ut/
namespace deri::log {
struct Check;
struct Check : LogConfig<Level::INFO> {};
}  // namespace deri::log

namespace deri::test {

struct Location {
  const void *ptr;
  // TODO: Use source_location when GCC 11 is widely available.

  [[gnu::always_inline]] inline static Location my_caller() {
    return {__builtin_extract_return_addr(__builtin_return_address(0))};
  }
};

class Test;

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

  template <class Stream>
  static void summary(Stream &);

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

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
  template <class Callable>
  inline void operator=(Callable &&callable) {
    Runner::runTest(*this, [&callable]() { callable(); });
  }
#pragma GCC diagnostic pop

  std::string_view name{"<unnamed>"};

 private:
  int subcase_counter{};
  Test *parent{nullptr};
  friend Runner;
};

class Check;
template <typename Contained>
class Value;

template <typename Left, typename Right, class Operation>
inline constexpr auto binaryOp(Operation operation, Left &&lhs, Right &&rhs);

template <typename Left, typename Right, class Operation, typename Result>
class BinaryOp;

namespace {
using namespace std::string_view_literals;
template <class Operation>
static inline constexpr std::string_view as_string;
template <>
[[maybe_unused]] inline constexpr auto as_string<std::plus<>>{"+"sv};
template <>
[[maybe_unused]] inline constexpr auto as_string<std::minus<>>{"-"sv};
template <>
[[maybe_unused]] inline constexpr auto as_string<std::multiplies<>>{"*"sv};
template <>
[[maybe_unused]] inline constexpr auto as_string<std::divides<>>{"/"sv};
template <>
[[maybe_unused]] inline constexpr auto as_string<std::modulus<>>{"%"sv};
template <>
[[maybe_unused]] inline constexpr auto as_string<std::negate<>>{"-"sv};
template <>
[[maybe_unused]] inline constexpr auto as_string<std::logical_and<>>{"&&"sv};
template <>
[[maybe_unused]] inline constexpr auto as_string<std::logical_or<>>{"||"sv};
template <>
[[maybe_unused]] inline constexpr auto as_string<std::logical_not<>>{"!"sv};
template <>
[[maybe_unused]] inline constexpr auto as_string<std::equal_to<>>{"=="sv};
template <>
[[maybe_unused]] inline constexpr auto as_string<std::not_equal_to<>>{"!="sv};
template <>
[[maybe_unused]] inline constexpr auto as_string<std::less<>>{"<"sv};
template <>
[[maybe_unused]] inline constexpr auto as_string<std::less_equal<>>{"<="sv};
template <>
[[maybe_unused]] inline constexpr auto as_string<std::greater<>>{">"sv};
template <>
[[maybe_unused]] inline constexpr auto as_string<std::greater_equal<>>{">="sv};
}  // namespace

template <typename Value>
static inline constexpr auto evaluated(Value &&value) requires(
    requires(Value value) { value.evaluate(); }) {
  return value.evaluate();
}

template <typename Value>
static inline constexpr auto &&evaluated(Value &&value) {
  return std::forward<Value>(value);
}

class Check {
  using Logger = log::Logger<log::Check>;

 public:
  template <typename Snatched>
  constexpr auto operator%(Snatched &&expression_beginning) const;

  static constexpr void updateRoot(const auto &new_root) {
    root_expression = static_cast<const void *>(&new_root);
  }
  static constexpr void completeIfRoot(auto &expression);

 private:
  static constexpr bool isThisRoot(const auto &expression) {
    return root_expression == static_cast<const void *>(&expression);
  }

  static inline const void *root_expression{};
};

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
template <typename Left, typename Right, class Operation, typename Result>
class BinaryOp {
 public:
  constexpr BinaryOp(const BinaryOp &other)
      : lhs{other.lhs}, rhs{other.rhs}, op{other.op} {
    Check::updateRoot(*this);
  };
  constexpr BinaryOp(Operation op, auto &&lhs, auto &&rhs)
      : lhs(lhs), rhs(rhs), op(op) {
    Check::updateRoot(*this);
  }
  constexpr ~BinaryOp() { Check::completeIfRoot(*this); }

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

  template <class Stream>
  friend inline Stream &operator<<(
      Stream &os, const BinaryOp<Left, Right, Operation, Result> &bin) {
    os << "(" << bin.lhs << " " << as_string<Operation> << " " << bin.rhs
       << ")";
    return os;
  }

 private:
  Left lhs;
  Right rhs;
  [[no_unique_address]] Operation op;
};
#pragma GCC diagnostic pop

template <typename Left, typename Right, class Operation>
constexpr auto binaryOp(Operation operation, Left &&lhs, Right &&rhs) {
  using Return = decltype(operation(evaluated(lhs), evaluated(rhs)));
  return BinaryOp<std::remove_reference_t<Left>,
                  std::remove_reference_t<Right>,
                  std::remove_reference_t<Operation>,
                  Return>(
      operation, std::forward<Left>(lhs), std::forward<Right>(rhs));
}

template <std::integral Contained>
class Value<Contained> {
 public:
  constexpr Value(const Value &other) : value(other.value) {
    Check::updateRoot(*this);
  }
  constexpr Value(Contained value) : value(value) { Check::updateRoot(*this); }
  constexpr ~Value() { Check::completeIfRoot(*this); }

  constexpr const Contained &evaluate() const { return value; }

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

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
  constexpr auto operator||(auto rhs) const {
    return binaryOp(std::logical_or(), *this, rhs);
  }
  constexpr auto operator&&(auto rhs) const {
    return binaryOp(std::logical_and(), *this, rhs);
  }
#pragma GCC diagnostic pop

  template <class Stream>
  friend inline Stream &operator<<(Stream &os, const Value<Contained> &val) {
    os << val.value;
    return os;
  }

 private:
  Contained value;
  friend Check;
};

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
template <typename Contained>
class Value<Contained *> {
 public:
  constexpr Value(const Value &other) : ptr(other.ptr) {
    Check::updateRoot(*this);
  }
  constexpr Value(Contained *ptr) : ptr(ptr) { Check::updateRoot(*this); }
  constexpr ~Value() { Check::completeIfRoot(*this); }

  constexpr Contained *evaluate() const { return ptr; }

  constexpr auto operator+(auto rhs) const {
    return binaryOp(std::plus(), *this, rhs);
  }
  constexpr auto operator-(auto rhs) const {
    return binaryOp(std::minus(), *this, rhs);
  }

  constexpr auto operator==(auto rhs) const {
    return binaryOp(std::equal_to(), *this, rhs);
  }
  constexpr auto operator!=(auto rhs) const {
    return binaryOp(std::not_equal_to(), *this, rhs);
  }

  constexpr auto operator||(auto rhs) const {
    return binaryOp(std::logical_or(), *this, rhs);
  }
  // Removing logical AND to avoid accidental null pointer dereference in
  // non-short-circuiting (ptr && ptr->value)
  constexpr auto operator&&(auto rhs) const = delete;

  template <class Stream>
  friend inline Stream &operator<<(Stream &os, const Value<Contained *> &val) {
    os << val.ptr;
    return os;
  }

 private:
  Contained *ptr;
  friend Check;
};
#pragma GCC diagnostic pop

constexpr void Check::completeIfRoot(auto &expression) {
  if (isThisRoot(expression)) {
    if (auto result = evaluated(expression)) [[likely]] {
      Runner::checkPassed(Location::my_caller());
      Logger::debug << "Passed: " << expression << "\n";
    } else [[unlikely]] {
      Runner::checkFailed(Location::my_caller());
      Logger::info << "Failed: " << expression << "\n";
    }
    root_expression = nullptr;
  }
}
template <typename Snatched>
constexpr auto Check::operator%(Snatched &&expression_beginning) const {
  return Value<std::remove_reference_t<Snatched>>{
      std::forward<Snatched>(expression_beginning)};
}

constexpr static Check check;
void printTotals(auto &os, const Stats &stats) {
  auto total = stats.failed + stats.passed + stats.skipped;
  os << total << " total";
  if (stats.passed > 0) {
    os << " | " << stats.passed << " passed";
  }
  if (stats.failed > 0) {
    os << " | " << stats.failed << " failed";
  }
  if (stats.skipped > 0) {
    os << " | " << stats.skipped << " skipped";
  }
}

template <class Stream>
void Runner::summary(Stream &os) {
  os << "========= TEST SUMMARY =========\n";
  os << "Cases:  ";
  printTotals(os, cases);
  os << "\n";
  os << "Checks: ";
  printTotals(os, checks);
  os << "\n";
  os << "================================\n";
}

template <class Stream>
void logTestSummary(Stream &os) {
  Runner::summary(os);
}

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
