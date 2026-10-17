#include <cassert>
#include <cstdlib>
#include <cstring>

static int g_freed = 0;

extern "C" {
extern const char D_004D7DB0[8] = {0};
void func_100670(void *) { g_freed++; }

void func_00184a88(void *self, int val);
void *func_00184a98(void *self, int flags);
void func_00184aec(void *self);
void func_00184b5c(void *self, int idx, int val);
void func_00184b94(void *self);
void func_00184bb0(void *self);
void func_00184bc0(void *self, int idx, int val);
int func_00184bd0(void *self, int idx);
int func_00184be0(void *self, int idx);
int func_00184bf0(void *self, int idx);
int func_00184c00(void *self);
int func_00184c08(void *self);
int func_00184c18(void *self);
}

static void test_getters_setters_and_stats() {
    char mem[0x1000];
    memset(mem, 0, sizeof(mem));
    func_00184a88(mem, 42);
    assert(*(int *)(mem + 0x1C8) == 42);
    *(int *)(mem + 0x64) = 77;
    assert(func_00184c18(mem) == 77);
    func_00184b94(mem);
    assert(func_00184c08(mem) == 1);
    func_00184bb0(mem);
    assert(*(int *)(mem + 0x520) == 1);
    *(int *)(mem + 0x528) = 123;
    assert(func_00184c00(mem) == 123);
    func_00184aec(mem);
    assert(*(int *)(mem + 0x20) == 10);
    assert(*(int *)(mem + 0x518) == 0);
    assert(func_00184c08(mem) == 0);
}

static void test_element_stats_and_destructor() {
    char mem[0x1000];
    memset(mem, 0, sizeof(mem));
    func_00184b5c(mem, 2, 50);
    assert(func_00184bf0(mem, 2) == 50);
    assert(func_00184be0(mem, 2) == 50);
    func_00184b5c(mem, 2, 20);
    assert(func_00184bf0(mem, 2) == 70);
    assert(func_00184be0(mem, 2) == 20);
    func_00184bc0(mem, 2, 99);
    assert(func_00184be0(mem, 2) == 99);
    *(int *)(mem + 2 * 32 + 0x540) = 88;
    assert(func_00184bd0(mem, 2) == 88);
    g_freed = 0;
    void *res = func_00184a98(mem, 1);
    assert(res == mem);
    assert(*(const void **)mem == D_004D7DB0);
    assert(g_freed == 1);
    assert(func_00184a98(0, 1) == 0);
}

int main(int argc, char **argv) {
    if (argc < 2) return 1;
    int c = atoi(argv[1]);
    if (c == 0) test_getters_setters_and_stats();
    else if (c == 1) test_element_stats_and_destructor();
    else return 1;
    return 0;
}
