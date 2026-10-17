// Tests for func_275A40 — Milestone 87 (1316B)
// Verifies 4-corner building footprint passability checks,
// tile coordinate rounding, and setter invocation upon validation.
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include "unit_action_build_5a40.h"

static int g_f801cf350_calls = 0;
static int g_passable_calls = 0;
static int g_f802697b0_calls = 0;
static int g_map_valid_response = 1;
static int g_fn_valid_response = 1;

extern "C" int func_123350(float val) {
    return (int)std::round(val);
}

extern "C" int func_801CF350(void *, int, int, int) {
    g_f801cf350_calls++;
    return g_map_valid_response;
}

extern "C" void func_802697B0(void *, int) {
    g_f802697b0_calls++;
}

static int mock_passable(void *, int, int) {
    g_passable_calls++;
    return g_fn_valid_response;
}

static void setup_test(unsigned char *self, unsigned char *target,
                       unsigned char *owner, unsigned char *map, void **vtbl) {
    std::memset(self, 0, 512);
    std::memset(target, 0, 512);
    std::memset(owner, 0, 256);
    std::memset(map, 0, 256);
    std::memset(vtbl, 256 * sizeof(void *), 0);

    vtbl[45] = (void *)mock_passable;
    void *vtbl_ptr = vtbl;
    std::memcpy(self, &vtbl_ptr, sizeof(void *));

    void *owner_ptr = owner;
#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x10, &owner_ptr, sizeof(void *));
#else
    std::memcpy(self + 0x8, &owner_ptr, sizeof(void *));
#endif

    void *map_ptr = map;
    std::memcpy(owner + 0x70, &map_ptr, sizeof(void *));

    float x1 = 10.0f, y1 = 20.0f;
    float x2 = 14.0f, y2 = 24.0f;
    std::memcpy(self + 0x44, &x1, sizeof(float));
    std::memcpy(self + 0x48, &y1, sizeof(float));
    std::memcpy(target + 0x44, &x2, sizeof(float));
    std::memcpy(target + 0x48, &y2, sizeof(float));
}

static void test_all_corners_passable() {
    unsigned char self[512], target[512], owner[256], map[256];
    void *vtbl[256];
    setup_test(self, target, owner, map, vtbl);

    g_f801cf350_calls = 0;
    g_passable_calls = 0;
    g_f802697b0_calls = 0;
    g_map_valid_response = 1;
    g_fn_valid_response = 1;

    int res = func_275A40(self, target, nullptr);
    assert(res == 1);
    assert(g_f801cf350_calls == 4);
    assert(g_passable_calls == 4);
    assert(g_f802697b0_calls == 1);
    printf("PASS test_all_corners_passable\n");
}

static void test_corner_blocked_fails() {
    unsigned char self[512], target[512], owner[256], map[256];
    void *vtbl[256];
    setup_test(self, target, owner, map, vtbl);

    g_f801cf350_calls = 0;
    g_passable_calls = 0;
    g_f802697b0_calls = 0;
    g_map_valid_response = 0; // map check fails

    int res = func_275A40(self, target, nullptr);
    assert(res == 0);
    assert(g_f801cf350_calls == 1);
    assert(g_f802697b0_calls == 0);
    printf("PASS test_corner_blocked_fails\n");
}

int main() {
    test_all_corners_passable();
    test_corner_blocked_fails();
    printf("All unit_action_build_5a40 tests passed!\n");
    return 0;
}
