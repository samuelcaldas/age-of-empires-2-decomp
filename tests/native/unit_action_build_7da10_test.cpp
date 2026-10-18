// Tests for func_0027DA10 (and func_27DA10) — Milestone 144 (1792B)
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_7da10.h"

struct ExpectedMapping {
    int code;
    int expected_cat;
    int expected_idx;
};

static const ExpectedMapping k_mappings[] = {
    // Block 0: (7, 0)
    {0x4022, 7, 0}, {0x3ed4, 7, 0}, {0x3ed3, 7, 0},
    // Block 1: (7, 2)
    {0x401c, 7, 2}, {0x3ed5, 7, 2},
    // Block 2: (7, 1)
    {0x3ed8, 7, 1}, {0x3ed7, 7, 1},
    // Block 3: (7, 3)
    {0x3ed6, 7, 3},
    // Block 4: (6, 0)
    {0x4055, 6, 0}, {0x401b, 6, 0}, {0x3ed1, 6, 0}, {0x3ed0, 6, 0}, {0x3ecf, 6, 0},
    // Block 5: (6, 1)
    {0x4019, 6, 1}, {0x4018, 6, 1}, {0x3ece, 6, 1},
    // Block 6: (10, 0)
    {0x3ee3, 10, 0},
    // Block 7: (5, 4)
    {0x402d, 5, 4}, {0x402a, 5, 4},
    // Block 8: (5, 5)
    {0x4029, 5, 5}, {0x4028, 5, 5},
    // Block 9: (5, 8)
    {0x4049, 5, 8}, {0x3eea, 5, 8},
    // Block 10: (5, 1)
    {0x3ed9, 5, 1},
    // Block 11: (5, 0)
    {0x3eda, 5, 0},
    // Block 12: (5, 2)
    {0x3edb, 5, 2}, {0x3fb5, 5, 2}, {0x4034, 5, 2},
    // Block 13: (5, 3)
    {0x3f9f, 5, 3},
    // Block 14: (5, 7)
    {0x403b, 5, 7},
    // Block 15: (11, 0)
    {0x3ee4, 11, 0},
    // Block 16: (9, 0)
    {0x403e, 9, 0}, {0x3fa1, 9, 0}, {0x3ede, 9, 0},
    // Block 17: (9, 3)
    {0x3edd, 9, 3},
    // Block 18: (9, 1)
    {0x4037, 9, 1}, {0x3ee0, 9, 1},
    // Block 19: (9, 2)
    {0x406d, 9, 2}, {0x4040, 9, 2}, {0x3edf, 9, 2},
    // Block 20: (8, 2)
    {0x4057, 8, 2}, {0x3ec6, 8, 2}, {0x3ec4, 8, 2},
    // Block 21: (8, 1)
    {0x4021, 8, 1}, {0x4020, 8, 1},
    // Block 22: (8, 0)
    {0x403c, 8, 0}, {0x3fc6, 8, 0},
    // Block 23: (4, 0)
    {0x3ef9, 4, 0},
    // Block 24: (4, 2)
    {0x405a, 4, 2},
    // Block 25: (4, 3)
    {0x405c, 4, 3},
    // Block 26: (4, 4)
    {0x405e, 4, 4},
    // Block 27: (4, 5)
    {0x4060, 4, 5},
    // Block 28: (13, 1)
    {0x3ef1, 13, 1}, {0x40be, 13, 1}, {0x3ef0, 13, 1}, {0x3eef, 13, 1},
    {0x3eee, 13, 1}, {0x3eed, 13, 1}, {0x3eec, 13, 1}, {0x3eeb, 13, 1},
    {0x3ee9, 13, 1}, {0x3ee8, 13, 1}, {0x3ee7, 13, 1}, {0x3ee6, 13, 1},
    {0x3ee5, 13, 1},
    // Block 29: (13, 0)
    {0x3ffd, 13, 0},
};

static const int k_num_mappings = sizeof(k_mappings) / sizeof(k_mappings[0]);

static int g_func_001C0F90_called = 0;
static void *g_last_self = nullptr;
static int g_last_cat = -1;
static int g_last_idx = -1;
static char g_last_flag = -1;
static int g_return_val = 55;

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
        g_return_val = 300 + i;

        int res = func_0027DA10(dummy_self, k_mappings[i].code);
        assert(res == g_return_val);
        assert(g_func_001C0F90_called == 1);
        assert(g_last_self == dummy_self);
        assert(g_last_cat == k_mappings[i].expected_cat);
        assert(g_last_idx == k_mappings[i].expected_idx);
        assert(g_last_flag == 0);
    }
    printf("PASS test_all_action_codes (%d mappings verified)\n", k_num_mappings);
}

static void test_unhandled_action_codes() {
    unsigned char dummy_self[32];
    int unhandled[] = {0, 1, 0x100, 0x3ec3, 0x3ed2, 0x3ee1, 0x3ffc, 0x40bf, 0x7fff, -1};
    for (int code : unhandled) {
        g_func_001C0F90_called = 0;
        int res = func_0027DA10(dummy_self, code);
        assert(res == 0);
        assert(g_func_001C0F90_called == 0);
    }
    printf("PASS test_unhandled_action_codes\n");
}

static void test_alias() {
    unsigned char dummy_self[32];
    g_func_001C0F90_called = 0;
    g_return_val = 666;
    int res = func_27DA10(dummy_self, 0x3ffd);
    assert(res == 666);
    assert(g_func_001C0F90_called == 1);
    assert(g_last_cat == 13);
    assert(g_last_idx == 0);
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
    printf("All unit_action_build_7da10 tests passed!\n");
    return 0;
}
