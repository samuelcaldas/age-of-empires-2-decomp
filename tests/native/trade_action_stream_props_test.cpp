#include <cassert>
#include <cstdlib>

struct MockItem {
    void *node;
    MockItem *next;
    unsigned char mode;
};

struct MockObj {
    MockItem *head;
    void *extra;
};

static int g_calls = 0;
extern "C" {
void func_001835a0(void*, void*, int, int, int, int, int) { g_calls++; }
void func_00183eb0(void*, void*, int, int, int, int, int) { g_calls++; }
int func_00183f00(void*) { return 101; }
int func_001835f0(void*) { return 102; }
int func_00183f20(void*) { return 201; }
int func_00183650(void*) { return 202; }
void func_00183600(void*, int) { g_calls++; }
void func_00183f10(void*, int) { g_calls++; }
void func_00183610(void*, int, void*) { g_calls++; }
void func_00183f60(void*, int, void*) { g_calls++; }
int func_00183f70(void*, int) { return 301; }
int func_00183660(void*, int) { return 302; }
int func_00183fe0(void*) { return 401; }
int func_00183670(void*) { return 402; }
int func_00183ff0(void*, int) { return 501; }
int func_00183680(void*, int) { return 502; }
int func_00184030(void*, int, int, int, int, int) { return 601; }
int func_001836c0(void*, int, int, int, int, int) { return 602; }
int func_00183700(void*) { return 15; }

void func_00182c40(void*, void*, short, short, int, int, int);
int func_00182d20(void*, int);
int func_00182d90(void*, int);
void func_00182e00(void*, int, int);
void func_00182e90(MockObj*, int);
int func_00182f20(void*, int, int);
int func_00182f90(void*, int);
int func_00183000(void*, int, int);
int func_00183070(void*, int, int, int, int, int, int);
unsigned char func_001830e0(void*);
}

static void test_draw_and_broadcast() {
    int id = 42;
    MockItem item = { &id, 0, 0 };
    MockObj obj = { &item, (void *)0x8888 };
    g_calls = 0;
    func_00182c40(&obj, 0, 1, 2, 3, 4, 5);
    func_00182e00(&obj, 42, 99);
    func_00182e90(&obj, 77);
    assert(g_calls == 3);
}

static void test_getters_and_min() {
    int id = 42;
    MockItem item = { &id, 0, 0 };
    MockObj obj = { &item, 0 };
    assert(func_00182d20(&obj, 42) == 102);
    assert(func_00182d90(&obj, 42) == 202);
    assert(func_00182f20(&obj, 42, 5) == 302);
    assert(func_00182f90(&obj, 42) == 402);
    assert(func_00183000(&obj, 42, 5) == 502);
    assert(func_00183070(&obj, 0, 0, 0, 0, 42, 5) == 602);
    assert(func_001830e0(&obj) == 15);
}

int main(int argc, char **argv) {
    if (argc < 2) return 1;
    int c = atoi(argv[1]);
    if (c == 0) test_draw_and_broadcast();
    else if (c == 1) test_getters_and_min();
    else return 1;
    return 0;
}
