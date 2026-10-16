#include <cassert>
#include <cmath>
#include <cstddef>
#include <cstring>
#include <string>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001CE650(
    void *self, void *player, int a2, int y, int x, int t1, int flag_single_spawn
);

static int g_func_1cf350_calls = 0;
static int g_func_1aab30_calls = 0;
static int g_method15_calls = 0;
static int g_method13_calls = 0;
static float g_last_placed_x = 0.0f;
static float g_last_placed_y = 0.0f;
static int g_mock_placement_err = 0;

int func_1CF350(void *self, int x, int y) {
    g_func_1cf350_calls++;
    return 1;
}

int func_1AAB30() {
    g_func_1aab30_calls++;
    return 16383; // ~0.5f
}

static int mock_method15_placement_check(
    void *entity, void *player, int a2, int a3, int t0, int t1, int t2, int t3,
    float pos_x, float pos_y, long long s0, long long s1
) {
    g_method15_calls++;
    return g_mock_placement_err;
}

static void mock_method13_place_entity(
    void *entity, void *player, float pos_x, float pos_y, float z
) {
    g_method13_calls++;
    g_last_placed_x = pos_x;
    g_last_placed_y = pos_y;
}
}

static void *g_comp_vtable[20] = {};

static void reset_test_state() {
    g_func_1cf350_calls = 0; g_func_1aab30_calls = 0;
    g_method15_calls = 0; g_method13_calls = 0;
    g_last_placed_x = 0.0f; g_last_placed_y = 0.0f;
    g_mock_placement_err = 0;
    g_comp_vtable[15] = (void *)&mock_method15_placement_check;
    g_comp_vtable[13] = (void *)&mock_method13_place_entity;
}

static void setup_zone_and_player(
    char *zone_mem, char *player_mem, void *dummy_entity, char *comp_mem
) {
    std::memset(zone_mem, 0, 0x10000);
    std::memset(player_mem, 0, 0x200);
    std::memset(comp_mem, 0, 0x40);

    *reinterpret_cast<void **>(comp_mem) = g_comp_vtable;
    *reinterpret_cast<void **>(reinterpret_cast<char *>(dummy_entity) + 0xA0) = comp_mem;

    static void *entity_table[16] = {};
    entity_table[0] = dummy_entity;
    *reinterpret_cast<void ***>(player_mem + 0x70) = entity_table;

    char *table1 = zone_mem + 1 * 416; // terrain 1
    *reinterpret_cast<short *>(table1 + 0x228) = 1; // 1 object type
    *reinterpret_cast<short *>(table1 + 0x192) = 0; // obj_id = 0
    *reinterpret_cast<unsigned char *>(table1 + 0x20A) = 1; // mode 1 (centered)
    *reinterpret_cast<short *>(table1 + 0x1CE) = 1000; // density 1000
}

static void test_flow_mode1_center_and_multi_spawn() {
    reset_test_state();
    char zone_mem[0x10000], player_mem[0x200], comp_mem[0x40], entity_mem[0x100];
    setup_zone_and_player(zone_mem, player_mem, entity_mem, comp_mem);

    func_001CE650(zone_mem, player_mem, 0, 5, 3, 0, 0);

    assert(g_func_1cf350_calls == 1);
    assert(g_method15_calls == 1);
    assert(g_method13_calls == 1);
    assert(std::fabs(g_last_placed_x - 3.5f) < 0.001f);
    assert(std::fabs(g_last_placed_y - 5.5f) < 0.001f);
}

static void test_flow_mode0_jitter_and_single_spawn() {
    reset_test_state();
    char zone_mem[0x10000], player_mem[0x200], comp_mem[0x40], entity_mem[0x100];
    setup_zone_and_player(zone_mem, player_mem, entity_mem, comp_mem);
    *reinterpret_cast<unsigned char *>(zone_mem + 1 * 416 + 0x20A) = 0; // mode 0

    func_001CE650(zone_mem, player_mem, 0, 5, 3, 0, 1);

    assert(g_method15_calls == 1);
    assert(g_method13_calls == 1);
    assert(g_func_1aab30_calls >= 2);
    assert(g_last_placed_x > 3.0f && g_last_placed_x < 4.0f);
}

static void test_placement_collision_fails_skips_spawn() {
    reset_test_state();
    char zone_mem[0x10000], player_mem[0x200], comp_mem[0x40], entity_mem[0x100];
    setup_zone_and_player(zone_mem, player_mem, entity_mem, comp_mem);

    g_mock_placement_err = 1; // placement check fails
    func_001CE650(zone_mem, player_mem, 0, 5, 3, 0, 0);

    assert(g_method15_calls == 1);
    assert(g_method13_calls == 0); // never placed!
}

int main(int argc, char **argv) {
    if (argc > 1 && std::string(argv[1]) == "single_jitter") {
        test_flow_mode0_jitter_and_single_spawn();
    } else if (argc > 1 && std::string(argv[1]) == "collision_skip") {
        test_placement_collision_fails_skips_spawn();
    } else {
        test_flow_mode1_center_and_multi_spawn();
        test_flow_mode0_jitter_and_single_spawn();
        test_placement_collision_fails_skips_spawn();
    }
    return 0;
}
