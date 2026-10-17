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
void *D_004D7DB0[35] = {0};

void func_117CAC(void *dst, int val, int size) { memset(dst, val, size); g_calls++; }
void func_188250(void *, float) { g_calls++; }
void func_188240(void *, int) { g_calls++; }
void func_188290(void *, int) { g_calls++; }
void func_1882A0(void *, int) { g_calls++; }
void func_1882B0(void *, int) { g_calls++; }
void func_1882D0(void *, int) { g_calls++; }
void func_1882F0(void *, int, int, int) { g_calls++; }
void func_188300(void *, int) { g_calls++; }
void func_188310(void *, int) { g_calls++; }
void func_188330(void *, int) { g_calls++; }
void func_188340(void *, int) { g_calls++; }
void func_1884A0(void *, float) { g_calls++; }
void func_188490(void *, float) { g_calls++; }
void func_1884F0(void *) { g_calls++; }
void func_188500(void *) { g_calls++; }
void func_188360(void *, int) { g_calls++; }
void func_1883C0(void *, int) { g_calls++; }
void func_1883B0(void *, int, int) { g_calls++; }
void func_188370(void *, int, int) { g_calls++; }
void func_188390(void *, int, int) { g_calls++; }
void func_1883D0(void *, int, int) { g_calls++; }
void func_1883E0(void *, int) { g_calls++; }
void func_1883F0(void *, int) { g_calls++; }
void func_188350(void *, int) { g_calls++; }
void func_188260(void *, const void *) { g_calls++; }

void *func_00184340(void *this_ptr, void *a1, int a2);
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
    assert(*(void **)mem == D_004D7DB0);
    assert(*(int *)(mem + 0x24) == 0);
    assert(*(int *)(mem + 0x48) == -1);
    assert(*(int *)(mem + 0x20) == 10);
    assert(*(unsigned char *)(mem + 0x4) == 0xFF);
    assert(D_004E30FC == 0x12345678);
    assert(D_004E315C == 0x005670C0);
    assert(g_calls > 50);
}

static void test_ctor_callback() {
    char mem[0x1100];
    memset(mem, 0, sizeof(mem));
    D_004D7DB0[26] = (void *)mock_method26;
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
