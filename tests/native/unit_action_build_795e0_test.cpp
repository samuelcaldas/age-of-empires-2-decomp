// Tests for func_002795E0, func_00279660, func_00279690, func_002796C0 — Milestone 121 (272B)
// Verifies attack task ordering and attacker count manipulation.
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_795e0.h"

static int g_action_stopped = 0;
static int g_task_bound = 0;
static int g_task_added = 0;

extern "C" {
    void func_138D10(void *) { g_action_stopped++; }
    void *func_366DA0(void *) {
        static int mock_task = 1;
        return &mock_task;
    }
    void func_365740(void *, void *, void *) { g_task_bound++; }
    void func_139430(void *, void *) { g_task_added++; }
    float func_1DEA80(void *) { return 15.0f; }
}

static void test_attacker_count_and_combat_attr() {
    unsigned char self[512];
    std::memset(self, 0, sizeof(self));

    // Initially 0 attackers
    assert(func_002796C0(self) == 0.0f);

    // Increment
    assert(func_00279660(self) == 1);
    short count1 = *(short *)(self + 0x124);
    assert(count1 == 1);
    assert(func_002796C0(self) == 15.0f);

    // Decrement
    assert(func_00279690(self) == 1);
    short count0 = *(short *)(self + 0x124);
    assert(count0 == 0);
    assert(func_002796C0(self) == 0.0f);

    // Decrement when 0 -> stays 0
    assert(func_00279690(self) == 1);
    short count_zero = *(short *)(self + 0x124);
    assert(count_zero == 0);

    printf("PASS test_attacker_count_and_combat_attr\n");
}

static void test_order_attack_task() {
    unsigned char self[512], target[256], action_mgr[64];
    std::memset(self, 0, sizeof(self));
    void *action_mgr_ptr = action_mgr;

#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x138, &action_mgr_ptr, sizeof(void *));
#else
    std::memcpy(self + 0xCC, &action_mgr_ptr, sizeof(void *));
#endif

    g_action_stopped = 0;
    g_task_bound = 0;
    g_task_added = 0;

    func_002795E0(self, target);

    assert(g_action_stopped == 1);
    assert(g_task_bound == 1);
    assert(g_task_added == 1);
    printf("PASS test_order_attack_task\n");
}

int main() {
    test_attacker_count_and_combat_attr();
    test_order_attack_task();
    printf("All unit_action_build_795e0 tests passed!\n");
    return 0;
}
