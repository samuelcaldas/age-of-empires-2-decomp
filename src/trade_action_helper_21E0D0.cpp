#pragma exceptions off
#include "sub_list.h"

extern "C" {
void *func_0021DF50(void *obj, int a1, int a2, int a3, int a4);

// Original VRAM 0x21E0D0 - 0x21E1C0
// Calls func_0021DF50 (at 0x21e188)
void *func_0021E0D0(void *obj, int a1, int a2, int a3, int a4) {
    return func_0021DF50(obj, a1 + 2, a2 + 2, a3, a4);
}
}
