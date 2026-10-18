#pragma exceptions off
#include "sub_list.h"

extern "C" {
void *func_123908(void *);
void *func_0021DBE0(void *obj, int a1, int a2, int a3);

// Original VRAM 0x21DC50 - 0x21DCA0
// Calls func_123908 (at 0x21dc68) and func_0021DBE0 (at 0x21dc78)
void *func_0021DC50(void *obj, int a1, int a2, int a3) {
    void *packet = obj != 0 ? obj : func_123908(0);
    return func_0021DBE0(packet, a1, a2, a3);
}
}
