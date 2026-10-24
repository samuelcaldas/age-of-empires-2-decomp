#pragma exceptions off
#include "zone_spatial_grid_compact_bucket.h"

extern "C" {
void *func_100730(unsigned int size);
void func_100630(void *ptr);
}

struct GridNode {
    char pad_C[0xC];
    GridNode *next;
    char pad_1C[0xC];
    int cell_x;
    int cell_y;
};

struct BucketList {
    char pad_20[0x20];
    GridNode *head;
};

struct DynamicArray {
    GridNode **items;
    int count;
    int capacity;
};

struct SpatialGrid {
    BucketList buckets[1];
};

extern "C" void func_001E6B10(SpatialGrid *self, int bucket_idx) {
    BucketList *b = (BucketList *)((char *)self + bucket_idx * 0x28);
    DynamicArray *arr = (DynamicArray *)((char *)self + 0x64 + bucket_idx * 0xC);
    GridNode *node = b->head;
    while (node != 0) {
        if (arr->count + 1 > arr->capacity) {
            int cap = arr->capacity;
            if (cap <= 0) {
                cap = 1;
            } else {
                cap <<= 1;
            }
            arr->capacity = cap;
            GridNode **new_items = (GridNode **)func_100730(cap * sizeof(GridNode *));
            if (new_items != 0) {
                int old_count = arr->count;
                if (arr->items != 0) {
                    for (int j = 0; j < old_count; j++) {
                        new_items[j] = arr->items[j];
                    }
                }
                func_100630(arr->items);
                arr->items = new_items;
            }
        }
        arr->items[arr->count++] = node;
        node = node->next;
    }
    b->head = 0;
    for (int i = 0; i < arr->count; i++) {
        arr->items[i]->cell_x = -1;
        arr->items[i]->cell_y = -1;
    }
}
