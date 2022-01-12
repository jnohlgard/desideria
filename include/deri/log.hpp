/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include <charconv>
#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <span>
#include <type_traits>

#include <unistd.h>

#if __has_include("logging_conf.hpp")
#include "logging_conf.hpp"
#endif

namespace deri::log {
enum class Level : int {
  OFF = -1,
  CRITICAL = 0,
  ERROR,
  WARNING,
  INFO,
  DEBUG,
  TRACE,
};

class LogToStdout;
template <typename Domain, class OutputClass>
class LoggerImpl;

/// Default logger config when nothing is defined
struct DefaultConfig {
  using Output = LogToStdout;
  static constexpr Level level = Level::CRITICAL;
};

/// Convenience base class to set the log level with less typing.
template <Level log_level>
struct LogConfig {
  static constexpr Level level{log_level};
};

template <typename Domain>
concept HasLevel = requires(Domain config) {
  { Domain::level } -> std::convertible_to<Level>;
};

template <class, class = void>
struct HasOutput : std::false_type {};
// specialization recognizes types that do have a nested ::Output member:
template <class Domain>
struct HasOutput<Domain, std::void_t<typename Domain::Output>>
    : std::true_type {};

template <class Domain,
          class Output = typename std::conditional_t<HasOutput<Domain>::value,
                                                     Domain,
                                                     DefaultConfig>::Output>
class Logger : public LoggerImpl<Domain, Output> {};

template <typename Domain>
class ConsoleLogger : public LoggerImpl<Domain, LogToStdout> {};

class LogToStdout {
 public:
  [[gnu::format(__printf__, 1, 0)]] static inline void printf(
      const char *format, std::va_list args) {
    ::vprintf(format, args);
  }
  [[gnu::format(__printf__, 1, 2)]] static inline void printf(
      const char *format, ...) {
    std::va_list args;
    va_start(args, format);
    printf(format, args);
    va_end(args);
  }

  static inline void write(std::span<const char> message) {
    ::write(STDOUT_FILENO, message.data(), message.size());
  }
};

template <class Logger, Level level>
class LoggerStream {
 public:
  template <typename Value>
  requires(
      !std::is_integral_v<std::remove_cvref_t<Value>>) inline LoggerStream &
  operator<<(Value &&value) {
    Logger::template log<level>(value);
    return *this;
  }

  template <std::integral Integer>
  inline LoggerStream &operator<<(Integer number) {
    // we need a buffer that has room for this many chars:
    // ceil(log10(2) * Integer_bits) + 1 (sign)
    // 3 * Integer_bits / 8 is an approximation that works for 16, 32, 64 bit
    // integers, the max() is just to cover for 8 bit numbers
    std::array<char, std::max(sizeof(Integer) * 3, 4u)> buf{};
    if (auto [end_ptr, error] = std::to_chars(begin(buf), end(buf), number, 10);
        error == std::errc()) {
      Logger::template log<level>(std::span(begin(buf), end_ptr));
    }
    return *this;
  }

  // Specialization to output characters as-is
  inline LoggerStream &operator<<(char data) {
    Logger::template log<level>(std::span(&data, sizeof(data)));
    return *this;
  }

  template <typename Message>
  requires(std::is_convertible_v<Message,
                                 std::span<const char>>) inline LoggerStream &
  operator()(Message &&message) {
    Logger::template log<level>(message);
    return *this;
  }

  template <typename ConstCharPtr>
  [[gnu::format(__printf__, 2, 3)]] inline std::
      enable_if_t<std::is_same_v<ConstCharPtr, const char *>, LoggerStream &>
      operator()(ConstCharPtr format, ...) {
    std::va_list args;
    va_start(args, format);
    Logger::template log<level>(format, args);
    va_end(args);
    return *this;
  }

  template <size_t length>
  inline auto &operator()(char const (&message)[length]) {
    Logger::template log<level>(message);
    return *this;
  }

  inline auto &operator()(char fill, size_t count) {
    for (auto k = 0; k < count; ++k) {
      *this << fill;
    }
    return *this;
  }
};

template <typename Domain, class OutputClass>
class LoggerImpl {
 public:
  using Output = OutputClass;
  template <Level level>
  using Stream = LoggerStream<LoggerImpl<Domain, OutputClass>, level>;

  // printf-style logging methods
  [[gnu::format(__printf__, 1, 0)]] static inline void printf(
      const char *format, std::va_list args) {
    Output::printf(format, args);
  }

  template <Level message_level>
  [[gnu::format(__printf__, 1, 0)]] static inline void log(const char *format,
                                                           std::va_list args) {
    if (level<Domain>() < message_level) {
      return;
    }
    printf(format, args);
    return;
  }

  // These need to be templates in order to resolve the ambiguity between these
  // and the verbatim write methods further down. We pretend const char * is a
  // template argument but restricting it with std::is_same
  template <typename ConstCharPtr>
  [[gnu::format(__printf__, 1, 2)]] static inline auto printf(
      ConstCharPtr format, ...)
      -> std::enable_if_t<std::is_same_v<ConstCharPtr, const char *>> {
    std::va_list args;
    va_start(args, format);
    printf(format, args);
    va_end(args);
  }

  template <Level message_level, typename ConstCharPtr>
  [[gnu::format(__printf__, 1, 2)]] static inline auto log(ConstCharPtr format,
                                                           ...)
      -> std::enable_if_t<std::is_same_v<ConstCharPtr, const char *>> {
    if (level<Domain>() < message_level) {
      return;
    }
    std::va_list args;
    va_start(args, format);
    printf(format, args);
    va_end(args);
    return;
  }

  // Verbatim copy of the message string when there are no format arguments
  template <typename Message>
  requires std::is_convertible_v<Message, std::span<const char>>
  static inline void printf(Message &&message) { Output::write(message); }

  template <size_t length>
  static inline void printf(char const (&message)[length]) {
    // Trim terminating null byte
    Output::write(std::span<const char, length - 1>(message, length - 1));
  }

  template <Level message_level, size_t length>
  static inline void log(char const (&message)[length]) {
    if (level<Domain>() < message_level) {
      return;
    }
    printf(message);
    return;
  }

  template <Level message_level, typename Message>
  requires std::is_convertible_v<Message, std::span<const char>>
  static inline void log(Message &&message) {
    if (level<Domain>() < message_level) {
      return;
    }
    printf(std::forward<Message>(message));
    return;
  }

  template <Level message_level>
  static inline Stream<message_level> stream() {
    return {};
  }
  static inline LoggerStream<LoggerImpl, Level::CRITICAL> critical{};
  static inline LoggerStream<LoggerImpl, Level::ERROR> error{};
  static inline LoggerStream<LoggerImpl, Level::WARNING> warning{};
  static inline LoggerStream<LoggerImpl, Level::INFO> info{};
  static inline LoggerStream<LoggerImpl, Level::DEBUG> debug{};
  static inline LoggerStream<LoggerImpl, Level::TRACE> trace{};

  // Use the default log level if there is no definition of the given domain
  // config
  template <HasLevel Config>
  static constexpr Level level() {
    return Config::level;
  }
  template <typename ConfigMissingLevel>
  static constexpr Level level() {
    return DefaultConfig::level;
  }

  template <typename Label, Level level = Level::TRACE>
  class Tracer {
   public:
    explicit Tracer(auto &&label) : label(std::forward<Label>(label)) {
      log<level>(" '-> %s\n", label);
    }

    ~Tracer() { log<level>(" <-' %s\n", label); }

    Tracer() = delete;
    Tracer(const Tracer &) = delete;
    Tracer(Tracer &&) noexcept = delete;
    Tracer &operator=(const Tracer &) = delete;
    Tracer &operator=(Tracer &&) noexcept = delete;

   private:
    Label label;
  };

  template <Level level = Level::TRACE>
  [[nodiscard]] static inline auto scopeTrace(auto &&label)
      -> Tracer<decltype(label), level> {
    return Tracer<decltype(label), level>(std::forward<decltype(label)>(label));
  }
};

}  // namespace deri::log
