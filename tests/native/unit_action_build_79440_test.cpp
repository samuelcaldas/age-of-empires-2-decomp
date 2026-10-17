// Tests for func_00279440 & func_002794B0 — Milestone 120 (412B)
// Verifies clear flag & order move, and task query status evaluation.
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_79440.h"

static int g_flag_cleared = 0;
static int g_ordered_move = 0;
static int g_func_347810_called = 0;

extern "C" {
    void func_26AD60(void *, int) { g_flag_cleared++; }
    void func_13A0A0(void *, void *, float, float, float) { g_ordered_move++; }
    static unsigned char g_active_task[16];
    static bool g_has_active_task = true;
    void *func_139860(void *) {
        return g_has_active_task ? g_active_task : nullptr;
    }
    void func_347810(void *, short *out_flag) {
        g_func_347810_called++;
        *out_flag = 42;
    }
    void func_347880(void *, short *, short *, int, int) {}
}

static void test_clear_flag_and_order_move() {
    unsigned char self[256], target[256];
    g_flag_cleared = 0;
    g_ordered_move = 0;
    func_00279440(self, target, 1.0f, 2.0f, 3.0f);
    assert(g_flag_cleared == 1);
    assert(g_ordered_move == 1);
    printf("PASS test_clear_flag_and_order_move\n");
}

static void test_task_query_pack_action() {
    unsigned char self[512], action_mgr[64];
    std::memset(self, 0, sizeof(self));
    void *action_mgr_ptr = action_mgr;

#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x138, &action_mgr_ptr, sizeof(void *));
#else
    std::memcpy(self + 0xCC, &action_mgr_ptr, sizeof(void *));
#endif

    short action = 0x7D; // Pack action
    std::memcpy(g_active_task + 0x4, &action, sizeof(short));
    g_has_active_task = true;
    g_func_347810_called = 0;

    short out_action = 0, out_f1 = 0, out_f2 = 0;
    int ret = func_002794B0(self, &out_action, &out_f1, &out_f2);
    assert(ret == 1);
    assert(out_action == 0x7D);
    assert(out_f1 == -1);
    assert(out_f2 == 42);
    assert(g_func_347810_called == 1);
    printf("PASS test_task_query_pack_action\n");
}

int main() {
    test_clear_flag_and_order_move();
    test_task_query_pack_action();
    printf("All unit_action_build_79440 tests passed!\n");
    return 0;
}
