// Tests for func_0027C390 (and func_27C390) — Milestone 141 (2288B)
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_7c390.h"

static int g_func_1C1350_called = 0;
static int g_last_categories[113];
static int g_last_indices[113];
static int g_last_codes[113];

extern "C" {
    void func_1C1350(void *, int category, int index, int code) {
        if (g_func_1C1350_called < 113) {
            g_last_categories[g_func_1C1350_called] = category;
            g_last_indices[g_func_1C1350_called] = index;
            g_last_codes[g_func_1C1350_called] = code;
        }
        g_func_1C1350_called++;
    }
}

static void test_mappings() {
    unsigned char self[64];
    g_func_1C1350_called = 0;

    func_0027C390(self);

    assert(g_func_1C1350_called == 113);

    // Verify first mapping: {1, 20, 0x4a3c}
    assert(g_last_categories[0] == 1);
    assert(g_last_indices[0] == 20);
    assert(g_last_codes[0] == 0x4a3c);

    // Verify last mapping: {13, 1, 0x4b7a}
    assert(g_last_categories[112] == 13);
    assert(g_last_indices[112] == 1);
    assert(g_last_codes[112] == 0x4b7a);

    // Verify alias func_27C390
    func_27C390(self);
    assert(g_func_1C1350_called == 226);

    printf("PASS test_mappings\n");
}

int main() {
    test_mappings();
    printf("All unit_action_build_7c390 tests passed!\n");
    return 0;
}
