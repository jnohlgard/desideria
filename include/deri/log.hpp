/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

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

template <typename Domain>
concept HasLevel = requires(Domain config) {
  { Domain::level } -> std::convertible_to<Level>;
};

class LogToStdout {
 public:
  template <typename Format, typename... Args>
  requires(sizeof...(Args) > 0 && std::is_convertible_v<Format, const char *>)
      // attribute(format) only works with C-style ellipsis variadic functions
      // (va_list)
      /*[[gnu::format(__printf__, 1, 2)]]*/ static inline void printf(
          Format &&format, Args... args) {
#pragma GCC diagnostic push
    // We can't use -Wformat-nonliteral right now because of the missing
    // attribute above
#pragma GCC diagnostic ignored "-Wformat-nonliteral"
    ::printf(format, args...);
#pragma GCC diagnostic pop
  }

  static inline void write(std::span<const char> message) {
    ::write(STDOUT_FILENO, message.data(), message.size());
  }
};

template <typename Domain, class OutputClass>
class Logger {
 public:
  using Output = OutputClass;

  // printf-style logging methods
  template <typename Format, typename... Args>
  requires(sizeof...(Args) > 0)
      /*[[gnu::format(__printf__, 1, 2)]]*/ static inline void printf(
          Format &&format, Args... args) {
    Output::printf(std::forward<Format>(format), args...);
  }

  template <Level message_level, typename Format, typename... Args>
  requires(sizeof...(Args) > 0)
      /*[[gnu::format(__printf__, 1, 2)]]*/ static inline void log(
          Format &&format, Args... args) {
    if (level<Domain>() < message_level) {
      return;
    }
    printf(std::forward<Format>(format), args...);
  }

  template <typename Format, typename... Args>
  requires(sizeof...(Args) > 0) static inline void critical(Format &&format,
                                                            Args... args) {
    log<Level::CRITICAL>(std::forward<Format>(format), args...);
  }
  template <typename Format, typename... Args>
  requires(sizeof...(Args) > 0) static inline void error(Format &&format,
                                                         Args... args) {
    log<Level::ERROR>(std::forward<Format>(format), args...);
  }
  template <typename Format, typename... Args>
  requires(sizeof...(Args) > 0) static inline void warning(Format &&format,
                                                           Args... args) {
    log<Level::WARNING>(std::forward<Format>(format), args...);
  }
  template <typename Format, typename... Args>
  requires(sizeof...(Args) > 0) static inline void info(Format &&format,
                                                        Args... args) {
    log<Level::INFO>(std::forward<Format>(format), args...);
  }
  template <typename Format, typename... Args>
  requires(sizeof...(Args) > 0) static inline void debug(Format &&format,
                                                         Args... args) {
    log<Level::DEBUG>(std::forward<Format>(format), args...);
  }
  template <typename Format, typename... Args>
  requires(sizeof...(Args) > 0) static inline void trace(Format &&format,
                                                         Args... args) {
    log<Level::TRACE>(std::forward<Format>(format), args...);
  }

  // Verbatim copy of the message string when there are no format arguments
  template <typename Message>
  requires std::is_convertible_v<Message, std::span<const char>>
  static inline void printf(Message &&message) { Output::write(message); }

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
  template <typename NotConfig>
  static constexpr Level level() {
    return default_level;
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

 private:
  static constexpr Level default_level = Level::CRITICAL;
};

template <typename Domain>
class ConsoleLogger : public Logger<Domain, LogToStdout> {};

}  // namespace deri::log
