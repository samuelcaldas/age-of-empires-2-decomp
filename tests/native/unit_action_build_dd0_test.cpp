// Tests for func_00272DD0 — Milestone 69 (64B)
// Verifies stats reduction call (func_00272A88 with -1.0f)
// and conditional base class cleanup dispatch (func_00194D70).
#include <cassert>
#include <cstdio>
#include "unit_action_build_dd0.h"

static int g_stats_calls = 0;
static void *g_stats_self = nullptr;
static float g_stats_amount = 0.0f;
static int g_cleanup_calls = 0;
static void *g_cleanup_arg = nullptr;

extern "C" void func_00272A88(void *self, float amount) {
    g_stats_calls++;
    g_stats_self = self;
    g_stats_amount = amount;
}

extern "C" void func_00194D70(void *, void *arg1) {
    g_cleanup_calls++;
    g_cleanup_arg = arg1;
}

static void test_non_null_arg_calls_both() {
    g_stats_calls = 0;
    g_cleanup_calls = 0;

    void *dummy_self = (void *)0x1234;
    void *dummy_arg = (void *)0x5678;

    func_00272DD0(dummy_self, dummy_arg);

    assert(g_stats_calls == 1);
    assert(g_stats_self == dummy_self);
    assert(g_stats_amount == -1.0f);
    assert(g_cleanup_calls == 1);
    assert(g_cleanup_arg == dummy_arg);
    printf("PASS test_non_null_arg_calls_both\n");
}

static void test_null_arg_skips_cleanup() {
    g_stats_calls = 0;
    g_cleanup_calls = 0;

    void *dummy_self = (void *)0x1234;

    func_00272DD0(dummy_self, nullptr);

    assert(g_stats_calls == 1);
    assert(g_stats_self == dummy_self);
    assert(g_stats_amount == -1.0f);
    assert(g_cleanup_calls == 0);
    printf("PASS test_null_arg_skips_cleanup\n");
}

int main() {
    test_non_null_arg_calls_both();
    test_null_arg_skips_cleanup();
    printf("All unit_action_build_dd0 tests passed!\n");
    return 0;
}
