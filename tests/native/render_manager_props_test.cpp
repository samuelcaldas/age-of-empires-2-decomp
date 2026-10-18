#include "render_manager_props.h"
#include <cassert>
#include <cstdlib>

static void *g_3444e0_arg = 0;
static int g_3444e0_calls = 0;

extern "C" {
void func_3444E0(void *arg) {
    g_3444e0_calls++;
    g_3444e0_arg = arg;
}
}

static void test_basic_getters_and_setters() {
    RenderManagerProps props = {};
    func_00188020(&props, 0x42);
    assert(func_00188050(&props) == 0x42);

    func_00188030(&props, 12345);
    assert(func_00188040(&props) == 12345);

    func_00188250(&props, 4.5f);
    assert(func_00188060(&props) == 4.5f);

    func_00188240(&props, 1);
    assert(func_00188070(&props) == 1);
    assert(func_00188080(&props) == 0);

    func_00188240(&props, 0);
    assert(func_00188070(&props) == 0);
    assert(func_00188080(&props) == 1);
}

static void test_array_and_indexed_getters() {
    RenderManagerProps props = {};
    for (int i = 0; i < 9; i++) {
        props.field_99D[i] = (unsigned char)((i << 1) | (i & 1));
        props.field_9A8[i] = (unsigned char)(i + 10);
    }
    assert(func_00188180(&props, 3) == 1);
    assert(func_00188180(&props, 4) == 0);
    assert(func_00188190(&props, 3) == 3);
    assert(func_001881b0(&props, 3) == ((3 << 1) | 1));
    assert(func_001881e0(&props, 5) == 15);
    assert(func_001881e0(&props, 10) == 1);
}

static void test_tail_call_3444e0() {
    RenderManagerProps props = {};
    props.field_24 = (void *)0xBEEF;
    g_3444e0_calls = 0;
    func_00188230(&props);
    assert(g_3444e0_calls == 1);
    assert(g_3444e0_arg == (void *)0xBEEF);
}

int main(int count, char **args) {
    if (count != 2) return 1;
    switch (std::atoi(args[1])) {
    case 0: test_basic_getters_and_setters(); return 0;
    case 1: test_array_and_indexed_getters(); return 0;
    case 2: test_tail_call_3444e0(); return 0;
    default: return 1;
    }
}
