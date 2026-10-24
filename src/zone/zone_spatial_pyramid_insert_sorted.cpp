#pragma exceptions off

#include "zone_spatial_pyramid_insert_sorted.h"

extern "C" void func_001D42A0(void *self, void *list_head, void *node, int flag) {
    if (node == 0) {
        return;
    }

    char *node_ptr = (char *)node;
    char *head_ptr = (char *)list_head;

    if (flag != 0) {
        *(void **)(node_ptr + 0x20) = *(void **)(head_ptr + 0x20);
        *(void **)(head_ptr + 0x20) = node;
        return;
    }

    void **prev_ptr = (void **)(head_ptr + 0x20);
    float node_val = *(float *)(node_ptr + 0x18);

    while (*prev_ptr != 0) {
        char *curr = (char *)*prev_ptr;
        float curr_val = *(float *)(curr + 0x18);
        if (curr_val < node_val) {
            prev_ptr = (void **)(curr + 0x20);
        } else {
            *(void **)(node_ptr + 0x20) = *prev_ptr;
            *prev_ptr = node;
            return;
        }
    }

    *(void **)(node_ptr + 0x20) = 0;
    *prev_ptr = node;
}
