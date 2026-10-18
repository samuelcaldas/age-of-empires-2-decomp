#include "render_manager_surface.h"
#include <cassert>
#include <cstdlib>

void *D_00598DA0 = 0;

static int g_1ae480_calls = 0;
static int g_1ab7e0_calls = 0;
static int g_1ae510_calls = 0;
static int g_1f34e0_calls = 0;
static int g_25d060_last_id = 0;
static int g_25d060_calls = 0;

extern "C" {
void *func_1AE480(void *) { g_1ae480_calls++; return (void *)0x8888; }
int func_1AB7E0(void *, void *, int, int, int, int, int) { g_1ab7e0_calls++; return 1; }
void func_1AE510(void *, void *) { g_1ae510_calls++; }
void func_1F34E0(void *) { g_1f34e0_calls++; }
void func_25D060(int id) { g_25d060_calls++; g_25d060_last_id = id; }
void func_00A80BB0() {}
}

static void test_surface_allocation_and_helpers() {
    RenderManagerSurface mgr = {};
    g_1ae480_calls = g_1ab7e0_calls = 0;
    int res = func_001889a0(&mgr);
    assert(res == 1);
    assert(mgr.field_106C == (void *)0x8888);
    assert(g_1ae480_calls == 1);
    assert(g_1ab7e0_calls == 1);

    func_00188a30();
    func_00188bc0();
    func_00188bd0();
    assert(func_00188a60() == 0);
    assert(func_00188ba0() == 0);
    assert(func_00188bb0() == 0);
    assert(func_00188be0() == 0);
    assert(func_00188bf0() == 1);

    g_1f34e0_calls = 0;
    func_00188a40(&mgr);
    assert(mgr.field_408 == 1);
    assert(g_1f34e0_calls == 1);
}

static void test_subobj1ac_lookup() {
    RenderManagerSurface mgr = {};
    mgr.field_1AC = 0;
    assert(func_00188a70(&mgr) == -1);

    SubObj1AC obj = {};
    obj.field_10E0 = 777;
    mgr.field_1AC = &obj;
    assert(func_00188a70(&mgr) == 777);
}

static void test_switch_dispatch() {
    g_25d060_calls = 0;
    func_00188a90(1);
    assert(g_25d060_calls == 1 && g_25d060_last_id == 0x1013);

    func_00188a90(7);
    assert(g_25d060_calls == 2 && g_25d060_last_id == 0x1014);

    func_00188a90(0); // default
    assert(g_25d060_calls == 2);
}

int main(int count, char **args) {
    if (count != 2) return 1;
    switch (std::atoi(args[1])) {
    case 0: test_surface_allocation_and_helpers(); return 0;
    case 1: test_subobj1ac_lookup(); return 0;
    case 2: test_switch_dispatch(); return 0;
    default: return 1;
    }
}
