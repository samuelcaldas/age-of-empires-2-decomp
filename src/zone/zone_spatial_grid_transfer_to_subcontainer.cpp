#pragma exceptions off
#include "zone_spatial_grid_transfer_to_subcontainer.h"

extern "C" {
void *func_100730(unsigned int size);
void func_100630(void *ptr);
}

struct ListNode {
    char pad_0C[0xC];
    ListNode *next;
    ListNode *prev;
};

struct SubContainer {
    void **buffer;
    int count;
    int capacity;
};

struct SpatialGrid {
    char pad_64[0x64];
    SubContainer sub[2];
};

extern "C" void func_001E8A20(SpatialGrid *self, int sub_idx, void *node_ptr) {
    ListNode *node = (ListNode *)node_ptr;
    node->prev->next = node->next;
    if (node->next != 0) {
        node->next->prev = node->prev;
    }
}
