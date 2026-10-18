#include <cassert>
#include <cstring>
#include <cstdint>

extern "C" {
void *func_0021DCA0(void *obj, int a1, int a2, int a3);
void *func_0021DC50(void *obj, int a1, int a2, int a3);
}

static int dc50_calls = 0;
static int last_a1 = 0;
static int last_a2 = 0;

extern "C" {
void *func_0021DC50(void *obj, int a1, int a2, int a3) {
    dc50_calls++;
    last_a1 = a1;
    last_a2 = a2;
    return obj;
}
}

void test_trade_action_helper_21DCA0() {
    dc50_calls = 0;
    char dummy[32];
    void *res = func_0021DCA0(dummy, 10, 20, 5);
    assert(res == dummy);
    assert(dc50_calls == 1);
    assert(last_a1 == 11);
    assert(last_a2 == 21);
}

int main() {
    test_trade_action_helper_21DCA0();
    return 0;
}
