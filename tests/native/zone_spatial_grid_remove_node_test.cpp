#include <cassert>
#include "zone_spatial_grid_remove_node.h"

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

static void *g_last_pool = nullptr;

extern "C" void func_1F24A0(void *pool) {
    g_last_pool = pool;
}

struct Node {
    char pad_00[7];
    unsigned char field_7;
    char pad_08[8];
    int cell_idx;
    int list_idx;
};

struct PyramidCell {
    Node **items;
    int count;
    int capacity;
};

struct SpatialGrid {
    char pad_00[0x12B440];
    int field_12B440;
    char pad_after[0x12B448 - 0x12B440 - 4];
    PyramidCell *cells;
    char pad_after2[0x12B578 - 0x12B448 - 4];
    void *pool;
};

int main() {
    SpatialGrid grid;
    grid.field_12B440 = 10;
    grid.pool = (void *)0x12345678;

    PyramidCell cells[2];
    Node *items[3];
    Node n0, n1, n2;

    n0.field_7 = 0;
    n0.cell_idx = 0;
    n0.list_idx = 0;

    n1.field_7 = 0xED;
    n1.cell_idx = 0;
    n1.list_idx = 1;

    n2.field_7 = 0;
    n2.cell_idx = 0;
    n2.list_idx = 2;

    items[0] = &n0;
    items[1] = &n1;
    items[2] = &n2;

    cells[0].items = items;
    cells[0].count = 3;
    cells[0].capacity = 5;

    grid.cells = cells;

    // Test removing null node
    func_001EE790(&grid, nullptr);
    assert(g_last_pool == nullptr);

    // Test removing n1 (list_idx = 1)
    func_001EE790(&grid, &n1);
    assert(cells[0].count == 2);
    assert(cells[0].items[1] == &n2);
    assert(n2.list_idx == 1);
    assert(grid.field_12B440 == 9);
    assert(g_last_pool == (void *)0x12345678);

    return 0;
}
