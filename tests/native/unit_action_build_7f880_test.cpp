// Tests for func_0027F880 (and func_27F880) — Milestone 147 (16B)
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_7f880.h"

static int g_func_138A40_called = 0;
static void *g_last_self = nullptr;
static int g_last_arg1 = -1;

extern "C" {
    void func_138A40(void *self, int arg1) {
        g_func_138A40_called++;
        g_last_self = self;
        g_last_arg1 = arg1;
    }
}

static void test_delegation() {
    unsigned char dummy_self[32];
    int test_vals[] = {0, 1, 42, -1, 100, 0x1234};
    for (int val : test_vals) {
        g_func_138A40_called = 0;
        g_last_self = nullptr;
        g_last_arg1 = -1;

        func_0027F880(dummy_self, val);

        assert(g_func_138A40_called == 1);
        assert(g_last_self == dummy_self);
        assert(g_last_arg1 == val);
    }
    printf("PASS test_delegation\n");
}

static void test_alias() {
    unsigned char dummy_self[32];
    g_func_138A40_called = 0;
    func_27F880(dummy_self, 999);
    assert(g_func_138A40_called == 1);
    assert(g_last_arg1 == 999);
    printf("PASS test_alias\n");
}

int main(int argc, char **argv) {
    if (argc > 1) {
        int case_num = argv[1][0] - '0';
        if (case_num == 0) {
            test_delegation();
            return 0;
        } else if (case_num == 1) {
            test_alias();
            return 0;
        } else {
            fprintf(stderr, "Unknown test case %d\n", case_num);
            return 1;
        }
    }
    test_delegation();
    test_alias();
    printf("All unit_action_build_7f880 tests passed!\n");
    return 0;
}
