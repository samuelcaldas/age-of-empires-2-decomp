#include <cassert>
#include <cstdlib>
#include <cstring>

struct StaticPool { char slots[4000 * 12]; };
struct AnimPool { char slots[6000 * 28]; };

struct MockRenderMgr {
    void *vtable[5];
};

static int g_calls = 0;
static int mock_vmethod4(void *self, void *a, void *b, void *c, void *d) {
    (void)self; (void)a; (void)b; (void)c; (void)d;
    g_calls++;
    return 99;
}

extern "C" {
void *D_004E3180 = 0;
void func_00183240(void *n, void *t, int, short, short, int) { *(void**)n = t; g_calls++; }
void func_001832c0(void *n, void*, void*) { *(void**)n = (void*)0x111; g_calls++; }
void func_00183780(void *n, void *t, int, short, short, int) { *(void**)n = t; g_calls++; }
void func_00183870(void *n, void*, void*) { *(void**)n = (void*)0x222; g_calls++; }

void func_00184070(StaticPool *pool);
void *func_001840a0(StaticPool *pool);
void *func_001840d0(StaticPool *pool, void *tex, int prio, short x, short y, int fl);
void *func_00184140(StaticPool *pool, void *stream, void *textures);
void func_001841b0(AnimPool *pool);
void *func_001841e0(AnimPool *pool);
void *func_00184210(AnimPool *pool, void *tex, int prio, short x, short y, int fl);
void *func_00184280(AnimPool *pool, void *stream, void *textures);
int func_001842f0(void *p0, void *p1, void *p2, void *p3);
}

static void test_static_and_anim_pools() {
    StaticPool s_pool;
    func_001840a0(&s_pool);
    assert(*(unsigned char *)((char *)&s_pool + 11) == 0);
    g_calls = 0;
    void *s_node = func_001840d0(&s_pool, (void *)0x1234, 1, 10, 20, 0);
    assert(s_node == &s_pool);
    assert(*(unsigned char *)((char *)s_node + 11) == 1);
    void *s_deser = func_00184140(&s_pool, 0, 0);
    assert(s_deser == (char *)&s_pool + 12);

    AnimPool a_pool;
    func_001841e0(&a_pool);
    assert(*(unsigned char *)((char *)&a_pool + 11) == 0);
    void *a_node = func_00184210(&a_pool, (void *)0x5678, 2, 30, 40, 0);
    assert(a_node == &a_pool);
    assert(*(unsigned char *)((char *)a_node + 11) == 1);
    void *a_deser = func_00184280(&a_pool, 0, 0);
    assert(a_deser == (char *)&a_pool + 28);
    assert(g_calls == 4);
}

static void test_render_manager_dispatcher() {
    MockRenderMgr mgr;
    mgr.vtable[4] = (void*)mock_vmethod4;
    void *mgr_ptr = &mgr.vtable[0];
    D_004E3180 = &mgr_ptr;
    g_calls = 0;
    int res = func_001842f0(0, 0, 0, 0);
    assert(res == 99);
    assert(g_calls == 1);
    D_004E3180 = 0;
    assert(func_001842f0(0, 0, 0, 0) == 0);
}

int main(int argc, char **argv) {
    if (argc < 2) return 1;
    int c = atoi(argv[1]);
    if (c == 0) test_static_and_anim_pools();
    else if (c == 1) test_render_manager_dispatcher();
    else return 1;
    return 0;
}
