/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

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

template <typename Domain, class OutputClass>
class LoggerImpl {
 public:
  using Output = OutputClass;

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
  }

  template <typename ConstCharPtr>
  [[gnu::format(__printf__, 1, 2)]] static inline auto critical(
      ConstCharPtr format, ...)
      -> std::enable_if_t<std::is_same_v<ConstCharPtr, const char *>> {
    std::va_list args;
    va_start(args, format);
    log<Level::CRITICAL>(format, args);
    va_end(args);
  }

  template <typename ConstCharPtr>
  [[gnu::format(__printf__, 1, 2)]] static inline auto error(
      ConstCharPtr format, ...)
      -> std::enable_if_t<std::is_same_v<ConstCharPtr, const char *>> {
    std::va_list args;
    va_start(args, format);
    log<Level::ERROR>(format, args);
    va_end(args);
  }

  template <typename ConstCharPtr>
  [[gnu::format(__printf__, 1, 2)]] static inline auto warning(
      ConstCharPtr format, ...)
      -> std::enable_if_t<std::is_same_v<ConstCharPtr, const char *>> {
    std::va_list args;
    va_start(args, format);
    log<Level::WARNING>(format, args);
    va_end(args);
  }

  template <typename ConstCharPtr>
  [[gnu::format(__printf__, 1, 2)]] static inline auto info(ConstCharPtr format,
                                                            ...)
      -> std::enable_if_t<std::is_same_v<ConstCharPtr, const char *>> {
    std::va_list args;
    va_start(args, format);
    log<Level::INFO>(format, args);
    va_end(args);
  }

  template <typename ConstCharPtr>
  [[gnu::format(__printf__, 1, 2)]] static inline auto debug(
      ConstCharPtr format, ...)
      -> std::enable_if_t<std::is_same_v<ConstCharPtr, const char *>> {
    std::va_list args;
    va_start(args, format);
    log<Level::DEBUG>(format, args);
    va_end(args);
  }

  template <typename ConstCharPtr>
  [[gnu::format(__printf__, 1, 2)]] static inline auto trace(
      ConstCharPtr format, ...)
      -> std::enable_if_t<std::is_same_v<ConstCharPtr, const char *>> {
    std::va_list args;
    va_start(args, format);
    log<Level::TRACE>(format, args);
    va_end(args);
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
  }

  template <size_t length>
  static inline void critical(char const (&message)[length]) {
    log<Level::CRITICAL>(message);
  }

  template <size_t length>
  static inline void error(char const (&message)[length]) {
    log<Level::ERROR>(message);
  }

  template <size_t length>
  static inline void warning(char const (&message)[length]) {
    log<Level::WARNING>(message);
  }

  template <size_t length>
  static inline void info(char const (&message)[length]) {
    log<Level::INFO>(message);
  }

  template <size_t length>
  static inline void debug(char const (&message)[length]) {
    log<Level::DEBUG>(message);
  }

  template <size_t length>
  static inline void trace(char const (&message)[length]) {
    log<Level::TRACE>(message);
  }

  template <Level message_level, typename Message>
  requires std::is_convertible_v<Message, std::span<const char>>
  static inline void log(Message &&message) {
    if (level<Domain>() < message_level) {
      return;
    }
    printf(std::forward<Message>(message));
  }
  template <typename Message>
  requires std::is_convertible_v<Message, std::span<const char>>
  static inline void critical(Message &&message) {
    log<Level::CRITICAL>(std::forward<Message>(message));
  }
  template <typename Message>
  requires std::is_convertible_v<Message, std::span<const char>>
  static inline void error(Message &&message) {
    log<Level::ERROR>(std::forward<Message>(message));
  }
  template <typename Message>
  requires std::is_convertible_v<Message, std::span<const char>>
  static inline void warning(Message &&message) {
    log<Level::WARNING>(std::forward<Message>(message));
  }
  template <typename Message>
  requires std::is_convertible_v<Message, std::span<const char>>
  static inline void info(Message &&message) {
    log<Level::INFO>(std::forward<Message>(message));
  }
  template <typename Message>
  requires std::is_convertible_v<Message, std::span<const char>>
  static inline void debug(Message &&message) {
    log<Level::DEBUG>(std::forward<Message>(message));
  }
  template <typename Message>
  requires std::is_convertible_v<Message, std::span<const char>>
  static inline void trace(Message &&message) {
    log<Level::TRACE>(std::forward<Message>(message));
  }

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
