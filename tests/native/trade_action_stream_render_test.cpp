#include <cassert>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>

static int g_freed = 0;
static int g_clipped_draws = 0;
static int g_simple_draws = 0;

struct MockNode {
    void *item_ptr;
    MockNode *next;
    unsigned char mode;
};

extern "C" {
void func_00183210(void *pool, void *item) {
    (void)pool; (void)item;
    g_freed++;
}
int func_00183450(void *node, float x, float y) {
    (void)node; (void)x; (void)y;
    return 1;
}
int func_001839D0(void *node, float x, float y) {
    (void)node; (void)x; (void)y;
    return 0; // triggers unlink
}
void func_00183460(void *node, void *dest, short x, short y, short cx1, short cy1, short cx2, short cy2, void *extra) {
    (void)node; (void)dest; (void)x; (void)y; (void)cx1; (void)cy1; (void)cx2; (void)cy2; (void)extra;
    g_clipped_draws++;
}
void func_001839E0(void *node, void *dest, short x, short y, short cx1, short cy1, short cx2, short cy2, void *extra) {
    (void)node; (void)dest; (void)x; (void)y; (void)cx1; (void)cy1; (void)cx2; (void)cy2; (void)extra;
    g_clipped_draws++;
}
void func_00183550(void *node, void *dest, short x, short y, int p0, int p1) {
    (void)node; (void)dest; (void)x; (void)y; (void)p0; (void)p1;
    g_simple_draws++;
}
void func_00183E00(void *node, void *dest, short x, short y, int p0, int p1) {
    (void)node; (void)dest; (void)x; (void)y; (void)p0; (void)p1;
    g_simple_draws++;
}

void func_00182890(void *this_ptr, float x, float y);
void func_001829f0(void *this_ptr, void *dest, short x, short y, short cx1, short cy1, short cx2, short cy2);
void func_00182b60(void *this_ptr, void *dest, short x, short y, int p0, int p1);
}

static void test_render_preserves() {
    g_freed = 0;
    MockNode n1 = { (void *)0x1234, 0, 0 };
    void *obj[2] = { &n1, 0 };
    func_00182890(obj, 10.0f, 20.0f);
    assert(g_freed == 0);
    assert(obj[0] == &n1);
}

static void test_render_unlinks() {
    g_freed = 0;
    MockNode n1 = { (void *)0x1234, 0, 1 };
    void *obj[2] = { &n1, 0 };
    func_00182890(obj, 10.0f, 20.0f);
    assert(g_freed == 1);
    assert(obj[0] == 0);
}

static void test_draw_clipped() {
    g_clipped_draws = 0;
    MockNode n1 = { (void *)0x1234, 0, 0 };
    void *obj[2] = { &n1, (void *)0x999 };
    func_001829f0(obj, (void *)0xAAAA, 10, 20, 0, 0, 100, 100);
    assert(g_clipped_draws == 1);
}

static void test_draw_simple() {
    g_simple_draws = 0;
    MockNode n1 = { (void *)0x1234, 0, 0 };
    void *obj[2] = { &n1, 0 };
    func_00182b60(obj, (void *)0xAAAA, 10, 20, 1, 2);
    assert(g_simple_draws == 1);
}

int main(int argc, char **argv) {
    if (argc < 2) return 1;
    int c = atoi(argv[1]);
    switch (c) {
        case 0: test_render_preserves(); break;
        case 1: test_render_unlinks(); break;
        case 2: test_draw_clipped(); break;
        case 3: test_draw_simple(); break;
        default: return 1;
    }
    return 0;
}
