// Tests for func_00277F50 — Milestone 107 (112B)
// Verifies repair affordability resource check.
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_77f50.h"

static int g_can_afford_ret = 1;
static float g_last_ratio = 0.0f;
extern "C" int func_2E01E0(void *, short, int, int, int, int, float ratio) {
    g_last_ratio = ratio;
    return g_can_afford_ret;
}

static void test_afford_repair() {
    unsigned char self[128], proto[512], owner[128];
    std::memset(self, 0, sizeof(self));
    std::memset(proto, 0, sizeof(proto));
    std::memset(owner, 0, sizeof(owner));

    void *proto_ptr = proto;
    void *owner_ptr = owner;
#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x8, &proto_ptr, sizeof(void *));
    std::memcpy(self + 0x10, &owner_ptr, sizeof(void *));
#else
    std::memcpy(self + 0x4, &proto_ptr, sizeof(void *));
    std::memcpy(self + 0x8, &owner_ptr, sizeof(void *));
#endif
    short proto_id = 45;
    short max_hp = 1000;
    std::memcpy(proto + 0x8, &proto_id, sizeof(short));
    std::memcpy(proto + 0x3E, &max_hp, sizeof(short));

    float current_hp = 800.0f;
    std::memcpy(self + 0x30, &current_hp, sizeof(float));

    // missing_hp = 200 -> missing / max = 0.2 -> ratio = 0.1
    g_can_afford_ret = 1;
    int ret = func_00277F50(self);
    assert(ret == 1);
    assert(g_last_ratio == 0.1f);

    // Test when player cannot afford
    g_can_afford_ret = 0;
    ret = func_00277F50(self);
    assert(ret == 0);

    printf("PASS test_afford_repair\n");
}

int main() {
    test_afford_repair();
    printf("All unit_action_build_77f50 tests passed!\n");
    return 0;
}
