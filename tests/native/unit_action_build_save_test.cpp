#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "unit_action_build_save.h"

static int g_func_273330_called = 0;
static int g_func_226F70_called = 0;
static int g_baselist_save_called = 0;
static int g_total_bytes_written = 0;

extern "C" {
    char func_26AD20(void *action, int flag) { (void)action; (void)flag; return 1; }
    void func_273330(ActionRebind *self, void *stream) {
        (void)self; (void)stream;
        g_func_273330_called++;
    }
    void func_00226F70(void *stream, void *buffer, int size) {
        (void)stream; (void)buffer;
        g_func_226F70_called++;
        g_total_bytes_written += size;
    }
    void Save__8BaseListFPv(void *item, void *stream) {
        (void)item; (void)stream;
        g_baselist_save_called++;
    }
}

// Case 0: Guard checks on null inputs
static void test_save_guards() {
    char dummy_act[0x200] = {0};
    ActionRebind *act = (ActionRebind*)dummy_act;
    char dummy_stream[16];

    g_func_273330_called = 0;
    func_0026DAC0(nullptr, dummy_stream);
    assert(g_func_273330_called == 0);

    func_0026DAC0(act, nullptr);
    assert(g_func_273330_called == 0);
}

// Case 1: Stream serialization writes header, state, and trailing fields
static void test_save_execution_flow() {
    char dummy_act[0x200] = {0};
    ActionRebind *act = (ActionRebind*)dummy_act;
    char dummy_stream[16];

    char dummy_world[0xC00] = {0};
    act->m_world = (WorldExtended*)dummy_world;

    g_func_273330_called = 0;
    g_func_226F70_called = 0;
    g_total_bytes_written = 0;

    func_0026DAC0(act, dummy_stream);

    assert(g_func_273330_called == 1);
    assert(g_func_226F70_called > 10);
    assert(g_total_bytes_written > 50);
}

// Case 2: BaseList item serialization when items present
static void test_save_items_dispatch() {
    char dummy_act[0x200] = {0};
    ActionRebind *act = (ActionRebind*)dummy_act;
    char dummy_stream[16];

    char item1[16];
    char item2[16];
    char item3[16];
    *(void**)((char*)act + 0x128) = item1;
    *(void**)((char*)act + 0x12C) = item2;
    *(void**)((char*)act + 0x14C) = item3;

    g_baselist_save_called = 0;
    func_0026DAC0(act, dummy_stream);
    assert(g_baselist_save_called == 3);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_save_guards();
        test_save_execution_flow();
        test_save_items_dispatch();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_save_guards(); break;
        case 1: test_save_execution_flow(); break;
        case 2: test_save_items_dispatch(); break;
        default: return 1;
    }
    return 0;
}
