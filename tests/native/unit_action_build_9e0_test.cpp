// Tests for func_002719E0 — Milestone 62 (80B)
// Verifies bounds checking [0..3], null pointer guards, and id lookup at +0x24.
#include <cassert>
#include <climits>
#include <cstdio>
#include <cstring>
#include "unit_action_build_9e0.h"

static void test_negative_index_returns_minus_one() {
    unsigned char self_buf[512] = {};
    assert(func_002719E0(self_buf, -1) == -1);
    assert(func_002719E0(self_buf, -100) == -1);
    assert(func_002719E0(self_buf, INT_MIN) == -1);
    printf("PASS test_negative_index_returns_minus_one\n");
}

static void test_out_of_bounds_index_returns_minus_one() {
    unsigned char self_buf[512] = {};
    assert(func_002719E0(self_buf, 4) == -1);
    assert(func_002719E0(self_buf, 5) == -1);
    assert(func_002719E0(self_buf, 100) == -1);
    assert(func_002719E0(self_buf, INT_MAX) == -1);
    printf("PASS test_out_of_bounds_index_returns_minus_one\n");
}

static void test_null_element_returns_minus_one() {
    unsigned char self_buf[512] = {};
    for (int i = 0; i < 4; ++i) {
        assert(func_002719E0(self_buf, i) == -1);
    }
    printf("PASS test_null_element_returns_minus_one\n");
}

static void test_valid_element_reads_id() {
    unsigned char self_buf[512] = {};
    unsigned char item_buf[64] = {};
    short expected_id = 1234;
    std::memcpy(item_buf + 0x24, &expected_id, sizeof(short));

    for (int i = 0; i < 4; ++i) {
        std::memset(self_buf, 0, sizeof(self_buf));
        void *ptr = item_buf;
        std::memcpy(self_buf + 0x134 + i * sizeof(void *), &ptr, sizeof(void *));
        assert(func_002719E0(self_buf, i) == 1234);
    }
    printf("PASS test_valid_element_reads_id\n");
}

int main() {
    test_negative_index_returns_minus_one();
    test_out_of_bounds_index_returns_minus_one();
    test_null_element_returns_minus_one();
    test_valid_element_reads_id();
    printf("All unit_action_build_9e0 tests passed!\n");
    return 0;
}
