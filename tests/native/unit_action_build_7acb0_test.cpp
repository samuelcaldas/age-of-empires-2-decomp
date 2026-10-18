// Tests for func_0027ACB0 — Milestone 133 (2076B)
// Verifies CombatManager periodic tick update and tactical zone scan.
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_7acb0.h"

static int g_func_27B4B0_called = 0;
static float g_last_threshold = 0.0f;
static int g_func_27B700_called = 0;

extern "C" {
    void func_27B4B0(void *, int, float val) {
        g_func_27B4B0_called++;
        g_last_threshold = val;
    }
    void func_27B700(void *) {
        g_func_27B700_called++;
    }
}

static void test_periodic_update_tick() {
    unsigned char self[0x1000], owner[0x2000], props[0x1000];
    std::memset(self, 0, sizeof(self));
    std::memset(owner, 0, sizeof(owner));
    std::memset(props, 0, sizeof(props));

    void *owner_ptr = owner;
    void *props_ptr = props;

#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x5D8, &owner_ptr, sizeof(void *));
    std::memcpy(owner + 0x1758, &props_ptr, sizeof(void *));
#else
    std::memcpy(self + 0x5D4, &owner_ptr, sizeof(void *));
    std::memcpy(owner + 0xBAC, &props_ptr, sizeof(void *));
#endif

    int interval = 5;
    std::memcpy(self + 0x5E4, &interval, sizeof(int));
    int counter = 0;
    std::memcpy(self + 0x5E8, &counter, sizeof(int));

    float val1 = 15.0f, val2 = 10.0f;
    std::memcpy(props + 0x94, &val1, sizeof(float));
    std::memcpy(props + 0xA0, &val2, sizeof(float));

    g_func_27B4B0_called = 0;
    g_func_27B700_called = 0;

    // Ticks 1 to 4: counter increments, tick skipped
    for (int i = 0; i < 4; ++i) {
        func_0027ACB0(self);
        assert(g_func_27B4B0_called == 0);
    }
    int cur_counter = *(int *)(self + 0x5E8);
    assert(cur_counter == 4);

    // Tick 5: interval reached -> update executes!
    func_0027ACB0(self);
    assert(g_func_27B4B0_called == 1);
    assert(g_last_threshold == 15.0f);
    assert(g_func_27B700_called == 1);
    cur_counter = *(int *)(self + 0x5E8);
    assert(cur_counter == 0);

    printf("PASS test_periodic_update_tick\n");
}

int main() {
    test_periodic_update_tick();
    printf("All unit_action_build_7acb0 tests passed!\n");
    return 0;
}
