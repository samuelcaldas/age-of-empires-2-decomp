#include <cassert>
#include <cstring>
#include <cstdint>

extern "C" {
void *func_0021DE20(void *obj, int a1, int a2, int a3, int a4);
void *func_0021DD10(void *obj, int a1, int a2, int a3, int a4);
}

static int dd10_calls = 0;
static int last_a2 = 0;

extern "C" {
void *func_0021DD10(void *obj, int a1, int a2, int a3, int a4) {
    dd10_calls++;
    last_a2 = a2;
    return obj;
}
}

void test_trade_action_helper_21DE20() {
    dd10_calls = 0;
    char dummy[32];
    void *res = func_0021DE20(dummy, 1, 10, 3, 2);
    assert(res == dummy);
    assert(dd10_calls == 1);
    assert(last_a2 == 15);
}

int main() {
    test_trade_action_helper_21DE20();
    return 0;
}
