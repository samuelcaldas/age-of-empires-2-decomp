#include "render_manager_command.h"
#include <cassert>
#include <cstdlib>

int D_004E8990 = 0;
static int g_18ffd0_val = 15, g_d8_called = 0, g_d8_a2 = -1;
static int g_8c_called = 0, g_8c_val = -1, g_f8_called = 0, g_f8_ret = 1;

static void mock_d8(void *, int, int a2) { g_d8_called++; g_d8_a2 = a2; }
static void mock_8c(void *, int v) { g_8c_called++; g_8c_val = v; }
static int mock_f8(void *, int, int) { g_f8_called++; return g_f8_ret; }

static void *g_player_vt[70] = {0};
static void *g_sub_vt[40] = {0};
static void *g_mgr_vt[80] = {0};

struct FakePlayer { void *vt0; char p[0x1B30 - 4]; void *vt; } g_player = {g_player_vt, {}, g_player_vt};
static FakePlayer *g_player_ptrs[2] = {&g_player, &g_player};
struct FakeSub { void *vt; char p[0x50]; FakePlayer **f54; } g_sub = {g_sub_vt, {}, g_player_ptrs};

struct FakeMgr {
    void *vt; char p1[0x1A8]; void *f1ac; char p2[0x254]; FakeSub *f404;
};

extern "C" {
int func_18FFD0(void *) { return g_18ffd0_val; }
int func_188870(void *, int) { return 0; }
}

static void init_vt() {
    g_player_vt[52] = g_player_vt[54] = (void *)mock_d8;
    g_sub_vt[33] = g_sub_vt[35] = (void *)mock_8c;
    g_mgr_vt[60] = g_mgr_vt[62] = (void *)mock_f8;
}

static void test_stub_6db0() {
    assert(func_00186db0() == 1);
}

static void test_command_6076() {
    FakeMgr mgr = {g_mgr_vt, {}, (void *)0x111, {}, &g_sub};
    g_18ffd0_val = 15; D_004E8990 = 0; g_d8_called = 0; g_f8_ret = 1;
    assert(func_00186c20((RenderManagerCommand *)&mgr, 0, 0, 6076, 42) == 1);
    assert(g_d8_called == 1 && g_d8_a2 == 1 && g_f8_called == 1);
}

static void test_command_6077() {
    FakeMgr mgr = {g_mgr_vt, {}, (void *)0x111, {}, &g_sub};
    g_18ffd0_val = 15; D_004E8990 = 0; g_d8_called = 0; g_f8_ret = 0;
    assert(func_00186c20((RenderManagerCommand *)&mgr, 0, 0, 6077, 42) == 0);
    assert(g_d8_called == 1 && g_d8_a2 == 0);
}

static void test_command_switch_modes() {
    FakeMgr mgr = {g_mgr_vt, {}, (void *)0x111, {}, &g_sub};
    g_18ffd0_val = 10; // < 13 skips D8 dispatch
    g_d8_called = g_8c_called = 0; g_f8_ret = 1;
    assert(func_00186c20((RenderManagerCommand *)&mgr, 0, 0, 6050, 0) == 1);
    assert(g_d8_called == 0 && g_8c_called == 1 && g_8c_val == 1);

    g_8c_called = 0;
    assert(func_00186c20((RenderManagerCommand *)&mgr, 0, 0, 6051, 0) == 1);
    assert(g_8c_called == 1 && g_8c_val == 0);

    g_8c_called = 0;
    assert(func_00186c20((RenderManagerCommand *)&mgr, 0, 0, 6074, 0) == 1);
    assert(g_8c_called == 0);
}

int main(int count, char **args) {
    if (count != 2) return 1;
    init_vt();
    switch (std::atoi(args[1])) {
    case 0: test_stub_6db0(); return 0;
    case 1: test_command_6076(); return 0;
    case 2: test_command_6077(); return 0;
    case 3: test_command_switch_modes(); return 0;
    default: return 1;
    }
}
