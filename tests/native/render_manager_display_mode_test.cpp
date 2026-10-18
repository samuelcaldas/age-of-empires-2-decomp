#include "render_manager_display_mode.h"
#include <cassert>
#include <cstdlib>

int D_004E89EC = 0;
const char D_00491A28[] = "display";

static int g_1db4e0_calls = 0;
static int g_2264e0_calls = 0;
static int g_25d2d0_a = 0, g_25d2d0_b = 0;
static void *g_25d060_obj = 0;

extern "C" {
void func_1DB4E0(void *) { g_1db4e0_calls++; }
void func_1AAF80(void *) {}
void func_188A40(void *) {}
void func_2264E0(void *, int, int) { g_2264e0_calls++; }
void func_2254D0(void *, void *) {}
void func_225450(void *, void *) {}
void func_1F2CB0(void *, const char *) {}
void func_00A80BB0() {}
void func_25D2D0(int a, int b) { g_25d2d0_a = a; g_25d2d0_b = b; }
void func_25D060(void *obj) { g_25d060_obj = obj; }
}

static void test_display_mode_change() {
    RenderManagerDisplayMode mgr = {};
    SubObj70 s70 = {};
    s70.field_18 = 640;
    s70.field_1C = 480;
    mgr.field_70 = &s70;

    SubObj6C s6C = {};
    s6C.field_44 = 2;
    s6C.field_45 = 2;
    mgr.field_6C = &s6C;

    // Same resolution returns immediately
    g_1db4e0_calls = 0;
    func_00188740(&mgr, 640, 480);
    assert(g_1db4e0_calls == 0);

    // Resolution change with field_44 == 2 and field_45 == 2
    func_00188740(&mgr, 800, 600);
    assert(g_1db4e0_calls == 1);
    assert(D_004E89EC == 1);

    // Negative / window mode
    s6C.field_44 = 0;
    s6C.field_45 = 0;
    g_2264e0_calls = 0;
    func_00188740(&mgr, 0, 0);
    assert(g_2264e0_calls == 2);
    assert(mgr.field_40 == (int)0x92080000);
}

static void test_array_ops_and_limits() {
    RenderManagerDisplayMode mgr = {};
    func_00188880(&mgr, 2, 42);
    assert(func_00188870(&mgr, 2) == 42);

    func_00188890(&mgr, 3);
    assert(mgr.field_9F8[3] == -1);

    func_001888b0(&mgr, 3, 50);
    assert(mgr.field_9F8[3] == 50);
    func_001888b0(&mgr, 3, 60);
    assert(mgr.field_9F8[3] == 50); // does not increase
    func_001888b0(&mgr, 3, 30);
    assert(mgr.field_9F8[3] == 30); // decreases

    int out = -1;
    func_00188900(&mgr, 3, &out);
    assert(out == 30);
    func_00188900(&mgr, 15, &out);
    assert(out == 0);
}

static void test_screen_coords_and_scalars() {
    RenderManagerDisplayMode mgr = {};
    int res = func_00188940(&mgr, (void *)0x7777, 0x100, 0x200);
    assert(res == 1);
    assert(g_25d2d0_a == (0x100 >> 4) + 0x40);
    assert(g_25d2d0_b == (0x200 >> 6) + 0x7F);
    assert(g_25d060_obj == (void *)0x7777);

    func_00188990(&mgr, 999);
    assert(func_00188980(&mgr) == 999);
}

int main(int count, char **args) {
    if (count != 2) return 1;
    switch (std::atoi(args[1])) {
    case 0: test_display_mode_change(); return 0;
    case 1: test_array_ops_and_limits(); return 0;
    case 2: test_screen_coords_and_scalars(); return 0;
    default: return 1;
    }
}
