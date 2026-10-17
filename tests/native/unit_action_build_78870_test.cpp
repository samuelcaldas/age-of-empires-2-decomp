// Tests for func_00278870 & func_00278910 — Milestone 114 (288B)
// Verifies incremental threat accumulator addition and subtraction.
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_78870.h"

extern "C" float func_2786F0(void *) {
    return 10.0f; // Mock DPS
}

static void test_threat_add_and_remove() {
    unsigned char self[256], proto[64];
    std::memset(self, 0, sizeof(self));
    std::memset(proto, 0, sizeof(proto));

    void *proto_ptr = proto;
#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x8, &proto_ptr, sizeof(void *));
#else
    std::memcpy(self + 0x4, &proto_ptr, sizeof(void *));
#endif
    short type = 4; // Applicable threat type
    std::memcpy(proto + 0xE, &type, sizeof(short));

    float accum = 50.0f;
    float divisor = 2.0f;

    // Add threat: 50.0 + (10.0 / 2.0) = 55.0
    func_00278870(self, &accum, divisor);
    assert(accum == 55.0f);

    // Remove threat: 55.0 - (10.0 / 2.0) = 50.0
    func_00278910(self, &accum, divisor);
    assert(accum == 50.0f);

    // Test zero divisor guard (no change)
    func_00278870(self, &accum, 0.0f);
    assert(accum == 50.0f);

    printf("PASS test_threat_add_and_remove\n");
}

int main() {
    test_threat_add_and_remove();
    printf("All unit_action_build_78870 tests passed!\n");
    return 0;
}
