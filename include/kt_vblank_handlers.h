#ifndef KT_VBLANK_HANDLERS_H
#define KT_VBLANK_HANDLERS_H

#include "kt_thread_sema.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned long long u64;

extern volatile u64 D_00CA1550[3];
extern struct SemaContainer D_00C7F430;
extern struct SemaContainer D_00C80490;
extern int D_004E331C;

int func_00220D50(void);
int func_00220DA0(void);

#ifdef __cplusplus
}
#endif

#endif // KT_VBLANK_HANDLERS_H
