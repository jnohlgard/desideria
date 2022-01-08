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

template <class Return, typename... Args>
class Function<Return(Args...)> {
  using Call = Return(const void *, Args...);
  using FunctionType = Return(Args...);
  static constexpr auto max_size = 1 * sizeof(void *);
  static constexpr auto *default_call = panic;

  template <class Callable>
  class Invoker {
   public:
    static Return call(const void *ptr, Args... args) {
      auto *callable = std::launder(reinterpret_cast<const Callable *>(ptr));
      return callable->operator()(args...);
    }
  };
  class UnwrapCall {
   public:
    static Return call(const void *ptr, Args... args) {
      auto *func = reinterpret_cast<const FunctionType *>(ptr);
      return func(args...);
    }
  };

 public:
  Function() = default;
  Function(const Function &) = default;
  Function &operator=(const Function &) = default;
  ~Function() = default;

  Function(FunctionType *func) : call{UnwrapCall::call} {}

  template <class Callable>
  requires(sizeof(Callable) <= max_size &&
           std::is_copy_constructible_v<Callable> &&
           std::is_trivially_destructible_v<Callable>)
      Function(Callable &&callable)
      : call{Invoker<Callable>::call} {
    new (&inline_storage) Callable(std::forward<Callable>(callable));
  }

  explicit operator bool() const {
    return call != reinterpret_cast<const Call *>(default_call);
  }

  Return operator()(Args... args) const { call(&inline_storage, args...); }

  Call *call{reinterpret_cast<const Call *>(default_call)};
  std::aligned_storage_t<max_size, alignof(void *)> inline_storage{};
};
}  // namespace deri
