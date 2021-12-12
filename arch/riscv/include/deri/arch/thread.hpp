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
  void setProgramCounter(Function &&function) {
    pc = reinterpret_cast<FunctionAddressRegister>(function);
  }

  void setStackPointer(std::span<std::byte> stack) {
    sp = stack.data() + stack.size();
  }

  void setArg0(auto *arg_0) { a0 = reinterpret_cast<IntRegister>(arg_0); }

  FunctionAddressRegister pc{};
  FunctionAddressRegister ra{};
  AddressRegister sp{};
  AddressRegister gp{__global_pointer$};
  AddressRegister tp{this};
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

  /**
   * Names of the registers, in the order the fields appear in @c SavedContext
   */
  static inline const std::array register_names = {
      "pc", "ra", "sp", "gp", "tp",  "t0",  "t1", "t2", "s0", "s1", "a0",
      "a1", "a2", "a3", "a4", "a5",  "a6",  "a7", "s2", "s3", "s4", "s5",
      "s6", "s7", "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6",
  };
};

/**
 * Save the current state of all registers
 *
 * Registers ra, a0 and pc need to be saved manually
 */
void saveContext(SavedContext &context);

/**
 * Dump a saved context struct in human readable form to standard out
 *
 * @param context the saved context to print
 */
void dumpContext(const SavedContext &context);
}  // namespace deri::arch
