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

using Log = deri::log::ConsoleLogger<log::Example>;

void logTest() {
//  auto tr = Logger::scopeTrace<deri::log::Level::CRITICAL>("logTest");
  Log::critical("Critical\n");
  Log::critical("Critical string_view\n"sv);
  Log::critical("Critical formatted literal %u\n", 1234u);
  Log::error("Error const char literal\n");
  Log::error("Error span\n"_span);
  Log::error("Error formatted literal %u\n", 9876543u);
  Log::warning("Warning const char literal\n");
  Log::warning("Warning span\n"_span);
  Log::warning("Warning formatted literal %u\n", 123456u);
  Log::info("Info const char literal\n");
  Log::info("Info span\n"_span);
  Log::info("Info formatted literal %u\n", 65432u);
  Log::debug("Debug\n");
  Log::debug("Debug formatted literal %u\n", 4321u);
  Log::trace("Trace\n");
  Log::log<deri::log::Level::CRITICAL>("Log::log CRITICAL\n");
  Log::info << "Streaming operator INFO\n";
  Log::debug << "Streaming operator DEBUG\n";
  Log::info << "Streaming formatting" << 123456 << '\n';
  Log::debug << "Streaming disabled formatting" << 123456 << '\n';
}

int main() {
  Log::print("Hello world from Logger\n");
  logTest();

  while (true) {
    asm volatile("" ::: "memory");
  }
  return 0;
}
