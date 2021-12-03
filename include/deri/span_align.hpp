/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include <cstdint>
#include <span>

namespace deri {
/**
 * Align a span by trimming elements so that the data pointer and size are
 * even 2** @p nbits aligned
 *
 * @tparam ElementType type of data that the span is viewing
 * @param span unaligned span
 * @param nbits number of bits of alignment
 * @return aligned span
 */
template <typename ElementType>
constexpr std::span<ElementType> span_align(std::span<ElementType> span,
                                            unsigned nbits) {
  const auto alignment = (1u << nbits);
  auto start = reinterpret_cast<uintptr_t>(span.data());
  auto end = start + span.size_bytes();
  // Round up for the starting address
  start = (start + (alignment - 1)) & ~(alignment - 1);
  // Round down for the ending address
  end = end & ~(alignment - 1);
  return {reinterpret_cast<ElementType *>(start),
          reinterpret_cast<ElementType *>(end)};
}
}  // namespace deri
