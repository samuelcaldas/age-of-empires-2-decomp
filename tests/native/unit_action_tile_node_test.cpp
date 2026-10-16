#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "unit_action_tile_node.h"

static int g_func_3357B0_called = 0;
static int g_func_335920_called = 0;
static int g_func_334FC0_called = 0;
static short g_last_val = 0;

extern "C" {
    void func_003357B0(void *arg0, short val) {
        (void)arg0;
        g_func_3357B0_called++;
        g_last_val = val;
    }
    void func_00335920(void *arg0, short val) {
        (void)arg0;
        g_func_335920_called++;
        g_last_val = val;
    }
    void func_00334FC0(void *arg0, short val) {
        (void)arg0;
        g_func_334FC0_called++;
        g_last_val = val;
    }
}

struct DummyTileNode {
    char pad_00[4];
    void *m_field4; // 0x04
    void *m_field8; // 0x08
    char pad_0C[0x54];
    short m_field60; // 0x60
};

// Case 0: func_00269D80 node detach and guards
static void test_func_00269D80() {
    g_func_3357B0_called = 0;
    func_00269D80(nullptr, 0, 0);
    assert(g_func_3357B0_called == 0);

    DummyTileNode node;
    memset(&node, 0, sizeof(node));
    node.m_field60 = -1;
    func_00269D80(&node, 0, 0);
    assert(g_func_3357B0_called == 0);

    node.m_field60 = 42;
    func_00269D80(&node, 0, 0);
    assert(g_func_3357B0_called == 1);
    assert(g_func_335920_called == 1);
    assert(g_func_334FC0_called == 1);
    assert(g_last_val == 42);
    assert(node.m_field60 == -1);
}

// Case 1: func_00269E50 node attach with previous detach
static void test_func_00269E50() {
    DummyTileNode node;
    memset(&node, 0, sizeof(node));
    node.m_field60 = -1;

    g_func_3357B0_called = 0;
    func_00269E50((ActionRebind*)&node, 99, 0);
    assert(g_func_3357B0_called == 0);
    assert(node.m_field60 == 99);

    // Re-attaching detaches old
    func_00269E50((ActionRebind*)&node, 105, 0);
    assert(g_func_3357B0_called == 1);
    assert(g_last_val == 99);
    assert(node.m_field60 == 105);
}

// Case 2: func_00269F30 node teardown
static void test_func_00269F30() {
    DummyTileNode node;
    memset(&node, 0, sizeof(node));
    node.m_field60 = 77;

    g_func_3357B0_called = 0;
    func_00269F30((ActionRebind*)&node, 0, 0);
    assert(g_func_3357B0_called == 1);
    assert(g_last_val == 77);
    assert(node.m_field60 == -1);

    // Subsequent call does nothing
    func_00269F30((ActionRebind*)&node, 0, 0);
    assert(g_func_3357B0_called == 1);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_func_00269D80();
        test_func_00269E50();
        test_func_00269F30();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_func_00269D80(); break;
        case 1: test_func_00269E50(); break;
        case 2: test_func_00269F30(); break;
        default: return 1;
    }
    return 0;
}
