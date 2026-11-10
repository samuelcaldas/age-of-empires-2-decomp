#pragma exceptions off
#include "sub_list.h"

// Host builds use a pointer-sized integer; the PS2 target is 32-bit.
#if defined(__mips__)
typedef int PointerSizedInt;
#else
typedef long PointerSizedInt;
#endif

extern "C" {
int func_002B61F0(void *self, int index) {
    if (index >= 0) {
        if (index < 239) {
            return *(int *)((char *)(index * 4) + (PointerSizedInt)self + 0x858);
        }
    }
    return -1;
}
}
