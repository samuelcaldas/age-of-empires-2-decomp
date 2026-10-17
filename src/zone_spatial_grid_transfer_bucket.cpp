#pragma exceptions off
#include "zone_spatial_grid_transfer_bucket.h"

extern "C" {
void *func_100730(unsigned int size);
void func_100630(void *ptr);
void *func_117AF8(void *dst, const void *src, unsigned int size);
}

struct Node {
    char pad[0xC];
    Node *next;
};

struct Bucket {
    char pad[0x20];
    Node *head;
    char pad_64[0x40];
    void **items;
    int count;
    int capacity;
};

struct SpatialGrid {
    char pad[0x20];
    Bucket buckets[1];
};

extern "C" void func_001E67B0(SpatialGrid *self, int bucket_idx) {
    Bucket *b = &self->buckets[bucket_idx];
    Node *node = b->head;
    while (node != 0) {
        if (b->count + 1 > b->capacity) {
            int cap = b->capacity;
            if (cap <= 0) {
                cap = 1;
            } else {
                cap <<= 1;
            }
            b->capacity = cap;
            void **new_items = (void **)func_100730(cap * sizeof(void *));
            if (new_items != 0) {
                int old_count = b->count;
                if (b->items != 0) {
                    for (int j = 0; j < old_count; j++) {
                        new_items[j] = b->items[j];
                    }
                }
                func_100630(b->items);
                b->items = new_items;
            }
        }
        b->items[b->count++] = node;
        node = node->next;
    }
    b->head = 0;
}
