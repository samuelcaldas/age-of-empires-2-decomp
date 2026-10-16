#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "unit_action_build_state.h"

static int g_func_273810_called = 0;
static int g_func_1D0F00_called = 0;
static int g_func_1D1100_called = 0;

extern "C" {
    int func_1233E0(float val) { return (int)val; }
    int func_123350(float val) { return (int)val; }
    void func_273810(ActionRebind *self) { (void)self; g_func_273810_called++; }
    void func_1D0F00(void *zone, int x, int y, int a3, int a4) {
        (void)zone; (void)x; (void)y; (void)a3; (void)a4;
        g_func_1D0F00_called++;
    }
    void func_1D1100(void *zone, int x, int y) {
        (void)zone; (void)x; (void)y;
        g_func_1D1100_called++;
    }
}

struct ExtendedMock {
    void *vtable;
    void *m_field4;
    char pad_08[0x35 - 0x8];
    char m_field35;
    char pad_36[0x44 - 0x36];
    float m_x;
    float m_y;
};

struct DummyEntity {
    char pad[0x20];
    float ext_x;
    float ext_y;
};

// Case 0: func_0026E1E0 work state dispatch
static void test_set_work_state() {
    ExtendedMock mock;
    memset(&mock, 0, sizeof(mock));
    ActionRebind *act = (ActionRebind*)&mock;

    g_func_273810_called = 0;
    func_0026E1E0(act, 0x11, 42.8f);
    assert(mock.m_field35 == 42);
    assert(g_func_273810_called == 0);

    func_0026E1E0(act, 0x05, 42.8f);
    assert(g_func_273810_called == 1);
}

// Case 1: func_0026E230 footprint tile updates
static void test_footprint_tile_updates() {
    ExtendedMock mock;
    memset(&mock, 0, sizeof(mock));
    ActionRebind *act = (ActionRebind*)&mock;

    DummyEntity ent;
    ent.ext_x = 1.0f;
    ent.ext_y = 1.0f;
    mock.m_field4 = &ent;
    mock.m_x = 10.0f;
    mock.m_y = 20.0f;

    char dummy_zone[16];
    g_func_1D0F00_called = 0;
    g_func_1D1100_called = 0;

    func_0026E230(act, dummy_zone);

    // Range [9..11] x [19..21] is 3x3 = 9 tiles
    assert(g_func_1D0F00_called == 9);
    assert(g_func_1D1100_called == 9);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_set_work_state();
        test_footprint_tile_updates();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_set_work_state(); break;
        case 1: test_footprint_tile_updates(); break;
        default: return 1;
    }
    return 0;
}
