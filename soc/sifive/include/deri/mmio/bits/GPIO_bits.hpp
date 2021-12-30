/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/mmio/GPIO.hpp"

#include <cstdint>

namespace deri::mmio {
/**
 * Bitmasks for GPIO input_val
 *
 * Pin value.
 */
enum class GPIO_regs::input_val_bits : uint32_t {
  pin0 = (1u << 0),
  pin1 = (1u << 1),
  pin2 = (1u << 2),
  pin3 = (1u << 3),
  pin4 = (1u << 4),
  pin5 = (1u << 5),
  pin6 = (1u << 6),
  pin7 = (1u << 7),
  pin8 = (1u << 8),
  pin9 = (1u << 9),
  pin10 = (1u << 10),
  pin11 = (1u << 11),
  pin12 = (1u << 12),
  pin13 = (1u << 13),
  pin14 = (1u << 14),
  pin15 = (1u << 15),
  pin16 = (1u << 16),
  pin17 = (1u << 17),
  pin18 = (1u << 18),
  pin19 = (1u << 19),
  pin20 = (1u << 20),
  pin21 = (1u << 21),
  pin22 = (1u << 22),
  pin23 = (1u << 23),
  pin24 = (1u << 24),
  pin25 = (1u << 25),
  pin26 = (1u << 26),
  pin27 = (1u << 27),
  pin28 = (1u << 28),
  pin29 = (1u << 29),
  pin30 = (1u << 30),
  pin31 = (1u << 31),
};
void HasBitwiseOperators(GPIO_regs::input_val_bits);

/**
 * Bit shifts for GPIO input_val
 */
enum class GPIO_regs::input_val_shift : unsigned {
  pin0 = 0,
  pin1 = 1,
  pin2 = 2,
  pin3 = 3,
  pin4 = 4,
  pin5 = 5,
  pin6 = 6,
  pin7 = 7,
  pin8 = 8,
  pin9 = 9,
  pin10 = 10,
  pin11 = 11,
  pin12 = 12,
  pin13 = 13,
  pin14 = 14,
  pin15 = 15,
  pin16 = 16,
  pin17 = 17,
  pin18 = 18,
  pin19 = 19,
  pin20 = 20,
  pin21 = 21,
  pin22 = 22,
  pin23 = 23,
  pin24 = 24,
  pin25 = 25,
  pin26 = 26,
  pin27 = 27,
  pin28 = 28,
  pin29 = 29,
  pin30 = 30,
  pin31 = 31,
};

/**
 * Bitmasks for GPIO input_en
 *
 * Pin Input Enable Register
 */
enum class GPIO_regs::input_en_bits : uint32_t {
  pin0 = (1u << 0),
  pin1 = (1u << 1),
  pin2 = (1u << 2),
  pin3 = (1u << 3),
  pin4 = (1u << 4),
  pin5 = (1u << 5),
  pin6 = (1u << 6),
  pin7 = (1u << 7),
  pin8 = (1u << 8),
  pin9 = (1u << 9),
  pin10 = (1u << 10),
  pin11 = (1u << 11),
  pin12 = (1u << 12),
  pin13 = (1u << 13),
  pin14 = (1u << 14),
  pin15 = (1u << 15),
  pin16 = (1u << 16),
  pin17 = (1u << 17),
  pin18 = (1u << 18),
  pin19 = (1u << 19),
  pin20 = (1u << 20),
  pin21 = (1u << 21),
  pin22 = (1u << 22),
  pin23 = (1u << 23),
  pin24 = (1u << 24),
  pin25 = (1u << 25),
  pin26 = (1u << 26),
  pin27 = (1u << 27),
  pin28 = (1u << 28),
  pin29 = (1u << 29),
  pin30 = (1u << 30),
  pin31 = (1u << 31),
};
void HasBitwiseOperators(GPIO_regs::input_en_bits);

/**
 * Bit shifts for GPIO input_en
 */
enum class GPIO_regs::input_en_shift : unsigned {
  pin0 = 0,
  pin1 = 1,
  pin2 = 2,
  pin3 = 3,
  pin4 = 4,
  pin5 = 5,
  pin6 = 6,
  pin7 = 7,
  pin8 = 8,
  pin9 = 9,
  pin10 = 10,
  pin11 = 11,
  pin12 = 12,
  pin13 = 13,
  pin14 = 14,
  pin15 = 15,
  pin16 = 16,
  pin17 = 17,
  pin18 = 18,
  pin19 = 19,
  pin20 = 20,
  pin21 = 21,
  pin22 = 22,
  pin23 = 23,
  pin24 = 24,
  pin25 = 25,
  pin26 = 26,
  pin27 = 27,
  pin28 = 28,
  pin29 = 29,
  pin30 = 30,
  pin31 = 31,
};

/**
 * Bitmasks for GPIO output_en
 *
 * Pin Output Enable Register
 */
enum class GPIO_regs::output_en_bits : uint32_t {
  pin0 = (1u << 0),
  pin1 = (1u << 1),
  pin2 = (1u << 2),
  pin3 = (1u << 3),
  pin4 = (1u << 4),
  pin5 = (1u << 5),
  pin6 = (1u << 6),
  pin7 = (1u << 7),
  pin8 = (1u << 8),
  pin9 = (1u << 9),
  pin10 = (1u << 10),
  pin11 = (1u << 11),
  pin12 = (1u << 12),
  pin13 = (1u << 13),
  pin14 = (1u << 14),
  pin15 = (1u << 15),
  pin16 = (1u << 16),
  pin17 = (1u << 17),
  pin18 = (1u << 18),
  pin19 = (1u << 19),
  pin20 = (1u << 20),
  pin21 = (1u << 21),
  pin22 = (1u << 22),
  pin23 = (1u << 23),
  pin24 = (1u << 24),
  pin25 = (1u << 25),
  pin26 = (1u << 26),
  pin27 = (1u << 27),
  pin28 = (1u << 28),
  pin29 = (1u << 29),
  pin30 = (1u << 30),
  pin31 = (1u << 31),
};
void HasBitwiseOperators(GPIO_regs::output_en_bits);

/**
 * Bit shifts for GPIO output_en
 */
enum class GPIO_regs::output_en_shift : unsigned {
  pin0 = 0,
  pin1 = 1,
  pin2 = 2,
  pin3 = 3,
  pin4 = 4,
  pin5 = 5,
  pin6 = 6,
  pin7 = 7,
  pin8 = 8,
  pin9 = 9,
  pin10 = 10,
  pin11 = 11,
  pin12 = 12,
  pin13 = 13,
  pin14 = 14,
  pin15 = 15,
  pin16 = 16,
  pin17 = 17,
  pin18 = 18,
  pin19 = 19,
  pin20 = 20,
  pin21 = 21,
  pin22 = 22,
  pin23 = 23,
  pin24 = 24,
  pin25 = 25,
  pin26 = 26,
  pin27 = 27,
  pin28 = 28,
  pin29 = 29,
  pin30 = 30,
  pin31 = 31,
};

/**
 * Bitmasks for GPIO output_val
 *
 * Output Port Value Register
 */
enum class GPIO_regs::output_val_bits : uint32_t {
  pin0 = (1u << 0),
  pin1 = (1u << 1),
  pin2 = (1u << 2),
  pin3 = (1u << 3),
  pin4 = (1u << 4),
  pin5 = (1u << 5),
  pin6 = (1u << 6),
  pin7 = (1u << 7),
  pin8 = (1u << 8),
  pin9 = (1u << 9),
  pin10 = (1u << 10),
  pin11 = (1u << 11),
  pin12 = (1u << 12),
  pin13 = (1u << 13),
  pin14 = (1u << 14),
  pin15 = (1u << 15),
  pin16 = (1u << 16),
  pin17 = (1u << 17),
  pin18 = (1u << 18),
  pin19 = (1u << 19),
  pin20 = (1u << 20),
  pin21 = (1u << 21),
  pin22 = (1u << 22),
  pin23 = (1u << 23),
  pin24 = (1u << 24),
  pin25 = (1u << 25),
  pin26 = (1u << 26),
  pin27 = (1u << 27),
  pin28 = (1u << 28),
  pin29 = (1u << 29),
  pin30 = (1u << 30),
  pin31 = (1u << 31),
};
void HasBitwiseOperators(GPIO_regs::output_val_bits);

/**
 * Bit shifts for GPIO output_val
 */
enum class GPIO_regs::output_val_shift : unsigned {
  pin0 = 0,
  pin1 = 1,
  pin2 = 2,
  pin3 = 3,
  pin4 = 4,
  pin5 = 5,
  pin6 = 6,
  pin7 = 7,
  pin8 = 8,
  pin9 = 9,
  pin10 = 10,
  pin11 = 11,
  pin12 = 12,
  pin13 = 13,
  pin14 = 14,
  pin15 = 15,
  pin16 = 16,
  pin17 = 17,
  pin18 = 18,
  pin19 = 19,
  pin20 = 20,
  pin21 = 21,
  pin22 = 22,
  pin23 = 23,
  pin24 = 24,
  pin25 = 25,
  pin26 = 26,
  pin27 = 27,
  pin28 = 28,
  pin29 = 29,
  pin30 = 30,
  pin31 = 31,
};

/**
 * Bitmasks for GPIO pullup
 *
 * Internal Pull-Up Enable Register
 */
enum class GPIO_regs::pullup_bits : uint32_t {
  pin0 = (1u << 0),
  pin1 = (1u << 1),
  pin2 = (1u << 2),
  pin3 = (1u << 3),
  pin4 = (1u << 4),
  pin5 = (1u << 5),
  pin6 = (1u << 6),
  pin7 = (1u << 7),
  pin8 = (1u << 8),
  pin9 = (1u << 9),
  pin10 = (1u << 10),
  pin11 = (1u << 11),
  pin12 = (1u << 12),
  pin13 = (1u << 13),
  pin14 = (1u << 14),
  pin15 = (1u << 15),
  pin16 = (1u << 16),
  pin17 = (1u << 17),
  pin18 = (1u << 18),
  pin19 = (1u << 19),
  pin20 = (1u << 20),
  pin21 = (1u << 21),
  pin22 = (1u << 22),
  pin23 = (1u << 23),
  pin24 = (1u << 24),
  pin25 = (1u << 25),
  pin26 = (1u << 26),
  pin27 = (1u << 27),
  pin28 = (1u << 28),
  pin29 = (1u << 29),
  pin30 = (1u << 30),
  pin31 = (1u << 31),
};
void HasBitwiseOperators(GPIO_regs::pullup_bits);

/**
 * Bit shifts for GPIO pullup
 */
enum class GPIO_regs::pullup_shift : unsigned {
  pin0 = 0,
  pin1 = 1,
  pin2 = 2,
  pin3 = 3,
  pin4 = 4,
  pin5 = 5,
  pin6 = 6,
  pin7 = 7,
  pin8 = 8,
  pin9 = 9,
  pin10 = 10,
  pin11 = 11,
  pin12 = 12,
  pin13 = 13,
  pin14 = 14,
  pin15 = 15,
  pin16 = 16,
  pin17 = 17,
  pin18 = 18,
  pin19 = 19,
  pin20 = 20,
  pin21 = 21,
  pin22 = 22,
  pin23 = 23,
  pin24 = 24,
  pin25 = 25,
  pin26 = 26,
  pin27 = 27,
  pin28 = 28,
  pin29 = 29,
  pin30 = 30,
  pin31 = 31,
};

/**
 * Bitmasks for GPIO drive
 *
 * Drive Strength Register
 */
enum class GPIO_regs::drive_bits : uint32_t {
  pin0 = (1u << 0),
  pin1 = (1u << 1),
  pin2 = (1u << 2),
  pin3 = (1u << 3),
  pin4 = (1u << 4),
  pin5 = (1u << 5),
  pin6 = (1u << 6),
  pin7 = (1u << 7),
  pin8 = (1u << 8),
  pin9 = (1u << 9),
  pin10 = (1u << 10),
  pin11 = (1u << 11),
  pin12 = (1u << 12),
  pin13 = (1u << 13),
  pin14 = (1u << 14),
  pin15 = (1u << 15),
  pin16 = (1u << 16),
  pin17 = (1u << 17),
  pin18 = (1u << 18),
  pin19 = (1u << 19),
  pin20 = (1u << 20),
  pin21 = (1u << 21),
  pin22 = (1u << 22),
  pin23 = (1u << 23),
  pin24 = (1u << 24),
  pin25 = (1u << 25),
  pin26 = (1u << 26),
  pin27 = (1u << 27),
  pin28 = (1u << 28),
  pin29 = (1u << 29),
  pin30 = (1u << 30),
  pin31 = (1u << 31),
};
void HasBitwiseOperators(GPIO_regs::drive_bits);

/**
 * Bit shifts for GPIO drive
 */
enum class GPIO_regs::drive_shift : unsigned {
  pin0 = 0,
  pin1 = 1,
  pin2 = 2,
  pin3 = 3,
  pin4 = 4,
  pin5 = 5,
  pin6 = 6,
  pin7 = 7,
  pin8 = 8,
  pin9 = 9,
  pin10 = 10,
  pin11 = 11,
  pin12 = 12,
  pin13 = 13,
  pin14 = 14,
  pin15 = 15,
  pin16 = 16,
  pin17 = 17,
  pin18 = 18,
  pin19 = 19,
  pin20 = 20,
  pin21 = 21,
  pin22 = 22,
  pin23 = 23,
  pin24 = 24,
  pin25 = 25,
  pin26 = 26,
  pin27 = 27,
  pin28 = 28,
  pin29 = 29,
  pin30 = 30,
  pin31 = 31,
};

/**
 * Bitmasks for GPIO rise_ie
 *
 * Rise Interrupt Enable Register
 */
enum class GPIO_regs::rise_ie_bits : uint32_t {
  pin0 = (1u << 0),
  pin1 = (1u << 1),
  pin2 = (1u << 2),
  pin3 = (1u << 3),
  pin4 = (1u << 4),
  pin5 = (1u << 5),
  pin6 = (1u << 6),
  pin7 = (1u << 7),
  pin8 = (1u << 8),
  pin9 = (1u << 9),
  pin10 = (1u << 10),
  pin11 = (1u << 11),
  pin12 = (1u << 12),
  pin13 = (1u << 13),
  pin14 = (1u << 14),
  pin15 = (1u << 15),
  pin16 = (1u << 16),
  pin17 = (1u << 17),
  pin18 = (1u << 18),
  pin19 = (1u << 19),
  pin20 = (1u << 20),
  pin21 = (1u << 21),
  pin22 = (1u << 22),
  pin23 = (1u << 23),
  pin24 = (1u << 24),
  pin25 = (1u << 25),
  pin26 = (1u << 26),
  pin27 = (1u << 27),
  pin28 = (1u << 28),
  pin29 = (1u << 29),
  pin30 = (1u << 30),
  pin31 = (1u << 31),
};
void HasBitwiseOperators(GPIO_regs::rise_ie_bits);

/**
 * Bit shifts for GPIO rise_ie
 */
enum class GPIO_regs::rise_ie_shift : unsigned {
  pin0 = 0,
  pin1 = 1,
  pin2 = 2,
  pin3 = 3,
  pin4 = 4,
  pin5 = 5,
  pin6 = 6,
  pin7 = 7,
  pin8 = 8,
  pin9 = 9,
  pin10 = 10,
  pin11 = 11,
  pin12 = 12,
  pin13 = 13,
  pin14 = 14,
  pin15 = 15,
  pin16 = 16,
  pin17 = 17,
  pin18 = 18,
  pin19 = 19,
  pin20 = 20,
  pin21 = 21,
  pin22 = 22,
  pin23 = 23,
  pin24 = 24,
  pin25 = 25,
  pin26 = 26,
  pin27 = 27,
  pin28 = 28,
  pin29 = 29,
  pin30 = 30,
  pin31 = 31,
};

/**
 * Bitmasks for GPIO rise_ip
 *
 * Rise Interrupt Pending Register
 */
enum class GPIO_regs::rise_ip_bits : uint32_t {
  pin0 = (1u << 0),
  pin1 = (1u << 1),
  pin2 = (1u << 2),
  pin3 = (1u << 3),
  pin4 = (1u << 4),
  pin5 = (1u << 5),
  pin6 = (1u << 6),
  pin7 = (1u << 7),
  pin8 = (1u << 8),
  pin9 = (1u << 9),
  pin10 = (1u << 10),
  pin11 = (1u << 11),
  pin12 = (1u << 12),
  pin13 = (1u << 13),
  pin14 = (1u << 14),
  pin15 = (1u << 15),
  pin16 = (1u << 16),
  pin17 = (1u << 17),
  pin18 = (1u << 18),
  pin19 = (1u << 19),
  pin20 = (1u << 20),
  pin21 = (1u << 21),
  pin22 = (1u << 22),
  pin23 = (1u << 23),
  pin24 = (1u << 24),
  pin25 = (1u << 25),
  pin26 = (1u << 26),
  pin27 = (1u << 27),
  pin28 = (1u << 28),
  pin29 = (1u << 29),
  pin30 = (1u << 30),
  pin31 = (1u << 31),
};
void HasBitwiseOperators(GPIO_regs::rise_ip_bits);

/**
 * Bit shifts for GPIO rise_ip
 */
enum class GPIO_regs::rise_ip_shift : unsigned {
  pin0 = 0,
  pin1 = 1,
  pin2 = 2,
  pin3 = 3,
  pin4 = 4,
  pin5 = 5,
  pin6 = 6,
  pin7 = 7,
  pin8 = 8,
  pin9 = 9,
  pin10 = 10,
  pin11 = 11,
  pin12 = 12,
  pin13 = 13,
  pin14 = 14,
  pin15 = 15,
  pin16 = 16,
  pin17 = 17,
  pin18 = 18,
  pin19 = 19,
  pin20 = 20,
  pin21 = 21,
  pin22 = 22,
  pin23 = 23,
  pin24 = 24,
  pin25 = 25,
  pin26 = 26,
  pin27 = 27,
  pin28 = 28,
  pin29 = 29,
  pin30 = 30,
  pin31 = 31,
};

/**
 * Bitmasks for GPIO fall_ie
 *
 * Fall Interrupt Enable Register
 */
enum class GPIO_regs::fall_ie_bits : uint32_t {
  pin0 = (1u << 0),
  pin1 = (1u << 1),
  pin2 = (1u << 2),
  pin3 = (1u << 3),
  pin4 = (1u << 4),
  pin5 = (1u << 5),
  pin6 = (1u << 6),
  pin7 = (1u << 7),
  pin8 = (1u << 8),
  pin9 = (1u << 9),
  pin10 = (1u << 10),
  pin11 = (1u << 11),
  pin12 = (1u << 12),
  pin13 = (1u << 13),
  pin14 = (1u << 14),
  pin15 = (1u << 15),
  pin16 = (1u << 16),
  pin17 = (1u << 17),
  pin18 = (1u << 18),
  pin19 = (1u << 19),
  pin20 = (1u << 20),
  pin21 = (1u << 21),
  pin22 = (1u << 22),
  pin23 = (1u << 23),
  pin24 = (1u << 24),
  pin25 = (1u << 25),
  pin26 = (1u << 26),
  pin27 = (1u << 27),
  pin28 = (1u << 28),
  pin29 = (1u << 29),
  pin30 = (1u << 30),
  pin31 = (1u << 31),
};
void HasBitwiseOperators(GPIO_regs::fall_ie_bits);

/**
 * Bit shifts for GPIO fall_ie
 */
enum class GPIO_regs::fall_ie_shift : unsigned {
  pin0 = 0,
  pin1 = 1,
  pin2 = 2,
  pin3 = 3,
  pin4 = 4,
  pin5 = 5,
  pin6 = 6,
  pin7 = 7,
  pin8 = 8,
  pin9 = 9,
  pin10 = 10,
  pin11 = 11,
  pin12 = 12,
  pin13 = 13,
  pin14 = 14,
  pin15 = 15,
  pin16 = 16,
  pin17 = 17,
  pin18 = 18,
  pin19 = 19,
  pin20 = 20,
  pin21 = 21,
  pin22 = 22,
  pin23 = 23,
  pin24 = 24,
  pin25 = 25,
  pin26 = 26,
  pin27 = 27,
  pin28 = 28,
  pin29 = 29,
  pin30 = 30,
  pin31 = 31,
};

/**
 * Bitmasks for GPIO fall_ip
 *
 * Fall Interrupt Pending Register
 */
enum class GPIO_regs::fall_ip_bits : uint32_t {
  pin0 = (1u << 0),
  pin1 = (1u << 1),
  pin2 = (1u << 2),
  pin3 = (1u << 3),
  pin4 = (1u << 4),
  pin5 = (1u << 5),
  pin6 = (1u << 6),
  pin7 = (1u << 7),
  pin8 = (1u << 8),
  pin9 = (1u << 9),
  pin10 = (1u << 10),
  pin11 = (1u << 11),
  pin12 = (1u << 12),
  pin13 = (1u << 13),
  pin14 = (1u << 14),
  pin15 = (1u << 15),
  pin16 = (1u << 16),
  pin17 = (1u << 17),
  pin18 = (1u << 18),
  pin19 = (1u << 19),
  pin20 = (1u << 20),
  pin21 = (1u << 21),
  pin22 = (1u << 22),
  pin23 = (1u << 23),
  pin24 = (1u << 24),
  pin25 = (1u << 25),
  pin26 = (1u << 26),
  pin27 = (1u << 27),
  pin28 = (1u << 28),
  pin29 = (1u << 29),
  pin30 = (1u << 30),
  pin31 = (1u << 31),
};
void HasBitwiseOperators(GPIO_regs::fall_ip_bits);

/**
 * Bit shifts for GPIO fall_ip
 */
enum class GPIO_regs::fall_ip_shift : unsigned {
  pin0 = 0,
  pin1 = 1,
  pin2 = 2,
  pin3 = 3,
  pin4 = 4,
  pin5 = 5,
  pin6 = 6,
  pin7 = 7,
  pin8 = 8,
  pin9 = 9,
  pin10 = 10,
  pin11 = 11,
  pin12 = 12,
  pin13 = 13,
  pin14 = 14,
  pin15 = 15,
  pin16 = 16,
  pin17 = 17,
  pin18 = 18,
  pin19 = 19,
  pin20 = 20,
  pin21 = 21,
  pin22 = 22,
  pin23 = 23,
  pin24 = 24,
  pin25 = 25,
  pin26 = 26,
  pin27 = 27,
  pin28 = 28,
  pin29 = 29,
  pin30 = 30,
  pin31 = 31,
};

/**
 * Bitmasks for GPIO high_ie
 *
 * High Interrupt Enable Register
 */
enum class GPIO_regs::high_ie_bits : uint32_t {
  pin0 = (1u << 0),
  pin1 = (1u << 1),
  pin2 = (1u << 2),
  pin3 = (1u << 3),
  pin4 = (1u << 4),
  pin5 = (1u << 5),
  pin6 = (1u << 6),
  pin7 = (1u << 7),
  pin8 = (1u << 8),
  pin9 = (1u << 9),
  pin10 = (1u << 10),
  pin11 = (1u << 11),
  pin12 = (1u << 12),
  pin13 = (1u << 13),
  pin14 = (1u << 14),
  pin15 = (1u << 15),
  pin16 = (1u << 16),
  pin17 = (1u << 17),
  pin18 = (1u << 18),
  pin19 = (1u << 19),
  pin20 = (1u << 20),
  pin21 = (1u << 21),
  pin22 = (1u << 22),
  pin23 = (1u << 23),
  pin24 = (1u << 24),
  pin25 = (1u << 25),
  pin26 = (1u << 26),
  pin27 = (1u << 27),
  pin28 = (1u << 28),
  pin29 = (1u << 29),
  pin30 = (1u << 30),
  pin31 = (1u << 31),
};
void HasBitwiseOperators(GPIO_regs::high_ie_bits);

/**
 * Bit shifts for GPIO high_ie
 */
enum class GPIO_regs::high_ie_shift : unsigned {
  pin0 = 0,
  pin1 = 1,
  pin2 = 2,
  pin3 = 3,
  pin4 = 4,
  pin5 = 5,
  pin6 = 6,
  pin7 = 7,
  pin8 = 8,
  pin9 = 9,
  pin10 = 10,
  pin11 = 11,
  pin12 = 12,
  pin13 = 13,
  pin14 = 14,
  pin15 = 15,
  pin16 = 16,
  pin17 = 17,
  pin18 = 18,
  pin19 = 19,
  pin20 = 20,
  pin21 = 21,
  pin22 = 22,
  pin23 = 23,
  pin24 = 24,
  pin25 = 25,
  pin26 = 26,
  pin27 = 27,
  pin28 = 28,
  pin29 = 29,
  pin30 = 30,
  pin31 = 31,
};

/**
 * Bitmasks for GPIO high_ip
 *
 * High Interrupt Pending Register
 */
enum class GPIO_regs::high_ip_bits : uint32_t {
  pin0 = (1u << 0),
  pin1 = (1u << 1),
  pin2 = (1u << 2),
  pin3 = (1u << 3),
  pin4 = (1u << 4),
  pin5 = (1u << 5),
  pin6 = (1u << 6),
  pin7 = (1u << 7),
  pin8 = (1u << 8),
  pin9 = (1u << 9),
  pin10 = (1u << 10),
  pin11 = (1u << 11),
  pin12 = (1u << 12),
  pin13 = (1u << 13),
  pin14 = (1u << 14),
  pin15 = (1u << 15),
  pin16 = (1u << 16),
  pin17 = (1u << 17),
  pin18 = (1u << 18),
  pin19 = (1u << 19),
  pin20 = (1u << 20),
  pin21 = (1u << 21),
  pin22 = (1u << 22),
  pin23 = (1u << 23),
  pin24 = (1u << 24),
  pin25 = (1u << 25),
  pin26 = (1u << 26),
  pin27 = (1u << 27),
  pin28 = (1u << 28),
  pin29 = (1u << 29),
  pin30 = (1u << 30),
  pin31 = (1u << 31),
};
void HasBitwiseOperators(GPIO_regs::high_ip_bits);

/**
 * Bit shifts for GPIO high_ip
 */
enum class GPIO_regs::high_ip_shift : unsigned {
  pin0 = 0,
  pin1 = 1,
  pin2 = 2,
  pin3 = 3,
  pin4 = 4,
  pin5 = 5,
  pin6 = 6,
  pin7 = 7,
  pin8 = 8,
  pin9 = 9,
  pin10 = 10,
  pin11 = 11,
  pin12 = 12,
  pin13 = 13,
  pin14 = 14,
  pin15 = 15,
  pin16 = 16,
  pin17 = 17,
  pin18 = 18,
  pin19 = 19,
  pin20 = 20,
  pin21 = 21,
  pin22 = 22,
  pin23 = 23,
  pin24 = 24,
  pin25 = 25,
  pin26 = 26,
  pin27 = 27,
  pin28 = 28,
  pin29 = 29,
  pin30 = 30,
  pin31 = 31,
};

/**
 * Bitmasks for GPIO low_ie
 *
 * Low Interrupt Enable Register
 */
enum class GPIO_regs::low_ie_bits : uint32_t {
  pin0 = (1u << 0),
  pin1 = (1u << 1),
  pin2 = (1u << 2),
  pin3 = (1u << 3),
  pin4 = (1u << 4),
  pin5 = (1u << 5),
  pin6 = (1u << 6),
  pin7 = (1u << 7),
  pin8 = (1u << 8),
  pin9 = (1u << 9),
  pin10 = (1u << 10),
  pin11 = (1u << 11),
  pin12 = (1u << 12),
  pin13 = (1u << 13),
  pin14 = (1u << 14),
  pin15 = (1u << 15),
  pin16 = (1u << 16),
  pin17 = (1u << 17),
  pin18 = (1u << 18),
  pin19 = (1u << 19),
  pin20 = (1u << 20),
  pin21 = (1u << 21),
  pin22 = (1u << 22),
  pin23 = (1u << 23),
  pin24 = (1u << 24),
  pin25 = (1u << 25),
  pin26 = (1u << 26),
  pin27 = (1u << 27),
  pin28 = (1u << 28),
  pin29 = (1u << 29),
  pin30 = (1u << 30),
  pin31 = (1u << 31),
};
void HasBitwiseOperators(GPIO_regs::low_ie_bits);

/**
 * Bit shifts for GPIO low_ie
 */
enum class GPIO_regs::low_ie_shift : unsigned {
  pin0 = 0,
  pin1 = 1,
  pin2 = 2,
  pin3 = 3,
  pin4 = 4,
  pin5 = 5,
  pin6 = 6,
  pin7 = 7,
  pin8 = 8,
  pin9 = 9,
  pin10 = 10,
  pin11 = 11,
  pin12 = 12,
  pin13 = 13,
  pin14 = 14,
  pin15 = 15,
  pin16 = 16,
  pin17 = 17,
  pin18 = 18,
  pin19 = 19,
  pin20 = 20,
  pin21 = 21,
  pin22 = 22,
  pin23 = 23,
  pin24 = 24,
  pin25 = 25,
  pin26 = 26,
  pin27 = 27,
  pin28 = 28,
  pin29 = 29,
  pin30 = 30,
  pin31 = 31,
};

/**
 * Bitmasks for GPIO low_ip
 *
 * Low Interrupt Pending Register
 */
enum class GPIO_regs::low_ip_bits : uint32_t {
  pin0 = (1u << 0),
  pin1 = (1u << 1),
  pin2 = (1u << 2),
  pin3 = (1u << 3),
  pin4 = (1u << 4),
  pin5 = (1u << 5),
  pin6 = (1u << 6),
  pin7 = (1u << 7),
  pin8 = (1u << 8),
  pin9 = (1u << 9),
  pin10 = (1u << 10),
  pin11 = (1u << 11),
  pin12 = (1u << 12),
  pin13 = (1u << 13),
  pin14 = (1u << 14),
  pin15 = (1u << 15),
  pin16 = (1u << 16),
  pin17 = (1u << 17),
  pin18 = (1u << 18),
  pin19 = (1u << 19),
  pin20 = (1u << 20),
  pin21 = (1u << 21),
  pin22 = (1u << 22),
  pin23 = (1u << 23),
  pin24 = (1u << 24),
  pin25 = (1u << 25),
  pin26 = (1u << 26),
  pin27 = (1u << 27),
  pin28 = (1u << 28),
  pin29 = (1u << 29),
  pin30 = (1u << 30),
  pin31 = (1u << 31),
};
void HasBitwiseOperators(GPIO_regs::low_ip_bits);

/**
 * Bit shifts for GPIO low_ip
 */
enum class GPIO_regs::low_ip_shift : unsigned {
  pin0 = 0,
  pin1 = 1,
  pin2 = 2,
  pin3 = 3,
  pin4 = 4,
  pin5 = 5,
  pin6 = 6,
  pin7 = 7,
  pin8 = 8,
  pin9 = 9,
  pin10 = 10,
  pin11 = 11,
  pin12 = 12,
  pin13 = 13,
  pin14 = 14,
  pin15 = 15,
  pin16 = 16,
  pin17 = 17,
  pin18 = 18,
  pin19 = 19,
  pin20 = 20,
  pin21 = 21,
  pin22 = 22,
  pin23 = 23,
  pin24 = 24,
  pin25 = 25,
  pin26 = 26,
  pin27 = 27,
  pin28 = 28,
  pin29 = 29,
  pin30 = 30,
  pin31 = 31,
};

/**
 * Bitmasks for GPIO iof_en
 *
 * HW I/O Function Enable Register
 */
enum class GPIO_regs::iof_en_bits : uint32_t {
  pin0 = (1u << 0),
  pin1 = (1u << 1),
  pin2 = (1u << 2),
  pin3 = (1u << 3),
  pin4 = (1u << 4),
  pin5 = (1u << 5),
  pin6 = (1u << 6),
  pin7 = (1u << 7),
  pin8 = (1u << 8),
  pin9 = (1u << 9),
  pin10 = (1u << 10),
  pin11 = (1u << 11),
  pin12 = (1u << 12),
  pin13 = (1u << 13),
  pin14 = (1u << 14),
  pin15 = (1u << 15),
  pin16 = (1u << 16),
  pin17 = (1u << 17),
  pin18 = (1u << 18),
  pin19 = (1u << 19),
  pin20 = (1u << 20),
  pin21 = (1u << 21),
  pin22 = (1u << 22),
  pin23 = (1u << 23),
  pin24 = (1u << 24),
  pin25 = (1u << 25),
  pin26 = (1u << 26),
  pin27 = (1u << 27),
  pin28 = (1u << 28),
  pin29 = (1u << 29),
  pin30 = (1u << 30),
  pin31 = (1u << 31),
};
void HasBitwiseOperators(GPIO_regs::iof_en_bits);

/**
 * Bit shifts for GPIO iof_en
 */
enum class GPIO_regs::iof_en_shift : unsigned {
  pin0 = 0,
  pin1 = 1,
  pin2 = 2,
  pin3 = 3,
  pin4 = 4,
  pin5 = 5,
  pin6 = 6,
  pin7 = 7,
  pin8 = 8,
  pin9 = 9,
  pin10 = 10,
  pin11 = 11,
  pin12 = 12,
  pin13 = 13,
  pin14 = 14,
  pin15 = 15,
  pin16 = 16,
  pin17 = 17,
  pin18 = 18,
  pin19 = 19,
  pin20 = 20,
  pin21 = 21,
  pin22 = 22,
  pin23 = 23,
  pin24 = 24,
  pin25 = 25,
  pin26 = 26,
  pin27 = 27,
  pin28 = 28,
  pin29 = 29,
  pin30 = 30,
  pin31 = 31,
};

/**
 * Bitmasks for GPIO iof_sel
 *
 * HW I/O Function Select Register
 */
enum class GPIO_regs::iof_sel_bits : uint32_t {
  pin0 = (1u << 0),
  pin1 = (1u << 1),
  pin2 = (1u << 2),
  pin3 = (1u << 3),
  pin4 = (1u << 4),
  pin5 = (1u << 5),
  pin6 = (1u << 6),
  pin7 = (1u << 7),
  pin8 = (1u << 8),
  pin9 = (1u << 9),
  pin10 = (1u << 10),
  pin11 = (1u << 11),
  pin12 = (1u << 12),
  pin13 = (1u << 13),
  pin14 = (1u << 14),
  pin15 = (1u << 15),
  pin16 = (1u << 16),
  pin17 = (1u << 17),
  pin18 = (1u << 18),
  pin19 = (1u << 19),
  pin20 = (1u << 20),
  pin21 = (1u << 21),
  pin22 = (1u << 22),
  pin23 = (1u << 23),
  pin24 = (1u << 24),
  pin25 = (1u << 25),
  pin26 = (1u << 26),
  pin27 = (1u << 27),
  pin28 = (1u << 28),
  pin29 = (1u << 29),
  pin30 = (1u << 30),
  pin31 = (1u << 31),
};
void HasBitwiseOperators(GPIO_regs::iof_sel_bits);

/**
 * Bit shifts for GPIO iof_sel
 */
enum class GPIO_regs::iof_sel_shift : unsigned {
  pin0 = 0,
  pin1 = 1,
  pin2 = 2,
  pin3 = 3,
  pin4 = 4,
  pin5 = 5,
  pin6 = 6,
  pin7 = 7,
  pin8 = 8,
  pin9 = 9,
  pin10 = 10,
  pin11 = 11,
  pin12 = 12,
  pin13 = 13,
  pin14 = 14,
  pin15 = 15,
  pin16 = 16,
  pin17 = 17,
  pin18 = 18,
  pin19 = 19,
  pin20 = 20,
  pin21 = 21,
  pin22 = 22,
  pin23 = 23,
  pin24 = 24,
  pin25 = 25,
  pin26 = 26,
  pin27 = 27,
  pin28 = 28,
  pin29 = 29,
  pin30 = 30,
  pin31 = 31,
};

/**
 * Bitmasks for GPIO out_xor
 *
 * Output XOR (invert) Register
 */
enum class GPIO_regs::out_xor_bits : uint32_t {
  pin0 = (1u << 0),
  pin1 = (1u << 1),
  pin2 = (1u << 2),
  pin3 = (1u << 3),
  pin4 = (1u << 4),
  pin5 = (1u << 5),
  pin6 = (1u << 6),
  pin7 = (1u << 7),
  pin8 = (1u << 8),
  pin9 = (1u << 9),
  pin10 = (1u << 10),
  pin11 = (1u << 11),
  pin12 = (1u << 12),
  pin13 = (1u << 13),
  pin14 = (1u << 14),
  pin15 = (1u << 15),
  pin16 = (1u << 16),
  pin17 = (1u << 17),
  pin18 = (1u << 18),
  pin19 = (1u << 19),
  pin20 = (1u << 20),
  pin21 = (1u << 21),
  pin22 = (1u << 22),
  pin23 = (1u << 23),
  pin24 = (1u << 24),
  pin25 = (1u << 25),
  pin26 = (1u << 26),
  pin27 = (1u << 27),
  pin28 = (1u << 28),
  pin29 = (1u << 29),
  pin30 = (1u << 30),
  pin31 = (1u << 31),
};
void HasBitwiseOperators(GPIO_regs::out_xor_bits);

/**
 * Bit shifts for GPIO out_xor
 */
enum class GPIO_regs::out_xor_shift : unsigned {
  pin0 = 0,
  pin1 = 1,
  pin2 = 2,
  pin3 = 3,
  pin4 = 4,
  pin5 = 5,
  pin6 = 6,
  pin7 = 7,
  pin8 = 8,
  pin9 = 9,
  pin10 = 10,
  pin11 = 11,
  pin12 = 12,
  pin13 = 13,
  pin14 = 14,
  pin15 = 15,
  pin16 = 16,
  pin17 = 17,
  pin18 = 18,
  pin19 = 19,
  pin20 = 20,
  pin21 = 21,
  pin22 = 22,
  pin23 = 23,
  pin24 = 24,
  pin25 = 25,
  pin26 = 26,
  pin27 = 27,
  pin28 = 28,
  pin29 = 29,
  pin30 = 30,
  pin31 = 31,
};

static_assert(offsetof(GPIO_regs, input_val) == 0x0);
static_assert(offsetof(GPIO_regs, input_en) == 0x4);
static_assert(offsetof(GPIO_regs, output_en) == 0x8);
static_assert(offsetof(GPIO_regs, output_val) == 0xc);
static_assert(offsetof(GPIO_regs, pullup) == 0x10);
static_assert(offsetof(GPIO_regs, drive) == 0x14);
static_assert(offsetof(GPIO_regs, rise_ie) == 0x18);
static_assert(offsetof(GPIO_regs, rise_ip) == 0x1c);
static_assert(offsetof(GPIO_regs, fall_ie) == 0x20);
static_assert(offsetof(GPIO_regs, fall_ip) == 0x24);
static_assert(offsetof(GPIO_regs, high_ie) == 0x28);
static_assert(offsetof(GPIO_regs, high_ip) == 0x2c);
static_assert(offsetof(GPIO_regs, low_ie) == 0x30);
static_assert(offsetof(GPIO_regs, low_ip) == 0x34);
static_assert(offsetof(GPIO_regs, iof_en) == 0x38);
static_assert(offsetof(GPIO_regs, iof_sel) == 0x3c);
static_assert(offsetof(GPIO_regs, out_xor) == 0x40);
}  // namespace deri::mmio
