#pragma exceptions off
#include "unit_action_build_6ca0.h"

int func_276CA0(void *self, int task_mode) {
#if defined(__LP64__) || defined(_LP64)
    void *proto = *(void **)((char *)self + 0x8);
#else
    void *proto = *(void **)((char *)self + 0x4);
#endif
    short type = *(short *)((char *)proto + 0xE);
    if (type != 9 && type != 10 && type != 0x3A) {
        return 1;
    }

    if (task_mode == 4) {
        return 1;
    }

    unsigned char byte_0 = *(unsigned char *)((char *)proto + 0x0);
    if (byte_0 == 0x3C) {
        return 1;
    }
    return 0;
}
