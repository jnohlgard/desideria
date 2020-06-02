/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */
#ifndef DERI_ARCH_ASM_H_
#define DERI_ARCH_ASM_H_

#ifndef __cplusplus
/**
 * Shorthand notation for better readability
 *
 * This is normally available when compiling with GNU extensions but we want to
 * avoid requiring any extensions if possible
 */
#define asm __asm__

#endif // !defined(__cplusplus)
#endif // DERI_ARCH_ASM_H_
