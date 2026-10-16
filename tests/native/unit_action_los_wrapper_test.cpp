#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "unit_action_los_wrapper.h"

static int g_func_26AD20_ret = 0;
static int g_add_los_called = 0;
static int g_remove_los_called = 0;
static int g_last_a2 = 0;
static int g_last_a4 = 0;

extern "C" {
    char func_26AD20(void *action, int flag) {
        (void)action; (void)flag;
        return (char)g_func_26AD20_ret;
    }
    int func_123350(float val) { return (int)val; }
    void func_00268A60(ActionRebind *self, void *zone, int a2, int a3, int a4) {
        (void)self; (void)zone; (void)a3;
        g_add_los_called++;
        g_last_a2 = a2;
        g_last_a4 = a4;
    }
    void func_00268C30(ActionRebind *self, void *zone, int a2, int a3, int a4) {
        (void)self; (void)zone; (void)a3;
        g_remove_los_called++;
        g_last_a2 = a2;
        g_last_a4 = a4;
    }
}

struct DummyEntity {
    char pad[0x20];
    float ext_x;
    float ext_y;
};

// Case 0: func_0026D960 with flag 0x4000 clear overrides a2 = 1
static void test_add_los_flag_clear() {
    char dummy_act[256] = {0};
    ActionRebind *act = (ActionRebind*)dummy_act;
    DummyEntity ent;
    ent.ext_x = 1.0f; ent.ext_y = 1.0f;
    act->m_field4 = &ent;

    g_func_26AD20_ret = 0; // flag clear
    g_add_los_called = 0;
    func_0026D960(act, nullptr, 99, 10, 5);

    assert(g_add_los_called == 1);
    assert(g_last_a2 == 1); // overridden to 1
    assert(g_last_a4 == 5); // preserves original a4
}

// Case 1: func_0026D960 with flag 0x4000 set and even extents overrides a4 = 1
static void test_add_los_flag_set_even() {
    char dummy_act[256] = {0};
    ActionRebind *act = (ActionRebind*)dummy_act;
    DummyEntity ent;
    ent.ext_x = 1.0f; ent.ext_y = 1.0f; // sum = 2 (even)
    act->m_field4 = &ent;

    g_func_26AD20_ret = 1; // flag set
    g_add_los_called = 0;
    func_0026D960(act, nullptr, 99, 10, 5);

    assert(g_add_los_called == 1);
    assert(g_last_a2 == 99); // original a2
    assert(g_last_a4 == 1);  // overridden to 1 because sum is even
}

// Case 2: func_0026DA20 remove LOS with flag clear preserves a4
static void test_remove_los_flag_clear() {
    char dummy_act[256] = {0};
    ActionRebind *act = (ActionRebind*)dummy_act;
    DummyEntity ent;
    ent.ext_x = 1.0f; ent.ext_y = 1.0f;
    act->m_field4 = &ent;

    g_func_26AD20_ret = 0;
    g_remove_los_called = 0;
    func_0026DA20(act, nullptr, 77, 10, 9);

    assert(g_remove_los_called == 1);
    assert(g_last_a2 == 77);
    assert(g_last_a4 == 9);
}

// Case 3: func_0026DA20 remove LOS with flag set and even extents overrides a4 = 1
static void test_remove_los_flag_set_even() {
    char dummy_act[256] = {0};
    ActionRebind *act = (ActionRebind*)dummy_act;
    DummyEntity ent;
    ent.ext_x = 2.0f; ent.ext_y = 2.0f; // sum = 4 (even)
    act->m_field4 = &ent;

    g_func_26AD20_ret = 1;
    g_remove_los_called = 0;
    func_0026DA20(act, nullptr, 77, 10, 9);

    assert(g_remove_los_called == 1);
    assert(g_last_a2 == 77);
    assert(g_last_a4 == 1);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_add_los_flag_clear();
        test_add_los_flag_set_even();
        test_remove_los_flag_clear();
        test_remove_los_flag_set_even();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_add_los_flag_clear(); break;
        case 1: test_add_los_flag_set_even(); break;
        case 2: test_remove_los_flag_clear(); break;
        case 3: test_remove_los_flag_set_even(); break;
        default: return 1;
    }
    return 0;
}
