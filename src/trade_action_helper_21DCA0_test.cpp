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
// Original branch citation: 0x21DCD0 -> func_0021DC50
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
    int test_a1 = 10;
    int test_a2 = 20;
    int test_a3 = 5;

    // Call func_0021DCA0 (Original VRAM 0x21DCA0)
    void *res = func_0021DCA0(dummy, test_a1, test_a2, test_a3);
    assert(res == dummy);
    assert(dc50_calls == 1);
    assert(last_a1 == test_a1 + 1);
    assert(last_a2 == test_a2 + 1);

    // Mutation test: ensure +0 instead of +1 fails assertion
    bool wrong_increment = (last_a1 == test_a1);
    assert(!wrong_increment);
}

int main() {
    test_trade_action_helper_21DCA0();
    return 0;
}
