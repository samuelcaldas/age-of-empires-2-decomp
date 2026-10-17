#include <cassert>
#include <cstddef>
#include <cstring>
#include <string>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
int func_001CF350(void *self, int x, int y);
}

static void setup_grid(char *zone_mem, char *cell_mem, int x, int y, unsigned char terrain) {
    std::memset(zone_mem, 0, 0x10000);
    std::memset(cell_mem, 0, 28);
    cell_mem[5] = terrain;

    static char *row_ptrs[8];
    row_ptrs[y] = cell_mem - x * 28;
    *reinterpret_cast<char ***>(zone_mem + 0x8E8C) = row_ptrs;
}

static void test_active_entry_returns_terrain() {
    char zone_mem[0x10000], cell_mem[28];
    setup_grid(zone_mem, cell_mem, 3, 2, 7);

    // Terrain 7: table entry at 7 * 416, active flag at 0x8C = 1
    char *entry = zone_mem + 7 * 416;
    entry[0x8C] = 1;

    int ret = func_001CF350(zone_mem, 3, 2);
    assert(ret == 7);
}

static void test_inactive_entry_with_valid_fallback_returns_terrain() {
    char zone_mem[0x10000], cell_mem[28];
    setup_grid(zone_mem, cell_mem, 3, 2, 7);

    char *entry = zone_mem + 7 * 416;
    entry[0x8C] = 0; // inactive
    *reinterpret_cast<short *>(entry + 0x14C) = 12; // fallback >= 0

    int ret = func_001CF350(zone_mem, 3, 2);
    assert(ret == 7);
}

static void test_inactive_entry_with_negative_fallback_returns_zero() {
    char zone_mem[0x10000], cell_mem[28];
    setup_grid(zone_mem, cell_mem, 3, 2, 7);

    char *entry = zone_mem + 7 * 416;
    entry[0x8C] = 0; // inactive
    *reinterpret_cast<short *>(entry + 0x14C) = -1; // fallback < 0

    int ret = func_001CF350(zone_mem, 3, 2);
    assert(ret == 0);
}

static void test_terrain_ge_33_returns_zero() {
    char zone_mem[0x10000], cell_mem[28];
    setup_grid(zone_mem, cell_mem, 3, 2, 33); // 33 >= 33

    char *entry = zone_mem + 33 * 416;
    entry[0x8C] = 1;

    int ret = func_001CF350(zone_mem, 3, 2);
    assert(ret == 0);

    // Also test 45
    cell_mem[5] = 45;
    ret = func_001CF350(zone_mem, 3, 2);
    assert(ret == 0);
}

int main(int argc, char **argv) {
    if (argc > 1 && std::string(argv[1]) == "fallback_valid") {
        test_inactive_entry_with_valid_fallback_returns_terrain();
    } else if (argc > 1 && std::string(argv[1]) == "fallback_neg") {
        test_inactive_entry_with_negative_fallback_returns_zero();
    } else if (argc > 1 && std::string(argv[1]) == "bounds_ge_33") {
        test_terrain_ge_33_returns_zero();
    } else {
        test_active_entry_returns_terrain();
        test_inactive_entry_with_valid_fallback_returns_terrain();
        test_inactive_entry_with_negative_fallback_returns_zero();
        test_terrain_ge_33_returns_zero();
    }
    return 0;
}
