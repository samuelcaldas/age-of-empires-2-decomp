#include "render_manager_subsystem_queries.h"
#include <cassert>
#include <cstdlib>

int D_004E8980 = 0;
static int g_225560_arg = 0, g_225e80_arg = 0, g_1db7d0_calls = 0;
static int g_1db7c0_calls = 0, g_1db760_calls = 0, g_224300_calls = 0;

extern "C" {
int func_225560(int a) { g_225560_arg = a; return 10; }
int func_225E80(int f) { g_225e80_arg = f; return 20; }
void func_1DB7D0(void *a) { (void)a; g_1db7d0_calls++; }
void func_1DB7C0(void *a) { (void)a; g_1db7c0_calls++; }
int func_1DB760(void *a) { (void)a; g_1db760_calls++; return 30; }
void func_224300(int a) { (void)a; g_224300_calls++; }
}

static void test_6000_6010() {
    assert(func_00186000(0, 42) == 10 && g_225560_arg == 42);
    RenderManagerSubsystemQueries mgr = {0};
    assert(func_00186010(&mgr) == 0);
    SubObj404E sub = {0};
    mgr.field_404 = &sub;
    sub.field_50 = 0;
    assert(func_00186010(&mgr) == 0);
    sub.field_50 = 3;
    void *items[3] = {(void *)0x1, (void *)0x2, (void *)0x3};
    sub.field_54 = items;
    sub.field_98 = 1;
    assert(func_00186010(&mgr) == (void *)0x2);
    sub.field_98 = 3;
    assert(func_00186010(&mgr) == 0);
}

static void test_6080_60c0() {
    RenderManagerSubsystemQueries mgr = {0};
    for (int i = 0; i < 9; i++) mgr.field_9CC[i] = i * 10;
    assert(func_00186080(&mgr, 40) == 4);
    assert(func_00186080(&mgr, 99) == -1);
    mgr.field_2C = 0x555;
    assert(func_001860c0(&mgr) == 20 && g_225e80_arg == 0x555);
}

static void test_60d0_6110() {
    RenderManagerSubsystemQueries mgr = {0};
    g_1db7d0_calls = 0;
    func_001860d0(&mgr);
    assert(g_1db7d0_calls == 1 && mgr.field_1E4 == 1);
    func_001860d0(&mgr); // already set, no call
    assert(g_1db7d0_calls == 1);

    g_1db7c0_calls = 0;
    func_00186110(&mgr);
    assert(g_1db7c0_calls == 1 && mgr.field_1E4 == 0);
    func_00186110(&mgr); // already zero, no call
    assert(g_1db7c0_calls == 1);
}

static void test_6150_61a0_61c0() {
    RenderManagerSubsystemQueries mgr = {0};
    mgr.field_7C = 0;
    g_1db7d0_calls = 0; g_224300_calls = 0;
    func_00186150(&mgr, 0);
    assert(mgr.field_1E8 == 1 && g_1db7d0_calls == 0);
    mgr.field_7C = 1;
    func_00186150(&mgr, 7);
    assert(mgr.field_1E8 == 7 && g_1db7d0_calls == 1 && g_224300_calls == 1);

    D_004E8980 = 0;
    func_001861a0(&mgr, 0);
    assert(mgr.field_1EC == 0 && D_004E8980 == 0);
    func_001861a0(&mgr, 123);
    assert(mgr.field_1EC == 123 && D_004E8980 == 123);

    g_1db760_calls = 0;
    assert(func_001861c0(&mgr) == 30 && g_1db760_calls == 1);
}

int main(int count, char **args) {
    if (count != 2) return 1;
    switch (std::atoi(args[1])) {
    case 0: test_6000_6010(); return 0;
    case 1: test_6080_60c0(); return 0;
    case 2: test_60d0_6110(); return 0;
    case 3: test_6150_61a0_61c0(); return 0;
    default: return 1;
    }
}
