/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include "deri/log.hpp"
#include "deri/span_literals.hpp"

#include <string_view>

using namespace deri::literals;
using namespace std::literals;

namespace log {
struct Example {
  static constexpr auto level = deri::log::Level::INFO;
};
}  // namespace log

using Logger = deri::log::ConsoleLogger<log::Example>;

void logTest() {
  auto tr = Logger::scopeTrace<deri::log::Level::CRITICAL>("logTest");
  Logger::critical("Critical\n");
  Logger::critical("Critical string_view\n"sv);
  Logger::critical("Formatted literal %u\n", 1234u);
  Logger::error("Error const char literal\n");
  Logger::error("Error span\n"_span);
  Logger::warning("Warning const char literal\n");
  Logger::warning("Warning span\n"_span);
  Logger::info("Info const char literal\n");
  Logger::info("Info span\n"_span);
  Logger::debug("Debug\n");
  Logger::trace("Trace\n");
}

int main() {
  Logger::printf("Hello world from Logger\n");
  logTest();

  while (true) {
    asm volatile("" ::: "memory");
  }
  return 0;
}
