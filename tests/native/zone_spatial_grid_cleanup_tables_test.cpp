#include <cassert>
#include <cstdio>
#include <cstring>
#include <cstdlib>

struct SpatialGrid;

#define func_1F24A0 mock_func_1F24A0
#define func_117CAC mock_func_117CAC
#define func_1F2010 mock_func_1F2010
#define func_1E6380 mock_func_1E6380
#define func_1ED1F0 mock_func_1ED1F0
#define D_004E2E08 mock_D_004E2E08
#define D_00A801D0 mock_D_00A801D0

static int g_1f24a0_count = 0;
static int g_1f2010_count = 0;
static int g_1e6380_count = 0;
static int g_1ed1f0_count = 0;

extern "C" {
void *mock_D_004E2E08 = (void *)0x1234;
char mock_D_00A801D0[0x1000];

void mock_func_1F24A0(SpatialGrid *ptr) { g_1f24a0_count++; }
void mock_func_117CAC(void *dst, int val, int size) { memset(dst, val, size); }
void mock_func_1F2010(SpatialGrid *ptr) { g_1f2010_count++; }
void mock_func_1E6380(SpatialGrid *ptr) { g_1e6380_count++; }
void mock_func_1ED1F0(SpatialGrid *ptr) { g_1ed1f0_count++; }
}

#include "../../src/zone/zone_spatial_grid_cleanup_tables.cpp"

int main() {
    SpatialGrid *grid = (SpatialGrid *)calloc(1, sizeof(SpatialGrid));
    assert(grid != NULL);

    grid->pool = (void *)1;
    grid->mgr = (void *)1;
    grid->cached_nodes[0] = (void *)1;
    grid->cached_nodes[1] = (void *)2;
    grid->cached_nodes[2] = (void *)3;
    grid->cached_nodes[3] = (void *)4;

    int ret = func_001ED840(grid);
    assert(ret == 1);
    assert(g_1f24a0_count == 4);
    assert(g_1f2010_count == 1);
    assert(g_1e6380_count == 1);
    assert(g_1ed1f0_count == 1);
    assert(grid->pool == 0);
    assert(grid->mgr == 0);
    assert(grid->table1 == grid);

    free(grid);
    printf("zone_spatial_grid_cleanup_tables_test passed\n");
    return 0;
}
