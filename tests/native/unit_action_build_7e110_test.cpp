// Tests for func_0027E110 (and func_27E110) — Milestone 145 (912B)
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_7e110.h"

static int g_func_1C14D0_called = 0;
static int g_func_001C0F90_called = 0;

extern "C" {
    int func_1C14D0(void *self, int cat) {
        g_func_1C14D0_called++;
        if (cat == 1) return 56;
        if (cat == 2) return 16;
        return 10;
    }

    int func_001C0F90(void *self, int cat, int idx, char *f1, char *f2, char *f3) {
        g_func_001C0F90_called++;
        if (f1) *f1 = (char)(cat + 1);
        if (f2) *f2 = (char)(idx + 2);
        if (f3) *f3 = (char)(cat + idx + 3);

        // Return a distinct byte for (cat, idx)
        return (cat ^ idx) & 0xFF;
    }
}

static void test_null_out_cat() {
    unsigned char dummy_self[32];
    g_func_1C14D0_called = 0;
    g_func_001C0F90_called = 0;

    int res = func_0027E110(dummy_self, nullptr, 0, 0, 0, 0);
    assert(res == 0);
    assert(g_func_1C14D0_called == 0);
    assert(g_func_001C0F90_called == 0);
    printf("PASS test_null_out_cat\n");
}

static void test_initial_category_match() {
    unsigned char dummy_self[32];
    int cat = 1;
    // For cat=1, idx=5:
    // res = (1 ^ 5) & 0xFF = 4
    // f1 = 2
    // f2 = 7
    // f3 = 9
    g_func_1C14D0_called = 0;
    g_func_001C0F90_called = 0;

    int res = func_0027E110(dummy_self, &cat, 4, 7, 2, 9);
    assert(res == 5);
    assert(cat == 1);
    printf("PASS test_initial_category_match\n");
}

static void test_search_match() {
    unsigned char dummy_self[32];
    int cat = 0;
    // Target cat=2, idx=3:
    // res = (2 ^ 3) & 0xFF = 1
    // f1 = 3
    // f2 = 5
    // f3 = 8
    g_func_1C14D0_called = 0;
    g_func_001C0F90_called = 0;

    int res = func_0027E110(dummy_self, &cat, 1, 5, 3, 8);
    assert(res == 3);
    assert(cat == 2);
    printf("PASS test_search_match\n");
}

static void test_not_found() {
    unsigned char dummy_self[32];
    int cat = 0;
    g_func_1C14D0_called = 0;
    g_func_001C0F90_called = 0;

    int res = func_0027E110(dummy_self, &cat, 0xFF, 0xFF, 0xFF, 0xFF);
    assert(res == -1);
    printf("PASS test_not_found\n");
}

static void test_alias() {
    unsigned char dummy_self[32];
    int cat = 1;
    int res = func_27E110(dummy_self, &cat, 4, 7, 2, 9);
    assert(res == 5);
    assert(cat == 1);
    printf("PASS test_alias\n");
}

int main(int argc, char **argv) {
    if (argc > 1) {
        int case_num = argv[1][0] - '0';
        if (case_num == 0) {
            test_null_out_cat();
            test_initial_category_match();
            return 0;
        } else if (case_num == 1) {
            test_search_match();
            test_not_found();
            return 0;
        } else if (case_num == 2) {
            test_alias();
            return 0;
        } else {
            fprintf(stderr, "Unknown test case %d\n", case_num);
            return 1;
        }
    }
    test_null_out_cat();
    test_initial_category_match();
    test_search_match();
    test_not_found();
    test_alias();
    printf("All unit_action_build_7e110 tests passed!\n");
    return 0;
}
