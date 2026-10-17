#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "unit_action_build_cancel_task_fixture.h"

static int g_free_called = 0;
static void *g_last_freed_ptr = nullptr;

extern "C" {
    void func_116F68(void *ptr) {
        g_free_called++;
        g_last_freed_ptr = ptr;
    }
}

static void reset_test_state() {
    g_free_called = 0;
    g_last_freed_ptr = nullptr;
}

// Case 0: count != 0 skips free and preserves slots and cap
static void test_active_count() {
    reset_test_state();
    char dummy_slots[16];
    DummyCancelAction action = {};
    action.m_count = 2; // active!
    action.m_slots = dummy_slots;
    action.m_cap = 15;

    func_0026FF60((ActionRebind*)&action);

    assert(g_free_called == 0);
    assert(action.m_slots == dummy_slots);
    assert(action.m_cap == 15);
}

// Case 1: count == 0 and slots == nullptr clears cap without free
static void test_zero_count_null_slots() {
    reset_test_state();
    DummyCancelAction action = {};
    action.m_count = 0;
    action.m_slots = nullptr;
    action.m_cap = 15;

    func_0026FF60((ActionRebind*)&action);

    assert(g_free_called == 0);
    assert(action.m_cap == 0);
}

// Case 2: count == 0 and slots != nullptr frees slots and clears cap
static void test_zero_count_free() {
    reset_test_state();
    char dummy_slots[16];
    DummyCancelAction action = {};
    action.m_count = 0;
    action.m_slots = dummy_slots;
    action.m_cap = 15;

    func_0026FF60((ActionRebind*)&action);

    assert(g_free_called == 1);
    assert(g_last_freed_ptr == dummy_slots);
    assert(action.m_slots == nullptr);
    assert(action.m_cap == 0);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_active_count();
        test_zero_count_null_slots();
        test_zero_count_free();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_active_count(); break;
        case 1: test_zero_count_null_slots(); break;
        case 2: test_zero_count_free(); break;
        default: return 1;
    }
    return 0;
}
