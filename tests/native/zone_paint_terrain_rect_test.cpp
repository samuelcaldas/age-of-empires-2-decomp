#include <cassert>
#include <cstddef>
#include <cstring>
#include <string>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001CF9B0(
    void *self, void *world, void *player, short x0, short y0, short x1, short y1,
    int terrain_type, unsigned char flag
);

static int g_func_314ea0_calls = 0;
static int g_func_1cdf30_calls = 0;
static int g_func_1d1cc0_calls = 0;
static int g_func_1d00c0_calls = 0;
static int g_func_1c9e00_calls = 0;

void func_314EA0(short *x0, short *y0, short *x1, short *y1, int min_x, int min_y, int max_x, int max_y) {
    g_func_314ea0_calls++;
    if (*x0 < min_x) *x0 = min_x;
    if (*y0 < min_y) *y0 = min_y;
    if (*x1 > max_x) *x1 = max_x;
    if (*y1 > max_y) *y1 = max_y;
}

void func_1CDF30(void *self, void *world, void *player, int y, int x, int terrain, int flag_delete_mode, int range_min, int range_max) {
    g_func_1cdf30_calls++;
}

void func_1D1CC0(void *self, void *cell) { g_func_1d1cc0_calls++; }
void func_1D00C0(void *self, int x, int y) { g_func_1d00c0_calls++; }
void func_1C9E00(void *self, int x0, int y0, int x1, int y1, int flag) { g_func_1c9e00_calls++; }
}

static void reset_test_state() {
    g_func_314ea0_calls = 0; g_func_1cdf30_calls = 0;
    g_func_1d1cc0_calls = 0; g_func_1d00c0_calls = 0;
    g_func_1c9e00_calls = 0;
}

static void setup_zone(char *zone_mem, char *cells_grid, int width, int height) {
    std::memset(zone_mem, 0, 0x10000);
    std::memset(cells_grid, 0, width * height * 28);

    *reinterpret_cast<int *>(zone_mem + 0x8) = width;
    *reinterpret_cast<int *>(zone_mem + 0xC) = height;
    *reinterpret_cast<short *>(zone_mem + 0x8EA8) = 32; // max_terrain = 32

    static char *row_ptrs[16];
    for (int r = 0; r < height; r++) {
        row_ptrs[r] = cells_grid + r * width * 28;
    }
    *reinterpret_cast<char ***>(zone_mem + 0x8E8C) = row_ptrs;
}

static void test_paint_rect_flow() {
    reset_test_state();
    char zone_mem[0x10000], cells_grid[10 * 10 * 28];
    setup_zone(zone_mem, cells_grid, 10, 10);

    // Active terrain 5
    char *entry = zone_mem + 5 * 416;
    entry[0x8C] = 1;

    char dummy_world[0x100] = {}, dummy_player[0x100] = {};

    func_001CF9B0(zone_mem, dummy_world, dummy_player, 2, 2, 3, 3, 5, 0);

    assert(g_func_314ea0_calls == 1);
    // 2x2 = 4 cells painted with terrain 5
    assert(g_func_1cdf30_calls == 4);
    assert(g_func_1c9e00_calls == 1); // raster extent updated
    assert(g_func_1d00c0_calls >= 4); // surrounding tiles updated
}

static void test_oob_terrain_skips() {
    reset_test_state();
    char zone_mem[0x10000], cells_grid[10 * 10 * 28];
    setup_zone(zone_mem, cells_grid, 10, 10);

    char dummy_world[0x100] = {}, dummy_player[0x100] = {};

    // Terrain 50 >= max_terrain (32)
    func_001CF9B0(zone_mem, dummy_world, dummy_player, 2, 2, 3, 3, 50, 0);

    assert(g_func_314ea0_calls == 0);
    assert(g_func_1cdf30_calls == 0);
    assert(g_func_1c9e00_calls == 0);
}

int main(int argc, char **argv) {
    if (argc > 1 && std::string(argv[1]) == "oob_terrain") {
        test_oob_terrain_skips();
    } else {
        test_paint_rect_flow();
        test_oob_terrain_skips();
    }
    return 0;
}
