#include <cassert>
#include <cstring>
#include <cstdint>

extern "C" {
void *func_0021DD10(void *obj, int a1, int a2, int a3, int a4);
void *func_123908(void *);
void *func_1046D0(void *obj, int reg, unsigned long long data);
void *func_21C050(void *obj, int mode);
}

static int alloc_calls = 0;
static int reg_calls = 0;
static int mode_calls = 0;

extern "C" {
void *func_123908(void *) {
    alloc_calls++;
    static char dummy[32];
    return dummy;
}

void *func_1046D0(void *obj, int reg, unsigned long long data) {
    reg_calls++;
    return obj;
}

void *func_21C050(void *obj, int mode) {
    mode_calls++;
    return obj;
}
}

void test_trade_action_helper_21DD10() {
    alloc_calls = 0;
    reg_calls = 0;
    mode_calls = 0;
    char dummy[32];
    void *res = func_0021DD10(dummy, 1, 2, 3, 2);
    assert(res == dummy);
    assert(alloc_calls == 0);
    assert(reg_calls == 3); // 2 from loop + 1 for reg 0x04
    assert(mode_calls == 1);

    void *res_alloc = func_0021DD10(0, 1, 2, 3, 1);
    assert(res_alloc != 0);
    assert(alloc_calls == 1);
}

int main() {
    test_trade_action_helper_21DD10();
    return 0;
}
