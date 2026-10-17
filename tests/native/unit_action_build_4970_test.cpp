// Tests for func_274970 — Milestone 79 (800B)
// Verifies ActionBuild teardown / cancel logic, flag evaluations,
// and conditional stats reductions via func_00272A88(-1.0f).
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_4970.h"

static int g_f13ab90_calls = 0;
static int g_f205f70_calls = 0;
static int g_f2643c0_calls = 0;
static int g_f272a88_calls = 0;
static float g_f272a88_amount = 0.0f;
static int g_f264290_calls = 0;
static int g_f150f50_calls = 0;
static int g_f2e00d0_calls = 0;
static int g_flag_response_100 = 0;
static int g_flag_response_400 = 0;

extern "C" void func_0013AB90(void *) { g_f13ab90_calls++; }
extern "C" void func_00205F70(void *) { g_f205f70_calls++; }
extern "C" void func_002643C0(void *, int) { g_f2643c0_calls++; }

extern "C" int func_0026AD20(void *, int flag) {
    if (flag == 0x100) return g_flag_response_100;
    if (flag == 0x400) return g_flag_response_400;
    return 0;
}

extern "C" void func_00272A88(void *, float amount) {
    g_f272a88_calls++;
    g_f272a88_amount = amount;
}

extern "C" void func_00264290(void *) { g_f264290_calls++; }
extern "C" void func_00150F50(void *) { g_f150f50_calls++; }
extern "C" void func_002E00D0(void *) { g_f2e00d0_calls++; }

static void test_teardown_with_stats_reduction() {
    g_f13ab90_calls = 0;
    g_f205f70_calls = 0;
    g_f2643c0_calls = 0;
    g_f272a88_calls = 0;
    g_f264290_calls = 0;
    g_f150f50_calls = 0;
    g_f2e00d0_calls = 0;

    g_flag_response_100 = 1;
    g_flag_response_400 = 1;

    unsigned char self[64] = {};
    unsigned char target[64] = {};

    int res = func_274970(self, target);
    assert(res == 1);
    assert(g_f13ab90_calls == 1);
    assert(g_f205f70_calls == 1);
    assert(g_f2643c0_calls == 1);
    assert(g_f272a88_calls == 2);
    assert(g_f272a88_amount == -1.0f);
    assert(g_f264290_calls == 1);
    assert(g_f150f50_calls == 1);
    assert(g_f2e00d0_calls == 1);
    printf("PASS test_teardown_with_stats_reduction\n");
}

static void test_teardown_without_stats_reduction() {
    g_f272a88_calls = 0;
    g_flag_response_100 = 0;
    g_flag_response_400 = 0;

    unsigned char self[64] = {};
    unsigned char target[64] = {};

    int res = func_274970(self, target);
    assert(res == 1);
    assert(g_f272a88_calls == 0);
    printf("PASS test_teardown_without_stats_reduction\n");
}

int main() {
    test_teardown_with_stats_reduction();
    test_teardown_without_stats_reduction();
    printf("All unit_action_build_4970 tests passed!\n");
    return 0;
}
