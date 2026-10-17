// Tests for func_00272A88 — Milestone 66 (396B)
// Verifies entity type switch logic and accumulation into owner stats
// (+0x94 for unit types 2, 4, 19, 20, 21; +0xA0 for standard building types).
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_a88.h"

static void setup_test(unsigned char *self, unsigned char *proto,
                       unsigned char *owner, unsigned char *stats) {
    std::memset(self, 0, 64);
    std::memset(proto, 0, 64);
    std::memset(owner, 0, 4096);
    std::memset(stats, 0, 256);

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
}

static void test_resource_94_accumulation() {
    unsigned char self[64], proto[64], owner[4096], stats[256];
    setup_test(self, proto, owner, stats);

    short type = 4;
    std::memcpy(proto + 0xE, &type, sizeof(short));

    func_00272A88(self, 12.5f);
    float val_94 = *(float *)(stats + 0x94);
    float val_a0 = *(float *)(stats + 0xA0);
    assert(val_94 == 12.5f);
    assert(val_a0 == 0.0f);
    printf("PASS test_resource_94_accumulation\n");
}

static void test_resource_a0_accumulation() {
    unsigned char self[64], proto[64], owner[4096], stats[256];
    setup_test(self, proto, owner, stats);

    short type = 0x35; // 53
    std::memcpy(proto + 0xE, &type, sizeof(short));

    func_00272A88(self, 33.0f);
    float val_94 = *(float *)(stats + 0x94);
    float val_a0 = *(float *)(stats + 0xA0);
    assert(val_94 == 0.0f);
    assert(val_a0 == 33.0f);
    printf("PASS test_resource_a0_accumulation\n");
}

static void test_unhandled_type_noop() {
    unsigned char self[64], proto[64], owner[4096], stats[256];
    setup_test(self, proto, owner, stats);

    short type = 999;
    std::memcpy(proto + 0xE, &type, sizeof(short));

    func_00272A88(self, 50.0f);
    float val_94 = *(float *)(stats + 0x94);
    float val_a0 = *(float *)(stats + 0xA0);
    assert(val_94 == 0.0f);
    assert(val_a0 == 0.0f);
    printf("PASS test_unhandled_type_noop\n");
}

int main() {
    test_resource_94_accumulation();
    test_resource_a0_accumulation();
    test_unhandled_type_noop();
    printf("All unit_action_build_a88 tests passed!\n");
    return 0;
}
