#include <cassert>
#include <cstring>
#include <cstdint>

extern "C" {
void *func_0021E0D0(void *obj, int a1, int a2, int a3, int a4);
void *func_0021DF50(void *obj, int a1, int a2, int a3, int a4);
}

static int df50_calls = 0;
static int last_a1 = 0;
static int last_a2 = 0;

extern "C" {
void *func_0021DF50(void *obj, int a1, int a2, int a3, int a4) {
    df50_calls++;
    last_a1 = a1;
    last_a2 = a2;
    return obj;
}
}

void test_trade_action_helper_21E0D0() {
    df50_calls = 0;
    char dummy[32];
    void *res = func_0021E0D0(dummy, 10, 20, 3, 2);
    assert(res == dummy);
    assert(df50_calls == 1);
    assert(last_a1 == 12);
    assert(last_a2 == 22);
}

int main() {
    test_trade_action_helper_21E0D0();
    return 0;
}
