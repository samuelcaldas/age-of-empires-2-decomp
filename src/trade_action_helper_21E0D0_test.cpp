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
static int last_a3 = 0;
static int last_a4 = 0;

extern "C" {
// Original branch citation: 0x21E188 -> func_0021DF50
void *func_0021DF50(void *obj, int a1, int a2, int a3, int a4) {
    df50_calls++;
    last_a1 = a1;
    last_a2 = a2;
    last_a3 = a3;
    last_a4 = a4;
    return obj;
}
}

void test_trade_action_helper_21E0D0() {
    df50_calls = 0;
    last_a1 = 0;
    last_a2 = 0;
    last_a3 = 0;
    last_a4 = 0;

    char dummy[32];
    int test_a1 = 10;
    int test_a2 = 20;
    int test_a3 = 3;
    int test_a4 = 2;

    // Call func_0021E0D0 (Original VRAM 0x21E0D0)
    void *res = func_0021E0D0(dummy, test_a1, test_a2, test_a3, test_a4);
    assert(res == dummy);
    assert(df50_calls == 1);

    // Verify argument forwarding and +2 offset calculation
    assert(last_a1 == test_a1 + 2);
    assert(last_a2 == test_a2 + 2);
    assert(last_a3 == test_a3);
    assert(last_a4 == test_a4);

    // Mutation test: ensure wrong offset (e.g. +1 instead of +2) fails assertion
    bool wrong_offset = (last_a1 == test_a1 + 1);
    assert(!wrong_offset);
}

int main() {
    test_trade_action_helper_21E0D0();
    return 0;
}
