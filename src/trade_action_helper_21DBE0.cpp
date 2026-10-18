#pragma exceptions off
#include "sub_list.h"

extern "C" {
void *func_1046D0(void *obj, int reg, unsigned long long data);
void *func_21C050(void *obj, int mode);

// Original VRAM 0x21DBE0 - 0x21DC50
// Calls func_1046D0 (at 0x21dc28) and func_21C050 (at 0x21dc30) in a loop with mode computation
void *func_0021DBE0(void *obj, int a1, int a2, int a3) {
    if (obj == 0) {
        return 0;
    }
    for (int i = 0; i < a3; ++i) {
        func_1046D0(obj, a1 + i, (unsigned long long)(unsigned int)(a2 + i));
    }
    func_21C050(obj, a1);
    return obj;
}
}
