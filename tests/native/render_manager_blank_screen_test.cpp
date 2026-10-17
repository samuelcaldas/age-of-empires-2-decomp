#include "render_manager_blank_screen.h"
#include <cassert>
#include <cstdlib>

const char D_00491A18[] = "Blank Screen";

static int g_alloc_fail = 0;
static int g_215a00_fail = 0;
static int g_step = 0;
static const char *g_last_name = 0;

extern "C" {
void func_00A80BB0() {}
void *func_100850(int size) {
    if (g_alloc_fail) return 0;
    return (void *)(size == 0x804 ? 0x8040 : 0);
}
void func_215910(void *obj, const char *name) {
    assert(obj == (void *)0x8040 && name == D_00491A18);
    g_step = 1;
}
int func_215A00(void *obj, void *f70, int zero, int neg1, int t0) {
    assert(g_step == 1 && obj == (void *)0x8040 && f70 == (void *)0x7070);
    assert(zero == 0 && neg1 == -1 && t0 == 0);
    g_step = 2;
    return g_215a00_fail ? 0 : 1;
}
void func_1F2900(void *arg0, const char *name, int zero) {
    assert(g_step == 2 && arg0 == (void *)func_00A80BB0 && name == D_00491A18 && zero == 0);
    g_step = 3;
}
void func_188A40(RenderManagerBlank *self) {
    assert(g_step == 3 && self != 0);
    g_step = 4;
}
}

static void test_blank_screen_success() {
    RenderManagerBlank mgr = {0};
    mgr.field_70 = (void *)0x7070;
    g_alloc_fail = 0;
    g_215a00_fail = 0;
    g_step = 0;
    int res = func_001859a0(&mgr);
    assert(res == 1 && g_step == 4);
}

static void test_blank_screen_alloc_fail() {
    RenderManagerBlank mgr = {0};
    g_alloc_fail = 1;
    g_step = 0;
    int res = func_001859a0(&mgr);
    assert(res == 0 && g_step == 0);
}

static void test_blank_screen_215a00_fail() {
    RenderManagerBlank mgr = {0};
    mgr.field_70 = (void *)0x7070;
    g_alloc_fail = 0;
    g_215a00_fail = 1;
    g_step = 0;
    int res = func_001859a0(&mgr);
    assert(res == 0 && g_step == 2);
}

static void test_set_statistics_flags() {
    RenderManagerBlank mgr = {0};
    func_00185a50(&mgr);
    assert(mgr.field_568 == 1 && mgr.field_588 == 1 && mgr.field_5A8 == 1);
    assert(mgr.field_688 == 1 && mgr.field_6E8 == 1);
    assert(mgr.field_54C == 1 && mgr.field_5CC == 1);
}

int main(int count, char **args) {
    if (count != 2) return 1;
    switch (std::atoi(args[1])) {
    case 0: test_blank_screen_success(); return 0;
    case 1: test_blank_screen_alloc_fail(); return 0;
    case 2: test_blank_screen_215a00_fail(); return 0;
    case 3: test_set_statistics_flags(); return 0;
    default: return 1;
    }
}
