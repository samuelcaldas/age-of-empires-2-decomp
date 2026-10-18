#pragma exceptions off
#include "sub_list.h"

extern "C" {
// Original VRAM 0x21E090 - 0x21E0D0
// Conditional validation helper function
int func_0021E090(void *obj, int a1, int a2) {
    if (obj == 0) {
        return 0;
    }
    if (a1 == 20 || a1 == 19) {
        return a2 != 0 ? 1 : 0;
    }
    return 0;
}
}
