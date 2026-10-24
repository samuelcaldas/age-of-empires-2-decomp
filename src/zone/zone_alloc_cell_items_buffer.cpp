#pragma exceptions off

#include "zone_alloc_cell_items_buffer.h"

extern "C" {
void func_1D08E0(void *self, void *bucket, int size);
}

extern "C" void *func_001D0DC0(void *self, int size_level) {
    char *zm = (char *)self;
    char *bucket = zm + 0x8F24 + size_level * 68;

    if (*(int *)(bucket + 0x28) == 0) {
        func_1D08E0(self, bucket, *(int *)(bucket + 0x2C));
    }

    void *free_node = *(void **)(bucket + 0x18);
    if (free_node != 0) {
        *(void **)(bucket + 0x18) = *(void **)free_node;
        *(int *)(bucket + 0x28) -= 1;
        return free_node;
    }

    int cur_idx = *(int *)(bucket + 0x20);
    int factor = *(int *)(bucket + 0x30);
    int chunk_idx = *(int *)(bucket + 0x1C);
    void **buffers = *(void ***)(bucket + 0x0);

    *(int *)(bucket + 0x28) -= 1;
    void *slot = (char *)buffers[chunk_idx] + (cur_idx * factor) * 4;

    *(int *)(bucket + 0x20) = cur_idx + 1;

    int *sizes = *(int **)(bucket + 0x8);
    if (*(int *)(bucket + 0x20) == sizes[chunk_idx]) {
        chunk_idx++;
        *(int *)(bucket + 0x1C) = chunk_idx;
        *(int *)(bucket + 0x20) = 0;

        if (chunk_idx == *(int *)(bucket + 0x10)) {
            *(int *)(bucket + 0x1C) = -1;
        }
    }

    return slot;
}
