#ifndef COMMON_H
#define COMMON_H

#ifndef NULL
#define NULL ((void *)0)
#endif

#ifndef INCLUDE_ASM
#define INCLUDE_ASM(FOLDER, NAME)
#endif

#ifndef offsetof
#define offsetof(st, m) ((unsigned int)((char *)&((st *)0)->m - (char *)0))
#endif

#ifndef WEAK
#if defined(__GNUC__) && !defined(__MWERKS__)
#define WEAK __attribute__((weak))
#else
#define WEAK
#endif
#endif

#if !defined(__STDC_VERSION__) || __STDC_VERSION__ < 201112L
#ifdef __cplusplus
extern "C" {
#endif
extern char static_assert_failed[1];
#ifdef __cplusplus
}
#endif
#define _Static_assert(cond, msg) extern char static_assert_failed[(cond) ? 1 : -1]
#endif

#include "kt_mouse.h"

typedef u32 GuestAddr;

#endif /* COMMON_H */
