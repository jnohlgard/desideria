/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include "deri/log.hpp"
#include "deri/unit_test.hpp"

using namespace deri::test;

int sut(int num) { return 2 * num; }

namespace log {
using namespace deri::log;
struct Test;
struct Test : LogConfig<Level::INFO> {};
}  // namespace log

using Logger = deri::log::Logger<log::Test>;

using namespace deri::literals;

int main() {
  int count = 0;
  "Subcases"_test = [&count] {
    ++count;
    auto actual = sut(12);
    auto expected = 24;
    check(actual == expected);
    Logger::info("Before subcases\n");
    "subcase1"_test = [] {
      Logger::info(" First subcase\n");
      "subsub1"_test = [] { Logger::info("  in subsub1\n"); };
      "subsub2"_test = [] { Logger::info("  in subsub2\n"); };
    };
    "subcase2"_test = [] { Logger::info(" Second subcase\n"); };
    "subcase3"_test = [] {
      Logger::info(" Third subcase\n");
      "subsub1"_test = [] {
        Logger::info("  in 3-1\n");
        "subsubsub"_test = [] { Logger::info("   in 3-1-1\n"); };
        "subsubsub"_test = [] { Logger::info("   in 3-1-2\n"); };
      };
    };
    "sub4"_test = [] { Logger::info(" in 4\n"); };
    Logger::info("After subcases\n");
  };
  Logger::info("Top level was called ") << count << " times\n";
  check(count == 6);  // number of leaf nodes in the tree above
  return 0;
}
