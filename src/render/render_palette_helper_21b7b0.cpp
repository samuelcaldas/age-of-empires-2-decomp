#pragma exceptions off
#include "sub_list.h"

extern "C" {
void *func_0021B760(void *manager);
int func_0021B4C0(void *palette_obj, int unused, int start_idx, int count, void *src_buf, int trans_idx);

int func_0021B7B0(void *manager, int unused, void *palette_src, void **out_slot) {
    void *slot = func_0021B760(manager);
    if (slot == 0) {
        return 1;
    }

    if (palette_src != 0) {
        func_0021B4C0(slot, 0, 0, 256, palette_src, 0xFF);
    }

    if (out_slot != 0) {
        *out_slot = slot;
    }

    return 0;
}

void *func_0021B830(void *manager) {
    char *viewport = (char *)manager;
    int i = 0;
    while (i < 6) {
        if (*(int *)viewport == 0) {
            *(int *)viewport = 1;
            return viewport;
        }
        i++;
        viewport += 0xA8;
    }
    return 0;
}
}
