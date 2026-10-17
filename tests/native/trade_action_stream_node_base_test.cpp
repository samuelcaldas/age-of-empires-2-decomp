#include <cassert>
#include <cstdlib>
#include <cstring>

struct AspNode {
    void *texture;
    short x;
    short y;
    unsigned char mode;
    unsigned char priority;
    unsigned char active;
    unsigned char ref_count;
};

static int g_calls = 0;
extern "C" {
void func_00261ED0(void*, int, int, int, int, int) { g_calls++; }
void func_00226D90(void*, void *d, int s) { memset(d, 0, s); }
void func_00226F70(void*, void*, int) { g_calls++; }
void func_00262570(void*, void*, int, int, int, int, int, int, int, int) { g_calls++; }
void func_00262760(void*, void*, int, int, int, int, int) { g_calls++; }
void func_002628E0(void*, void*, int, int, int, int, int, int) { g_calls++; }
void func_002621E0(void*, int, int, void *p) { *(short*)p = 42; }
int func_00262BA0(void*) { return 10; }
int func_00262FA0(void*) { return 15; }
int func_002634A0(void*) { return 1; }

void func_00183240(AspNode*, void*, int, short, short, int);
void func_001832c0(AspNode*, void*, void*);
void func_00183380(AspNode*);
void func_00183390(AspNode*, short, short);
void func_001833a0(AspNode*, void*);
int func_00183450(AspNode*, float, float);
void func_00183460(AspNode*, void*, short, short, short, short, short, short, void*);
void func_00183550(AspNode*, void*, short, short, int, int);
void func_001835a0(AspNode*, void*, short, short, int, int, int);
int func_001835f0(AspNode*);
void func_00183600(AspNode*, int);
void func_00183610(AspNode*, int, void*);
int func_00183650(AspNode*);
int func_00183660(AspNode*, int);
int func_00183670(AspNode*);
int func_00183680(AspNode*, int);
int func_001836c0(AspNode*, int, int, int, int, int);
int func_00183700(AspNode*);
int func_00183740(AspNode*);
}

static void test_lifecycle_and_draw() {
    AspNode node;
    char dummy_tex[64];
    memset(dummy_tex, 0, sizeof(dummy_tex));
    g_calls = 0;
    func_00183240(&node, dummy_tex, 5, 10, 20, 1);
    assert(node.priority == 1);
    assert(node.texture == dummy_tex);
    func_00183390(&node, 100, 200);
    assert(node.x == 100 && node.y == 200);
    func_00183460(&node, 0, 0, 0, 0, 0, 0, 0, 0);
    func_00183550(&node, 0, 0, 0, 1, 2);
    func_001835a0(&node, 0, 0, 0, 1, 2, 3);
    assert(g_calls >= 4);
}

static void test_getters_and_queries() {
    AspNode node;
    char dummy_tex[64];
    memset(dummy_tex, 0, sizeof(dummy_tex));
    node.texture = dummy_tex;
    node.mode = 7;
    assert(func_00183450(&node, 0.0f, 0.0f) == 1);
    assert(func_001835f0(&node) == 7);
    func_00183600(&node, 9);
    assert(node.mode == 9);
    assert(func_00183650(&node) == 0);
    assert(func_00183660(&node, 0) == 1);
    assert(func_00183670(&node) == 0);
    assert(func_00183680(&node, 0) == 42);
    assert(func_001836c0(&node, 0, 0, 0, 0, 0) == 10);
    assert(func_00183700(&node) == 15);
    assert(func_00183740(&node) == 1);
}

int main(int argc, char **argv) {
    if (argc < 2) return 1;
    int c = atoi(argv[1]);
    if (c == 0) test_lifecycle_and_draw();
    else if (c == 1) test_getters_and_queries();
    else return 1;
    return 0;
}
