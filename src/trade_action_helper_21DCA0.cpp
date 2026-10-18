#pragma exceptions off
#include "sub_list.h"

extern "C" {
void *func_0021DC50(void *obj, int a1, int a2, int a3);

// Original VRAM 0x21DCA0 - 0x21DD10
// Calls func_0021DC50 (at 0x21dcd0)
void *func_0021DCA0(void *obj, int a1, int a2, int a3) {
    return func_0021DC50(obj, a1 + 1, a2 + 1, a3);
}
}
