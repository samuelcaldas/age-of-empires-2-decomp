#include "render_manager_window_proc.h"
#include <cassert>
#include <cstdlib>

int D_004E897C = 0, D_004E8998 = 0;
const char D_00491A28[] = "Status Screen", D_00491A38[] = "Comm Cancel";
static int g_mode = 0, g_f8 = 0, g_def = 0, g_60d0 = 0, g_1908 = 0, g_18bf = 0, g_1fb8 = 0, g_1f29 = 0;
static int g_b8 = 0, g_c0 = 0, g_dc = 0, g_e4 = 0;

static int sc_m50(void *, int a1, int a2, int a3, int a4) { (void)a1; (void)a3; (void)a4; return a2 == 999 ? 77 : 0; }
static void sc_mf8(void *) { g_f8++; }
static int r1(void *, int, int, int, int) { return 1; }
static int rb8(void *, int, int, int, int) { return g_b8; }
static int rc0(void *, int, int, int, int) { return g_c0; }
static int rdc(void *, int, int, int, int) { return g_dc; }
static int re4(void *, int, int, int, int) { return g_e4; }

static void *g_sc_vt[64] = {0}, *g_mgr_vt[64] = {0};
static struct { void *vt; } g_sc_obj = {g_sc_vt};
struct FakeMgr { void *vt; char p1[0x28]; int f2c, f30; char p2[0x38]; SubObj6C *f6c; char p3[0x13C]; void *f1ac; char p4[0x38]; int f1e8; };

extern "C" {
void func_00A80BB0() {}
ActiveScreen *func_1F26C0(void *) { return g_mode ? (ActiveScreen *)&g_sc_obj : 0; }
void *func_1F2700(void *, const char *) { return &g_sc_obj; }
void func_1908B0(void *, int) { g_1908++; }
void func_18BFA0(void *, int) { g_18bf++; }
void func_1FB860(void *, int, const char *, int, int, int, int) { g_1fb8++; }
void func_1F2900(void *, const char *, int) { g_1f29++; }
int func_225510(int, int, int, int) { g_def++; return 0xDEF; }
void func_001860d0(void *) { g_60d0++; }
}

static void init_vt() {
    g_sc_vt[18] = g_sc_vt[20] = (void *)sc_m50; g_sc_vt[60] = g_sc_vt[62] = (void *)sc_mf8;
    g_mgr_vt[42] = g_mgr_vt[44] = (void *)r1; g_mgr_vt[43] = g_mgr_vt[45] = (void *)r1;
    g_mgr_vt[44] = g_mgr_vt[46] = (void *)rb8; g_mgr_vt[45] = g_mgr_vt[47] = (void *)r1;
    g_mgr_vt[46] = g_mgr_vt[48] = (void *)rc0; g_mgr_vt[48] = g_mgr_vt[50] = (void *)r1;
    g_mgr_vt[52] = g_mgr_vt[54] = (void *)r1; g_mgr_vt[53] = g_mgr_vt[55] = (void *)rdc;
    g_mgr_vt[54] = g_mgr_vt[56] = (void *)r1; g_mgr_vt[55] = g_mgr_vt[57] = (void *)re4;
    g_mgr_vt[56] = g_mgr_vt[58] = (void *)r1;
}

static void test_active_screen() {
    FakeMgr mgr = {g_mgr_vt}; g_mode = 1;
    assert(func_001861d0((RenderManagerWindowProc *)&mgr, 1, 999, 0, 0) == 77);
    assert(func_001861d0((RenderManagerWindowProc *)&mgr, 1, 512, 0, 0) != 77);
    assert(func_001861d0((RenderManagerWindowProc *)&mgr, 1, 275, 0, 0) != 77);
    g_mode = 0;
}

static void test_mouse_and_keys() {
    FakeMgr mgr = {g_mgr_vt};
    D_004E897C = 1; mgr.f1e8 = 0; g_60d0 = 0;
    assert(func_001861d0((RenderManagerWindowProc *)&mgr, 0, 512, 0, 0) == 0xDEF && g_60d0 == 1 && D_004E897C == 0);
    assert(func_001861d0((RenderManagerWindowProc *)&mgr, 0, 522, 0, 0) == 0xDEF);
    g_b8 = 0;
    assert(func_001861d0((RenderManagerWindowProc *)&mgr, 0, 260, 0, 0) == 0);
    assert(func_001861d0((RenderManagerWindowProc *)&mgr, 0, 256, 0, 0) == 0);
}

static void test_user_command_paint() {
    FakeMgr mgr = {g_mgr_vt}; g_mode = 1; g_f8 = 0;
    assert(func_001861d0((RenderManagerWindowProc *)&mgr, 0, 261, 18, 0) == 0xDEF && g_f8 == 1);
    g_mode = 0;
    assert(func_001861d0((RenderManagerWindowProc *)&mgr, 0, 1024, 0, 0) == 0xDEF);
    g_c0 = 0; assert(func_001861d0((RenderManagerWindowProc *)&mgr, 0, 273, 0, 0) == 0);
    assert(func_001861d0((RenderManagerWindowProc *)&mgr, 1, 15, 0, 0) == 0xDEF);
    assert(func_001861d0((RenderManagerWindowProc *)&mgr, 0, 15, 0, 0) == 0xDEF);
}

static void test_activate_size_cancel() {
    FakeMgr mgr = {g_mgr_vt}; mgr.f30 = 1; mgr.f2c = 42; D_004E8998 = 0;
    func_001861d0((RenderManagerWindowProc *)&mgr, 42, 6, 0x10000, 99); assert(D_004E8998 == 99);
    func_001861d0((RenderManagerWindowProc *)&mgr, 42, 6, 0x00010001, 0); assert(D_004E8998 == 0);
    SubObj6C sub = {}; sub.field_58 = 1; mgr.f6c = &sub;
    assert(func_001861d0((RenderManagerWindowProc *)&mgr, 0, 5, 0, 0) == 0xDEF);
    g_mode = 1; mgr.f1ac = (void *)0x123; g_1908 = g_18bf = g_1fb8 = g_1f29 = 0;
    assert(func_001861d0((RenderManagerWindowProc *)&mgr, 0, 1295, 0, 0) == 0xDEF);
    assert(g_1908 == 1 && g_18bf == 2 && g_1fb8 == 1 && g_1f29 == 1);
    g_mode = 0;
}

int main(int count, char **args) {
    if (count != 2) return 1;
    init_vt();
    switch (std::atoi(args[1])) {
    case 0: test_active_screen(); return 0;
    case 1: test_mouse_and_keys(); return 0;
    case 2: test_user_command_paint(); return 0;
    case 3: test_activate_size_cancel(); return 0;
    default: return 1;
    }
}
