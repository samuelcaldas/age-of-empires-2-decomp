#include <cassert>
#include <cstdlib>
#include <cstring>

static int g_calls = 0;
static int g_method26_result = 0;

static int mock_method26(void *self) {
    (void)self;
    g_calls++;
    return g_method26_result;
}

extern "C" {
void *D_004E3180 = 0;
int D_004E3110 = 0;
int D_004E3114 = 0;
int D_004E30FC = 0;
int D_004E3100 = 0;
int D_004E3104 = 0;
int D_004E3108 = 0;
int D_004E310C = 0;
int D_004E315C = 0;
void *D_4D7DB0[35] = {0};
extern const char D_491988[16] = {0};
extern const char D_5670C0[16] = {0};

void func_117CAC(void *dst, int val, int size) { memset(dst, val, size); g_calls++; }
void func_00188250(void *, float) { g_calls++; }
void func_00188240(void *, int) { g_calls++; }
void func_00188290(void *, int) { g_calls++; }
void func_001882a0(void *, int) { g_calls++; }
void func_001882b0(void *, int) { g_calls++; }
void func_001882d0(void *, int) { g_calls++; }
void func_001882f0(void *, int, int, int) { g_calls++; }
void func_00188300(void *, int) { g_calls++; }
void func_00188310(void *, int) { g_calls++; }
void func_00188330(void *, int) { g_calls++; }
void func_00188340(void *, int) { g_calls++; }
void func_001884a0(void *, float) { g_calls++; }
void func_00188490(void *, float) { g_calls++; }
void func_001884F0(void *) { g_calls++; }
void func_00188500(void *) { g_calls++; }
void func_00188360(void *, int) { g_calls++; }
void func_001883c0(void *, int) { g_calls++; }
void func_001883b0(void *, int, int) { g_calls++; }
void func_00188370(void *, int, int) { g_calls++; }
void func_00188390(void *, int, int) { g_calls++; }
void func_001883d0(void *, int, int) { g_calls++; }
void func_001883e0(void *, int) { g_calls++; }
void func_001883f0(void *, int) { g_calls++; }
void func_00188350(void *, int) { g_calls++; }
void func_00188260(void *, const void *) { g_calls++; }

void *func_00184340(char *p, void *a1, int a2);
}

static void test_ctor_init() {
    char mem[0x1100];
    memset(mem, 0xCC, sizeof(mem));
    char ctx[0x20];
    *(int *)(ctx + 0xC) = 0x12345678;
    g_calls = 0;
    void *res = func_00184340(mem, ctx, 0);
    assert(res == mem);
    assert(D_004E3180 == mem);
    assert(*(void **)mem == D_4D7DB0);
    assert(*(int *)(mem + 0x24) == 0);
    assert(*(int *)(mem + 0x48) == -1);
    assert(*(int *)(mem + 0x20) == 10);
    assert(*(unsigned char *)(mem + 0x4) == 0xFF);
    assert(D_004E30FC == 0x12345678);
    assert(D_004E315C == (int)D_5670C0);
    assert(g_calls > 50);
}

static void test_ctor_callback() {
    char mem[0x1100];
    memset(mem, 0, sizeof(mem));
    for (int i = 0; i < 35; i++) {
        D_4D7DB0[i] = (void *)mock_method26;
    }
    char ctx[0x20];
    *(int *)(ctx + 0xC) = 0;
    g_calls = 0;
    g_method26_result = 0;
    func_00184340(mem, ctx, 1);
    assert(*(int *)(mem + 0x64) == 1);
    assert(g_calls > 50);
}

int main(int argc, char **argv) {
    if (argc < 2) return 1;
    int c = atoi(argv[1]);
    if (c == 0) test_ctor_init();
    else if (c == 1) test_ctor_callback();
    else return 1;
    return 0;
}
