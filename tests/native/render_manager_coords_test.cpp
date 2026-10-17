#include "render_manager_coords.h"
#include <cassert>
#include <cstdlib>

static int g_method20_calls = 0, g_185dc0_ret = 5, g_190c40_calls = 0;
void RenderManagerCoords::Method00() {}
void RenderManagerCoords::Method04() {}
void RenderManagerCoords::Method08() {}
void RenderManagerCoords::Method0C() {}
void RenderManagerCoords::Method10() {}
void RenderManagerCoords::Method14() {}
void RenderManagerCoords::Method20() { g_method20_calls++; }

extern "C" {
int func_185DC0(RenderManagerCoords *s, int a1) { (void)s; (void)a1; return g_185dc0_ret; }
void func_190C40(void *a) { (void)a; g_190c40_calls++; }
}

static void test_e50_e70() {
    RenderManagerCoords mgr;
    mgr.field_84 = (void *)0x8484;
    assert(func_00185e50(&mgr, 0) == (void *)0x8484);
    assert(func_00185e50(&mgr, 1) == 0);
    mgr.field_84 = 0;
    assert(func_00185e50(&mgr, 0) == 0);

    void *items[3] = {(void *)0x11, (void *)0x22, (void *)0x33};
    mgr.field_90 = items;
    mgr.field_8C = 3;
    assert(func_00185e70(&mgr, -1) == 0);
    assert(func_00185e70(&mgr, 1) == (void *)0x22);
    assert(func_00185e70(&mgr, 3) == 0);
    mgr.field_90 = 0;
    assert(func_00185e70(&mgr, 1) == 0);
}

static void test_ec0_f00() {
    RenderManagerCoords mgr;
    SubObj404C sub = {0};
    mgr.field_1AC = (void *)0x1AC;
    mgr.field_404 = &sub;
    g_190c40_calls = 0;
    func_00185ec0(&mgr);
    assert(g_190c40_calls == 1 && sub.field_30 == 1);

    g_method20_calls = 0;
    g_185dc0_ret = 5;
    func_00185f00(&mgr, 10, 42);
    assert(mgr.field_B20 == 5 && mgr.field_B24 == 42 && g_method20_calls == 1);
    func_00185f00(&mgr, 5, 99);
    assert(g_method20_calls == 1); // a1 == field_B20, no change
}

static void test_f80() {
    POINT pt = {0, 0};
    int b1 = 0, b2 = 0, b3 = 0, b4 = 0;
    // Normal coords
    func_00185f80(0, 0xF, 0x00640032, &pt, &b1, &b2, &b3, &b4);
    assert(pt.x == 50 && pt.y == 100);
    assert(b1 == 1 && b2 == 2 && b3 == 8 && b4 == 4);
    // Wrap coords (> 60000)
    func_00185f80(0, 0, 0xFFFFEA62, &pt, &b1, &b2, &b3, &b4);
    assert(pt.x == 60002 - 65536 && pt.y == -1);
}

int main(int count, char **args) {
    if (count != 2) return 1;
    switch (std::atoi(args[1])) {
    case 0: test_e50_e70(); return 0;
    case 1: test_ec0_f00(); return 0;
    case 2: test_f80(); return 0;
    default: return 1;
    }
}
