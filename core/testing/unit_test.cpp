/*
 * Copyright (c) 2022 Joakim Nohlgård
 */

#include "deri/unit_test.hpp"

#include "deri/log.hpp"

namespace deri::log {
struct TestReport;
// struct TestReport : LogConfig<Level::TRACE> {};
}  // namespace deri::log

namespace deri::test {
using Logger = log::Logger<log::TestReport>;
void check(bool result) {
  if (!result) [[unlikely]] {
    Runner::failed_check(Location::my_caller());
  }
}

void Runner::runTest(Test &test, Function<void()> test_function) {
  // Depth-first iteration over all test case leaves.
  // We do not have any prior knowledge about the test case tree when we get
  // here the first time so we need to figure out the layout as we go.
  // In order to be able to count the branch decisions we need to have a
  // separate coordinate on each level of subcases.
  Test *enclosing_test{nullptr};
  if (current_test == nullptr) {
    // Top-level test case, start over from the beginning
    next_subcase.fill(0);
    level = 0;
  } else {
    // This is a subcase of another case
    if (level >= next_subcase.size()) {
      Logger::critical("Too many nested levels of test cases (")
          << level << ")\n";
      return;
    }
    if (next_subcase[level] != current_test->subcase_counter++ || found_leaf) {
      // We are not targeting this subcase in this iteration
      Logger::trace(' ', level)
          << "Not right now: " << level << " " << test.name << "\n";
      return;
    }
    enclosing_test = current_test;
    ++level;
  }
  do {
    test.subcase_counter = 0;
    current_test = &test;
    Logger::info(' ', level) << "Entering test " << test.name << "\n";

    test_function();

    Logger::info(' ', level) << "Leaving test " << test.name << "\n";
    // Run next subcase in the next iteration
    if (next_subcase[level] == test.subcase_counter) {
      // This test branch was completed
      found_leaf = true;
      Logger::debug(' ', level)
          << "Completed " << level << " " << test.name << "\n";
      // Target the first branch in the next case on the parent level
      next_subcase[level] = 0;
      if (level == 0) {
        break;
      }
      ++next_subcase[level - 1];
    }
    if (enclosing_test != nullptr) {
      --level;
      current_test = enclosing_test;
      break;
    }
    found_leaf = false;
  } while (true);
}

void Runner::failed_check(Location location) {
  // TODO: Remember location
}
}  // namespace deri::test
