#pragma exceptions off
#include "sub_list.h"

extern "C" {
void *func_123908(void *);
void *func_1046D0(void *obj, int reg, unsigned long long data);
void *func_21C050(void *obj, int mode);

// Original VRAM 0x21DD10 - 0x21DE20
// Calls func_123908 (at 0x21dd30), func_1046D0 (at 0x21ddb4, 0x21dde8), func_21C050 (at 0x21ddf0)
void *func_0021DD10(void *obj, int a1, int a2, int a3, int a4) {
    void *packet = obj != 0 ? obj : func_123908(0);
    for (int i = 0; i < a4; ++i) {
        func_1046D0(packet, a1 + i, (unsigned long long)(unsigned int)(a2 + i));
    }
    func_1046D0(packet, 0x04, (unsigned long long)(unsigned int)a3);
    func_21C050(packet, a1);
    return packet;
}
}
