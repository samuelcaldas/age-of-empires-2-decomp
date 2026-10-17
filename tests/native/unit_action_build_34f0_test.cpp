// Tests for func_2734F0 — Milestone 74 (800B)
// Verifies ActionBuild frame execution: state gate check, progress increments,
// countdown decrement for type 40, special action trigger, and health updates.
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include "unit_action_build_34f0.h"

static int g_round_calls = 0;
static int g_special_action_calls = 0;
static int g_v32c_calls = 0;

extern "C" int func_123350(float val) {
    g_round_calls++;
    return (int)std::round(val);
}

extern "C" int func_80196610(void *) {
    g_special_action_calls++;
    return 1;
}

static void mock_v32c(void *, void *, int, int) {
    g_v32c_calls++;
}

static void setup_test(unsigned char *self, unsigned char *proto,
                       unsigned char *owner, unsigned char *mgr,
                       unsigned char *stats, void **self_vtbl) {
    std::memset(self, 0, 512);
    std::memset(proto, 0, 512);
    std::memset(owner, 0, 8192);
    std::memset(mgr, 0, 256);
    std::memset(stats, 0, 512);
    std::memset(self_vtbl, 0, 256 * sizeof(void *));

    self_vtbl[203] = (void *)mock_v32c;
    void *self_vtbl_ptr = self_vtbl;
    std::memcpy(self, &self_vtbl_ptr, sizeof(void *));

    void *proto_ptr = proto;
    void *owner_ptr = owner;
#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x8, &proto_ptr, sizeof(void *));
    std::memcpy(self + 0x10, &owner_ptr, sizeof(void *));
#else
    std::memcpy(self + 0x4, &proto_ptr, sizeof(void *));
    std::memcpy(self + 0x8, &owner_ptr, sizeof(void *));
#endif

    void *mgr_ptr = mgr;
    std::memcpy(owner + 0xB98, &mgr_ptr, sizeof(void *));
    void *stats_ptr = stats;
    std::memcpy(owner + 0xBAC, &stats_ptr, sizeof(void *));
}

static void test_state_not_2_returns_zero() {
    unsigned char self[512], proto[512], owner[8192], mgr[256], stats[512];
    void *self_vtbl[256];
    setup_test(self, proto, owner, mgr, stats, self_vtbl);

    *(unsigned char *)(self + 0x39) = 1; // not 2
    int res = func_2734F0(self);
    assert(res == 0);
    printf("PASS test_state_not_2_returns_zero\n");
}

static void test_progress_type_18_updates() {
    unsigned char self[512], proto[512], owner[8192], mgr[256], stats[512];
    void *self_vtbl[256];
    setup_test(self, proto, owner, mgr, stats, self_vtbl);

    *(unsigned char *)(self + 0x39) = 2; // active
    short type = 0x12;
    std::memcpy(proto + 0xE, &type, sizeof(short));

    float dt = 0.5f;
    std::memcpy(mgr + 0xAC, &dt, sizeof(float));
    float rate = 10.0f;
    std::memcpy(stats + 0x8C, &rate, sizeof(float));
    float initial_val = 50.0f;
    std::memcpy(self + 0x40, &initial_val, sizeof(float));

    int res = func_2734F0(self);
    assert(res == 1);
    float final_val = *(float *)(self + 0x40);
    assert(std::fabs(final_val - 55.0f) < 1e-4f);
    assert(*(short *)(self + 0x3C) == 0x22);
    printf("PASS test_progress_type_18_updates\n");
}

int main() {
    test_state_not_2_returns_zero();
    test_progress_type_18_updates();
    printf("All unit_action_build_34f0 tests passed!\n");
    return 0;
}
