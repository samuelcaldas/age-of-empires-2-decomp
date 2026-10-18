#include "render_manager_draw_buffer.h"
#include <cassert>
#include <cstdlib>

const int D_00391CF0[2] = { 0, 1 };
const char D_003921D0[24] = {};
const char D_00567CA0[864] = {};

static int g_21bc30_calls = 0;
static int g_219fb0_calls = 0;

extern "C" {
void func_21BC30(const void *, const void *, int, int, int) {
    g_21bc30_calls++;
}

int func_219FB0(void *, int, int, int) {
    g_219fb0_calls++;
    return 123;
}
}

static void test_lifecycle_and_accessors() {
    RenderManagerDrawBuffer buf = {};
    assert(func_00188c00() == 1);

    buf.field_14 = (DrawBufferItem *)0x1234;
    buf.field_18 = 5;
    RenderManagerDrawBuffer *res = func_00188c10(&buf);
    assert(res == &buf);
    assert(buf.field_14 == 0);
    assert(buf.field_18 == 0);

    assert(func_00188db0(&buf) == &buf.field_4);
    buf.field_10 = 7;
    assert(func_00188dc0(&buf) == 7);
}

static void test_initialization() {
    RenderManagerDrawBuffer buf = {};
    buf.field_10 = 2;
    g_21bc30_calls = 0;

    func_00188c20(&buf, 1);
    assert(buf.field_18 == 1);
    assert(buf.field_14 == (DrawBufferItem *)&D_00567CA0[432]);
    assert(g_21bc30_calls == 2);
}

static void test_element_processing_and_offset() {
    RenderManagerDrawBuffer buf = {};
    DrawBufferItem items[3] = {};
    items[1].field_0 = 10;
    items[1].field_4 = 20;
    buf.field_10 = 3;
    buf.field_14 = items;
    buf.field_18 = 0;

    assert(func_00188cf0(&buf, -1) == -1);
    assert(func_00188cf0(&buf, 3) == -1);

    g_21bc30_calls = g_219fb0_calls = 0;
    int res = func_00188cf0(&buf, 1);
    assert(res == 123);
    assert(g_21bc30_calls == 1);
    assert(g_219fb0_calls == 1);

    void *ptr = func_00188dd0(&buf, 1);
    assert(ptr == (char *)&items[1] + 8);
}

int main(int count, char **args) {
    if (count != 2) return 1;
    switch (std::atoi(args[1])) {
    case 0: test_lifecycle_and_accessors(); return 0;
    case 1: test_initialization(); return 0;
    case 2: test_element_processing_and_offset(); return 0;
    default: return 1;
    }
}
