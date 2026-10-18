#pragma exceptions off
#include "sub_list.h"

extern "C" {
void *func_0021DD10(void *obj, int a1, int a2, int a3, int a4);

// Original VRAM 0x21DE20 - 0x21DE90
// Calls func_0021DD10 (at 0x21de48)
void *func_0021DE20(void *obj, int a1, int a2, int a3, int a4) {
    return func_0021DD10(obj, a1, a2 + 5, a3, a4);
}
}
