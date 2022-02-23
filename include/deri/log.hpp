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

namespace output {

class Stdout {
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
}  // namespace output

/// Default logger config when nothing is defined
struct DefaultConfig {
  using Output = output::Stdout;
  static constexpr auto level{Level::CRITICAL};
};

/// Convenience base class to set the log level with less typing.
template <Level log_level>
struct Config {
  static constexpr auto level{log_level};
};

template <class>
static inline constexpr Level level{DefaultConfig::level};
// specialization recognizes types that do have a nested ::level member:
template <class Domain>
requires(requires {
  { Domain::level } -> std::convertible_to<Level>;
}) inline constexpr Level level<Domain>{Domain::level};

template <class, class = void>
struct HasOutput : std::false_type {};
// specialization recognizes types that do have a nested ::Output member:
template <class Domain>
struct HasOutput<Domain, std::void_t<typename Domain::Output>>
    : std::true_type {};

template <class Output>
class Stream {
 public:
  template <typename Message>
  requires(std::is_convertible_v<Message, std::span<const char>>) inline void
  operator()(Message &&message) {
    Output::write(message);
  }

  template <size_t length>
  inline void operator()(char const (&message)[length]) {
    Output::write(message);
  }

  template <typename ConstCharPtr>
  [[gnu::format(__printf__, 2, 3)]] inline auto operator()(ConstCharPtr format,
                                                           ...)
      -> std::enable_if_t<std::is_same_v<ConstCharPtr, const char *>, void> {
    std::va_list args;
    va_start(args, format);
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat-nonliteral"
    Output::printf(format, args);
#pragma GCC diagnostic pop
    va_end(args);
  }

  inline Stream &operator()(char fill, size_t count) {
    std::array<char, 8> buf{fill};
    while (count > buf.size()) {
      Output::write(buf);
      count -= buf.size();
    }
    Output::write(std::span<const char>{buf.data(), count});
    return *this;
  }
};

/// Disabled log levels use this stream
// The compiler will eliminate all calls to these methods during the
// optimization step, even at -Og level.
template <>
class Stream<void> {
 public:
  template <typename Message>
  requires(std::is_convertible_v<Message, std::span<const char>>) inline void
  operator()(Message &&message) {}

  template <size_t length>
  inline void operator()(char const (&message)[length]) {}

  template <typename ConstCharPtr>
  [[gnu::format(__printf__, 2, 3)]] inline auto operator()(ConstCharPtr format,
                                                           ...)
      -> std::enable_if_t<std::is_same_v<ConstCharPtr, const char *>, void> {}

  inline Stream &operator()(char fill, size_t count) {
    return *this;
  }
};

template <Level message_level, class Domain>
static inline constexpr bool is_level_enabled_in_domain{message_level <=
                                                        level<Domain>};

template <class Domain,
          class Output = typename std::conditional_t<HasOutput<Domain>::value,
                                                     Domain,
                                                     DefaultConfig>::Output>
class Logger {
  template <Level message_level>
  using EnabledStream =
      std::conditional_t<is_level_enabled_in_domain<message_level, Domain>,
                         Stream<Output>,
                         Stream<void>>;
  template <Level message_level>
  static constexpr inline auto is_enabled =
      is_level_enabled_in_domain<message_level, Domain>;

 public:
  static inline EnabledStream<Level::CRITICAL> critical{};
  static inline EnabledStream<Level::ERROR> error{};
  static inline EnabledStream<Level::WARNING> warning{};
  static inline EnabledStream<Level::INFO> info{};
  static inline EnabledStream<Level::DEBUG> debug{};
  static inline EnabledStream<Level::TRACE> trace{};
  template <Level message_level>
  static inline EnabledStream<message_level> log{};

  // unconditional printing regardless of configured log level
  static inline Stream<Output> print{};

  Logger() = delete;
  Logger(const Logger &) = delete;
  void operator=(const Logger &) = delete;
  ~Logger() = delete;
};

template <typename Domain>
using ConsoleLogger = Logger<Domain, output::Stdout>;

template <typename Value, class Stream>
requires(std::is_convertible_v<Value, std::span<const char>>) inline Stream &
operator<<(Stream &os, Value &&value) {
  os(value);
  return os;
}

template <std::integral Integer, class Output>
inline constexpr auto &operator<<(Stream<Output> &os, Integer number) {
  if constexpr (!std::is_same_v<Output, void>) {
    // we need a buffer that has room for this many chars:
    // ceil(log10(2) * Integer_bits) + 1 (sign)
    // 3 * Integer_bits / 8 is an approximation that works for 16, 32, 64 bit
    // integers, the max() is just to cover for 8 bit numbers
    std::array<char, std::max(sizeof(Integer) * 3, 4u)> buf{};
    if (auto [end_ptr, error] = std::to_chars(begin(buf), end(buf), number, 10);
        error == std::errc()) {
      os(std::span{begin(buf), end_ptr});
    }
  }
  return os;
}

// Add to_char(float) when there is a use case for it.

template <class Output>
inline Stream<Output> &operator<<(Stream<Output> &os, const void *ptr) {
  if (!ptr) {
    os("(null)");
  } else {
    std::array<char, std::max(sizeof(ptr) * 2, 4u)> buf{};
    if (auto [end_ptr, error] = std::to_chars(
            begin(buf), end(buf), reinterpret_cast<uintptr_t>(ptr), 16);
        error == std::errc{}) {
      os("0x");
      os(std::span{begin(buf), end_ptr});
    }
  }
  return os;
}

template <typename Target, class Output>
requires(!std::is_same_v<const Target, const char>) inline Stream<Output>
    &operator<<(Stream<Output> &os, const Target *ptr) {
  return os << static_cast<const void *>(ptr);
}

template <class Output>
inline Stream<Output> &operator<<(Stream<Output> &os, bool value) {
  if (value) {
    os("true");
  } else {
    os("false");
  }
  return os;
}

// Specialization to output characters as-is
template <class Output>
inline Stream<Output> &operator<<(Stream<Output> &os, char data) {
  os(std::span(&data, 1));
  return os;
}
}  // namespace deri::log

namespace deri::logold {
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
    if (Logger::logEnabled(level)) {
      std::va_list args;
      va_start(args, format);
      Logger::template log<level>(format, args);
      va_end(args);
    }
    return *this;
  }

  template <size_t length>
  inline auto &operator()(char const (&message)[length]) {
    if (Logger::logEnabled(level)) {
      Logger::template log<level>(message);
    }
    return *this;
  }

  inline auto &operator()(char fill, size_t count) {
    for (auto k = 0; k < count; ++k) {
      *this << fill;
    }
    return *this;
  }
};

template <typename Value, class Logger, Level level>
requires(std::is_convertible_v<
         Value,
         std::span<const char>>) inline LoggerStream<Logger, level>
    &operator<<(LoggerStream<Logger, level> &os, Value &&value) {
  if (Logger::logEnabled(level)) {
    Logger::template log<level>(value);
  }
  return os;
}

template <std::integral Integer, class Logger, Level level>
inline LoggerStream<Logger, level> &operator<<(LoggerStream<Logger, level> &os,
                                               Integer number) {
  if (Logger::logEnabled(level)) {
    // we need a buffer that has room for this many chars:
    // ceil(log10(2) * Integer_bits) + 1 (sign)
    // 3 * Integer_bits / 8 is an approximation that works for 16, 32, 64 bit
    // integers, the max() is just to cover for 8 bit numbers
    std::array<char, std::max(sizeof(Integer) * 3, 4u)> buf{};
    if (auto [end_ptr, error] = std::to_chars(begin(buf), end(buf), number, 10);
        error == std::errc()) {
      Logger::template log<level>(std::span{begin(buf), end_ptr});
    }
  }

  return os;
}

template <class Logger, Level level>
inline LoggerStream<Logger, level> &operator<<(LoggerStream<Logger, level> &os,
                                               const void *ptr) {
  if (Logger::logEnabled(level)) {
    if (!ptr) {
      Logger::template log<level>("(null)");
    } else {
      std::array<char, std::max(sizeof(ptr) * 2, 4u)> buf{};
      if (auto [end_ptr, error] = std::to_chars(
              begin(buf), end(buf), reinterpret_cast<uintptr_t>(ptr), 16);
          error == std::errc{}) {
        Logger::template log<level>("0x");
        Logger::template log<level>(std::span{begin(buf), end_ptr});
      }
    }
  }
  return os;
}

template <typename Target, class Logger, Level level>
requires(!std::is_same_v<const Target, const char>) inline LoggerStream<Logger,
                                                                        level>
    &operator<<(LoggerStream<Logger, level> &os, const Target *ptr) {
  return os << static_cast<const void *>(ptr);
}

template <class Logger, Level level>
inline LoggerStream<Logger, level> &operator<<(LoggerStream<Logger, level> &os,
                                               bool value) {
  if (Logger::logEnabled(level)) {
    if (value) {
      Logger::template log<level>("true");
    } else {
      Logger::template log<level>("false");
    }
  }
  return os;
}

// Specialization to output characters as-is
template <class Logger, Level level>
inline LoggerStream<Logger, level> &operator<<(LoggerStream<Logger, level> &os,
                                               char data) {
  if (Logger::logEnabled(level)) {
    Logger::template log<level>(std::span(&data, sizeof(data)));
  }
  return os;
}

template <typename DomainConfig, class OutputClass>
class LoggerImpl {
 public:
  using Domain = DomainConfig;
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
    if (!logEnabled(message_level)) {
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
    if (!logEnabled(message_level)) {
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
    if (!logEnabled(message_level)) {
      return;
    }
    printf(message);
  }

  template <Level message_level, typename Message>
  requires std::is_convertible_v<Message, std::span<const char>>
  static inline void log(Message &&message) {
    if (!logEnabled(message_level)) {
      return;
    }
    printf(std::forward<Message>(message));
  }

  template <Level message_level>
  static inline Stream<message_level> stream{};
  static inline LoggerStream<LoggerImpl, Level::CRITICAL> critical{};
  static inline LoggerStream<LoggerImpl, Level::ERROR> error{};
  static inline LoggerStream<LoggerImpl, Level::WARNING> warning{};
  static inline LoggerStream<LoggerImpl, Level::INFO> info{};
  static inline LoggerStream<LoggerImpl, Level::DEBUG> debug{};
  static inline LoggerStream<LoggerImpl, Level::TRACE> trace{};

  // Use the default log level if there is no definition of the given domain
  // config
  template <typename ConfigMissingLevel>
  static constexpr auto level() {
    return DefaultConfig::level;
  }
  template <HasLevel Config>
  static constexpr auto level() {
    return Config::level;
  }

  static constexpr auto logLevel() { return level<Domain>(); }

  static constexpr bool logEnabled(Level level) { return level <= logLevel(); }

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

}  // namespace deri::logold
