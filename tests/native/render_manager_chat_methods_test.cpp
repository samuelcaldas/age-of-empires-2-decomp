#include "render_manager_chat_methods.h"
#include <cassert>
#include <cstdlib>

static int g_116f68_calls = 0;
static void *g_116f68_ptr = 0;

extern "C" {
void func_116F68(void *ptr) {
    g_116f68_calls++;
    g_116f68_ptr = ptr;
}
}

static void test_message_accessors_and_bounds() {
    ChatLog log = {};
    log.field_54[0] = (void *)0x1111;
    log.field_54[50] = (void *)0x2222;

    assert(func_001890a0(&log, 0) == (void *)0x1111);
    assert(func_001890a0(&log, 50) == (void *)0x2222);
    assert(func_001890a0(&log, -1) == 0);
    assert(func_001890a0(&log, 51) == 0);
}

static void test_clear_messages() {
    ChatLog log = {};
    log.field_54[5] = (void *)0xAAAA;
    log.field_124 = 15;
    g_116f68_calls = 0;

    func_001890e0(&log);
    assert(g_116f68_calls == 1);
    assert(g_116f68_ptr == (void *)0xAAAA);
    assert(log.field_54[5] == 0);
    assert(log.field_124 == 0);
}

static void test_scalars_and_arrays() {
    ChatLog log = {};
    func_00189150(&log, 123);
    assert(log.field_0 == 123);

    func_00189160(&log, 3, 456);
    assert(func_00189190(&log, 3) == 456);
    assert(func_00189190(&log, -1) == 0);
    assert(func_00189190(&log, 10) == 0);

    log.field_2C[4] = 789;
    assert(func_001891d0(&log, 4) == 789);
    assert(func_001891d0(&log, -1) == 0);
    assert(func_001891d0(&log, 10) == 0);

    func_00189200();
    func_00189210();
    assert(func_00189220() == 1);
    log.field_124 = 25;
    assert(func_00189230(&log) == 25);
    assert(func_00189240() == 50);
    log.field_120 = 99;
    assert(func_00189250(&log) == 99);
}

int main(int count, char **args) {
    if (count != 2) return 1;
    switch (std::atoi(args[1])) {
    case 0: test_message_accessors_and_bounds(); return 0;
    case 1: test_clear_messages(); return 0;
    case 2: test_scalars_and_arrays(); return 0;
    default: return 1;
    }
}
