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

void Runner::runTest(Test &test, Function<void()> test_function) {
  // Depth-first iteration over all test case leaves.
  // We do not have any prior knowledge about the test case tree when we get
  // here the first time so we need to figure out the layout as we go.
  // In order to be able to count the branch decisions we need to have a
  // separate coordinate on each level of subcases.
  if (current_test == nullptr) {
    // Top-level test case, start over from the beginning
    next_subcase.fill(0);
    level = 0;
    failed_before_current_iteration = checks.failed;
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
    test.parent = current_test;
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
      if (!found_leaf) {
        if (failed_before_current_iteration == checks.failed) {
          ++cases.passed;
        } else {
          ++cases.failed;
        }
        failed_before_current_iteration = checks.failed;
      }
      found_leaf = true;
      Logger::trace(' ', level)
          << "Completed " << level << " " << test.name << "\n";
      // Target the first branch in the next case on the parent level
      next_subcase[level] = 0;
      if (level == 0) {
        break;
      }
      ++next_subcase[level - 1];
    }
    if (test.parent != nullptr) {
      --level;
      current_test = test.parent;
      break;
    }
    found_leaf = false;
  } while (true);
}
void Runner::checkPassed(Location location) {
  Logger::info("Pass %p\n", location.ptr);
  ++checks.passed;
}
void Runner::checkFailed(Location location) {
  Logger::info("Fail %p\n", location.ptr);
  ++checks.failed;
  if (location_count < locations.size()) {
    locations[location_count] = location;
    ++location_count;
  }
}

}  // namespace deri::test
