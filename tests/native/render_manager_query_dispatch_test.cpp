#include "render_manager_query_dispatch.h"
#include <cassert>
#include <cstdlib>

static int g_fc_called = 0, g_fc_a1 = 0, g_fc_a2 = 0, g_fc_ret = 1;
static int g_100_called = 0, g_100_ret = 1;

static int mock_fc(void *, int a1, int a2) {
    g_fc_called++; g_fc_a1 = a1; g_fc_a2 = a2; return g_fc_ret;
}
static int mock_100(void *) { g_100_called++; return g_100_ret; }

static void *g_mgr_vt[80] = {0};
struct FakeMgr { void *vt; };

static void init_vt() {
    g_mgr_vt[61] = g_mgr_vt[63] = (void *)mock_fc;   // MethodFC (offset 252)
    g_mgr_vt[62] = g_mgr_vt[64] = (void *)mock_100;  // Method100 (offset 256)
}

static void test_stubs() {
    assert(func_00186e00() == 1);
    assert(func_00186e40() == 1);
}

static void test_method_fc_true() {
    FakeMgr mgr = {g_mgr_vt};
    g_fc_called = 0; g_fc_ret = 42;
    assert(func_00186dc0((RenderManagerQueryDispatch *)&mgr, 0, 0, 10, 20) == 1);
    assert(g_fc_called == 1 && g_fc_a1 == 10 && g_fc_a2 == 20);
}

static void test_method_fc_false() {
    FakeMgr mgr = {g_mgr_vt};
    g_fc_called = 0; g_fc_ret = 0;
    assert(func_00186dc0((RenderManagerQueryDispatch *)&mgr, 0, 0, 5, 15) == 0);
    assert(g_fc_called == 1 && g_fc_a1 == 5 && g_fc_a2 == 15);
}

static void test_method_100() {
    FakeMgr mgr = {g_mgr_vt};
    g_100_called = 0; g_100_ret = 100;
    assert(func_00186e10((RenderManagerQueryDispatch *)&mgr) == 1);
    assert(g_100_called == 1);
    g_100_ret = 0;
    assert(func_00186e10((RenderManagerQueryDispatch *)&mgr) == 0);
}

int main(int count, char **args) {
    if (count != 2) return 1;
    init_vt();
    switch (std::atoi(args[1])) {
    case 0: test_stubs(); return 0;
    case 1: test_method_fc_true(); return 0;
    case 2: test_method_fc_false(); return 0;
    case 3: test_method_100(); return 0;
    default: return 1;
    }
}
