// Tests for func_00277E50 — Milestone 106 (256B)
// Verifies direct repair cost deduction and incremental step application.
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_77e50.h"

static int g_deduct_called = 0;
static float g_deduct_ratio = 0.0f;
extern "C" int func_2E03F0(void *, short, int, float ratio) {
    g_deduct_called++;
    g_deduct_ratio = ratio;
    return 1;
}

static int g_step_called = 0;
static float g_last_delta_hp = 0.0f;
extern "C" int func_268FB0(void *, float delta_hp) {
    g_step_called++;
    g_last_delta_hp = delta_hp;
    return 1;
}

static void test_non_applicable_type() {
    unsigned char self[128], proto[512], owner[128];
    std::memset(self, 0, sizeof(self));
    std::memset(proto, 0, sizeof(proto));
    std::memset(owner, 0, sizeof(owner));

    void *proto_ptr = proto;
#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x8, &proto_ptr, sizeof(void *));
#else
    std::memcpy(self + 0x4, &proto_ptr, sizeof(void *));
#endif
    short type = 10; // Not 2, 13, 20, 21, 22, 51, 53-55
    std::memcpy(proto + 0xE, &type, sizeof(short));

    g_deduct_called = 0;
    g_step_called = 0;
    int ret = func_00277E50(self, 25.0f, owner);
    assert(ret == 2);
    assert(g_deduct_called == 0);
    assert(g_step_called == 1);
    assert(g_last_delta_hp == 25.0f);
    printf("PASS test_non_applicable_type\n");
}

static void test_applicable_direct_repair_cost() {
    unsigned char self[128], proto[512], owner[128];
    std::memset(self, 0, sizeof(self));
    std::memset(proto, 0, sizeof(proto));
    std::memset(owner, 0, sizeof(owner));

    void *proto_ptr = proto;
#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x8, &proto_ptr, sizeof(void *));
#else
    std::memcpy(self + 0x4, &proto_ptr, sizeof(void *));
#endif
    short type = 51; // Applicable
    short proto_id = 200;
    short max_hp = 500;
    std::memcpy(proto + 0xE, &type, sizeof(short));
    std::memcpy(proto + 0x8, &proto_id, sizeof(short));
    std::memcpy(proto + 0x3E, &max_hp, sizeof(short));

    float current_hp = 450.0f;
    std::memcpy(self + 0x30, &current_hp, sizeof(float));

    g_deduct_called = 0;
    g_step_called = 0;
    // delta_hp = 100 -> current_hp + 100 = 550 > 500 -> clamped to 50
    // ratio = 50 / (500 * 2) = 0.05
    int ret = func_00277E50(self, 100.0f, owner);
    assert(ret == 2);
    assert(g_deduct_called == 1);
    assert(g_step_called == 1);
    assert(g_last_delta_hp == 50.0f);
    assert(g_deduct_ratio == 0.05f);
    printf("PASS test_applicable_direct_repair_cost\n");
}

int main() {
    test_non_applicable_type();
    test_applicable_direct_repair_cost();
    printf("All unit_action_build_77e50 tests passed!\n");
    return 0;
}
