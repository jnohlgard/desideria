/*
 * Copyright (c) 2022 Joakim Nohlgård
 */

#pragma once

#include "deri/panic.hpp"

#include <concepts>
#include <cstddef>
#include <memory>
#include <new>
#include <type_traits>
#include <utility>

namespace deri {
template <class FunctionSignature>
class Function;

// Deduction guide
template <class Return, class... Args>
Function(Return (*)(Args...)) -> Function<Return(Args...)>;

template <class Return, typename... Args>
class Function<Return(Args...)> {
  using CallWrapped = Return(const void *, Args...);
  using WrappedFunction = Return(Args...);
  static constexpr auto max_size = 1 * sizeof(void *);
  // We use the panic handler as a catchall for calling unset targets. The
  // function signature does not match, but it will still print out all the
  // arguments as part of the context dump
  static constexpr auto *default_call = panic;

  template <class Callable>
  requires(!std::is_same_v<Callable, Function>) class Invoker {
   public:
    static Return call(const void *ptr,
                       Args... args) requires(requires(Callable obj,
                                                       Args... args) {
      { obj(args...) } -> std::convertible_to<Return>;
    }) {
      auto *callable = std::launder(reinterpret_cast<const Callable *>(ptr));
      return (*callable)(args...);
    }
  };
  class UnwrapCall {
   public:
    static Return call(const void *ptr, Args... args) {
      auto *func = reinterpret_cast<WrappedFunction *const *>(ptr);
      return (*func)(args...);
    }
  };

 public:
  Function() = default;
  Function(const Function &) = default;
  Function &operator=(const Function &) = default;
  Function(Function &&) noexcept = default;
  Function &operator=(Function &&) noexcept = default;
  ~Function() = default;

  Function(WrappedFunction *func) : call{UnwrapCall::call} {
    new (&inline_storage) WrappedFunction *{func};
  }

  template <class Callable>
  requires(sizeof(Callable) <= max_size &&
           std::is_copy_constructible_v<Callable> &&
           std::is_trivially_destructible_v<Callable>)
      Function(Callable &&callable)
      : call{Invoker<Callable>::call} {
    new (&inline_storage) Callable(std::forward<Callable>(callable));
  }

  explicit operator bool() const {
    return call != reinterpret_cast<const CallWrapped *>(default_call);
  }

  Return operator()(Args... args) const { call(&inline_storage, args...); }

  CallWrapped *call{reinterpret_cast<const CallWrapped *>(default_call)};
  std::aligned_storage_t<max_size, alignof(void *)> inline_storage{};
};
}  // namespace deri
