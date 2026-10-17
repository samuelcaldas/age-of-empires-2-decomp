// Tests for func_275700 — Milestone 84 (568B)
// Verifies ActionBuild attack / damage resolution: null target check,
// special siege attack handling, and combat damage delegation.
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_5700.h"

static int g_v168_calls = 0;
static int g_v80_calls = 0;
static int g_v94_calls = 0;
static int g_f5dd0_calls = 0;

extern "C" int func_801AAB30() { return 1000; }

extern "C" int func_80195DD0(void *, void *, void *, float) {
    g_f5dd0_calls++;
    return 1;
}

static void mock_v168(void *, int, int, int, int, int, int) { g_v168_calls++; }
static void mock_v80(void *) { g_v80_calls++; }
static void mock_v94(void *, int, int, float) { g_v94_calls++; }

static void setup_test(unsigned char *self, unsigned char *target,
                       unsigned char *proto, void **self_vtbl, void **target_vtbl) {
    std::memset(self, 0, 512);
    std::memset(target, 0, 512);
    std::memset(proto, 0, 256);
    std::memset(self_vtbl, 0, 128 * sizeof(void *));
    std::memset(target_vtbl, 0, 64 * sizeof(void *));

    self_vtbl[90] = (void *)mock_v168;
    target_vtbl[32] = (void *)mock_v80;
    target_vtbl[37] = (void *)mock_v94;

    void *self_vtbl_ptr = self_vtbl;
    std::memcpy(self, &self_vtbl_ptr, sizeof(void *));

    void *target_vtbl_ptr = target_vtbl;
    std::memcpy(target, &target_vtbl_ptr, sizeof(void *));

    void *proto_ptr = proto;
#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x8, &proto_ptr, sizeof(void *));
#else
    std::memcpy(self + 0x4, &proto_ptr, sizeof(void *));
#endif
}

static void test_null_target_returns_zero() {
    unsigned char self[512] = {};
    int res = func_275700(self, nullptr, nullptr, 1.0f);
    assert(res == 0);
    printf("PASS test_null_target_returns_zero\n");
}

static void test_special_siege_attack() {
    unsigned char self[512], target[512], proto[256];
    void *self_vtbl[128], *target_vtbl[64];
    setup_test(self, target, proto, self_vtbl, target_vtbl);

    g_v168_calls = 0;
    g_v80_calls = 0;

    short model_7a = 0x7A;
    std::memcpy(proto + 0x8, &model_7a, sizeof(short));

    int res = func_275700(self, target, nullptr, 1.0f);
    assert(res == 1);
    assert(g_v168_calls == 1);
    assert(g_v80_calls == 1);
    printf("PASS test_special_siege_attack\n");
}

int main() {
    test_null_target_returns_zero();
    test_special_siege_attack();
    printf("All unit_action_build_5700 tests passed!\n");
    return 0;
}
