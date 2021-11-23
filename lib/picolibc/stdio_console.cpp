/*
 * Copyright (c) 2020 Joakim Nohlgård
 */

#include "deri/console.hpp"

extern "C" {
#include <stdio.h>
}
#include <span>

namespace {
int stdio_put(char, FILE *);
int stdio_get(FILE *);
int stdio_flush(FILE *);

// Bare minimum stdout
FILE _stdio{
    .unget = decltype(FILE::unget)(0),
    .flags = _FDEV_SETUP_RW,
    .put = stdio_put,
    .get = stdio_get,
    .flush = stdio_flush,
};
}  // namespace

extern "C" {
extern FILE *const stdout;
extern FILE *const stdin;
extern FILE *const stderr;

FILE *const stdout = &_stdio;
FILE *const stdin = &_stdio;
FILE *const stderr = &_stdio;
}
namespace {

int stdio_put(char c, FILE *) {
  std::span<const char, sizeof c> buffer{&c, sizeof c};
  deri::console.write(as_bytes(buffer));
  return buffer.size();
}
int stdio_get(FILE *) { return 0; }

int stdio_flush(FILE *) { return 0; }
}  // namespace
