// Tests for func_0027D2E0 (and func_27D2E0) — Milestone 143 (1840B)
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_7d2e0.h"

struct ExpectedMapping {
    int code;
    int expected_cat;
    int expected_idx;
};

static const ExpectedMapping k_mappings[] = {
    {0x5, 0, 5},
    {0x7, 0, 6},
    {0xa, 12, 0},
    {0xc, 3, 27},
    {0xd, 1, 54},
    {0xe, 1, 51},
    {0x16, 12, 10},
    {0x17, 0, 14},
    {0x18, 1, 30},
    {0x1c, 0, 9},
    {0x1d, 0, 10},
    {0x1f, 0, 2},
    {0x21, 12, 8},
    {0x22, 12, 9},
    {0x23, 12, 11},
    {0x24, 12, 6},
    {0x25, 12, 7},
    {0x26, 12, 5},
    {0x28, 1, 48},
    {0x29, 1, 46},
    {0x2a, 1, 47},
    {0x31, 0, 12},
    {0x32, 1, 42},
    {0x33, 0, 13},
    {0x4e, 0, 6},
    {0x54, 12, 1},
    {0x55, 12, 2},
    {0x56, 12, 3},
    {0x57, 12, 4},
    {0x6e, 0, 7},
    {0x6f, 0, 8},
    {0x73, 0, 1},
    {0x74, 0, 0},
    {0x7b, 0, 11},
    {0xa1, 1, 22},
    {0xa3, 4, 6},
    {0xa7, 0, 12},
    {0xa8, 1, 53},
    {0xaa, 3, 27},
    {0xab, 4, 7},
    {0xac, 1, 41},
    {0xad, 1, 24},
    {0xae, 3, 27},
    {0xaf, 1, 23},
};

static const int k_num_mappings = sizeof(k_mappings) / sizeof(k_mappings[0]);

static int g_func_001C0F90_called = 0;
static void *g_last_self = nullptr;
static int g_last_cat = -1;
static int g_last_idx = -1;
static char g_last_flag = -1;
static int g_return_val = 77;

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
        g_return_val = 200 + i;

        int res = func_0027D2E0(dummy_self, k_mappings[i].code);
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
    int unhandled[] = {0, 1, 2, 3, 4, 6, 8, 9, 0xb, 0x15, 0x27, 0x53, 0x75, 0xb0, 0xffff, -1};
    for (int code : unhandled) {
        g_func_001C0F90_called = 0;
        int res = func_0027D2E0(dummy_self, code);
        assert(res == 0);
        assert(g_func_001C0F90_called == 0);
    }
    printf("PASS test_unhandled_action_codes\n");
}

static void test_alias() {
    unsigned char dummy_self[32];
    g_func_001C0F90_called = 0;
    g_return_val = 888;
    int res = func_27D2E0(dummy_self, 0xaf);
    assert(res == 888);
    assert(g_func_001C0F90_called == 1);
    assert(g_last_cat == 1);
    assert(g_last_idx == 23);
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
    printf("All unit_action_build_7d2e0 tests passed!\n");
    return 0;
}
