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
  static constexpr auto max_size = 1 * sizeof(void *);
  using Call = Return(void *, Args...);
  using Destroy = void(void *);

  template <class Callable>
  class Invoker {
   public:
    static Return call(void *ptr, Args... args) {
      auto *callable = std::launder(reinterpret_cast<Callable *>(ptr));
      return callable->operator()(args...);
    }
  };
  class Panic {
   public:
    [[noreturn]] static Return call(void *, Args...) { panic(); }
  };

 public:
  Function() : call{Panic::call} {}
  Function(const Function &) = default;
  Function &operator=(const Function &) = default;
  template <class Callable>
  requires(sizeof(Callable) <= max_size &&
           std::is_copy_constructible_v<Callable> &&
           std::is_trivially_destructible_v<
               Callable>) explicit Function(Callable &&callable)
      : call{Invoker<Callable>::call} {
    new (&inline_storage) Callable(std::forward<Callable>(callable));
  }

  Return operator()(Args... args) { call(&inline_storage, args...); }

  Call *call;
  std::aligned_storage_t<max_size, alignof(void *)> inline_storage{};
};
}  // namespace deri
