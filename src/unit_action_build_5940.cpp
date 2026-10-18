#pragma exceptions off
#include "unit_action_build_5940.h"

void func_275940(void *self, short *out_rate, short *out_range) {
#if defined(__LP64__) || defined(_LP64)
    void *proto = *(void **)((char *)self + 0x8);
#else
    void *proto = *(void **)((char *)self + 0x4);
#endif

    *out_rate = (short)*(unsigned char *)((char *)proto + 0xE8);

    void *entries = *(void **)((char *)proto + 0xEC);
    if (entries != 0) {
        short count = *(short *)((char *)proto + 0xEA);
        for (int i = 0; i < count; ++i) {
            char *entry = (char *)entries + i * 4;
            if (*(short *)entry == 4) {
                *out_rate = *(short *)(entry + 2);
            }
        }
    }

    *out_range = *(short *)((char *)proto + 0x11C);
}
