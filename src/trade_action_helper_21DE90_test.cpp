#include <cassert>
#include <cstring>
#include <cstdint>

extern "C" {
void *func_0021DE90(void *obj, int a1, int a2, int a3, int a4);
void *func_0021DF50(void *obj, int a1, int a2, int a3, int a4);
void *func_221B60(void *obj);
void *func_221AC0(void *obj);
}

static int b60_calls = 0;
static int ac0_calls = 0;
static int df50_calls = 0;

extern "C" {
void *func_221B60(void *obj) {
    b60_calls++;
    return obj;
}

void *func_221AC0(void *obj) {
    ac0_calls++;
    return obj;
}

void *func_0021DF50(void *obj, int a1, int a2, int a3, int a4) {
    df50_calls++;
    return obj;
}
}

void test_trade_action_helper_21DE90() {
    b60_calls = 0;
    ac0_calls = 0;
    df50_calls = 0;
    char dummy[32];
    void *res = func_0021DE90(dummy, 1, 2, 3, 4);
    assert(res == dummy);
    assert(b60_calls == 2);
    assert(ac0_calls == 1);
    assert(df50_calls == 1);

    void *null_res = func_0021DE90(0, 1, 2, 3, 4);
    assert(null_res == 0);
}

int main() {
    test_trade_action_helper_21DE90();
    return 0;
}
