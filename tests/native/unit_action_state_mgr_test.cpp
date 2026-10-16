#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "unit_action_state_mgr.h"

static int g_func_3675D0_called = 0;
static int g_func_1C9E00_called = 0;
static int g_func_26AD20_ret = 1;
static int g_func_26AD30_called = 0;
static int g_func_26AD60_called = 0;
static int g_last_flag = -1;

extern "C" {
    int func_123350(float val) { return (int)val; }
    void func_3675D0(void *arg0, int a1, int a2) {
        (void)arg0; (void)a1; (void)a2;
        g_func_3675D0_called++;
    }
    void func_1C9E00(void *arg0, int a1, int a2, int a3, int a4, int a5) {
        (void)arg0; (void)a1; (void)a2; (void)a3; (void)a4; (void)a5;
        g_func_1C9E00_called++;
    }
    char func_26AD20(void *action, int flag) {
        (void)action; (void)flag;
        return g_func_26AD20_ret;
    }
    void func_26AD30(void *action, int flag) {
        (void)action;
        g_func_26AD30_called++;
        g_last_flag = flag;
    }
    void func_26AD60(void *action, int flag) {
        (void)action;
        g_func_26AD60_called++;
        g_last_flag = flag;
    }
}

// Case 0: func_0026A460 coordinate rounding and helpers
static void test_func_0026A460() {
    g_func_3675D0_called = 0;
    g_func_1C9E00_called = 0;
    func_0026A460(nullptr, 1.0f, 2.0f);
    assert(g_func_3675D0_called == 0);

    char dummy[100];
    func_0026A460(dummy, 12.4f, 34.8f);
    assert(g_func_3675D0_called == 1);
    assert(g_func_1C9E00_called == 1);
}

// Case 1: func_0026A540 notification dispatch based on func_26AD20
static void test_func_0026A540() {
    char dummy[100];
    g_func_26AD30_called = 0;
    g_func_26AD60_called = 0;

    // Both called when func_26AD20 returns non-zero
    g_func_26AD20_ret = 1;
    func_0026A540(dummy, 7);
    assert(g_func_26AD30_called == 1);
    assert(g_func_26AD60_called == 1);
    assert(g_last_flag == 7);

    // Only 26AD30 called when func_26AD20 returns zero
    g_func_26AD20_ret = 0;
    g_func_26AD30_called = 0;
    g_func_26AD60_called = 0;
    func_0026A540(dummy, 9);
    assert(g_func_26AD30_called == 1);
    assert(g_func_26AD60_called == 0);
    assert(g_last_flag == 9);
}

// Case 2: func_0026A680 frame store and idempotence
static void test_func_0026A680() {
    char dummy[100];
    memset(dummy, 0, sizeof(dummy));
    dummy[0x35] = 3;

    func_0026A680(dummy, 5);
    assert((unsigned char)dummy[0x35] == 5);

    // Identical frame is no-op
    func_0026A680(dummy, 5);
    assert((unsigned char)dummy[0x35] == 5);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_func_0026A460();
        test_func_0026A540();
        test_func_0026A680();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_func_0026A460(); break;
        case 1: test_func_0026A540(); break;
        case 2: test_func_0026A680(); break;
        default: return 1;
    }
    return 0;
}
