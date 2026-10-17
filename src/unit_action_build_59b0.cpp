#pragma exceptions off
#include "unit_action_build_59b0.h"

void func_2759B0(void *self, short *out_rate, short *out_range) {
    *out_rate = -1;

#if defined(__LP64__) || defined(_LP64)
    void *proto = *(void **)((char *)self + 0x8);
#else
    void *proto = *(void **)((char *)self + 0x4);
#endif

    void *entries = *(void **)((char *)proto + 0xEC);
    if (entries != nullptr) {
        short count = *(short *)((char *)proto + 0xEA);
        for (int i = 0; i < count; ++i) {
            char *entry = (char *)entries + i * 4;
            if (*(short *)entry == 3) {
                *out_rate = *(short *)(entry + 2);
            }
        }
    }

    if (*out_rate == -1) {
        *out_rate = (short)*(unsigned char *)((char *)proto + 0xE8);
    }

    *out_range = *(short *)((char *)proto + 0x142);
}
