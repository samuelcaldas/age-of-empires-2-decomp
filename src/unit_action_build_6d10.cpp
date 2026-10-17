#pragma exceptions off
#include "unit_action_build_6d10.h"

int func_276D10(void *self) {
#if defined(__LP64__) || defined(_LP64)
    void *proto = *(void **)((char *)self + 0x8);
#else
    void *proto = *(void **)((char *)self + 0x4);
#endif
    short type = *(short *)((char *)proto + 0xE);
    if (type == 0x15 || type == 2) {
        return 0;
    }
    return 1;
}
