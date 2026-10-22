#include <cassert>
#include <cstdio>
#include <cstdlib>
#include "unit_action_build_has_tasks_fixture.h"

static int g_has_items_called = 0;
static void *g_last_list = nullptr;
static int g_mock_has_items_cc = 0;
static int g_mock_has_items_14c = 0;

extern "C" {
    int HasItems__8BaseListFv(void *list) {
        g_has_items_called++;
        g_last_list = list;
        if (list == (void*)0xCCCC) {
            return g_mock_has_items_cc;
        }
        if (list == (void*)0x1414) {
            return g_mock_has_items_14c;
        }
        return 0;
    }
}

static void reset_state() {
    g_has_items_called = 0;
    g_last_list = nullptr;
    g_mock_has_items_cc = g_mock_has_items_14c = 0;
}

static void test_list_cc_has_items_returns_one() {
    reset_state();
    g_mock_has_items_cc = 1;
    DummyTasksAction action = { nullptr, {}, (void*)0xCCCC, {}, (void*)0x1414 };
    int res = func_002714B0((ActionRebind*)&action);
    assert(g_has_items_called == 1 && g_last_list == (void*)0xCCCC);
    assert(res == 1);
}

static void test_list_14c_has_items_returns_one() {
    reset_state();
    g_mock_has_items_cc = 0;
    g_mock_has_items_14c = 1;
    DummyTasksAction action = { nullptr, {}, (void*)0xCCCC, {}, (void*)0x1414 };
    int res = func_002714B0((ActionRebind*)&action);
    assert(g_has_items_called == 2 && g_last_list == (void*)0x1414);
    assert(res == 1);
}

static void test_both_lists_empty_returns_zero() {
    reset_state();
    g_mock_has_items_cc = 0;
    g_mock_has_items_14c = 0;
    DummyTasksAction action = { nullptr, {}, (void*)0xCCCC, {}, (void*)0x1414 };
    int res = func_002714B0((ActionRebind*)&action);
    assert(g_has_items_called == 2);
    assert(res == 0);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_list_cc_has_items_returns_one();
        test_list_14c_has_items_returns_one();
        test_both_lists_empty_returns_zero();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_list_cc_has_items_returns_one(); break;
        case 1: test_list_14c_has_items_returns_one(); break;
        case 2: test_both_lists_empty_returns_zero(); break;
        default: return 1;
    }
    return 0;
}
