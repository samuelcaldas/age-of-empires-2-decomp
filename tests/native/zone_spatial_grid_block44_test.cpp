#include <cassert>
#include <cstring>
#include "zone_spatial_grid_init_tables.h"
#include "zone_spatial_grid_cleanup_tables.h"
#include "zone_spatial_grid_sync_terrain_types.h"

static int g_func_117CAC_called = 0;
static int g_func_1F1ED0_called = 0;
static int g_func_1E6340_called = 0;
static int g_func_1F2320_called = 0;
static int g_func_1F24A0_called = 0;
static int g_func_1F2010_called = 0;
static int g_func_1E6380_called = 0;
static int g_func_1ED1F0_called = 0;

extern "C" {
void func_117CAC(void *dst, int val, int size) {
    g_func_117CAC_called++;
    memset(dst, val, size);
}

int func_1F1ED0(SpatialGrid *self) {
    g_func_1F1ED0_called++;
    return 1;
}

int func_1E6340(SpatialGrid *self) {
    g_func_1E6340_called++;
    return 1;
}

int func_1F2320(SpatialGrid *self) {
    g_func_1F2320_called++;
    return 1;
}

void func_1F24A0(SpatialGrid *self) {
    g_func_1F24A0_called++;
}

void func_1F2010(SpatialGrid *self) {
    g_func_1F2010_called++;
}

void func_1E6380(SpatialGrid *self) {
    g_func_1E6380_called++;
}

void func_1ED1F0(SpatialGrid *self) {
    g_func_1ED1F0_called++;
}
}

struct DummyGrid44 {
    char pad_00[0x27100];
    char buffer_27100[0x320];
    char buffer_27420[0x3FFC];
    char pad_after[0x12B41C - 0x27100 - 0x320 - 0x3FFC];
    char is_initialized;
    char pad_align[3];
    GameWorld *world;
    int width;
    int height;
    float f_width;
    float f_height;
    void *table1;
    void *table2;
    int level_count;
    void *nodes_table;
    int total_nodes;
    char pad_levels[0x12B570 - 0x12B450];
    void *mgr;
    char pad_12B574[4];
    void *pool;
    void *buffer_12B31C;
    int field_12B580;
    char pad_12B584[0x12B5B4 - 0x12B580 - 4];
    void *cached_nodes[4];
};

extern "C" {
extern void *D_004E2E08;
}

int main() {
    D_004E2E08 = (void *)0x12345678;

    // Test 1: func_001ED3D0 - initialization of spatial grid dimensions & tables
    WorldMapInfo map;
    map.width = 100;
    map.height = 100;
    GameWorld world;
    world.map_info = &map;

    DummyGrid44 grid;
    memset(&grid, 0, sizeof(grid));

    g_func_117CAC_called = 0;
    g_func_1F1ED0_called = 0;
    g_func_1E6340_called = 0;
    g_func_1F2320_called = 0;

    int res_init = func_001ED3D0((SpatialGrid *)&grid, &world);
    assert(res_init == 1);
    assert(grid.world == &world);
    assert(grid.width == 100);
    assert(grid.height == 100);
    assert(grid.f_width == 100.0f);
    assert(grid.f_height == 100.0f);
    assert(g_func_117CAC_called >= 1);
    assert(g_func_1F1ED0_called == 1);
    assert(g_func_1E6340_called == 1);
    assert(g_func_1F2320_called == 4);

    // Test 2: func_001ED840 - cleanup tables
    g_func_1F24A0_called = 0;
    g_func_1F2010_called = 0;
    g_func_1E6380_called = 0;
    g_func_1ED1F0_called = 0;

    int res_cleanup = func_001ED840((SpatialGrid *)&grid);
    assert(res_cleanup == 1);
    assert(g_func_1F24A0_called == 4);
    assert(g_func_1F2010_called == 1);
    assert(g_func_1E6380_called == 1);
    assert(g_func_1ED1F0_called == 1);

    // Test 3: func_001ED9C0 - sync terrain types
    struct MockTile {
        char pad[5];
        unsigned char type;
        char pad2[22];
    } mock_tiles[4];
    memset(mock_tiles, 0, sizeof(mock_tiles));
    mock_tiles[0].type = 1;
    mock_tiles[1].type = 2;

    MockTile *mock_tile_rows[2] = { &mock_tiles[0], &mock_tiles[2] };
    struct MockMap {
        char pad[0x8E8C];
        MockTile **tile_rows;
    } mock_map;
    mock_map.tile_rows = mock_tile_rows;

    struct MockWorldObj {
        char pad[0x3C];
        char *map_ptr;
    } mock_world_obj;
    mock_world_obj.map_ptr = (char *)&mock_map;

    int cell_row0[2] = { 0, 0 };
    int cell_row1[2] = { 0, 0 };
    int *grid_rows[2] = { cell_row0, cell_row1 };

    struct MockSpatialGridSync {
        char pad_00[0x12B420];
        MockWorldObj *world;
        int width;
        int height;
        char pad_12B42C[8];
        void *table1;
        int **grid_rows;
    } sync_grid;
    memset(&sync_grid, 0, sizeof(sync_grid));
    sync_grid.world = &mock_world_obj;
    sync_grid.width = 2;
    sync_grid.height = 2;
    sync_grid.grid_rows = grid_rows;

    int res_sync = func_001ED9C0((SpatialGrid *)&sync_grid);
    assert(res_sync == 1);

    return 0;
}
