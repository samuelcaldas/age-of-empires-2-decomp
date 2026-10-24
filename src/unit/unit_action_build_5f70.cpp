#pragma exceptions off
#include "unit_action_build_5f70.h"

extern "C" {
    int func_002687C0(void *self);
    int func_00268530(void *self);
    int func_123350(float val);
}

int func_275F70(void *self) {
    if ((func_002687C0(self) & 0xFF) == 0) {
        return 0;
    }

    if (*(short *)((char *)self + 0x3C) != 9) {
        return 1;
    }

#if defined(__LP64__) || defined(_LP64)
    void *proto = *(void **)((char *)self + 0x8);
#else
    void *proto = *(void **)((char *)self + 0x4);
#endif

    if (*(unsigned char *)((char *)proto + 0x0) == 0x50) {
        return 1;
    }

    int workers = func_00268530(self);
    float progress = *(float *)((char *)self + 0x40);
    int total = func_123350((float)workers + progress);

    unsigned char limit = *(unsigned char *)((char *)proto + 0x1);
    return (total < limit) ? 0 : 1;
}
