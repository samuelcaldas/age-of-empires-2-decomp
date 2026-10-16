#include "unit_action_resolve_fixture.h"

// Case 0: Normal placement with asymmetric coordinates and float capture
static void test_resolve_success() {
    dummy_child_vtable[75] = (void*)mock_m75;
    MockAction parent, child;
    child.vtable = dummy_child_vtable;

    char dummy_map_zone[32];
    *(int*)(dummy_map_zone + 0x8) = 500; *(int*)(dummy_map_zone + 0xC) = 500;
    char dummy_b98[0x40];
    *(void**)(dummy_b98 + 0x3C) = dummy_map_zone;
    char dummy_world[0xC00];
    *(void**)(dummy_world + 0xB98) = dummy_b98;
    parent.m_world = (WorldExtended*)dummy_world;

    char dummy_child_f4[0xB0];
    *(float*)(dummy_child_f4 + 0x20) = 1.0f; *(float*)(dummy_child_f4 + 0x24) = 1.0f;
    char dummy_sub[0x40];
    *(void**)(dummy_sub + 0x3C) = (void*)mock_m3c;
    *(void**)(dummy_child_f4 + 0xA0) = dummy_sub;

    g_rand_calls = 0; g_use_rand_sequence = 0; g_rand_val = 0;
    g_m3c_ret = 0; g_m73_ret = 1; g_m3c_called = 0; g_m75_called = 0;
    float ox = 0.0f, oy = 0.0f;

    // Asymmetric coordinates: coord_x=100.0, coord_y=200.0, ext_x=2.0, ext_y=1.0
    int ok = func_002699A0((ActionRebind*)&parent, 5, &ox, &oy, dummy_child_f4, (ActionRebind*)&child, 100.0f, 200.0f, 2.0f, 1.0f);
    assert(ok == 1);
    assert(g_last_received_tile_x == 103 && g_last_received_tile_y == 199);
    assert(g_m3c_called == 1 && g_m75_called == 1);
    assert(g_last_m3c_x == ox && g_last_m3c_y == oy);
    assert(g_last_m75_x == ox && g_last_m75_y == oy);

    // Verify full Method3C ABI contract
    assert(g_last_m3c_f4 == (void*)dummy_child_f4 && g_last_m3c_world == (void*)dummy_world);
    assert(g_last_m3c_self == (void*)&parent && g_last_m3c_a2 == 0 && g_last_m3c_a3 == 1);
    assert(g_last_m3c_t0 == 1 && g_last_m3c_t1 == 1 && g_last_m3c_t2 == 0 && g_last_m3c_t3 == 1);
    assert(g_last_m3c_s0 == 1 && g_last_m3c_s8 == 0 && g_last_m3c_s16 == 0);
}

// Case 1: All 50 attempts fail due to obstacles, leaves coordinates from 50th attempt with varying RNG
static void test_resolve_obstacle_failure() {
    dummy_child_vtable[75] = (void*)mock_m75;
    MockAction parent, child;
    child.vtable = dummy_child_vtable;

    char dummy_map_zone[32];
    *(int*)(dummy_map_zone + 0x8) = 500; *(int*)(dummy_map_zone + 0xC) = 500;
    char dummy_b98[0x40];
    *(void**)(dummy_b98 + 0x3C) = dummy_map_zone;
    char dummy_world[0xC00];
    *(void**)(dummy_world + 0xB98) = dummy_b98;
    parent.m_world = (WorldExtended*)dummy_world;

    char dummy_child_f4[0xB0];
    *(float*)(dummy_child_f4 + 0x20) = 1.0f; *(float*)(dummy_child_f4 + 0x24) = 1.0f;
    char dummy_sub[0x40];
    *(void**)(dummy_sub + 0x3C) = (void*)mock_m3c;
    *(void**)(dummy_child_f4 + 0xA0) = dummy_sub;

    g_m3c_ret = 1; g_m3c_called = 0; g_rand_calls = 0; g_use_rand_sequence = 1;
    for (int i = 0; i < 49; ++i) {
        g_rand_sequence[2 * i] = 0; // side 0
        g_rand_sequence[2 * i + 1] = i * 100;
    }
    // Attempt 50 (index 49): side 0, offset generator returns 16383 (mid-offset)
    g_rand_sequence[98] = 0;
    g_rand_sequence[99] = 16383;

    float ox = 0.0f, oy = 0.0f;
    int ok = func_002699A0((ActionRebind*)&parent, 5, &ox, &oy, dummy_child_f4, (ActionRebind*)&child, 50.0f, 50.0f, 2.0f, 2.0f);
    assert(ok == 0);
    assert(g_m3c_called == 50 && g_rand_calls == 100);
    assert(std::fabs(ox - 53.01f) < 0.01f && std::fabs(oy - 50.0f) < 0.01f);
}

// Case 2: Boundary rand 32767 produces side 4 with exactly ONE RNG call
static void test_resolve_rand_32767_boundary() {
    dummy_child_vtable[75] = (void*)mock_m75;
    MockAction parent, child;
    child.vtable = dummy_child_vtable;

    char dummy_map_zone[32];
    *(int*)(dummy_map_zone + 0x8) = 500; *(int*)(dummy_map_zone + 0xC) = 500;
    char dummy_b98[0x40];
    *(void**)(dummy_b98 + 0x3C) = dummy_map_zone;
    char dummy_world[0xC00];
    *(void**)(dummy_world + 0xB98) = dummy_b98;
    parent.m_world = (WorldExtended*)dummy_world;

    char dummy_child_f4[0xB0];
    *(float*)(dummy_child_f4 + 0x20) = 1.0f; *(float*)(dummy_child_f4 + 0x24) = 1.0f;
    char dummy_sub[0x40];
    *(void**)(dummy_sub + 0x3C) = (void*)mock_m3c;
    *(void**)(dummy_child_f4 + 0xA0) = dummy_sub;

    g_use_rand_sequence = 0; g_rand_val = 32767; g_m3c_ret = 0; g_m73_ret = 1; g_rand_calls = 0;
    float ox = 123.0f, oy = 456.0f;

    int ok = func_002699A0((ActionRebind*)&parent, -1, &ox, &oy, dummy_child_f4, (ActionRebind*)&child, 50.0f, 50.0f, 2.0f, 2.0f);
    assert(ok == 1);
    assert(ox == 123.0f && oy == 456.0f);
    assert(g_rand_calls == 1);
}

// Case 3: Asymmetric full-integer arg1 comparison (arg1=261 vs res=5 calls func_00269F30)
static void test_resolve_asymmetric_arg1() {
    dummy_child_vtable[75] = (void*)mock_m75;
    MockAction parent, child;
    child.vtable = dummy_child_vtable;

    char dummy_map_zone[32];
    *(int*)(dummy_map_zone + 0x8) = 500; *(int*)(dummy_map_zone + 0xC) = 500;
    char dummy_b98[0x40];
    *(void**)(dummy_b98 + 0x3C) = dummy_map_zone;
    char dummy_world[0xC00];
    *(void**)(dummy_world + 0xB98) = dummy_b98;
    parent.m_world = (WorldExtended*)dummy_world;

    char dummy_child_f4[0xB0];
    *(float*)(dummy_child_f4 + 0x20) = 1.0f; *(float*)(dummy_child_f4 + 0x24) = 1.0f;
    char dummy_sub[0x40];
    *(void**)(dummy_sub + 0x3C) = (void*)mock_m3c;
    *(void**)(dummy_child_f4 + 0xA0) = dummy_sub;

    g_use_rand_sequence = 0; g_rand_val = 0; g_m3c_ret = 0; g_m73_ret = 1;
    float ox = 0.0f, oy = 0.0f;

    // arg1 = 261 (0x105): low byte is 5; func_00269E50 returns 5 -> 261 != 5 calls func_00269F30!
    g_func_269F30_called = 0;
    int ok = func_002699A0((ActionRebind*)&parent, 261, &ox, &oy, dummy_child_f4, (ActionRebind*)&child, 50.0f, 50.0f, 2.0f, 2.0f);
    assert(ok == 1 && g_func_269F30_called == 1);

    // If arg1 == 5, full integer 5 == 5 -> func_00269F30 NOT called!
    g_func_269F30_called = 0;
    ok = func_002699A0((ActionRebind*)&parent, 5, &ox, &oy, dummy_child_f4, (ActionRebind*)&child, 50.0f, 50.0f, 2.0f, 2.0f);
    assert(ok == 1 && g_func_269F30_called == 0);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_resolve_success();
        test_resolve_obstacle_failure();
        test_resolve_rand_32767_boundary();
        test_resolve_asymmetric_arg1();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_resolve_success(); break;
        case 1: test_resolve_obstacle_failure(); break;
        case 2: test_resolve_rand_32767_boundary(); break;
        case 3: test_resolve_asymmetric_arg1(); break;
        default: return 1;
    }
    return 0;
}
