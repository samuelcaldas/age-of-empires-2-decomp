#include <cassert>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include "zone_spatial_grid_buffer_manager_remove.h"

struct ElementTeam;
struct Element;

struct SpatialGridBufferManager {
    ElementTeam *owner;       // 0x000
    Element *elems[200];      // 0x004
    void *ptrs[200];          // 0x324
    int vals[200];            // 0x644
    short shorts[200];        // 0x964
    short cap;                // 0xAF4
    short count;              // 0xAF6
};

static void test_layout() {
    assert(offsetof(SpatialGridBufferManager, owner) == 0x000);
    assert(offsetof(SpatialGridBufferManager, elems) == 0x004);
    assert(offsetof(SpatialGridBufferManager, ptrs) == 0x324);
    assert(offsetof(SpatialGridBufferManager, vals) == 0x644);
    assert(offsetof(SpatialGridBufferManager, shorts) == 0x964);
    assert(offsetof(SpatialGridBufferManager, cap) == 0xAF4);
    assert(offsetof(SpatialGridBufferManager, count) == 0xAF6);
    assert(sizeof(SpatialGridBufferManager) == 0xAF8);
}

static void test_remove_empty() {
    SpatialGridBufferManager mgr;
    std::memset(&mgr, 0, sizeof(mgr));
    mgr.count = 0;

    int dummy = 42;
    int ret = func_001ECD10(&mgr, &dummy);
    assert(ret == 0);
    assert(mgr.count == 0);
}

static void test_remove_not_found() {
    SpatialGridBufferManager mgr;
    std::memset(&mgr, 0, sizeof(mgr));
    mgr.count = 2;

    int d1 = 1, d2 = 2, d3 = 3;
    mgr.elems[0] = (Element *)&d1;
    mgr.elems[1] = (Element *)&d2;

    int ret = func_001ECD10(&mgr, &d3);
    assert(ret == 0);
    assert(mgr.count == 2);
    assert(mgr.elems[0] == (Element *)&d1);
    assert(mgr.elems[1] == (Element *)&d2);
}

static void test_remove_last_element() {
    SpatialGridBufferManager mgr;
    std::memset(&mgr, 0, sizeof(mgr));
    mgr.count = 2;

    int d1 = 10, d2 = 20;
    mgr.elems[0] = (Element *)&d1;
    mgr.ptrs[0] = &d1;
    mgr.vals[0] = 100;
    mgr.shorts[0] = 1000;

    mgr.elems[1] = (Element *)&d2;
    mgr.ptrs[1] = &d2;
    mgr.vals[1] = 200;
    mgr.shorts[1] = 2000;

    int ret = func_001ECD10(&mgr, &d2);
    assert(ret == 1);
    assert(mgr.count == 1);
    assert(mgr.elems[0] == (Element *)&d1);
    assert(mgr.ptrs[0] == &d1);
    assert(mgr.vals[0] == 100);
    assert(mgr.shorts[0] == 1000);

    // Slot 1 zeroed
    assert(mgr.elems[1] == 0);
    assert(mgr.ptrs[1] == 0);
    assert(mgr.vals[1] == 0);
    assert(mgr.shorts[1] == 0);
}

static void test_remove_middle_element_shifts_last() {
    SpatialGridBufferManager mgr;
    std::memset(&mgr, 0, sizeof(mgr));
    mgr.count = 3;

    int d1 = 10, d2 = 20, d3 = 30;
    mgr.elems[0] = (Element *)&d1;
    mgr.ptrs[0] = &d1;
    mgr.vals[0] = 100;
    mgr.shorts[0] = 1000;

    mgr.elems[1] = (Element *)&d2;
    mgr.ptrs[1] = &d2;
    mgr.vals[1] = 200;
    mgr.shorts[1] = 2000;

    mgr.elems[2] = (Element *)&d3;
    mgr.ptrs[2] = &d3;
    mgr.vals[2] = 300;
    mgr.shorts[2] = 3000;

    // Remove element 1 (d2) -> element 2 (d3) is moved into slot 1
    int ret = func_001ECD10(&mgr, &d2);
    assert(ret == 1);
    assert(mgr.count == 2);

    // Slot 0 untouched
    assert(mgr.elems[0] == (Element *)&d1);
    assert(mgr.ptrs[0] == &d1);
    assert(mgr.vals[0] == 100);
    assert(mgr.shorts[0] == 1000);

    // Slot 1 receives slot 2
    assert(mgr.elems[1] == (Element *)&d3);
    assert(mgr.ptrs[1] == &d3);
    assert(mgr.vals[1] == 300);
    assert(mgr.shorts[1] == 3000);

    // Slot 2 zeroed
    assert(mgr.elems[2] == 0);
    assert(mgr.ptrs[2] == 0);
    assert(mgr.vals[2] == 0);
    assert(mgr.shorts[2] == 0);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_layout();
        test_remove_empty();
        test_remove_not_found();
        test_remove_last_element();
        test_remove_middle_element_shifts_last();
        return 0;
    }

    int test_case = std::atoi(argv[1]);
    switch (test_case) {
    case 0:
        test_layout();
        break;
    case 1:
        test_remove_empty();
        break;
    case 2:
        test_remove_not_found();
        break;
    case 3:
        test_remove_last_element();
        break;
    case 4:
        test_remove_middle_element_shifts_last();
        break;
    default:
        return 1;
    }
    return 0;
}
