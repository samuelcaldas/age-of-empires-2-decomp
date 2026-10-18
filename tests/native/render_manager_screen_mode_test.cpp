#include "render_manager_screen_mode.h"
#include <cassert>
#include <cstdlib>

static int g_1f33c0_calls = 0;
static int g_1f33b0_calls = 0;
static int g_method58_w = 0, g_method58_h = 0, g_method58_calls = 0;

struct MockScreenMode : public RenderManagerScreenMode {
    void M00() {} void M01() {} void M02() {} void M03() {} void M04() {}
    void M05() {} void M06() {} void M07() {} void M08() {} void M09() {}
    void M10() {} void M11() {} void M12() {} void M13() {} void M14() {}
    void M15() {} void M16() {} void M17() {} void M18() {} void M19() {}
    void Method58(int w, int h) {
        g_method58_calls++;
        g_method58_w = w;
        g_method58_h = h;
    }
};

extern "C" {
void func_203ED0(void *, int *out_x, int *out_y, int *out_z) {
    *out_x = 10;
    *out_y = 20;
    *out_z = 30;
}

void func_1F33C0(void *) { g_1f33c0_calls++; }
void func_1F33B0(void *) { g_1f33b0_calls++; }
void func_00A80BB0() {}
}

static void test_accumulate_poly_counts() {
    MockScreenMode mgr;
    int ox = -1, oy = -1, oz = -1;
    mgr.field_404 = 0;
    assert(func_00188590(&mgr, &ox, &oy, &oz) == 0);
    assert(ox == 0 && oy == 0 && oz == 0);

    SubObj404 obj = {};
    SubObj404Item item;
    SubObj404Item *items[2] = { &item, &item };
    obj.count_50 = 2;
    obj.items_54 = items;
    mgr.field_404 = &obj;

    assert(func_00188590(&mgr, &ox, &oy, &oz) == 1);
    assert(ox == 20 && oy == 40 && oz == 60);
}

static void test_screen_enable_disable() {
    MockScreenMode mgr;
    mgr.field_1F0 = 1;
    g_1f33c0_calls = g_1f33b0_calls = 0;

    func_00188680(&mgr);
    assert(mgr.field_1F0 == 0);
    assert(g_1f33c0_calls == 1);

    func_001886b0(&mgr);
    assert(mgr.field_1F0 == 1);
    assert(g_1f33b0_calls == 1);
}

static void test_screen_resolution_modes() {
    MockScreenMode mgr;
    SubObj28 sub = {};
    sub.field_AC = 640;
    sub.field_B0 = 480;
    sub.field_B4 = 800;
    sub.field_B8 = 600;
    mgr.field_28 = &sub;

    g_method58_calls = 0;
    func_001886f0(&mgr);
    assert(mgr.field_60 == 1);
    assert(g_method58_calls == 1 && g_method58_w == 800 && g_method58_h == 600);

    func_00188720(&mgr);
    assert(mgr.field_60 == 0);
    assert(g_method58_calls == 2 && g_method58_w == 640 && g_method58_h == 480);
}

int main(int count, char **args) {
    if (count != 2) return 1;
    switch (std::atoi(args[1])) {
    case 0: test_accumulate_poly_counts(); return 0;
    case 1: test_screen_enable_disable(); return 0;
    case 2: test_screen_resolution_modes(); return 0;
    default: return 1;
    }
}
