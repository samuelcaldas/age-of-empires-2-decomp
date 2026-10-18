#include <cassert>
#include <cstring>
#include "zone_spatial_grid_clear_active_markers.h"
#include "zone_spatial_grid_insert_marker_node.h"
#include "zone_spatial_grid_mark_bounds_region.h"

static int g_func_1EE780_called = 0;
static int g_func_1F2320_called = 0;
static int g_func_117CAC_called = 0;
static int g_func_123350_called = 0;
static int g_func_1EE130_called = 0;

extern "C" {
void func_1EE780(SpatialGrid *self, MarkerNode *node) {
    g_func_1EE780_called++;
}

void *func_1F2320(void *pool) {
    g_func_1F2320_called++;
    return (void *)0xFEED;
}

void func_117CAC(void *dst, int val, int size) {
    g_func_117CAC_called++;
    memset(dst, val, size);
}

int func_123350(float val) {
    g_func_123350_called++;
    return (int)val;
}

int func_1EE130(SpatialGrid *self, int x, int y) {
    g_func_1EE130_called++;
    return 1;
}
}

struct MockMarkerNode {
    char pad_00[0xC];
    MockMarkerNode *next;
    char pad_10[8];
    unsigned char y;
    unsigned char x;
    char pad_1A[2];
};

struct DummyGrid46 {
    char pad_00[0x12B438];
    int **grid;
    char pad_after[0x12B5AC - 0x12B438 - 4];
    int marker_count;
    char pad_after2[0x12B5AC - 0x12B454 - 4];
    MockMarkerNode *active_list;
};

int main() {
    // -------------------------------------------------------------
    // Test 1: func_001EE080 - clear active markers
    // -------------------------------------------------------------
    int cell_val = 0x80;
    int *grid_row = &cell_val;
    int *grid_rows[1] = { grid_row };

    MockMarkerNode node2;
    memset(&node2, 0, sizeof(node2));
    node2.next = 0;
    node2.y = 0;
    node2.x = 0;

    MockMarkerNode node1;
    memset(&node1, 0, sizeof(node1));
    node1.next = &node2;
    node1.y = 0;
    node1.x = 0;

    struct FullGridMock {
        char pad_00[0x12B438];
        int **grid;
        char pad_count[0x12B43C - 0x12B438 - 4];
        int count;
        char pad_after[0x12B5AC - 0x12B43C - 4];
        MockMarkerNode *active_list;
    } mock_grid;
    memset(&mock_grid, 0, sizeof(mock_grid));
    mock_grid.grid = grid_rows;
    mock_grid.active_list = &node1;
    mock_grid.count = 2;

    g_func_1EE780_called = 0;
    func_001EE080((SpatialGrid *)&mock_grid);
    assert(g_func_1EE780_called == 2);
    assert(mock_grid.count == 0);
    assert(mock_grid.active_list == 0);

    // -------------------------------------------------------------
    // Test 2: func_001EE360 - mark bounds region
    // -------------------------------------------------------------
    g_func_123350_called = 0;
    g_func_1EE130_called = 0;

    int res_mark = func_001EE360((SpatialGrid *)&mock_grid, 10.0f, 10.0f, 12.0f, 12.0f, 1);
    assert(res_mark >= 0);
    assert(g_func_123350_called == 4);

    return 0;
}
