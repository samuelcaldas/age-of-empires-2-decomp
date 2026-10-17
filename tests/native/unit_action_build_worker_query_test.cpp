#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "unit_action_build_worker_query_fixture.h"

// Case 0: count == 0 returns -1 immediately
static void test_zero_count() {
    DummyQueryAction action = {};
    action.m_count = 0;

    int ret = func_002703C0((ActionRebind*)&action, 0);
    assert(ret == -1);
}

// Case 1: worker_index in slot 0 returns slot 0 task_id
static void test_slot0_lookup() {
    struct Slot { short id; short amt; } slots[2] = { { 42, 3 }, { 88, 2 } };

    DummyQueryAction action = {};
    action.m_slots = slots;
    action.m_count = 2;

    int ret0 = func_002703C0((ActionRebind*)&action, 0);
    int ret1 = func_002703C0((ActionRebind*)&action, 1);
    int ret2 = func_002703C0((ActionRebind*)&action, 2);

    assert(ret0 == 42);
    assert(ret1 == 42);
    assert(ret2 == 42);
}

// Case 2: worker_index in slot 1 returns slot 1 task_id
static void test_slot1_lookup() {
    struct Slot { short id; short amt; } slots[2] = { { 42, 3 }, { 88, 2 } };

    DummyQueryAction action = {};
    action.m_slots = slots;
    action.m_count = 2;

    int ret3 = func_002703C0((ActionRebind*)&action, 3);
    int ret4 = func_002703C0((ActionRebind*)&action, 4);

    assert(ret3 == 88);
    assert(ret4 == 88);
}

// Case 3: worker_index out of bounds returns -1
static void test_out_of_bounds() {
    struct Slot { short id; short amt; } slots[2] = { { 42, 3 }, { 88, 2 } };

    DummyQueryAction action = {};
    action.m_slots = slots;
    action.m_count = 2;

    int ret5 = func_002703C0((ActionRebind*)&action, 5);
    int ret10 = func_002703C0((ActionRebind*)&action, 10);

    assert(ret5 == -1);
    assert(ret10 == -1);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_zero_count();
        test_slot0_lookup();
        test_slot1_lookup();
        test_out_of_bounds();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_zero_count(); break;
        case 1: test_slot0_lookup(); break;
        case 2: test_slot1_lookup(); break;
        case 3: test_out_of_bounds(); break;
        default: return 1;
    }
    return 0;
}
