#include <cassert>
#include <cmath>
#include <cstddef>
#include <cstring>
#include <string>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001CF3E0(
    void *self, short x0, short y0, short x1, short y1,
    int delta_elev, int param6, int param7
);

static int g_func_314ea0_calls = 0;
static int g_func_1d1cc0_calls = 0;
static int g_func_1cfcd0_calls = 0;
static int g_func_2082b0_calls = 0;
static int g_func_1c9fa0_calls = 0;
static int g_func_1c9e00_calls = 0;
static int g_method17_calls = 0;

void func_314EA0(short *x0, short *y0, short *x1, short *y1, int min_x, int min_y, int max_x, int max_y) {
    g_func_314ea0_calls++;
    if (*x0 < min_x) *x0 = min_x;
    if (*y0 < min_y) *y0 = min_y;
    if (*x1 > max_x) *x1 = max_x;
    if (*y1 > max_y) *y1 = max_y;
}

void func_1D1CC0(void *self, void *cell) { g_func_1d1cc0_calls++; }
unsigned char func_1CFCD0(void *self, int x, int y) { g_func_1cfcd0_calls++; return 3; }
void func_2082B0(void *map_comp, int x, int y) { g_func_2082b0_calls++; }
void func_1C9FA0(void *self, int x0, int y0, int x1, int y1) { g_func_1c9fa0_calls++; }
void func_1C9E00(void *self, int x0, int y0, int x1, int y1, int flag) { g_func_1c9e00_calls++; }

static void mock_method17(void *entity, float x, float y, float z) { g_method17_calls++; }
}

static void *g_item_vtable[25] = {};

static void reset_test_state() {
    g_func_314ea0_calls = 0; g_func_1d1cc0_calls = 0; g_func_1cfcd0_calls = 0;
    g_func_2082b0_calls = 0; g_func_1c9fa0_calls = 0; g_func_1c9e00_calls = 0;
    g_method17_calls = 0;
    g_item_vtable[17] = (void *)&mock_method17;
}

static void setup_test_world_and_grid(
    char *zone_mem, char *world_mem, char *player_mem, char *cells_grid,
    void *dummy_entity, void *item_ptrs[4]
) {
    std::memset(zone_mem, 0, 0x10000);
    std::memset(world_mem, 0, 0x200);
    std::memset(player_mem, 0, 0x1000);
    std::memset(cells_grid, 0, 10 * 10 * 28);

    *reinterpret_cast<int *>(zone_mem + 0x8) = 10; // width
    *reinterpret_cast<int *>(zone_mem + 0xC) = 10; // height
    *reinterpret_cast<void **>(zone_mem + 0x8EE8) = world_mem;

    static void *player_table[4] = {nullptr, player_mem, nullptr, nullptr};
    *reinterpret_cast<void ***>(world_mem + 0x54) = player_table;
    *reinterpret_cast<short *>(world_mem + 0x98) = 1; // player 1
    world_mem[0x31] = 0; // mode != 3

    static char *row_ptrs[10];
    for (int r = 0; r < 10; r++) {
        row_ptrs[r] = cells_grid + r * 10 * 28;
    }
    *reinterpret_cast<char ***>(zone_mem + 0x8E8C) = row_ptrs;

    // Target cell at (2, 2)
    char *target_cell = row_ptrs[2] + 2 * 28;
    target_cell[6] = 4; // initial elevation = 4
    *reinterpret_cast<void ***>(target_cell + 0x14) = item_ptrs;
    target_cell[0xD] = 1; // 1 item

    *reinterpret_cast<void **>(dummy_entity) = g_item_vtable;
}

static void test_elevation_rect_flow() {
    reset_test_state();
    char zone_mem[0x10000], world_mem[0x200], player_mem[0x1000], cells_grid[10 * 10 * 28], entity_mem[0x100];
    void *items[4] = {entity_mem, nullptr, nullptr, nullptr};

    setup_test_world_and_grid(zone_mem, world_mem, player_mem, cells_grid, entity_mem, items);

    // Update rect [2,2] to [2,2] with delta_elev = 2
    func_001CF3E0(zone_mem, 2, 2, 2, 2, 0, 2, 0);

    char *target_cell = cells_grid + 2 * 10 * 28 + 2 * 28;
    assert(g_func_314ea0_calls == 1);
    assert(target_cell[6] == 6); // 4 + 2 = 6
    assert(target_cell[4] == 3); // slope updated via func_1CFCD0
    assert(g_method17_calls >= 1); // entity height adjusted
    assert(g_func_2082b0_calls >= 1); // LOS updated
    assert(g_func_1c9fa0_calls == 1); // zone_rect_update
    assert(g_func_1c9e00_calls == 1); // zone_raster_extent
}

static void test_elevation_clamp_bounds() {
    reset_test_state();
    char zone_mem[0x10000], world_mem[0x200], player_mem[0x1000], cells_grid[10 * 10 * 28], entity_mem[0x100];
    void *items[4] = {entity_mem, nullptr, nullptr, nullptr};

    setup_test_world_and_grid(zone_mem, world_mem, player_mem, cells_grid, entity_mem, items);
    char *target_cell = cells_grid + 2 * 10 * 28 + 2 * 28;

    // Elevate past max: 4 + 10 = 14 -> clamped to 8
    func_001CF3E0(zone_mem, 2, 2, 2, 2, 0, 10, 0);
    assert(target_cell[6] == 8);

    // Elevate below min: 8 - 20 = -12 -> clamped to 0
    func_001CF3E0(zone_mem, 2, 2, 2, 2, 0, -20, 0);
    assert(target_cell[6] == 0);
}

static void test_mode3_skips_los_update() {
    reset_test_state();
    char zone_mem[0x10000], world_mem[0x200], player_mem[0x1000], cells_grid[10 * 10 * 28], entity_mem[0x100];
    void *items[4] = {entity_mem, nullptr, nullptr, nullptr};

    setup_test_world_and_grid(zone_mem, world_mem, player_mem, cells_grid, entity_mem, items);
    world_mem[0x31] = 3; // mode 3 (editor / generator)

    func_001CF3E0(zone_mem, 2, 2, 2, 2, 0, 1, 0);
    assert(g_func_2082b0_calls == 0); // LOS skipped
}

int main(int argc, char **argv) {
    if (argc > 1 && std::string(argv[1]) == "clamp_bounds") {
        test_elevation_clamp_bounds();
    } else if (argc > 1 && std::string(argv[1]) == "mode3_skip") {
        test_mode3_skips_los_update();
    } else {
        test_elevation_rect_flow();
        test_elevation_clamp_bounds();
        test_mode3_skips_los_update();
    }
    return 0;
}
