/*
 * Copyright (c) 2022 Joakim Nohlgård
 */

#pragma once

#include "deri/function.hpp"

#include <algorithm>
#include <string_view>

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
  unsigned failed{};
  unsigned passed{};
  unsigned skipped{};
};

class Runner {
 public:
  // Maximum number of recorded test check failure locations
  static constexpr auto max_locations = 10;
  // Maximum number of nested test cases.
  static constexpr auto max_levels = 8;

  static void failed_check(Location location);

  static void runTest(Test &test, Function<void()>);

 private:
  using SubcaseLocator = std::array<unsigned, max_levels>;
  static inline std::array<Location, max_locations> failed_locations{};
  static inline SubcaseLocator next_subcase{};
  static inline Stats cases{};
  static inline Stats checks{};
  static inline unsigned level{};
  static inline Test *current_test{nullptr};
  static inline bool found_leaf{};
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
  friend Runner;
};

struct Expression {};

struct Check {
  Check(Expression exp);
};

[[gnu::noinline]] void check(bool result);

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
