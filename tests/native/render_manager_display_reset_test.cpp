#include "render_manager_display_reset_test_support.h"
#include <cstring>

static void test_func_00189b40() {
    RenderManagerDisplayReset mgr = {};
    int dev1 = 1, dev2 = 2;
    mgr.field_15EC = &dev1;
    mgr.field_15F0 = &dev2;
    mgr.field_10C8 = 42;
    g_mock_reset = {};
    func_00189b40(&mgr);
    assert(mgr.field_10C8 == 0);
    assert(g_mock_reset.count_198260 == 2);
    assert(g_mock_reset.count_193190 == 1);
}

static void test_func_00189ba0_set() {
    RenderManagerDisplayReset mgr = {};
    mgr.field_152C = 0;
    func_00189ba0(&mgr);
    assert(mgr.field_152C == 1);
}

static void test_func_00189ba0_noop() {
    RenderManagerDisplayReset mgr = {};
    mgr.field_152C = 5;
    func_00189ba0(&mgr);
    assert(mgr.field_152C == 5);
}

static void test_func_00189bc0_active() {
    RenderManagerDisplayReset mgr = {};
    int sub = 99;
    mgr.field_152C = 1;
    mgr.field_164C = &sub;
    g_mock_reset = {};
    int res = func_00189bc0(&mgr);
    assert(res == 777);
    assert(mgr.field_152C == 0);
    assert(mgr.field_164C == 0);
    assert(g_mock_reset.count_1a9bf0 == 1);
    assert(g_mock_reset.count_193190 == 1);
}

static void test_func_00189bc0_inactive() {
    RenderManagerDisplayReset mgr = {};
    mgr.field_152C = 0;
    mgr.field_164C = 0;
    g_mock_reset = {};
    int res = func_00189bc0(&mgr);
    assert(res == 777);
    assert(g_mock_reset.count_1a9bf0 == 0);
    assert(g_mock_reset.count_193190 == 1);
}

static void test_func_00189c10_format() {
    RenderManagerDisplayReset mgr = {};
    char *res = func_00189c10(&mgr, 123);
    assert(res == mgr.field_FC5);
    assert(std::strcmp(res, "[123] StatusA - DetailB") == 0);
}

int main(int count, char **arguments) {
    if (count != 2) return 1;
    switch (std::atoi(arguments[1])) {
    case 0: test_func_00189b40(); return 0;
    case 1: test_func_00189ba0_set(); return 0;
    case 2: test_func_00189ba0_noop(); return 0;
    case 3: test_func_00189bc0_active(); return 0;
    case 4: test_func_00189bc0_inactive(); return 0;
    case 5: test_func_00189c10_format(); return 0;
    default: return 1;
    }
}
