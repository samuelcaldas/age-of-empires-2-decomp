// Tests for func_00272A80 — Milestone 65 (8B)
// Verifies inline 16-bit halfword getter at offset +0x124.
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_a80.h"

static void test_get_field_124_positive() {
    unsigned char self[512] = {};
    short expected = 1337;
    std::memcpy(self + 0x124, &expected, sizeof(short));

    short val = func_00272A80(self);
    assert(val == 1337);
    printf("PASS test_get_field_124_positive\n");
}

static void test_get_field_124_negative() {
    unsigned char self[512] = {};
    short expected = -42;
    std::memcpy(self + 0x124, &expected, sizeof(short));

    short val = func_00272A80(self);
    assert(val == -42);
    printf("PASS test_get_field_124_negative\n");
}

int main() {
    test_get_field_124_positive();
    test_get_field_124_negative();
    printf("All unit_action_build_a80 tests passed!\n");
    return 0;
}
