/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include <cstddef>
#include <cstdint>
#include <span>

extern "C" {
extern char __global_pointer$[];
}

namespace deri::arch {

constexpr size_t idle_stack_size = 512;

struct SavedContext {
  // These types make debugging easier.
  using IntRegister = uintptr_t;
  using AddressRegister = const void *;
  using FunctionAddressRegister = void (*)();

  template <typename Function>
  void setProgramCounter(Function function) {
    pc = reinterpret_cast<FunctionAddressRegister>(function);
  }

  void setStackPointer(std::span<std::byte> stack) {
    sp = stack.data() + stack.size();
  }

  FunctionAddressRegister pc{};
  FunctionAddressRegister ra{};
  AddressRegister sp{};
  AddressRegister gp{__global_pointer$};
  AddressRegister tp{};
  IntRegister t0{};
  IntRegister t1{};
  IntRegister t2{};
  IntRegister s0{};
  IntRegister s1{};
  IntRegister a0{};
  IntRegister a1{};
  IntRegister a2{};
  IntRegister a3{};
  IntRegister a4{};
  IntRegister a5{};
  IntRegister a6{};
  IntRegister a7{};
  IntRegister s2{};
  IntRegister s3{};
  IntRegister s4{};
  IntRegister s5{};
  IntRegister s6{};
  IntRegister s7{};
  IntRegister s8{};
  IntRegister s9{};
  IntRegister s10{};
  IntRegister s11{};
  IntRegister t3{};
  IntRegister t4{};
  IntRegister t5{};
  IntRegister t6{};
};
}  // namespace deri::arch
