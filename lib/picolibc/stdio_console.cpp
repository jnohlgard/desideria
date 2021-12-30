/*
 * Copyright (c) 2020 Joakim Nohlgård
 */

#include "deri/console.hpp"

#include <cstdio>
#include <span>

namespace {
int stdio_put(char, FILE *);
int stdio_get(FILE *);
int stdio_flush(FILE *);

// Bare minimum stdout
FILE _stdio{
    .unget = decltype(FILE::unget){},
    .flags = _FDEV_SETUP_RW,
    .put = stdio_put,
    .get = stdio_get,
    .flush = stdio_flush,
};
}  // namespace

extern FILE *const stdout;
extern FILE *const stdin;
extern FILE *const stderr;

[[gnu::used]] FILE *const stdout = &_stdio;
[[gnu::used]] FILE *const stdin = &_stdio;
[[gnu::used]] FILE *const stderr = &_stdio;

namespace {

int stdio_put(char c, FILE *) {
  std::span<const char, 1> buffer{&c, 1};
  deri::Console::write(as_bytes(buffer));
  return buffer.size();
}
int stdio_get(FILE *) { return 0; }

int stdio_flush(FILE *) { return 0; }
}  // namespace
