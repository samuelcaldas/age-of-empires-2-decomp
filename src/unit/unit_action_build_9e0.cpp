#pragma exceptions off
#include "unit_action_build_9e0.h"

short func_002719E0(void *self, int index) {
    if (index < 0 || index >= 4) {
        return -1;
    }
    void *elem = *(void **)((char *)self + 0x134 + index * sizeof(void *));
    if (elem == 0) {
        return -1;
    }
    return *(short *)((char *)elem + 0x24);
}
