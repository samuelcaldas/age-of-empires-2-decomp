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
// Original branch citation: 0x21DE48 -> func_0021DD10
void *func_0021DD10(void *obj, int a1, int a2, int a3, int a4) {
    dd10_calls++;
    last_a2 = a2;
    return obj;
}
}

void test_trade_action_helper_21DE20() {
    dd10_calls = 0;
    char dummy[32];
    int test_a2 = 10;

    // Call func_0021DE20 (Original VRAM 0x21DE20)
    void *res = func_0021DE20(dummy, 1, test_a2, 3, 2);
    assert(res == dummy);
    assert(dd10_calls == 1);
    assert(last_a2 == test_a2 + 5);

    // Mutation test: ensure wrong offset (e.g. +4) fails assertion
    bool wrong_offset = (last_a2 == test_a2 + 4);
    assert(!wrong_offset);
}

int main() {
    test_trade_action_helper_21DE20();
    return 0;
}
