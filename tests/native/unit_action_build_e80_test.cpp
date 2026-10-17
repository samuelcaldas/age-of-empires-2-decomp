// Tests for func_00272E80 — Milestone 71 (680B)
// Verifies action initiation, flag setting, vtable calls, stat accumulation,
// rounding helper calculation, and resource cost application.
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include "unit_action_build_e80.h"

static int g_flags_calls = 0;
static int g_sub_action_calls = 0;
static int g_stats_calls = 0;
static float g_stats_amount = 0.0f;
static int g_cost_calls = 0;
static int g_last_res_id = 0;
static float g_last_cost_amount = 0.0f;
static int g_v374_calls = 0;

extern "C" void func_0026AD60(void *, int) {
    g_flags_calls++;
}

extern "C" void func_00194E90(void *, void *, int, float, float, float) {
    g_sub_action_calls++;
}

extern "C" void func_0026AD30(void *, int) {}

extern "C" void func_00272A88(void *, float amount) {
    g_stats_calls++;
    g_stats_amount = amount;
}

extern "C" int func_123350(float val) {
    return (int)std::round(val);
}

static void mock_v374(void *) {
    g_v374_calls++;
}

static void mock_cost(void *, int res_id, float amount, int) {
    g_cost_calls++;
    g_last_res_id = res_id;
    g_last_cost_amount = amount;
}

static void setup_test(unsigned char *self, unsigned char *proto,
                       unsigned char *owner, unsigned char *stats,
                       void **self_vtbl, void **owner_vtbl) {
    std::memset(self, 0, 512);
    std::memset(proto, 0, 512);
    std::memset(owner, 0, 8192);
    std::memset(stats, 0, 512);
    std::memset(self_vtbl, 0, 256 * sizeof(void *));
    std::memset(owner_vtbl, 0, 64 * sizeof(void *));

    self_vtbl[221] = (void *)mock_v374;
    owner_vtbl[31] = (void *)mock_cost;

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

    void *stats_ptr = stats;
    std::memcpy(owner + 0xBAC, &stats_ptr, sizeof(void *));
    void *owner_vtbl_ptr = owner_vtbl;
    std::memcpy(owner + 0x1B30, &owner_vtbl_ptr, sizeof(void *));
}

static void test_initiation_success() {
    unsigned char self[512], proto[512], owner[8192], stats[512];
    void *self_vtbl[256], *owner_vtbl[64];
    setup_test(self, proto, owner, stats, self_vtbl, owner_vtbl);

    g_v374_calls = 0;
    g_stats_calls = 0;
    g_flags_calls = 0;
    g_cost_calls = 0;

    float stat_val = 0.5f;
    std::memcpy(stats + 0x104, &stat_val, sizeof(float));
    float proto_f148 = 42.0f;
    std::memcpy(proto + 0x148, &proto_f148, sizeof(float));
    short type = 0x12;
    std::memcpy(proto + 0xE, &type, sizeof(short));

    int res = func_00272E80(self, (void *)0x1234, 1, 10.0f, 20.0f, 30.0f);

    assert(res == 1);
    assert(g_v374_calls == 1);
    assert(g_stats_calls == 1);
    assert(g_stats_amount == 1.0f);
    assert(*(short *)(self + 0x10C) == 500);
    assert(*(float *)(self + 0x40) == 100.0f);
    assert(*(short *)(self + 0x3C) == 0x22);
    assert(*(short *)(self + 0x10E) == -1);
    printf("PASS test_initiation_success\n");
}

static void test_cost_application() {
    unsigned char self[512], proto[512], owner[8192], stats[512];
    void *self_vtbl[256], *owner_vtbl[64];
    setup_test(self, proto, owner, stats, self_vtbl, owner_vtbl);

    g_cost_calls = 0;
    proto[0] = 0x10; // not 0x50, so cost applies

    // Setup 1 cost entry at proto+0x12C
    char *entry = (char *)proto + 0x12C;
    short res_id = 0;
    short cost_val = 150;
    unsigned char active = 1;
    std::memcpy(entry, &res_id, sizeof(short));
    std::memcpy(entry + 2, &cost_val, sizeof(short));
    std::memcpy(entry + 4, &active, sizeof(unsigned char));

    // Entry 2 inactive (res_id = -1)
    short neg1 = -1;
    std::memcpy(entry + 6, &neg1, sizeof(short));
    std::memcpy(entry + 12, &neg1, sizeof(short));

    func_00272E80(self, (void *)0x1234, 1, 1.0f, 2.0f, 3.0f);

    assert(g_cost_calls == 2); // called for 0x62 and 0xA4
    assert(g_last_res_id == 0xA4);
    assert(g_last_cost_amount == 150.0f);
    printf("PASS test_cost_application\n");
}

int main() {
    test_initiation_success();
    test_cost_application();
    printf("All unit_action_build_e80 tests passed!\n");
    return 0;
}
