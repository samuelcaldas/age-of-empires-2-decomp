#include <cassert>
#include <cstdlib>
#include <cstring>

struct AspAnimatedNode {
    void *texture;
    short x, y;
    unsigned char mode, priority, active, ref_count;
    float frame_duration, elapsed_time, speed;
    unsigned char loop_frame, trigger_flag, end_flag, anim_mode;
};

static int g_calls = 0;
extern "C" {
int D_004E33F4 = 0;
void func_00183240(void *n, void *t, int, short, short, int) { *(void**)n = t; g_calls++; }
void func_001832c0(void*, void*, void*) { g_calls++; }
void func_001833a0(void*, void*) { g_calls++; }
int func_001aab30() { return 1000; }
void func_00226D90(void*, void* d, int s) { memset(d, 0, s); }
void func_00226F70(void*, void*, int) { g_calls++; }
void func_00262570(void*, void*, int, int, int, int, int, int, int, int) { g_calls++; }
void func_00262760(void*, void*, int, int, int, int, int) { g_calls++; }
void func_002628E0(void*, void*, int, int, int, int, int, int) { g_calls++; }
void func_00261ED0(void*, int, int, int, int, int) { g_calls++; }
void func_002621E0(void*, int, int, void *p) { *(short*)p = 77; }
int func_00262BA0(void*) { return 12; }

void func_00183780(AspAnimatedNode*, void*, int, short, short, int);
void func_00183870(AspAnimatedNode*, void*, void*);
void func_00183920(AspAnimatedNode*);
void func_00183930(AspAnimatedNode*, void*);
void func_001839d0(AspAnimatedNode*, float, float);
void func_00183cc0(AspAnimatedNode*, void*, short, short, short, short, short, short, void*);
void func_00183e00(AspAnimatedNode*, void*, short, short, int, int);
void func_00183eb0(AspAnimatedNode*, void*, short, short, int, int, int);
int func_00183f00(AspAnimatedNode*);
void func_00183f10(AspAnimatedNode*, int);
int func_00183f20(AspAnimatedNode*);
void func_00183f60(AspAnimatedNode*, int, void*);
int func_00183f70(AspAnimatedNode*, int);
int func_00183fe0(AspAnimatedNode*);
int func_00183ff0(AspAnimatedNode*, int);
int func_00184030(AspAnimatedNode*, int, int, int, int, int);
}

static void test_anim_lifecycle_and_draw() {
    AspAnimatedNode node;
    memset(&node, 0, sizeof(node));
    char dummy_tex[128];
    memset(dummy_tex, 0, sizeof(dummy_tex));
    *(float*)(dummy_tex + 32) = 0.05f;
    g_calls = 0;
    func_00183780(&node, dummy_tex, 3, 10, 20, 0);
    assert(node.priority == 2);
    assert(node.anim_mode == 1);
    func_00183920(&node);
    assert(node.ref_count == 0);
    func_001839d0(&node, 0.01f, 1.0f);
    func_00183cc0(&node, 0, 0, 0, 0, 0, 0, 0, 0);
    func_00183e00(&node, 0, 0, 0, 1, 2);
    func_00183eb0(&node, 0, 0, 0, 1, 2, 3);
    assert(g_calls >= 4);
}

static void test_anim_properties() {
    AspAnimatedNode node;
    char dummy_tex[128];
    memset(dummy_tex, 0, sizeof(dummy_tex));
    memset(&node, 0, sizeof(node));
    node.texture = dummy_tex;
    func_00183f10(&node, 5);
    assert(func_00183f00(&node) == 5);
    assert(node.loop_frame == 5);
    node.trigger_flag = 1;
    node.end_flag = 1;
    assert(func_00183f70(&node, 3) == 1);
    assert(func_00183fe0(&node) == 1);
    assert(func_00183ff0(&node, 0) == 77);
    assert(func_00184030(&node, 0, 0, 0, 0, 0) == 12);
}

int main(int argc, char **argv) {
    if (argc < 2) return 1;
    int c = atoi(argv[1]);
    if (c == 0) test_anim_lifecycle_and_draw();
    else if (c == 1) test_anim_properties();
    else return 1;
    return 0;
}
