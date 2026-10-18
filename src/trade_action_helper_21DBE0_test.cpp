#include <cassert>
#include <cstring>
#include <cstdint>

extern "C" {
void *func_0021DBE0(void *obj, int a1, int a2, int a3);
void *func_1046D0(void *obj, int reg, unsigned long long data);
void *func_21C050(void *obj, int mode);
}

static int reg_calls = 0;
static int mode_calls = 0;

extern "C" {
void *func_1046D0(void *obj, int reg, unsigned long long data) {
    reg_calls++;
    return obj;
}

void *func_21C050(void *obj, int mode) {
    mode_calls++;
    return obj;
}
}

void test_trade_action_helper_21DBE0() {
    reg_calls = 0;
    mode_calls = 0;
    char dummy[32];
    void *res = func_0021DBE0(dummy, 10, 20, 3);
    assert(res == dummy);
    assert(reg_calls == 3);
    assert(mode_calls == 1);

    void *null_res = func_0021DBE0(0, 10, 20, 3);
    assert(null_res == 0);
}

int main() {
    test_trade_action_helper_21DBE0();
    return 0;
}
