#include <cassert>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include "zone_spatial_grid_clear_active_markers.h"

struct MarkerNode {
    char pad_00[0xC];
    MarkerNode *next;
    char pad_10[8];
    unsigned int coord;
};

struct SpatialGrid {
    char pad_00[0x12B438];
    int **grid_table;
    int marker_count;
    char pad_after[0x12B5AC - 0x12B43C - 4];
    MarkerNode *marker_head;
};

extern "C" {
static int g_func_1EE780_calls = 0;
static void *g_func_1EE780_self = nullptr;
static MarkerNode *g_func_1EE780_last_node = nullptr;

void func_001EE780(SpatialGrid *self, MarkerNode *node) {
    g_func_1EE780_calls++;
    g_func_1EE780_self = self;
    g_func_1EE780_last_node = node;
}
}

static void test_layout() {
    assert(offsetof(MarkerNode, next) == 0x0C);
    assert(offsetof(MarkerNode, coord) == 0x18);
    assert(offsetof(SpatialGrid, grid_table) == 0x12B438);
    assert(offsetof(SpatialGrid, marker_count) == 0x12B43C);
    assert(offsetof(SpatialGrid, marker_head) == 0x12B5AC);
}

static void test_clear_active_markers_empty() {
    g_func_1EE780_calls = 0;
    g_func_1EE780_self = nullptr;
    g_func_1EE780_last_node = nullptr;

    SpatialGrid *grid = (SpatialGrid *)std::malloc(sizeof(SpatialGrid));
    assert(grid != nullptr);
    std::memset(grid, 0, sizeof(SpatialGrid));
    grid->marker_count = 0;
    grid->marker_head = nullptr;

    func_001EE080(grid);

    assert(g_func_1EE780_calls == 0);
    assert(grid->marker_head == nullptr);
    assert(grid->marker_count == 0);

    std::free(grid);
}

static void test_clear_active_markers_with_nodes() {
    g_func_1EE780_calls = 0;
    g_func_1EE780_self = nullptr;
    g_func_1EE780_last_node = nullptr;

    SpatialGrid *grid = (SpatialGrid *)std::malloc(sizeof(SpatialGrid));
    assert(grid != nullptr);
    std::memset(grid, 0, sizeof(SpatialGrid));

    // Allocate 2D grid table
    int *row5 = (int *)std::calloc(20, sizeof(int));
    int *row8 = (int *)std::calloc(20, sizeof(int));
    int **table = (int **)std::calloc(16, sizeof(int *));
    table[5] = row5;
    table[8] = row8;

    row5[10] = 0x80; // (x=10, y=5)
    row8[3] = 0x00;  // (x=3, y=8)

    MarkerNode node2;
    std::memset(&node2, 0, sizeof(node2));
    node2.next = nullptr;
    node2.coord = (3 << 8) | 8; // x=3, y=8

    MarkerNode node1;
    std::memset(&node1, 0, sizeof(node1));
    node1.next = &node2;
    node1.coord = (10 << 8) | 5; // x=10, y=5

    grid->grid_table = table;
    grid->marker_count = 2;
    grid->marker_head = &node1;

    func_001EE080(grid);

    assert(g_func_1EE780_calls == 2);
    assert(grid->marker_head == nullptr);
    assert(grid->marker_count == 0);

    // Toggled coordinates
    assert(row5[10] == 0x00); // 0x80 ^ 0x80 = 0
    assert(row8[3] == 0x80);  // 0x00 ^ 0x80 = 0x80

    std::free(row5);
    std::free(row8);
    std::free(table);
    std::free(grid);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        return 1;
    }
    int case_id = std::atoi(argv[1]);
    switch (case_id) {
    case 0:
        test_layout();
        break;
    case 1:
        test_clear_active_markers_empty();
        break;
    case 2:
        test_clear_active_markers_with_nodes();
        break;
    default:
        return 2;
    }
    std::cout << "PASS" << std::endl;
    return 0;
}
