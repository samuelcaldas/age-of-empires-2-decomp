#include <cassert>
#include <cstdio>
#include "tactical_ai_check_340cf0.h"

static void *g_last_called_ptr = nullptr;
static int g_mock_return_val = 0;
static int g_call_count = 0;

extern "C" {
int func_210010(void *ptr) {
    g_last_called_ptr = ptr;
    g_call_count++;
    return g_mock_return_val;
}
}

static void reset_mock() {
    g_last_called_ptr = nullptr;
    g_mock_return_val = 0;
    g_call_count = 0;
}

static void test_null_subpointer_returns_one() {
    reset_mock();
    TacticalObj_340CF0 obj;
    obj.field_838 = nullptr;

    int ret = func_00340CF0(&obj);
    assert(ret == 1);
    assert(g_call_count == 0);
    printf("PASS test_null_subpointer_returns_one\n");
}

static void test_valid_subpointer_dispatches_func_210010() {
    reset_mock();
    TacticalObj_340CF0 obj;
    int dummy = 42;
    obj.field_838 = &dummy;

    // When func_210010 returns 0, func_00340CF0 should return 1
    g_mock_return_val = 0;
    int ret = func_00340CF0(&obj);
    assert(ret == 1);
    assert(g_call_count == 1);
    assert(g_last_called_ptr == &dummy);

    // When func_210010 returns non-zero, func_00340CF0 should return 0
    reset_mock();
    g_mock_return_val = 5;
    ret = func_00340CF0(&obj);
    assert(ret == 0);
    assert(g_call_count == 1);
    assert(g_last_called_ptr == &dummy);

    printf("PASS test_valid_subpointer_dispatches_func_210010\n");
}

int main() {
    test_null_subpointer_returns_one();
    test_valid_subpointer_dispatches_func_210010();
    printf("All tactical_ai_check_340cf0 native tests passed!\n");
    return 0;
}
