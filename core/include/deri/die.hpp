/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#ifndef DERI_DIE_H_
#define DERI_DIE_H_

#define DIE(code, ...) deri::die(code)

namespace deri {
[[noreturn]] void die(unsigned int code);
} // namespace deri
#endif // DERI_DIE_H_
