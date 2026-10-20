// Tests for func_0027CC80 (and func_27CC80) — Milestone 142 (1632B)
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_7cc80.h"

struct ExpectedMapping {
    int code;
    int expected_cat;
    int expected_idx;
};

static const ExpectedMapping k_mappings[] = {
    // Block 0: (3, 13)
    {0x3f00, 3, 13}, {0x3f01, 3, 13}, {0x3f02, 3, 13},
    // Block 1: (3, 2)
    {0x3f03, 3, 2}, {0x3f04, 3, 2}, {0x3f05, 3, 2}, {0x3f06, 3, 2},
    // Block 2: (3, 4)
    {0x3f07, 3, 4}, {0x3f08, 3, 4}, {0x3f09, 3, 4},
    // Block 3: (3, 15)
    {0x3f0a, 3, 15}, {0x3f0b, 3, 15}, {0x3f0c, 3, 15}, {0x3f0d, 3, 15},
    // Block 4: (3, 20)
    {0x3f0e, 3, 20}, {0x3f0f, 3, 20},
    // Block 5: (3, 3)
    {0x3f10, 3, 3}, {0x3f11, 3, 3}, {0x3f12, 3, 3}, {0x3f13, 3, 3}, {0x3f14, 3, 3},
    // Block 6: (3, 12)
    {0x3f15, 3, 12},
    // Block 7: (3, 8)
    {0x3f1a, 3, 8}, {0x3f1b, 3, 8}, {0x3f32, 3, 8},
    // Block 8: (3, 9)
    {0x3f1c, 3, 9},
    // Block 9: (3, 1)
    {0x3f1d, 3, 1}, {0x3f1e, 3, 1}, {0x3f1f, 3, 1}, {0x3f20, 3, 1},
    // Block 10: (3, 6)
    {0x3f21, 3, 6}, {0x3f22, 3, 6}, {0x3f23, 3, 6},
    // Block 11: (3, 16)
    {0x3f24, 3, 16}, {0x3f25, 3, 16}, {0x3f26, 3, 16}, {0x3f27, 3, 16}, {0x3f28, 3, 16},
    // Block 12: (3, 17)
    {0x3f29, 3, 17}, {0x3f2a, 3, 17},
    // Block 13: (3, 14)
    {0x3f2b, 3, 14}, {0x3f2c, 3, 14}, {0x3f2d, 3, 14},
    // Block 14: (3, 21)
    {0x3f2e, 3, 21}, {0x3f2f, 3, 21},
    // Block 15: (3, 18)
    {0x3f30, 3, 18}, {0x3f31, 3, 18},
    // Block 16: (3, 19)
    {0x3f36, 3, 19},
    // Block 17: (3, 10)
    {0x3f37, 3, 10}, {0x3f38, 3, 10}, {0x3f39, 3, 10}, {0x401d, 3, 10},
    // Block 18: (3, 5)
    {0x3f4a, 3, 5},
    // Block 19: (3, 7)
    {0x3f4b, 3, 7}, {0x3f4c, 3, 7},
    // Block 20: (3, 22)
    {0x3fb7, 3, 22},
    // Block 21: (3, 0)
    {0x3fd8, 3, 0}, {0x3fd9, 3, 0}, {0x3fda, 3, 0}, {0x3fdb, 3, 0},
    // Block 22: (3, 23)
    {0x4050, 3, 23},
    // Block 23: (3, 24)
    {0x4067, 3, 24},
    // Block 24: (3, 25)
    {0x406f, 3, 25},
    // Block 25: (3, 26)
    {0x4078, 3, 26},
};

static const int k_num_mappings = sizeof(k_mappings) / sizeof(k_mappings[0]);

static int g_func_001C0F90_called = 0;
static void *g_last_self = nullptr;
static int g_last_cat = -1;
static int g_last_idx = -1;
static char g_last_flag = -1;
static int g_return_val = 42;

extern "C" {
    int func_001C0F90(void *self, int cat, int idx, char *f1, char *f2, char *f3) {
        g_func_001C0F90_called++;
        g_last_self = self;
        g_last_cat = cat;
        g_last_idx = idx;
        if (f1) {
            g_last_flag = *f1;
        }
        return g_return_val;
    }
}

static void test_all_action_codes() {
    unsigned char dummy_self[32];
    for (int i = 0; i < k_num_mappings; ++i) {
        g_func_001C0F90_called = 0;
        g_last_self = nullptr;
        g_last_cat = -1;
        g_last_idx = -1;
        g_last_flag = -1;
        g_return_val = 100 + i;

        int res = func_0027CC80(dummy_self, k_mappings[i].code);
        assert(res == g_return_val);
        assert(g_func_001C0F90_called == 1);
        assert(g_last_self == dummy_self);
        assert(g_last_cat == k_mappings[i].expected_cat);
        assert(g_last_idx == k_mappings[i].expected_idx);
        assert(g_last_flag == 0); // stack flag initialized to 0
    }
    printf("PASS test_all_action_codes (%d mappings verified)\n", k_num_mappings);
}

static void test_unhandled_action_codes() {
    unsigned char dummy_self[32];
    int unhandled[] = {0, 1, 0x3eff, 0x3f16, 0x3f33, 0x4000, 0x4079, 0x7fff, -1};
    for (int code : unhandled) {
        g_func_001C0F90_called = 0;
        int res = func_0027CC80(dummy_self, code);
        assert(res == 0);
        assert(g_func_001C0F90_called == 0);
    }
    printf("PASS test_unhandled_action_codes\n");
}

static void test_alias() {
    unsigned char dummy_self[32];
    g_func_001C0F90_called = 0;
    g_return_val = 999;
    int res = func_27CC80(dummy_self, 0x4078);
    assert(res == 999);
    assert(g_func_001C0F90_called == 1);
    assert(g_last_idx == 26);
    printf("PASS test_alias\n");
}

int main(int argc, char **argv) {
    if (argc > 1) {
        int case_num = argv[1][0] - '0';
        if (case_num == 0) {
            test_all_action_codes();
            return 0;
        } else if (case_num == 1) {
            test_unhandled_action_codes();
            return 0;
        } else if (case_num == 2) {
            test_alias();
            return 0;
        } else {
            fprintf(stderr, "Unknown test case %d\n", case_num);
            return 1;
        }
    }
    test_all_action_codes();
    test_unhandled_action_codes();
    test_alias();
    printf("All unit_action_build_7cc80 tests passed!\n");
    return 0;
}
