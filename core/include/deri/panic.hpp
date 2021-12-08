/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

namespace deri {
/**
 * Halt all execution after a fatal error
 *
 * Implementations are arch specific
 */
[[noreturn]] void panic();
}  // namespace deri
