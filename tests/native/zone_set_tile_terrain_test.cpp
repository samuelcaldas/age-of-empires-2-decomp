#include <cassert>
#include <cstddef>
#include <cstring>
#include <string>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001CF830(
    void *self, void *world, int x, int y, int terrain, int param6, int param7
);

static int g_func_1d1cc0_calls = 0;
static int g_func_1c9e00_calls = 0;
static int g_func_2082b0_calls = 0;
static int g_func_001ce3b0_calls = 0;
static int g_func_001ce650_calls = 0;
static int g_func_1d00c0_calls = 0;
static int g_last_clean_terrain = -1;
static int g_last_spawn_terrain = -1;

void func_1D1CC0(void *self, void *cell) { g_func_1d1cc0_calls++; }
void func_1C9E00(void *self, int x0, int y0, int x1, int y1, int flag) { g_func_1c9e00_calls++; }
void func_2082B0(void *map_comp, int x, int y) { g_func_2082b0_calls++; }

int func_001CE3B0(void *self, void *a1, int y, int x, int filter_type, int flag_delete_mode, int range_min, int range_max) {
    g_func_001ce3b0_calls++;
    g_last_clean_terrain = filter_type;
    return 42; // arbitrary result token
}

void func_001CE650(void *self, void *player, int a2, int y, int x, int t1, int flag_single_spawn) {
    g_func_001ce650_calls++;
    g_last_spawn_terrain = a2;
}

void func_1D00C0(void *self, int x, int y) { g_func_1d00c0_calls++; }
}

static void reset_test_state() {
    g_func_1d1cc0_calls = 0; g_func_1c9e00_calls = 0; g_func_2082b0_calls = 0;
    g_func_001ce3b0_calls = 0; g_func_001ce650_calls = 0; g_func_1d00c0_calls = 0;
    g_last_clean_terrain = -1; g_last_spawn_terrain = -1;
}

static void setup_zone_and_world(
    char *zone_mem, char *world_mem, char *player_mem, char *cell_mem,
    int x, int y, unsigned char initial_terrain
) {
    std::memset(zone_mem, 0, 0x10000);
    std::memset(world_mem, 0, 0x200);
    std::memset(player_mem, 0, 0x1000);
    std::memset(cell_mem, 0, 28);

    static void *player_table[4] = {player_mem, player_mem, nullptr, nullptr};
    *reinterpret_cast<void ***>(world_mem + 0x54) = player_table;
    world_mem[0x31] = 0; // mode != 3

    static char *row_ptrs[8];
    row_ptrs[y] = cell_mem - x * 28;
    *reinterpret_cast<char ***>(zone_mem + 0x8E8C) = row_ptrs;

    cell_mem[5] = initial_terrain;
}

static void test_terrain_change_flow() {
    reset_test_state();
    char zone_mem[0x10000], world_mem[0x200], player_mem[0x1000], cell_mem[28];
    setup_zone_and_world(zone_mem, world_mem, player_mem, cell_mem, 3, 2, 4);

    // Change terrain from 4 to 9
    func_001CF830(zone_mem, world_mem, 3, 2, 9, 10, 20);

    assert(cell_mem[5] == 9); // updated to 9
    assert(g_func_1c9e00_calls == 1); // raster extent updated
    assert(g_func_2082b0_calls == 1); // LOS updated
    assert(g_func_001ce3b0_calls == 1); // cleaned old terrain 4
    assert(g_last_clean_terrain == 4);
    assert(g_func_001ce650_calls == 1); // spawned new terrain 4 (passed as old_terrain)
    assert(g_func_1d00c0_calls == 1);
}

static void test_same_terrain_early_return() {
    reset_test_state();
    char zone_mem[0x10000], world_mem[0x200], player_mem[0x1000], cell_mem[28];
    setup_zone_and_world(zone_mem, world_mem, player_mem, cell_mem, 3, 2, 4);

    // Change to same terrain 4
    func_001CF830(zone_mem, world_mem, 3, 2, 4, 10, 20);

    assert(cell_mem[5] == 4);
    // Nothing should be called
    assert(g_func_1c9e00_calls == 0);
    assert(g_func_001ce3b0_calls == 0);
    assert(g_func_001ce650_calls == 0);
}

int main(int argc, char **argv) {
    if (argc > 1 && std::string(argv[1]) == "same_terrain") {
        test_same_terrain_early_return();
    } else {
        test_terrain_change_flow();
        test_same_terrain_early_return();
    }
    return 0;
}
