#include "render_manager_surfaces.h"
#include <cassert>
#include <cstdlib>

const char D_004919F0[] = "groupnum.shp";

static int g_alloc_fail = 0;
static int g_aba0_fail = 0;
static int g_last_id = 0;
static int g_aba70_called = 0;
static SurfaceEntry g_surfaces[6];

extern "C" {
void *func_25F2B0(int size) {
    if (g_alloc_fail) return 0;
    return (void *)(size == 0x14 ? 0x1400 : 0);
}
void func_25D6D0(void *obj, const char *name, int id) {
    assert(obj == (void *)0x1400 && id == 0x124E && name != 0);
    g_last_id = id;
}
void *func_1143F8(int count, int size) {
    if (g_alloc_fail) return 0;
    assert(count == 6 && size == 0xC);
    return g_surfaces;
}
void *func_1ABA00(void *f70) {
    if (g_aba0_fail) return 0;
    assert(f70 == (void *)0x7070);
    return (void *)0xABAB;
}
void func_1ABA70(void *f70) { assert(f70 == (void *)0x7070); g_aba70_called = 1; }
int func_2257A0(void *s0, int s2) { assert(s0 == (void *)0xABAB); return s2 + 10; }
int func_223000(int s2) { return s2 * 100; }
int func_223040(int s2) { return s2 * 200; }
}

static void test_groupnum_load() {
    RenderManagerSurfaces mgr = {0};
    g_alloc_fail = 0;
    g_last_id = 0;
    int res = func_001857b0(&mgr);
    assert(res == 1 && mgr.field_80 == 1 && mgr.field_84 == (void *)0x1400 && g_last_id == 0x124E);
}

static void test_groupnum_fail() {
    RenderManagerSurfaces mgr = {0};
    g_alloc_fail = 1;
    int res = func_001857b0(&mgr);
    assert(res == 1 && mgr.field_84 == 0);
}

static void test_surfaces_init() {
    RenderManagerSurfaces mgr = {0};
    mgr.field_70 = (void *)0x7070;
    g_alloc_fail = 0;
    g_aba0_fail = 0;
    g_aba70_called = 0;
    int res = func_00185810(&mgr);
    assert(res == 1 && mgr.field_1F8 == 6 && mgr.field_1FC == g_surfaces && g_aba70_called == 1);
    const int expected_s2[6] = {1, 2, 0, 5, 4, 3};
    for (int i = 0; i < 6; i++) {
        assert(g_surfaces[i].f0 == expected_s2[i]);
        assert(g_surfaces[i].f4 == expected_s2[i] * 100);
        assert(g_surfaces[i].f8 == expected_s2[i] * 200);
    }
}

static void test_surfaces_alloc_fail() {
    RenderManagerSurfaces mgr = {0};
    g_alloc_fail = 1;
    int res = func_00185810(&mgr);
    assert(res == 0);
}

static void test_surfaces_aba0_fail() {
    RenderManagerSurfaces mgr = {0};
    mgr.field_70 = (void *)0x7070;
    g_alloc_fail = 0;
    g_aba0_fail = 1;
    int res = func_00185810(&mgr);
    assert(res == 0);
}

int main(int count, char **args) {
    if (count != 2) return 1;
    switch (std::atoi(args[1])) {
    case 0: test_groupnum_load(); return 0;
    case 1: test_groupnum_fail(); return 0;
    case 2: test_surfaces_init(); return 0;
    case 3: test_surfaces_alloc_fail(); return 0;
    case 4: test_surfaces_aba0_fail(); return 0;
    default: return 1;
    }
}
