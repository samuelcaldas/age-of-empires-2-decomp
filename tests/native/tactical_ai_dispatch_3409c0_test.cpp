#include <cassert>
#include <cstdio>
#include "tactical_ai_dispatch_3409c0.h"

static void *g_last_340c30_ptr = nullptr;
static int g_call_count_340c30 = 0;
static void *g_last_1f8140_ptr = nullptr;
static int g_call_count_1f8140 = 0;
static int g_mock_1f8140_ret = 77;

extern "C" {
int func_340C30(void *self) {
    g_last_340c30_ptr = self;
    g_call_count_340c30++;
    return 123;
}

int func_1F8140(void *self) {
    g_last_1f8140_ptr = self;
    g_call_count_1f8140++;
    return g_mock_1f8140_ret;
}
}

static void reset_mocks() {
    g_last_340c30_ptr = nullptr;
    g_call_count_340c30 = 0;
    g_last_1f8140_ptr = nullptr;
    g_call_count_1f8140 = 0;
    g_mock_1f8140_ret = 77;
}

static void test_field_858_nonzero_dispatches_340c30_and_returns_zero() {
    reset_mocks();
    TacticalObj_3409C0 obj;
    obj.field_858 = 1;

    int ret = func_003409C0(&obj);
    assert(ret == 0);
    assert(g_call_count_340c30 == 1);
    assert(g_last_340c30_ptr == &obj);
    assert(g_call_count_1f8140 == 0);
    printf("PASS test_field_858_nonzero_dispatches_340c30_and_returns_zero\n");
}

static void test_field_858_zero_dispatches_1f8140_and_returns_its_value() {
    reset_mocks();
    TacticalObj_3409C0 obj;
    obj.field_858 = 0;
    g_mock_1f8140_ret = 42;

    int ret = func_003409C0(&obj);
    assert(ret == 42);
    assert(g_call_count_1f8140 == 1);
    assert(g_last_1f8140_ptr == &obj);
    assert(g_call_count_340c30 == 0);
    printf("PASS test_field_858_zero_dispatches_1f8140_and_returns_its_value\n");
}

int main() {
    test_field_858_nonzero_dispatches_340c30_and_returns_zero();
    test_field_858_zero_dispatches_1f8140_and_returns_its_value();
    printf("All tactical_ai_dispatch_3409c0 native tests passed!\n");
    return 0;
}
