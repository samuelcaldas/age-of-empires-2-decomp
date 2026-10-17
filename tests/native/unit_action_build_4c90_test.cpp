// Tests for func_274C90 — Milestone 80 (140B)
// Verifies elevation damage/combat modifier logic:
// - method_368 returns true -> 1.25f (+25% high-ground advantage)
// - self_z < target_z -> 0.75f (-25% low-ground disadvantage)
// - neutral -> 1.0f
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include "unit_action_build_4c90.h"

static int g_v368_result = 0;

static int mock_v368(void *) {
    return g_v368_result;
}

static void setup_test(unsigned char *self, unsigned char *target, void **vtbl) {
    std::memset(self, 0, 256);
    std::memset(target, 0, 256);
    std::memset(vtbl, 0, 256 * sizeof(void *));

    vtbl[218] = (void *)mock_v368;
    void *vtbl_ptr = vtbl;
    std::memcpy(self, &vtbl_ptr, sizeof(void *));
}

static void test_advantage_1_25() {
    unsigned char self[256], target[256];
    void *vtbl[256];
    setup_test(self, target, vtbl);

    g_v368_result = 1;
    float r = func_274C90(self, target);
    assert(std::fabs(r - 1.25f) < 1e-4f);
    printf("PASS test_advantage_1_25\n");
}

static void test_disadvantage_0_75() {
    unsigned char self[256], target[256];
    void *vtbl[256];
    setup_test(self, target, vtbl);

    g_v368_result = 0;
    float sz_low = 10.0f;
    float tz_high = 20.0f;
    std::memcpy(self + 0x4C, &sz_low, sizeof(float));
    std::memcpy(target + 0x4C, &tz_high, sizeof(float));

    float r = func_274C90(self, target);
    assert(std::fabs(r - 0.75f) < 1e-4f);
    printf("PASS test_disadvantage_0_75\n");
}

static void test_neutral_1_0() {
    unsigned char self[256], target[256];
    void *vtbl[256];
    setup_test(self, target, vtbl);

    g_v368_result = 0;
    float sz_high = 30.0f;
    std::memcpy(self + 0x4C, &sz_high, sizeof(float));

    float r = func_274C90(self, target);
    assert(std::fabs(r - 1.0f) < 1e-4f);
    printf("PASS test_neutral_1_0\n");
}

int main() {
    test_advantage_1_25();
    test_disadvantage_0_75();
    test_neutral_1_0();
    printf("All unit_action_build_4c90 tests passed!\n");
    return 0;
}
