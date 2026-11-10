#include <cassert>
#include <cstring>
#include <iostream>
#include "zone_spatial_grid_query_ray_intersection.h"

// Define external symbols referenced by func_001EC360
extern "C" {
int func_00123350(float val) {
    return (int)val;
}

int func_269E50(void *grid_obj, int ix, int iy) {
    return (ix + iy) & 0xFF;
}
}

int main() {
    // Setup mock items
    struct MockInfo {
        char pad[8];
        short type;
    };
    MockInfo info1;
    info1.type = 10;

    MockInfo info2;
    info2.type = 20;

    struct MockItem {
        void *vtable;
        MockInfo *info;
        char pad_08[0x39 - 8];
        unsigned char mode;
        char pad_3a[0x44 - 0x3a];
        float x;
        float y;
    };

    MockItem item1;
    std::memset(&item1, 0, sizeof(item1));
    item1.info = &info1;
    item1.mode = 1;
    item1.x = 5.0f;
    item1.y = 5.0f;

    MockItem item2;
    std::memset(&item2, 0, sizeof(item2));
    item2.info = &info2;
    item2.mode = 2;
    item2.x = 10.0f;
    item2.y = 10.0f;

    void *items[2] = { &item1, &item2 };

    struct MockCell {
        void **items_list;
        short count;
    };

    MockCell cell;
    cell.items_list = items;
    cell.count = 2;

    // Test 1: Query with target_type 10, no filter
    void *res1 = func_001EC360(&cell, 10, 0, 0, 0, -1.0f, -1.0f);
    assert(res1 == &item1);

    // Test 2: Query with non-matching target_type
    void *res2 = func_001EC360(&cell, 99, 0, 0, 0, -1.0f, -1.0f);
    assert(res2 == 0);

    // Test 3: Query with filter flag matching
    void *res3 = func_001EC360(&cell, 10, 1, 1, 0, -1.0f, -1.0f);
    assert(res3 == &item1);

    // Test 4: Query with filter flag not matching
    void *res4 = func_001EC360(&cell, 10, 1, 2, 0, -1.0f, -1.0f);
    assert(res4 == 0);

    // Test 5: Distance calculation
    void *res5 = func_001EC360(&cell, 10, 0, 0, 0, 6.0f, 6.0f);
    assert(res5 == &item1);

    std::cout << "zone_spatial_grid_query_ray_intersection_test passed\n";
    return 0;
}
