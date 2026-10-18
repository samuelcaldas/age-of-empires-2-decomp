// Tests for func_0027AC90 (and alias func_0027ACB0) — Milestone 133 (2080B)
// Verifies CombatManager periodic tick update and tactical zone scan.
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include "unit_action_build_7acb0.h"

static int g_func_123350_called = 0;
static int g_func_1233E0_called = 0;
static int g_func_1234E0_called = 0;
static int g_func_100190_called = 0;
static int g_func_27B4B0_called = 0;
static int g_func_27B700_called = 0;
static float g_last_threshold_val1 = 0.0f;
static float g_last_threshold_val2 = 0.0f;
static float g_last_sector = 0.0f;

extern "C" {
    int func_123350(float val) {
        g_func_123350_called++;
        return (int)val;
    }
    int func_1233E0(float val) {
        g_func_1233E0_called++;
        return (int)val;
    }
    float func_1234E0(float val) {
        g_func_1234E0_called++;
        return std::sqrt(val);
    }
    int func_100190(float val, double threshold) {
        g_func_100190_called++;
        return (val >= (float)threshold) ? 1 : 0;
    }
    void func_27B4B0(void *, int, float val1, float val2) {
        g_func_27B4B0_called++;
        g_last_threshold_val1 = val1;
        g_last_threshold_val2 = val2;
    }
    void func_27B700(void *, float sector, int, int, float) {
        g_func_27B700_called++;
        g_last_sector = sector;
    }
}

static void test_periodic_update_tick_skipped() {
    unsigned char self[0x1000];
    std::memset(self, 0, sizeof(self));

    int interval = 5;
    std::memcpy(self + 0x5E4, &interval, sizeof(int));
    int counter = 0;
    std::memcpy(self + 0x5E8, &counter, sizeof(int));

    g_func_27B4B0_called = 0;
    g_func_27B700_called = 0;

    // Ticks 1 to 4: counter increments, tick skipped
    for (int i = 0; i < 4; ++i) {
        func_0027AC90(self);
        assert(g_func_27B4B0_called == 0);
    }
    int cur_counter = *(int *)(self + 0x5E8);
    assert(cur_counter == 4);

    printf("PASS test_periodic_update_tick_skipped\n");
}

static void test_periodic_update_full_execution() {
    unsigned char self[0x1000], owner[0x2000], props[0x1000];
    std::memset(self, 0, sizeof(self));
    std::memset(owner, 0, sizeof(owner));
    std::memset(props, 0, sizeof(props));

    void *owner_ptr = owner;
    void *props_ptr = props;

#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x5D8, &owner_ptr, sizeof(void *));
    std::memcpy(owner + 0x1758, &props_ptr, sizeof(void *));
#else
    std::memcpy(self + 0x5D4, &owner_ptr, sizeof(void *));
    std::memcpy(owner + 0xBAC, &props_ptr, sizeof(void *));
#endif

    int interval = 1;
    std::memcpy(self + 0x5E4, &interval, sizeof(int));
    int counter = 0;
    std::memcpy(self + 0x5E8, &counter, sizeof(int));

    // Threshold values
    float val1 = 15.0f, val2 = 10.0f;
    std::memcpy(props + 0x94, &val1, sizeof(float));
    std::memcpy(props + 0xA0, &val2, sizeof(float));

    // Setup accumulator fields
    int s2_val1 = 10, s2_val2 = 10;
    std::memcpy(self + 0x624, &s2_val1, sizeof(int));
    std::memcpy(self + 0x628, &s2_val2, sizeof(int));

    // Setup coordinates in props
    float ac_val = 50.0f, c268_val = 50.0f;
    std::memcpy(props + 0xAC, &ac_val, sizeof(float));
    std::memcpy(props + 0x268, &c268_val, sizeof(float));

    // Sector values: make sector 3 (index 2) highest
    for (int i = 0; i < 8; ++i) {
        float p1 = (i == 2) ? 100.0f : 10.0f;
        float p2 = (i == 2) ? 100.0f : 10.0f;
        std::memcpy(props + 0x1B8 + i * 4, &p1, sizeof(float));
        std::memcpy(props + 0x1F8 + i * 4, &p2, sizeof(float));
    }

    // Set accumulator to exceed threshold (0.15^2 = 0.0225)
    float acc_init = 1.0f;
    std::memcpy(self + 0x68C, &acc_init, sizeof(float));

    g_func_123350_called = 0;
    g_func_1233E0_called = 0;
    g_func_1234E0_called = 0;
    g_func_100190_called = 0;
    g_func_27B4B0_called = 0;
    g_func_27B700_called = 0;

    func_0027AC90(self);

    // Verify all components executed
    assert(g_func_27B4B0_called == 1);
    assert(g_last_threshold_val1 == 15.0f);
    assert(g_last_threshold_val2 == 10.0f);

    // Sector evaluation and trigger
    assert(g_func_27B700_called == 1);
    assert(g_last_sector == 3.0f); // 1-based sector index for i = 2

    // Accumulators should be reset after dispatch
    assert(*(int *)(self + 0x620) == 0);
    assert(*(int *)(self + 0x690) == 0);
    assert(*(int *)(self + 0x694) == 0);
    assert(*(short *)(self + 0x698) == 0);
    assert(*(short *)(self + 0x69A) == 0);
    assert(*(float *)(self + 0x68C) == 0.0f);

    // Verify alias func_0027ACB0
    func_0027ACB0(self);

    printf("PASS test_periodic_update_full_execution\n");
}

int main(int argc, char **argv) {
    if (argc > 1) {
        int case_num = argv[1][0] - '0';
        if (case_num == 0) test_periodic_update_tick_skipped();
        else if (case_num == 1) test_periodic_update_full_execution();
        return 0;
    }
    test_periodic_update_tick_skipped();
    test_periodic_update_full_execution();
    printf("All unit_action_build_7acb0 tests passed!\n");
    return 0;
}
