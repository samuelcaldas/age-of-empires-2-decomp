#include <cassert>
#include <cstddef>
#include "zone_spatial_grid_lookup.h"

struct ZoneSpatialGrid {};

static ZoneSpatialGrid *expected_self = 0;
static void *expected_item = 0;
static void *mock_return_node = 0;
static int call_count = 0;

extern "C" void *func_001F2E00(ZoneSpatialGrid *self, void *item) {
    ++call_count;
    assert(self == expected_self);
    assert(item == expected_item);
    return mock_return_node;
}

int main() {
    ZoneSpatialGrid dummy_grid;
    int dummy_item = 0x12345678;
    expected_self = &dummy_grid;
    expected_item = &dummy_item;

    // Case 1: func_001F2E00 returns NULL -> func_001F2700 must return NULL
    mock_return_node = 0;
    call_count = 0;
    void *result = func_001F2700(&dummy_grid, &dummy_item);
    assert(call_count == 1);
    assert(result == 0);

    // Case 2: func_001F2E00 returns a valid node -> func_001F2700 returns node[0]
    void *node_storage[3];
    int target_entity = 0xdeadbeef;
    node_storage[0] = &target_entity;
    node_storage[1] = 0;
    node_storage[2] = 0;

    mock_return_node = node_storage;
    call_count = 0;
    result = func_001F2700(&dummy_grid, &dummy_item);
    assert(call_count == 1);
    assert(result == &target_entity);

    // Case 3: Dynamic mutation of node[0]
    int another_entity = 0xfeedface;
    node_storage[0] = &another_entity;
    call_count = 0;
    result = func_001F2700(&dummy_grid, &dummy_item);
    assert(call_count == 1);
    assert(result == &another_entity);

    return 0;
}
