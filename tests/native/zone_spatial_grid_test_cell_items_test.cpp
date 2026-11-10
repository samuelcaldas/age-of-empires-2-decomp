#include <cassert>
#include <cstdlib>
#include <cstring>
#include "zone_spatial_grid_test_cell_items.h"

static int s_func_1F0A10_calls = 0;
static int s_func_1F1190_calls = 0;

extern "C" {
int func_1F0A10(SpatialGrid *self, void *item, void *p3) {
    (void)self; (void)item; (void)p3;
    s_func_1F0A10_calls++;
    return 1;
}

int func_1F1190(SpatialGrid *self, void *item, void *p3) {
    (void)self; (void)item; (void)p3;
    s_func_1F1190_calls++;
    return 1;
}
}

struct SpatialNode {
    int type;
    unsigned char mode;
    unsigned char field_5;
    unsigned char field_6;
    unsigned char field_7;
    void *entity;
};

struct PyramidCell {
    SpatialNode **items;
    int count;
    int capacity;
};

struct SpatialGridMock {
    char pad_00[0x12B448];
    PyramidCell *cells;
    char pad_after[0x12B5B0 - 0x12B448 - 4];
    void *query_target;
};

int main() {
    SpatialGridMock *grid = (SpatialGridMock *)std::malloc(sizeof(SpatialGridMock));
    std::memset(grid, 0, sizeof(SpatialGridMock));

    SpatialNode node1;
    std::memset(&node1, 0, sizeof(node1));
    node1.type = 1;
    node1.entity = (void *)0x1234;

    SpatialNode *items[1] = {&node1};
    PyramidCell cells[1];
    cells[0].items = items;
    cells[0].count = 1;
    cells[0].capacity = 1;

    grid->cells = cells;
    grid->query_target = (void *)0x1234; // same entity -> should skip

    SpatialGrid *self = reinterpret_cast<SpatialGrid *>(grid);

    // Case 1: node->entity == query_target -> skipped -> returns 0
    int res = func_001EEEB0(self, 0, 0, NULL, 0);
    assert(res == 0);
    assert(s_func_1F0A10_calls == 0);

    // Case 2: node->entity != query_target -> calls func_1F0A10 -> returns 1
    grid->query_target = (void *)0x9999;
    res = func_001EEEB0(self, 0, 0, NULL, 0);
    assert(res == 1);
    assert(s_func_1F0A10_calls == 1);

    std::free(grid);
    return 0;
}
