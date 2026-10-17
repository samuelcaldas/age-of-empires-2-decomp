#include <cassert>
#include <cstdio>
#include "tactical_ai_action_filter_340d30.h"

static void *g_340d70_a0 = nullptr;
static void *g_340d70_a3 = nullptr;
static void *g_340d70_t0 = nullptr;
static int g_340d70_calls = 0;

static void *g_1f45e0_a0 = nullptr;
static void *g_1f45e0_a1 = nullptr;
static int g_1f45e0_a2 = 0;
static void *g_1f45e0_a3 = nullptr;
static int g_1f45e0_calls = 0;

extern "C" {
int func_340D70(void *a0, void *a3, void *t0) {
    g_340d70_a0 = a0;
    g_340d70_a3 = a3;
    g_340d70_t0 = t0;
    g_340d70_calls++;
    return 100;
}

int func_1F45E0(void *a0, void *a1, int a2, void *a3) {
    g_1f45e0_a0 = a0;
    g_1f45e0_a1 = a1;
    g_1f45e0_a2 = a2;
    g_1f45e0_a3 = a3;
    g_1f45e0_calls++;
    return 200;
}
}

static void reset_mocks() {
    g_340d70_a0 = nullptr;
    g_340d70_a3 = nullptr;
    g_340d70_t0 = nullptr;
    g_340d70_calls = 0;

    g_1f45e0_a0 = nullptr;
    g_1f45e0_a1 = nullptr;
    g_1f45e0_a2 = 0;
    g_1f45e0_a3 = nullptr;
    g_1f45e0_calls = 0;
}

static void test_filter_520_dispatches_340d70() {
    reset_mocks();
    int dummy0 = 1, dummy1 = 2, dummy3 = 3, dummy4 = 4;

    int ret = func_00340D30(&dummy0, &dummy1, 0x520, &dummy3, &dummy4);
    assert(ret == 100);
    assert(g_340d70_calls == 1);
    assert(g_340d70_a0 == &dummy0);
    assert(g_340d70_a3 == &dummy3);
    assert(g_340d70_t0 == &dummy4);
    assert(g_1f45e0_calls == 0);
    printf("PASS test_filter_520_dispatches_340d70\n");
}

static void test_filter_non520_dispatches_1f45e0() {
    reset_mocks();
    int dummy0 = 10, dummy1 = 20, dummy3 = 30, dummy4 = 40;

    int ret = func_00340D30(&dummy0, &dummy1, 0x123, &dummy3, &dummy4);
    assert(ret == 200);
    assert(g_1f45e0_calls == 1);
    assert(g_1f45e0_a0 == &dummy0);
    assert(g_1f45e0_a1 == &dummy1);
    assert(g_1f45e0_a2 == 0x123);
    assert(g_1f45e0_a3 == &dummy3);
    assert(g_340d70_calls == 0);
    printf("PASS test_filter_non520_dispatches_1f45e0\n");
}

int main() {
    test_filter_520_dispatches_340d70();
    test_filter_non520_dispatches_1f45e0();
    printf("All tactical_ai_action_filter_340d30 native tests passed!\n");
    return 0;
}
