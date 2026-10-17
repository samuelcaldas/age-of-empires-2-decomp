#pragma exceptions off
#include "sub_list.h"

extern "C" {
int func_0021A590(void *self, const int *in_rect, void *out_view) {
    char *self_bytes = (char *)self;
    int local_rect[4];

    if (in_rect == 0) {
        local_rect[0] = 0;
        local_rect[1] = 0;
        local_rect[2] = *(int *)(self_bytes + 0x3C) - 1;
        local_rect[3] = *(int *)(self_bytes + 0x38) - 1;
    }
    if (in_rect != 0) {
        local_rect[0] = in_rect[0];
        local_rect[1] = in_rect[1];
        local_rect[2] = in_rect[2];
        local_rect[3] = in_rect[3];
    }

    if (local_rect[2] < 0) {
        local_rect[2] = 0;
    }
    if (local_rect[1] < 0) {
        local_rect[1] = 0;
    }

    int *src = (int *)(self_bytes + 0x30);
    int *dst = (int *)out_view;
    for (int i = 0; i < 27; i++) {
        dst[i] = src[i];
    }

    int flags = *(int *)(self_bytes + 0x98);
    if ((flags & 0x4000) != 0) {
        *(int *)((char *)out_view + 0x24) = -1;
        return 0;
    }

    int pitch = *(int *)(self_bytes + 0x40);
    int f84 = *(int *)(self_bytes + 0x84);
    int offset = pitch * local_rect[1] + ((local_rect[0] * f84) >> 3);

    *(int *)((char *)out_view + 0x24) += offset;
    return 0;
}
}
