#include "render_manager_setters.h"
#include <cassert>
#include <cstdlib>
#include <cstring>

static int g_3449b0_calls = 0;
static void *g_3449b0_arg = 0;

extern "C" {
char *func_11B170(char *dst, const char *src, int n) {
    std::strncpy(dst, src, n);
    return dst;
}

void func_32F190(void *) {}
void func_32F1C0(void *) {}

void func_3449B0(void *obj) {
    g_3449b0_calls++;
    g_3449b0_arg = obj;
}
}

static void test_string_and_scalar_setters() {
    RenderManagerSetters mgr = {};
    func_00188260(&mgr, "test_name");
    assert(std::strcmp(mgr.field_911, "test_name") == 0);
    assert(mgr.field_990 == 0);

    func_00188290(&mgr, 100);
    assert(mgr.field_9BC == 100);
    func_001882a0(&mgr, 200);
    assert(mgr.field_9C0 == 200);

    func_001882b0(&mgr, 1);
    assert(mgr.field_991 == 1 && mgr.field_992 == 0);
    func_001882b0(&mgr, 0);
    assert(mgr.field_991 == 0 && mgr.field_992 == 1);

    func_001882d0(&mgr, 1);
    assert(mgr.field_992 == 1 && mgr.field_991 == 0);
    func_001882d0(&mgr, 0);
    assert(mgr.field_992 == 0 && mgr.field_991 == 1);
}

static void test_array_and_bitfield_setters() {
    RenderManagerSetters mgr = {};
    mgr.field_99D[2] = 0;
    func_00188370(&mgr, 2, 1);
    assert((mgr.field_99D[2] & 1) == 1);

    func_00188390(&mgr, 2, 5);
    assert((mgr.field_99D[2] & 1) == 1);
    assert((mgr.field_99D[2] >> 1) == 5);

    func_001883b0(&mgr, 2, 0xAA);
    assert(mgr.field_99D[2] == 0xAA);

    func_001883d0(&mgr, 3, 0x55);
    assert(mgr.field_9A8[3] == 0x55);
}

static void test_flags_and_helpers() {
    RenderManagerSetters mgr = {};
    func_001884b0(&mgr);
    assert(func_00188510(&mgr) == 1);
    func_001884f0(&mgr);
    assert(func_00188510(&mgr) == 0);

    func_00188530(&mgr, 1);
    assert(func_00188510(&mgr) == 1);
    func_00188530(&mgr, 0);
    assert(func_00188510(&mgr) == 0);

    mgr.field_24 = (void *)0x1234;
    g_3449b0_calls = 0;
    func_00188480(&mgr);
    assert(g_3449b0_calls == 1 && g_3449b0_arg == (void *)0x1234);
}

int main(int count, char **args) {
    if (count != 2) return 1;
    switch (std::atoi(args[1])) {
    case 0: test_string_and_scalar_setters(); return 0;
    case 1: test_array_and_bitfield_setters(); return 0;
    case 2: test_flags_and_helpers(); return 0;
    default: return 1;
    }
}
