#include <cassert>
#include <cstddef>
#include "tactical_ai_combat_subsystem_elevation_mesh_dispatch.h"

static int s_check_calls = 0;
static void *s_check_self = 0;
static int s_check_a2 = 0;
static int s_check_a3 = 0;
static short *s_check_s7C = 0;
static short *s_check_s7E = 0;
static int *s_check_s78 = 0;
static int s_check_ret = 0;

static int s_dispatch_calls = 0;
static void *s_dispatch_self = 0;
static int s_dispatch_a1 = 0;
static int s_dispatch_a2 = 0;
static int s_dispatch_a3 = 0;
static int s_dispatch_a4 = 0;
static int s_dispatch_a5 = 0;
static int s_dispatch_ret = 0;

extern "C" {
    int func_1A5010(void *self, int a2, int a3, short *s_7C, short *s_7E, int *s_78) {
        s_check_calls++;
        s_check_self = self;
        s_check_a2 = a2;
        s_check_a3 = a3;
        s_check_s7C = s_7C;
        s_check_s7E = s_7E;
        s_check_s78 = s_78;
        return s_check_ret;
    }

    int func_1F5C80(void *self, int a1, int a2, int a3, int a4, int a5) {
        s_dispatch_calls++;
        s_dispatch_self = self;
        s_dispatch_a1 = a1;
        s_dispatch_a2 = a2;
        s_dispatch_a3 = a3;
        s_dispatch_a4 = a4;
        s_dispatch_a5 = a5;
        return s_dispatch_ret;
    }
}

static void test_gated_rejection() {
    int dummy = 123;
    s_check_calls = 0;
    s_check_ret = 0;
    s_dispatch_calls = 0;

    int res = func_00328610(&dummy, 10, 20, 30, 40, 50);

    assert(res == 0);
    assert(s_check_calls == 1);
    assert(s_check_self == &dummy);
    assert(s_check_a2 == 20);
    assert(s_check_a3 == 30);
    assert(s_check_s7C != 0);
    assert(s_check_s7E != 0);
    assert(s_check_s78 != 0);
    assert(s_dispatch_calls == 0);
}

static void test_gated_acceptance() {
    int dummy = 456;
    s_check_calls = 0;
    s_check_ret = 1;
    s_dispatch_calls = 0;
    s_dispatch_ret = 777;

    int res = func_00328610(&dummy, 100, 200, 300, 400, 500);

    assert(res == 777);
    assert(s_check_calls == 1);
    assert(s_dispatch_calls == 1);
    assert(s_dispatch_self == &dummy);
    assert(s_dispatch_a1 == 100);
    assert(s_dispatch_a2 == 200);
    assert(s_dispatch_a3 == 300);
    assert(s_dispatch_a4 == 400);
    assert(s_dispatch_a5 == 500);
}

int main() {
    test_gated_rejection();
    test_gated_acceptance();
    return 0;
}
