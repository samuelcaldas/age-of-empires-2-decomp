// Tests for func_00278660 — Milestone 112 (160B)
// Verifies construction progress-to-facet threshold updates.
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_78660.h"

static void test_non_building_type() {
    unsigned char self[256], proto[64];
    std::memset(self, 0, sizeof(self));
    std::memset(proto, 0, sizeof(proto));

    void *proto_ptr = proto;
#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x8, &proto_ptr, sizeof(void *));
#else
    std::memcpy(self + 0x4, &proto_ptr, sizeof(void *));
#endif
    short type = 0x20; // Not 0x28
    std::memcpy(proto + 0xE, &type, sizeof(short));
    self[0x35] = 5;

    func_00278660(self);
    assert(self[0x35] == 5);
    printf("PASS test_non_building_type\n");
}

static void test_facet_thresholds() {
    unsigned char self[256], proto[64], sprite[64];
    std::memset(self, 0, sizeof(self));
    std::memset(proto, 0, sizeof(proto));
    std::memset(sprite, 0, sizeof(sprite));

    void *proto_ptr = proto;
    void *sprite_ptr = sprite;
#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x8, &proto_ptr, sizeof(void *));
    std::memcpy(self + 0x20, &sprite_ptr, sizeof(void *));
#else
    std::memcpy(self + 0x4, &proto_ptr, sizeof(void *));
    std::memcpy(self + 0x10, &sprite_ptr, sizeof(void *));
#endif
    short type = 0x28; // Building
    std::memcpy(proto + 0xE, &type, sizeof(short));
    sprite[0x3A] = 10; // max_facet

    // Stage 1: progress < 26.0f -> facet 2
    float prog1 = 15.0f;
    std::memcpy(self + 0x40, &prog1, sizeof(float));
    self[0x35] = 99;
    func_00278660(self);
    assert(self[0x35] == 2);

    // Stage 2: 26.0f <= progress < 51.0f -> facet 1
    float prog2 = 35.0f;
    std::memcpy(self + 0x40, &prog2, sizeof(float));
    func_00278660(self);
    assert(self[0x35] == 1);

    // Stage 3: progress >= 51.0f -> facet 0
    float prog3 = 75.0f;
    std::memcpy(self + 0x40, &prog3, sizeof(float));
    func_00278660(self);
    assert(self[0x35] == 0);

    printf("PASS test_facet_thresholds\n");
}

int main() {
    test_non_building_type();
    test_facet_thresholds();
    printf("All unit_action_build_78660 tests passed!\n");
    return 0;
}
