#pragma exceptions off

#include "zone_alloc_cell_items_buffer.h"

extern "C" {
void func_1D08E0(void *self, void *bucket, int size);
}

struct SpatialBucketLayout {
    void **buffers;    // 0x0
    char pad_4[4];     // 0x4
    int *sizes;        // 0x8
    char pad_C[4];     // 0xC
    int max_chunks;    // 0x10
    char pad_14[4];    // 0x14
    void *free_list;   // 0x18
    int chunk_idx;     // 0x1C
    int cur_idx;       // 0x20
    char pad_24[4];    // 0x24
    int remaining;     // 0x28
    int alloc_size;    // 0x2C
    int factor;        // 0x30
};

extern "C" void *func_001D0DC0(void *self, int size_level) {
    char *zm = (char *)self;
    SpatialBucketLayout *b = (SpatialBucketLayout *)(zm + 0xF2C + 0x7FF8 + size_level * 68);

    if (b->remaining == 0) {
        func_1D08E0(self, b, b->alloc_size);
    }

    void *free_node = b->free_list;
    if (free_node != 0) {
        b->free_list = *(void **)free_node;
        b->remaining -= 1;
        return free_node;
    }

    int cur = b->cur_idx;
    int chunk = b->chunk_idx;
    void *slot = (char *)b->buffers[chunk] + (cur * b->factor) * 4;

    b->remaining -= 1;
    b->cur_idx++;

    int next_chunk = b->chunk_idx;
    if (b->cur_idx == b->sizes[next_chunk]) {
        b->chunk_idx = next_chunk + 1;
        b->cur_idx = 0;
        if (b->chunk_idx == b->max_chunks) {
            b->chunk_idx = -1;
        }
    }

    return slot;
}
