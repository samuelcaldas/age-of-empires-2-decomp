#ifndef COMMON_H
#define COMMON_H

#include "kt_mouse.h"

#ifndef NULL
#define NULL ((void *)0)
#endif

#ifndef INCLUDE_ASM
#define INCLUDE_ASM(FOLDER, NAME)
#endif

typedef u32 GuestAddr;

#ifndef offsetof
#define offsetof(st, m) ((unsigned int)((char *)&((st *)0)->m - (char *)0))
#endif

#if !defined(__STDC_VERSION__) || __STDC_VERSION__ < 201112L
#define STATIC_ASSERT_JOIN2(a, b) a##b
#define STATIC_ASSERT_JOIN(a, b) STATIC_ASSERT_JOIN2(a, b)
#define _Static_assert(cond, msg) typedef char STATIC_ASSERT_JOIN(static_assert_line_, __LINE__)[(cond) ? 1 : -1]
#endif

#endif /* COMMON_H */
