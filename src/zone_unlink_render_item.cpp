#pragma exceptions off

#include "zone_unlink_render_item.h"

extern "C" void func_001D1CC0(void *self, void *item) {
    char *item_ptr = (char *)item;
    void *t0 = *(void **)(item_ptr + 0x10);
    if (t0 == 0) {
        return;
    }

    unsigned char slot = *(unsigned char *)(item_ptr + 4);
    char *zm = (char *)self;
    int offset = slot * 4;

    void **head_ptr = (void **)(zm + offset + 0x9048);
    void **curr = (void **)*head_ptr;
    void **prev = 0;

    while (curr != 0) {
        if (curr[0] == item) {
            break;
        }
        prev = curr;
        curr = (void **)curr[1];
    }

    curr[0] = t0;
    if (prev != 0) {
        prev[1] = curr[1];
    } else {
        *head_ptr = curr[1];
    }
    *(void **)(item_ptr + 0x10) = 0;

    void **tail_ptr = (void **)(zm + offset + 0x908C);
    if (*tail_ptr == curr) {
        *tail_ptr = prev;
    }

    void **free_head_ptr = (void **)(zm + offset + 0x90D0);
    curr[1] = *free_head_ptr;
    *free_head_ptr = curr;
}
