/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/registers.hpp"

#include <atomic>
#include <cstdint>

namespace deri::mmio {
struct GPIO_regs {
  enum class input_val_bits : uint32_t;
  enum class input_en_bits : uint32_t;
  enum class output_en_bits : uint32_t;
  enum class output_val_bits : uint32_t;
  enum class pullup_bits : uint32_t;
  enum class drive_bits : uint32_t;
  enum class rise_ie_bits : uint32_t;
  enum class rise_ip_bits : uint32_t;
  enum class fall_ie_bits : uint32_t;
  enum class fall_ip_bits : uint32_t;
  enum class high_ie_bits : uint32_t;
  enum class high_ip_bits : uint32_t;
  enum class low_ie_bits : uint32_t;
  enum class low_ip_bits : uint32_t;
  enum class iof_en_bits : uint32_t;
  enum class iof_sel_bits : uint32_t;
  enum class out_xor_bits : uint32_t;
  enum class input_val_shift : unsigned;
  enum class input_en_shift : unsigned;
  enum class output_en_shift : unsigned;
  enum class output_val_shift : unsigned;
  enum class pullup_shift : unsigned;
  enum class drive_shift : unsigned;
  enum class rise_ie_shift : unsigned;
  enum class rise_ip_shift : unsigned;
  enum class fall_ie_shift : unsigned;
  enum class fall_ip_shift : unsigned;
  enum class high_ie_shift : unsigned;
  enum class high_ip_shift : unsigned;
  enum class low_ie_shift : unsigned;
  enum class low_ip_shift : unsigned;
  enum class iof_en_shift : unsigned;
  enum class iof_sel_shift : unsigned;
  enum class out_xor_shift : unsigned;

  Register<input_val_bits> input_val;
  Register<input_en_bits> input_en;
  Register<output_en_bits> output_en;
  Register<output_val_bits> output_val;
  Register<pullup_bits> pullup;
  Register<drive_bits> drive;
  Register<rise_ie_bits> rise_ie;
  Register<rise_ip_bits> rise_ip;
  Register<fall_ie_bits> fall_ie;
  Register<fall_ip_bits> fall_ip;
  Register<high_ie_bits> high_ie;
  Register<high_ip_bits> high_ip;
  Register<low_ie_bits> low_ie;
  Register<low_ip_bits> low_ip;
  Register<iof_en_bits> iof_en;
  Register<iof_sel_bits> iof_sel;
  Register<out_xor_bits> out_xor;
};
}  // namespace deri::mmio
