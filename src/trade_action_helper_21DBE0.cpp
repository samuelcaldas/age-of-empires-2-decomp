#pragma exceptions off
#include "sub_list.h"

extern "C" {
void *func_1046D0(void *obj, int reg, unsigned long long data);
void *func_21C050(void *obj, int mode);

// Original VRAM 0x21DBE0 - 0x21DC50
// Calls func_1046D0 (at 0x21dc28) with a1 and a2, and func_21C050 (at 0x21dc30) with a3.
void *func_0021DBE0(void *obj, int a1, int a2, int a3) {
    if (obj == 0) {
        return 0;
    }
    func_1046D0(obj, a1, (unsigned long long)(unsigned int)a2);
    func_21C050(obj, a3);
    return obj;
}
}
