#include "render_manager_device.h"
#include <cassert>
#include <cstdlib>

static int g_reset_calls = 0;
static int g_act1_fail = 0;
static int g_act2_fail = 0;
static int g_act3_fail = 0;
static int g_tail_calls = 0;

extern "C" {
int func_344580(void *dev) {
    assert(dev == (void *)0xAA00);
    g_reset_calls++;
    return 1;
}
int func_344840(void *dev) { assert(dev == (void *)0xAA00); return 101; }
int func_3448D0(void *dev) { assert(dev == (void *)0xAA00); return 202; }
int func_3447F0(void *dev) { assert(dev == (void *)0xAA00); return 303; }
int func_3445F0(void *dev) {
    assert(dev == (void *)0xAA00);
    return g_act1_fail ? 0 : 1;
}
int func_3445C0(void *dev, int a1) {
    assert(dev == (void *)0xAA00 && a1 == 0x55);
    return g_act2_fail ? 0 : 1;
}
int func_344640(void *dev, int a1, int a2) {
    assert(dev == (void *)0xAA00 && a1 == 0x66 && a2 == 1);
    return g_act3_fail ? 0 : 1;
}
int func_344920(void *dev) {
    assert(dev == (void *)0xAA00);
    g_tail_calls++;
    return 777;
}
}

static void test_reset(bool has_device) {
    RenderManagerDevice mgr;
    mgr.device = has_device ? (void *)0xAA00 : 0;
    g_reset_calls = 0;
    func_00185030(&mgr);
    assert(g_reset_calls == (has_device ? 1 : 0));
}

static void test_metrics() {
    RenderManagerDevice mgr;
    mgr.device = (void *)0xAA00;
    int o1 = 0, o2 = 0, o3 = 0;
    func_00185060(&mgr, &o1, &o2, &o3);
    assert(o1 == 101 && o2 == 202 && o3 == 303);
}

static void test_actuators(int fail_step) {
    RenderManagerDevice mgr;
    mgr.device = (void *)0xAA00;
    g_act1_fail = (fail_step == 1);
    g_act2_fail = (fail_step == 2);
    g_act3_fail = (fail_step == 3);
    int res = func_001850d0(&mgr, 0, 0x55, 0x66);
    assert(res == (fail_step == 0 ? 1 : 0));
}

static void test_tail_call() {
    RenderManagerDevice mgr;
    mgr.device = (void *)0xAA00;
    g_tail_calls = 0;
    int res = func_00185150(&mgr);
    assert(res == 777 && g_tail_calls == 1);
}

int main(int count, char **args) {
    if (count != 2) return 1;
    switch (std::atoi(args[1])) {
    case 0: test_reset(true); return 0;
    case 1: test_reset(false); return 0;
    case 2: test_metrics(); return 0;
    case 3: test_actuators(0); return 0;
    case 4: test_actuators(1); return 0;
    case 5: test_actuators(2); return 0;
    case 6: test_actuators(3); return 0;
    case 7: test_tail_call(); return 0;
    default: return 1;
    }
}
