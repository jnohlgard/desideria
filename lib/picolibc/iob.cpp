/*
 * Copyright (c) 2020 Joakim Nohlgård
 */

#include <deri/console.h>

#include <cstdio>
#include <span>

namespace {
int iob_console_put(char, FILE *);
int iob_console_get(FILE *);
int iob_console_flush(FILE *);

// Bare minimum stdout
static FILE __stdio = {
    .unget = decltype(FILE::unget)(0),
    .flags = _FDEV_SETUP_RW,
    .put = iob_console_put,
    .get = iob_console_get,
    .flush = iob_console_flush,
};
}  // namespace

extern "C" {
extern FILE *const __iob[];

FILE *const __iob[3] = {&__stdio, &__stdio, &__stdio};
}
namespace {

int iob_console_put(char c, FILE *) {
  std::span<const char, sizeof c> buffer{&c, sizeof c};
  deri::console.write(as_bytes(buffer));
  return buffer.size();
}
int iob_console_get(FILE *) { return 0; }

int iob_console_flush(FILE *) { return 0; }
}  // namespace
