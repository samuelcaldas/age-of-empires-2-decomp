#include "render_manager_chat_init.h"
#include <cassert>
#include <cstdlib>
#include <cstring>

static int g_189160_calls = 0;
static int g_189160_indices[16];

extern "C" {
void *func_117CAC(void *dst, int c, int n) {
    return std::memset(dst, c, n);
}

void func_00189160(ChatLog *self, int idx, int val) {
    (void)self;
    (void)val;
    if (g_189160_calls < 16) {
        g_189160_indices[g_189160_calls] = idx;
    }
    g_189160_calls++;
}
}

static void test_chat_init_basic() {
    ChatLog log = {};
    log.field_128 = 999;
    log.field_120 = 888;
    log.field_124 = 777;
    for (int i = 0; i < 51; i++) {
        log.field_54[i] = (void *)0x1234;
    }

    g_189160_calls = 0;
    ChatLog *res = func_00188df0(&log, 42);
    assert(res == &log);
    assert(log.field_0 == 42);
    assert(log.field_128 == 0);
    assert(log.field_120 == 0);
    assert(log.field_124 == 0);

    for (int i = 0; i < 51; i++) {
        assert(log.field_54[i] == 0);
    }

    assert(g_189160_calls == 10);
    for (int i = 0; i < 10; i++) {
        assert(g_189160_indices[i] == i);
    }
}

int main(int count, char **args) {
    if (count != 2) return 1;
    switch (std::atoi(args[1])) {
    case 0: test_chat_init_basic(); return 0;
    default: return 1;
    }
}
