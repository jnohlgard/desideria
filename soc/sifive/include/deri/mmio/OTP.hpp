/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/registers.hpp"

#include <cstdint>

namespace deri::mmio {
struct OTP_regs {
  enum class lock_bits : uint32_t;
  enum class clock_bits : uint32_t;
  enum class output_en_bits : uint32_t;
  enum class select_bits : uint32_t;
  enum class write_en_bits : uint32_t;
  enum class mode_bits : uint32_t;
  enum class mrr_bits : uint32_t;
  enum class mpp_bits : uint32_t;
  enum class vrren_bits : uint32_t;
  enum class vppen_bits : uint32_t;
  enum class addr_bits : uint32_t;
  enum class data_in_bits : uint32_t;
  enum class data_out_bits : uint32_t;
  enum class rsctrl_bits : uint32_t;
  enum class lock_shift : unsigned;
  enum class clock_shift : unsigned;
  enum class output_en_shift : unsigned;
  enum class select_shift : unsigned;
  enum class write_en_shift : unsigned;
  enum class mode_shift : unsigned;
  enum class mrr_shift : unsigned;
  enum class mpp_shift : unsigned;
  enum class vrren_shift : unsigned;
  enum class vppen_shift : unsigned;
  enum class addr_shift : unsigned;
  enum class data_in_shift : unsigned;
  enum class data_out_shift : unsigned;
  enum class rsctrl_shift : unsigned;

  Register<lock_bits> lock;
  Register<clock_bits> clock;
  Register<output_en_bits> output_en;
  Register<select_bits> select;
  Register<write_en_bits> write_en;
  Register<mode_bits> mode;
  Register<mrr_bits> mrr;
  Register<mpp_bits> mpp;
  Register<vrren_bits> vrren;
  Register<vppen_bits> vppen;
  Register<addr_bits> addr;
  Register<data_in_bits> data_in;
  Register<data_out_bits> data_out;
  Register<rsctrl_bits> rsctrl;
};
}  // namespace deri::mmio
