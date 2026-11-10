#include <cassert>
#include <cstdlib>
#include <cstring>
#include <vector>
#include "zone_spatial_grid_compact_bucket.h"

// Concrete definitions matching src/zone/zone_spatial_grid_compact_bucket.cpp
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

// Memory mocks
extern "C" {
void *func_100730(unsigned int size) {
    return std::malloc(size);
}

void func_100630(void *ptr) {
    std::free(ptr);
}
}

int main() {
    // SpatialGrid layout in func_001E6B10:
    // BucketList *b = (BucketList *)((char *)self + bucket_idx * 0x28);
    // DynamicArray *arr = (DynamicArray *)((char *)self + 0x64 + bucket_idx * 0xC);
    // So for bucket_idx = 0: b is at self + 0, arr is at self + 0x64
    char grid_buf[0x200];
    std::memset(grid_buf, 0, sizeof(grid_buf));
    SpatialGrid *grid = reinterpret_cast<SpatialGrid *>(grid_buf);

    BucketList *b0 = reinterpret_cast<BucketList *>(grid_buf);
    DynamicArray *arr0 = reinterpret_cast<DynamicArray *>(grid_buf + 0x64);

    GridNode node1;
    std::memset(&node1, 0, sizeof(node1));
    node1.cell_x = 10;
    node1.cell_y = 20;

    GridNode node2;
    std::memset(&node2, 0, sizeof(node2));
    node2.cell_x = 30;
    node2.cell_y = 40;

    node1.next = &node2;
    node2.next = NULL;
    b0->head = &node1;

    // Call compact bucket
    func_001E6B10(grid, 0);

    // Verify bucket head cleared
    assert(b0->head == NULL);

    // Verify items copied to arr0
    assert(arr0->count == 2);
    assert(arr0->capacity >= 2);
    assert(arr0->items[0] == &node1);
    assert(arr0->items[1] == &node2);

    // Verify node cells reset to -1
    assert(node1.cell_x == -1);
    assert(node1.cell_y == -1);
    assert(node2.cell_x == -1);
    assert(node2.cell_y == -1);

    // Cleanup dynamic array
    func_100630(arr0->items);

    return 0;
}
