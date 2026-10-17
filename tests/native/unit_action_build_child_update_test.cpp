#include <cassert>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "unit_action_build_child_update_fixture.h"

static int g_func_271B40_called = 0;
static int g_func_271B40_ret = 1;
static int g_func_26F8A0_called = 0;
static int g_func_2697B0_called = 0;
static int g_func_332E60_called = 0;
static int g_func_14BCE0_called = 0;
static int g_func_14C7F0_called = 0;
static unsigned char g_last_14C7F0_param = 0;

static int g_m58_called = 0;
static int g_m17_called = 0;
static int g_m89_called = 0;
static int g_m81_called = 0;
static int g_m42_called = 0;
static int g_m192_called = 0;
static int g_sub23_called = 0;

extern "C" {
    int func_271B40(void *self, void *child_field4, float *out_x, float *out_y) {
        (void)self; (void)child_field4;
        g_func_271B40_called++;
        *out_x = 10.0f;
        *out_y = 20.0f;
        return g_func_271B40_ret;
    }

    void func_0026F8A0(ActionRebind *self) {
        (void)self;
        g_func_26F8A0_called++;
    }

    void func_2697B0(void *child, float x, float y, float z) {
        (void)child; (void)x; (void)y; (void)z;
        g_func_2697B0_called++;
    }

    void* func_332E60(void *fieldB98) {
        (void)fieldB98;
        g_func_332E60_called++;
        static DummyTargetMaster tm = { 10 };
        static DummyTargetUnit tu = { {}, &tm };
        return &tu;
    }

    void func_14BCE0(void *obj) {
        (void)obj;
        g_func_14BCE0_called++;
    }

    void func_14C7F0(void *obj, unsigned char param) {
        (void)obj;
        g_func_14C7F0_called++;
        g_last_14C7F0_param = param;
    }
}

static void mock_m58(void *c) { (void)c; g_m58_called++; }
static void mock_m17(void *c, float px, float py, float pz) { (void)c; (void)px; (void)py; (void)pz; g_m17_called++; }

static DummySubObject g_dummy_sub = {};
static DummySubObject *g_sub_ptr = &g_dummy_sub;

static void* mock_m89(void *c) { (void)c; g_m89_called++; return &g_sub_ptr; }
static void mock_m81(void *c, int val) { (void)c; (void)val; g_m81_called++; }
static void mock_m42(void *c, void *tgt, float tx, float ty, float fz) { (void)c; (void)tgt; (void)tx; (void)ty; (void)fz; g_m42_called++; }
static void mock_m192(void *c, int zero, void *tgt, int mode, float tx, float ty, float fz) { (void)c; (void)zero; (void)tgt; (void)mode; (void)tx; (void)ty; (void)fz; g_m192_called++; }
static void mock_sub23(void *s, int val) { (void)s; (void)val; g_sub23_called++; }

static void *dummy_child_vt[256] = {};
static void *dummy_sub_vt[32] = {};

static void init_test_vtables() {
    memset(dummy_child_vt, 0, sizeof(dummy_child_vt));
    dummy_child_vt[58] = (void*)mock_m58;
    dummy_child_vt[17] = (void*)mock_m17;
    dummy_child_vt[89] = (void*)mock_m89;
    dummy_child_vt[81] = (void*)mock_m81;
    dummy_child_vt[42] = (void*)mock_m42;
    dummy_child_vt[192] = (void*)mock_m192;

    memset(dummy_sub_vt, 0, sizeof(dummy_sub_vt));
    dummy_sub_vt[23] = (void*)mock_sub23;
    g_dummy_sub.vtable = dummy_sub_vt;
    g_dummy_sub.m_param46 = 77;
}

static void reset_test_state() {
    g_func_271B40_called = g_func_26F8A0_called = g_func_2697B0_called = 0;
    g_func_332E60_called = g_func_14BCE0_called = g_func_14C7F0_called = 0;
    g_func_271B40_ret = 1;
    g_last_14C7F0_param = 0;
    g_m58_called = g_m17_called = g_m89_called = g_m81_called = g_m42_called = g_m192_called = g_sub23_called = 0;
}

// Case 0: func_271B40 returns 0 exits immediately with 0
static void test_early_exit_fail() {
    reset_test_state();
    init_test_vtables();
    g_func_271B40_ret = 0;
    DummySelfAction self = {};
    DummyChildUnit child = { dummy_child_vt };
    int ret = func_0026F590((ActionRebind*)&self, (ActionRebind*)&child, 0.0f, 0.0f);
    assert(ret == 0 && g_func_271B40_called == 1 && g_func_26F8A0_called == 0);
}

// Case 1: valid x and y forwards coordinates and calls Method42
static void test_valid_coordinates() {
    reset_test_state();
    init_test_vtables();
    DummySelfAction self = {};
    self.m_z = 3.5f;
    DummyChildUnit child = { dummy_child_vt };
    int ret = func_0026F590((ActionRebind*)&self, (ActionRebind*)&child, 50.0f, 60.0f);
    assert(ret == 1 && g_func_26F8A0_called == 1 && g_func_2697B0_called == 1);
    assert(g_m58_called == 1 && g_m17_called == 1 && g_m81_called == 1 && g_m42_called == 1);
}

// Case 2: x == -1.0f resolves target unit from world and dispatches Method42
static void test_resolve_target() {
    reset_test_state();
    init_test_vtables();
    DummyWorldObj world = {};
    DummySelfAction self = {};
    self.m_world = &world;
    self.m_flag15B = 1;
    self.m_field168 = 10;
    self.m_field24 = 20;
    self.m_target_x = 100.0f;
    self.m_target_y = 200.0f;
    DummyChildUnit child = { dummy_child_vt };
    int ret = func_0026F590((ActionRebind*)&self, (ActionRebind*)&child, -1.0f, 0.0f);
    assert(ret == 1 && g_func_332E60_called == 1 && g_m42_called == 1);
}

// Case 3: sentinel fallback invokes sub23 and func_14C7F0
static void test_sentinel_fallback() {
    reset_test_state();
    init_test_vtables();
    DummySelfAction self = {};
    DummyChildUnit child = { dummy_child_vt };
    int ret = func_0026F590((ActionRebind*)&self, (ActionRebind*)&child, -1.0f, -1.0f);
    assert(ret == 1 && g_sub23_called == 1 && g_func_14C7F0_called == 1 && g_last_14C7F0_param == 77);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_early_exit_fail();
        test_valid_coordinates();
        test_resolve_target();
        test_sentinel_fallback();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_early_exit_fail(); break;
        case 1: test_valid_coordinates(); break;
        case 2: test_resolve_target(); break;
        case 3: test_sentinel_fallback(); break;
        default: return 1;
    }
    return 0;
}
