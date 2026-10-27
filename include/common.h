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
#define STATIC_ASSERT_JOIN2(a, b) a##b
#define STATIC_ASSERT_JOIN(a, b) STATIC_ASSERT_JOIN2(a, b)
#define _Static_assert(cond, msg) extern void STATIC_ASSERT_JOIN(static_assert_line_, __LINE__)(int [(cond) ? 1 : -1])
#endif

#include "kt_mouse.h"

typedef u32 GuestAddr;

#endif /* COMMON_H */
