#include <cassert>
#include <cstdlib>
#include <cstring>

static int g_calls = 0;
static int g_method_fail = -1;

struct ScreenContext {
    char pad_0[0x8C];
    int field_8C;
    int pad_90;
    int field_94;
    char pad_98[8];
    short field_A0;
    char pad_A2[0x12];
    int width;
    int height;
};

struct ScreenManager {
    void *vtable;
    char pad_4[0x20];
    int field_24;
    ScreenContext *ctx;
    void *field_2C;
    int field_30;
    char pad_34[0x30];
    int field_64;
    int field_68;
    char pad_6C[0x948];
    float field_9B4;
    char pad_9B8[0x174];
    int field_B2C;
    char pad_B30[0x52C];
    int field_105C;
};

static int mock_vm(void *s) { (void)s; return (g_calls++ == g_method_fail) ? 0 : 1; }

extern "C" {
int D_004E315C = 0x5670C0;
int func_2261C0() { g_calls++; return 10; }
void *func_1AAB70(int v) { g_calls++; return (void*)(long)v; }
int func_1860D0(void *s) { (void)s; g_calls++; return 1; }
int func_2260C0(void *c, int, int, int) { (void)c; g_calls++; return 999; }
int func_001847c0(ScreenManager *m);
}

static void test_screen_success() {
    ScreenContext ctx;
    memset(&ctx, 0, sizeof(ctx));
    ScreenManager mgr;
    memset(&mgr, 0, sizeof(mgr));
    mgr.ctx = &ctx;
    void *vtable[100];
    for (int i = 0; i < 100; i++) vtable[i] = (void *)mock_vm;
    mgr.vtable = vtable;
    g_calls = 0;
    g_method_fail = -1;
    int res = func_001847c0(&mgr);
    assert(res == 1);
    assert(ctx.width == 640);
    assert(ctx.height == 448);
    assert(ctx.field_A0 == 2);
    assert(ctx.field_8C == 10);
    assert(ctx.field_94 == 10);
    assert(mgr.field_105C == 3);
    assert(mgr.field_30 == 1);
    assert(mgr.field_68 == 999);
    assert(mgr.field_24 == 0x5670C0);
}

static void test_screen_pipeline_fail() {
    ScreenContext ctx;
    memset(&ctx, 0, sizeof(ctx));
    ScreenManager mgr;
    memset(&mgr, 0, sizeof(mgr));
    mgr.ctx = &ctx;
    void *vtable[100];
    for (int i = 0; i < 100; i++) vtable[i] = (void *)mock_vm;
    mgr.vtable = vtable;
    g_calls = 0;
    g_method_fail = 2; // fail method 6C
    int res = func_001847c0(&mgr);
    assert(res == 0);
    assert(mgr.field_64 == 2);
}

int main(int argc, char **argv) {
    if (argc < 2) return 1;
    int c = atoi(argv[1]);
    if (c == 0) test_screen_success();
    else if (c == 1) test_screen_pipeline_fail();
    else return 1;
    return 0;
}
