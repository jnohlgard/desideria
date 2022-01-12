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
  requires(!std::is_integral_v<std::remove_cvref_t<Value>>) LoggerStream &
  operator<<(Value &&value) {
    Logger::template log<level>(value);
    return *this;
  }

  template <std::integral Integer>
  LoggerStream &operator<<(Integer number) {
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
  LoggerStream &operator<<(char data) {
    Logger::template log<level>(std::span(&data, sizeof(data)));
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
  [[gnu::format(__printf__, 1, 0)]] static inline auto printf(
      const char *format, std::va_list args) {
    Output::printf(format, args);
  }

  template <Level message_level>
  [[gnu::format(__printf__, 1, 0)]] static inline Stream<message_level> log(
      const char *format, std::va_list args) {
    if (level<Domain>() < message_level) {
      return {};
    }
    printf(format, args);
    return {};
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
      -> std::enable_if_t<std::is_same_v<ConstCharPtr, const char *>,
                          Stream<message_level>> {
    if (level<Domain>() < message_level) {
      return {};
    }
    std::va_list args;
    va_start(args, format);
    printf(format, args);
    va_end(args);
    return {};
  }

  template <typename ConstCharPtr>
  [[gnu::format(__printf__, 1, 2)]] static inline auto critical(
      ConstCharPtr format, ...)
      -> std::enable_if_t<std::is_same_v<ConstCharPtr, const char *>,
                          Stream<Level::CRITICAL>> {
    std::va_list args;
    va_start(args, format);
    auto stream = log<Level::CRITICAL>(format, args);
    va_end(args);
    return stream;
  }

  template <typename ConstCharPtr>
  [[gnu::format(__printf__, 1, 2)]] static inline auto error(
      ConstCharPtr format, ...)
      -> std::enable_if_t<std::is_same_v<ConstCharPtr, const char *>,
                          Stream<Level::ERROR>> {
    std::va_list args;
    va_start(args, format);
    auto stream = log<Level::ERROR>(format, args);
    va_end(args);
    return stream;
  }

  template <typename ConstCharPtr>
  [[gnu::format(__printf__, 1, 2)]] static inline auto warning(
      ConstCharPtr format, ...)
      -> std::enable_if_t<std::is_same_v<ConstCharPtr, const char *>,
                          Stream<Level::WARNING>> {
    std::va_list args;
    va_start(args, format);
    auto stream = log<Level::WARNING>(format, args);
    va_end(args);
    return stream;
  }

  template <typename ConstCharPtr>
  [[gnu::format(__printf__, 1, 2)]] static inline auto info(ConstCharPtr format,
                                                            ...)
      -> std::enable_if_t<std::is_same_v<ConstCharPtr, const char *>,
                          Stream<Level::INFO>> {
    std::va_list args;
    va_start(args, format);
    auto stream = log<Level::INFO>(format, args);
    va_end(args);
    return stream;
  }

  template <typename ConstCharPtr>
  [[gnu::format(__printf__, 1, 2)]] static inline auto debug(
      ConstCharPtr format, ...)
      -> std::enable_if_t<std::is_same_v<ConstCharPtr, const char *>,
                          Stream<Level::DEBUG>> {
    std::va_list args;
    va_start(args, format);
    auto stream = log<Level::DEBUG>(format, args);
    va_end(args);
    return stream;
  }

  template <typename ConstCharPtr>
  [[gnu::format(__printf__, 1, 2)]] static inline auto trace(
      ConstCharPtr format, ...)
      -> std::enable_if_t<std::is_same_v<ConstCharPtr, const char *>,
                          Stream<Level::TRACE>> {
    std::va_list args;
    va_start(args, format);
    auto stream = log<Level::TRACE>(format, args);
    va_end(args);
    return stream;
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
  static inline Stream<message_level> log(char const (&message)[length]) {
    if (level<Domain>() < message_level) {
      return {};
    }
    printf(message);
    return {};
  }

  template <size_t length>
  static inline auto critical(char const (&message)[length]) {
    return log<Level::CRITICAL>(message);
  }

  template <size_t length>
  static inline auto error(char const (&message)[length]) {
    return log<Level::ERROR>(message);
  }

  template <size_t length>
  static inline auto warning(char const (&message)[length]) {
    return log<Level::WARNING>(message);
  }

  template <size_t length>
  static inline auto info(char const (&message)[length]) {
    return log<Level::INFO>(message);
  }

  template <size_t length>
  static inline auto debug(char const (&message)[length]) {
    return log<Level::DEBUG>(message);
  }

  template <size_t length>
  static inline auto trace(char const (&message)[length]) {
    return log<Level::TRACE>(message);
  }

  template <Level message_level, typename Message>
  requires std::is_convertible_v<Message, std::span<const char>>
  static inline Stream<message_level> log(Message &&message) {
    if (level<Domain>() < message_level) {
      return {};
    }
    printf(std::forward<Message>(message));
    return {};
  }
  template <typename Message>
  requires std::is_convertible_v<Message, std::span<const char>>
  static inline auto critical(Message &&message) {
    return log<Level::CRITICAL>(std::forward<Message>(message));
  }
  template <typename Message>
  requires std::is_convertible_v<Message, std::span<const char>>
  static inline auto error(Message &&message) {
    return log<Level::ERROR>(std::forward<Message>(message));
  }
  template <typename Message>
  requires std::is_convertible_v<Message, std::span<const char>>
  static inline auto warning(Message &&message) {
    return log<Level::WARNING>(std::forward<Message>(message));
  }
  template <typename Message>
  requires std::is_convertible_v<Message, std::span<const char>>
  static inline auto info(Message &&message) {
    return log<Level::INFO>(std::forward<Message>(message));
  }
  template <typename Message>
  requires std::is_convertible_v<Message, std::span<const char>>
  static inline auto debug(Message &&message) {
    return log<Level::DEBUG>(std::forward<Message>(message));
  }
  template <typename Message>
  requires std::is_convertible_v<Message, std::span<const char>>
  static inline auto trace(Message &&message) {
    return log<Level::TRACE>(std::forward<Message>(message));
  }

  template <Level message_level>
  static inline Stream<message_level> log() {
    return {};
  }
  static inline auto critical() { return log<Level::CRITICAL>(); }
  static inline auto error() { return log<Level::ERROR>(); }
  static inline auto info() { return log<Level::INFO>(); }
  static inline auto debug() { return log<Level::DEBUG>(); }
  static inline auto trace() { return log<Level::TRACE>(); }

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
