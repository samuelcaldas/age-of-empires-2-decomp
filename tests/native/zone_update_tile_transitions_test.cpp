#include <cassert>
#include <cstddef>
#include <cstring>
#include <string>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001D00C0(void *self, int x, int y);

static int g_func_1d1cc0_calls = 0;

void func_1D1CC0(void *self, void *cell) {
    g_func_1d1cc0_calls++;
}
}

static void reset_test_state() {
    g_func_1d1cc0_calls = 0;
}

static void setup_grid(char *zone_mem, char *cells_grid, int width, int height) {
    std::memset(zone_mem, 0, 0x10000);
    std::memset(cells_grid, 0, width * height * 28);

    *reinterpret_cast<int *>(zone_mem + 0x8) = width;
    *reinterpret_cast<int *>(zone_mem + 0xC) = height;

    static char *row_ptrs[10];
    for (int r = 0; r < height; r++) {
        row_ptrs[r] = cells_grid + r * width * 28;
    }
    *reinterpret_cast<char ***>(zone_mem + 0x8E8C) = row_ptrs;

    // Set fallback = -1 for all terrain tables
    for (int t = 0; t < 32; t++) {
        *reinterpret_cast<short *>(zone_mem + t * 416 + 0x14C) = -1;
    }
}

static void test_transitions_3x3_window() {
    reset_test_state();
    char zone_mem[0x10000], cells_grid[10 * 10 * 28];
    setup_grid(zone_mem, cells_grid, 10, 10);

    // Set cell->f_10 != 0 for center and all 8 neighbors to trigger func_1D1CC0
    for (int dy = 2; dy <= 4; dy++) {
        for (int dx = 2; dx <= 4; dx++) {
            *reinterpret_cast<int *>(cells_grid + dy * 10 * 28 + dx * 28 + 0x10) = 1;
        }
    }

    func_001D00C0(zone_mem, 3, 3);

    // Center cell (1) + 3x3 neighbors (9) = 10 calls to func_1D1CC0
    assert(g_func_1d1cc0_calls >= 9);
}

static void test_out_of_bounds_aborts() {
    reset_test_state();
    char zone_mem[0x10000], cells_grid[10 * 10 * 28];
    setup_grid(zone_mem, cells_grid, 10, 10);

    func_001D00C0(zone_mem, -1, 3);
    assert(g_func_1d1cc0_calls == 0);

    func_001D00C0(zone_mem, 10, 3);
    assert(g_func_1d1cc0_calls == 0);

    func_001D00C0(zone_mem, 3, -1);
    assert(g_func_1d1cc0_calls == 0);

    func_001D00C0(zone_mem, 3, 10);
    assert(g_func_1d1cc0_calls == 0);
}

static void test_fallback_terrain_resolved() {
    reset_test_state();
    char zone_mem[0x10000], cells_grid[10 * 10 * 28];
    setup_grid(zone_mem, cells_grid, 10, 10);

    // Terrain 4 has fallback = 8
    *reinterpret_cast<short *>(zone_mem + 4 * 416 + 0x14C) = 8;
    // Set center cell terrain to 4
    cells_grid[3 * 10 * 28 + 3 * 28 + 5] = 4;
    *reinterpret_cast<int *>(cells_grid + 3 * 10 * 28 + 3 * 28 + 0x10) = 1;

    func_001D00C0(zone_mem, 3, 3);
    assert(g_func_1d1cc0_calls >= 1);
}

int main(int argc, char **argv) {
    if (argc > 1 && std::string(argv[1]) == "oob") {
        test_out_of_bounds_aborts();
    } else if (argc > 1 && std::string(argv[1]) == "fallback") {
        test_fallback_terrain_resolved();
    } else {
        test_transitions_3x3_window();
        test_out_of_bounds_aborts();
        test_fallback_terrain_resolved();
    }
    return 0;
}
