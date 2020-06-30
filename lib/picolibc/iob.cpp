/*
 * Copyright (c) 2020 Joakim Nohlgård
 */

#include <deri/console.h>

extern "C" {
#include <stdio.h>
}
namespace {
int iob_console_put(char, FILE *);
int iob_console_get(FILE *);
int iob_console_flush(FILE *);

// Bare minimum stdout
static FILE __stdio = {
    .unget = '\0',
    .flags = _FDEV_SETUP_RW,
    .put = iob_console_put,
    .get = iob_console_get,
    .flush = iob_console_flush,
};
} // namespace

extern "C" {
extern FILE *const __iob[];

FILE *const __iob[3] = {&__stdio, &__stdio, &__stdio};
}
namespace {

int iob_console_put(char c, FILE *) {
  return deri::console->write(&c, sizeof(c));
}
int iob_console_get(FILE *) { return 0; }

int iob_console_flush(FILE *) { return 0; }
} // namespace
