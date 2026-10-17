#include <cassert>
#include <cstdio>
#include <cstdlib>
#include "unit_action_build_has_items_fixture.h"

static void reset_test_state() {
    g_hasitems_list1_ret = 0;
    g_hasitems_list2_ret = 0;
    g_hasitems_calls = 0;
}

static void test_first_list_has_items_returns_one() {
    reset_test_state();
    g_hasitems_list1_ret = 1;
    DummyHasItemsAction action = { nullptr, {}, (void*)0x1111, {}, (void*)0x2222 };
    int ret = func_002714B0((ActionRebind*)&action);
    assert(ret == 1);
    assert(g_hasitems_calls == 1);
}

static void test_second_list_has_items_returns_one() {
    reset_test_state();
    g_hasitems_list1_ret = 0;
    g_hasitems_list2_ret = 1;
    DummyHasItemsAction action = { nullptr, {}, (void*)0x1111, {}, (void*)0x2222 };
    int ret = func_002714B0((ActionRebind*)&action);
    assert(ret == 1);
    assert(g_hasitems_calls == 2);
}

static void test_neither_list_has_items_returns_zero() {
    reset_test_state();
    g_hasitems_list1_ret = 0;
    g_hasitems_list2_ret = 0;
    DummyHasItemsAction action = { nullptr, {}, (void*)0x1111, {}, (void*)0x2222 };
    int ret = func_002714B0((ActionRebind*)&action);
    assert(ret == 0);
    assert(g_hasitems_calls == 2);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_first_list_has_items_returns_one();
        test_second_list_has_items_returns_one();
        test_neither_list_has_items_returns_zero();
        return 0;
    }
    int t = atoi(argv[1]);
    if (t == 0) test_first_list_has_items_returns_one();
    if (t == 1) test_second_list_has_items_returns_one();
    if (t == 2) test_neither_list_has_items_returns_zero();
    return 0;
}
