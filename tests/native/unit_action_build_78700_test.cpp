// Tests for func_00278700 — Milestone 113 (356B)
// Verifies attack rating and damage-per-second computation.
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include "unit_action_build_78700.h"

struct DamageEntry {
    short damage_class;
    short amount;
};

static void test_zero_reload_time() {
    unsigned char self[256], proto[512];
    std::memset(self, 0, sizeof(self));
    std::memset(proto, 0, sizeof(proto));

    void *proto_ptr = proto;
#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x8, &proto_ptr, sizeof(void *));
#else
    std::memcpy(self + 0x4, &proto_ptr, sizeof(void *));
#endif
    float reload = 0.0f;
    std::memcpy(proto + 0x100, &reload, sizeof(float));

    float dps = func_00278700(self);
    assert(dps == 0.0f);
    printf("PASS test_zero_reload_time\n");
}

static void test_damage_sum_and_dps() {
    unsigned char self[256], proto[512];
    std::memset(self, 0, sizeof(self));
    std::memset(proto, 0, sizeof(proto));

    void *proto_ptr = proto;
#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x8, &proto_ptr, sizeof(void *));
#else
    std::memcpy(self + 0x4, &proto_ptr, sizeof(void *));
#endif
    float reload = 2.0f;
    std::memcpy(proto + 0x100, &reload, sizeof(float));
    float capability = 10.0f; // > 1.0f
    std::memcpy(proto + 0xF8, &capability, sizeof(float));
    short type = 1; // Not 4
    std::memcpy(proto + 0xE, &type, sizeof(short));

    DamageEntry entries[3] = {
        { 3, 6 }, // Pierce: 6
        { 4, 4 }, // Melee: 4
        { 1, 10 } // Other: ignored
    };
    DamageEntry *entries_ptr = entries;
    short count = 3;
#if defined(__LP64__) || defined(_LP64)
    std::memcpy(proto + 0x110, &entries_ptr, sizeof(void *));
    std::memcpy(proto + 0x118, &count, sizeof(short));
#else
    std::memcpy(proto + 0xF0, &entries_ptr, sizeof(void *));
    std::memcpy(proto + 0xF4, &count, sizeof(short));
#endif
    std::memcpy(proto + 0x100, &reload, sizeof(float));

    float dps = func_00278700(self);
    // (6 + 4) / 2.0 = 5.0
    assert(dps == 5.0f);
    printf("PASS test_damage_sum_and_dps\n");
}

int main() {
    test_zero_reload_time();
    test_damage_sum_and_dps();
    printf("All unit_action_build_78700 tests passed!\n");
    return 0;
}
