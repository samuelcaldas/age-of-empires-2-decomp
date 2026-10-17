#include <cassert>
#include <cstdio>
#include <cstdlib>
#include "unit_action_build_target_validate_fixture.h"

static void reset_test_state() {
    g_func_1950d0_called = g_gethead_called = 0;
    g_gethead_ret = nullptr;
    g_callmethod13_called = g_freelist_called = g_func_270530_called = 0;
    g_last_freelist_ptr = nullptr;
}

static void test_master_types_50_199_276_early_return() {
    short excluded_types[3] = { 50, 199, 276 };
    for (int i = 0; i < 3; ++i) {
        reset_test_state();
        DummyValidateMaster master = { {}, excluded_types[i] };
        DummyValidateAction action = { nullptr, &master, {}, (void*)0x1234 };
        func_00270EF0((ActionRebind*)&action);
        assert(g_func_1950d0_called == 0);
        assert(g_gethead_called == 0);
        assert(g_func_270530_called == 0);
    }
}

static void test_head_item_present_calls_method13_and_free() {
    reset_test_state();
    g_gethead_ret = (void*)0xABCD;
    DummyValidateMaster master = { {}, 100 };
    void *target_ptr = (void*)0x5678;
    DummyValidateAction action = { nullptr, &master, {}, target_ptr };
    func_00270EF0((ActionRebind*)&action);
    assert(g_func_1950d0_called == 1);
    assert(g_gethead_called == 1);
    assert(g_callmethod13_called == 1);
    assert(g_freelist_called == 1);
    assert(g_last_freelist_ptr == target_ptr);
    assert(g_func_270530_called == 0);
}

static void test_head_item_null_calls_worker_clear() {
    reset_test_state();
    g_gethead_ret = nullptr;
    DummyValidateMaster master = { {}, 100 };
    DummyValidateAction action = { nullptr, &master, {}, (void*)0x5678 };
    func_00270EF0((ActionRebind*)&action);
    assert(g_func_1950d0_called == 1);
    assert(g_gethead_called == 1);
    assert(g_callmethod13_called == 0);
    assert(g_freelist_called == 0);
    assert(g_func_270530_called == 1);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_master_types_50_199_276_early_return();
        test_head_item_present_calls_method13_and_free();
        test_head_item_null_calls_worker_clear();
        return 0;
    }
    int t = atoi(argv[1]);
    if (t == 0) test_master_types_50_199_276_early_return();
    if (t == 1) test_head_item_present_calls_method13_and_free();
    if (t == 2) test_head_item_null_calls_worker_clear();
    return 0;
}
