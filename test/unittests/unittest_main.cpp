/*
 * Copyright (C) 2022 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include "deri/log.hpp"
#include "deri/unit_test.hpp"

using namespace deri::test;

namespace log {
using namespace deri::log;
struct Test;
struct Test : LogConfig<Level::INFO> {};
}  // namespace log

using Logger = deri::log::Logger<log::Test>;

using namespace deri::literals;

namespace deri::test {
void test_forward_list();
}

int main() {
  test_forward_list();

  logTestSummary(Logger::warning);
  return 0;
}
