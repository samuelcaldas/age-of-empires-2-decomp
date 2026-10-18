// Tests for func_0027BC50 (and func_27BC50) — Milestone 140 (1856B)
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_7bc50.h"

static int g_func_27E4A0_called = 0;
static int g_last_categories[114];
static int g_last_indices[114];

extern "C" {
    void func_27E4A0(void *, int category, int index) {
        if (g_func_27E4A0_called < 114) {
            g_last_categories[g_func_27E4A0_called] = category;
            g_last_indices[g_func_27E4A0_called] = index;
        }
        g_func_27E4A0_called++;
    }
}

static void test_registrations() {
    unsigned char self[64];
    g_func_27E4A0_called = 0;

    func_0027BC50(self);

    assert(g_func_27E4A0_called == 114);

    // Verify first registration: {1, 20}
    assert(g_last_categories[0] == 1 && g_last_indices[0] == 20);

    // Verify last registration: {13, 1}
    assert(g_last_categories[113] == 13 && g_last_indices[113] == 1);

    // Verify boundary transition (category 0 starts at index 32)
    assert(g_last_categories[32] == 0 && g_last_indices[32] == 0);

    // Verify alias func_27BC50
    func_27BC50(self);
    assert(g_func_27E4A0_called == 228);

    printf("PASS test_registrations\n");
}

int main() {
    test_registrations();
    printf("All unit_action_build_7bc50 tests passed!\n");
    return 0;
}
