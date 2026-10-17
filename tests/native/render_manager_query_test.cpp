#include <cassert>
#include <cstdlib>
#include <cstring>

static int g_calls = 0;
static int g_val_fail = 0;

static void mock_vm10(void *self, int p1, void *buf, int size) {
    (void)self;
    assert(p1 == 123);
    assert(buf == (void *)0x00566EC0);
    assert(size == 0x200);
    g_calls++;
}

static void *mock_vm13(void *self, int a1, int a2, int a3, int t0, int t1) {
    (void)self;
    assert(a1 == 10);
    assert(a2 == 20);
    assert(a3 == 0);
    assert(t0 == 30);
    assert(t1 == 40);
    g_calls++;
    return (void *)0x5555;
}

extern "C" {
void *D_004E3110 = (void *)0x8888;

int func_1C1FD0(void *ctx, char *dest, int size) {
    (void)ctx;
    g_calls++;
    if (g_val_fail) return 0;
    strncpy(dest, "valid_data", size);
    return 1;
}

void *func_00184c28(void *self, int p1);
char *func_00184c70(void *self, int a1, char *dest, int size);
void *func_00184cc0(void *self, int a1, int a2, int a3, int t0);
}

static void test_query_and_validator() {
    void *vtable[20];
    vtable[10] = (void *)mock_vm10;
    void *mgr[1];
    mgr[0] = vtable;
    g_calls = 0;
    void *res = func_00184c28(mgr, 123);
    assert(res == (void *)0x00566EC0);
    assert(g_calls == 1);

    char buf[32];
    memset(buf, 'A', sizeof(buf));
    g_val_fail = 0;
    char *ret = func_00184c70(0, 0, buf, 32);
    assert(ret == buf);
    assert(strcmp(buf, "valid_data") == 0);

    g_val_fail = 1;
    ret = func_00184c70(0, 0, buf, 32);
    assert(buf[0] == '\0');
    assert(buf[31] == '\0');
}

static void test_trampoline() {
    void *vtable[20];
    vtable[13] = (void *)mock_vm13;
    void *mgr[1];
    mgr[0] = vtable;
    g_calls = 0;
    void *res = func_00184cc0(mgr, 10, 20, 30, 40);
    assert(res == (void *)0x5555);
    assert(g_calls == 1);
}

int main(int argc, char **argv) {
    if (argc < 2) return 1;
    int c = atoi(argv[1]);
    if (c == 0) test_query_and_validator();
    else if (c == 1) test_trampoline();
    else return 1;
    return 0;
}
