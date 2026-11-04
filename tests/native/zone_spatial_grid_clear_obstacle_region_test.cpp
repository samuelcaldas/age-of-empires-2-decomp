#include <cassert>
#include <cstdlib>
#include <cstring>
#include "zone_spatial_grid_clear_obstacle_region.h"

typedef void (*ObstacleCallback)(void *ctx);

struct SpatialGrid {
    char pad_00[0x12B438];
    int **grid_table;
    char pad_after[0x12B5A4 - 0x12B438 - 4];
    ObstacleCallback callback_fn;
    void *callback_ctx;
};

static int s_callback_invoked = 0;
static void *s_callback_arg = NULL;

static void test_callback(void *ctx) {
    s_callback_invoked++;
    s_callback_arg = ctx;
}

int main() {
    SpatialGrid *grid = (SpatialGrid *)std::malloc(sizeof(SpatialGrid));
    std::memset(grid, 0, sizeof(SpatialGrid));

    int row0[4] = {0x12345678, 0x11223344, 0x55667788, 0x778899AA};
    int row1[4] = {0x01020304, 0x0A0B0C0D, 0x0E0F1011, 0x12131415};
    int *rows[2] = {row0, row1};

    grid->grid_table = rows;
    grid->callback_fn = test_callback;
    grid->callback_ctx = (void *)0xBEEF;

    int res = func_001EE670(grid, 1, 0, 2, 1);
    assert(res == 1);
    assert(s_callback_invoked == 1);
    assert(s_callback_arg == (void *)0xBEEF);

    // Row 0, col 1: was 0x11223344 -> low byte 0x44 (assuming little endian x86/MIPS)
    assert(row0[0] == 0x12345678); // unchanged
    assert(row0[1] == (int)(unsigned char)0x44);
    assert(row0[2] == (int)(unsigned char)0x88);
    assert(row0[3] == 0x778899AA); // unchanged

    // Row 1, col 1: was 0x0A0B0C0D -> 0x0D
    assert(row1[0] == 0x01020304); // unchanged
    assert(row1[1] == (int)(unsigned char)0x0D);
    assert(row1[2] == (int)(unsigned char)0x11);
    assert(row1[3] == 0x12131415); // unchanged

    std::free(grid);
    return 0;
}
