#pragma exceptions off

#include "zone_spatial_allocator_pop.h"

extern "C" {
void *func_00100730(unsigned int size);
void *func_117AF8(void *dst, const void *src, unsigned int size);
void func_100630(void *ptr);
void *func_100850(unsigned int size);
void func_001D8120(void *root, void *node);
int func_1D80D0(void *node, unsigned int w, unsigned int h);
void *func_117CAC(void *dst, int val, unsigned int size);
}

struct SpatialTreeNode {
    void *buffer;
    SpatialTreeNode *child;
};

struct SpatialChunkAllocator {
    SpatialTreeNode *root;    // 0x0
    int elem_size;            // 0x4
    int chunk_capacity;       // 0x8
    int count;                // 0xC
    int capacity;             // 0x10
    void **items;             // 0x14
    unsigned char clear_flag; // 0x18
};

extern "C" void *func_001D81E0(SpatialChunkAllocator *self) {
    if (self->count == 0) {
        if ((unsigned int)(self->count + self->chunk_capacity) >= (unsigned int)self->capacity) {
            self->capacity += self->chunk_capacity * 2;
            void **new_items = (void **)func_00100730((unsigned int)self->capacity * 4);
            if (self->items != 0) {
                func_117AF8(new_items, self->items, self->count * 4);
            }
            func_100630(self->items);
            self->items = new_items;
        }

        SpatialTreeNode *node = (SpatialTreeNode *)func_100850(8);
        if (node != 0) {
            node->buffer = 0;
            node->child = 0;
        }

        if (self->root == 0) {
            self->root = node;
        } else {
            func_001D8120(self->root, node);
        }

        func_1D80D0(node, self->elem_size, self->chunk_capacity);

        char *buf = (char *)node->buffer;
        unsigned int i = 0;
        while (i < (unsigned int)self->chunk_capacity) {
            self->items[self->count] = buf;
            self->count++;
            buf += self->elem_size;
            i++;
        }
    }

    self->count--;
    void *item = self->items[self->count];
    if (self->clear_flag != 0) {
        func_117CAC(item, 0, self->elem_size);
    }
    return item;
}
