#include <cassert>
#include <cstring>
#include <cstdint>

extern "C" {
void *func_0021DC50(void *obj, int a1, int a2, int a3);
void *func_123908(void *);
void *func_0021DBE0(void *obj, int a1, int a2, int a3);
}

static int alloc_calls = 0;
static int dbe0_calls = 0;

extern "C" {
void *func_123908(void *) {
    alloc_calls++;
    static char dummy[32];
    return dummy;
}

void *func_0021DBE0(void *obj, int a1, int a2, int a3) {
    dbe0_calls++;
    return obj;
}
}

void test_trade_action_helper_21DC50() {
    alloc_calls = 0;
    dbe0_calls = 0;
    char dummy[32];
    void *res = func_0021DC50(dummy, 1, 2, 3);
    assert(res == dummy);
    assert(alloc_calls == 0);
    assert(dbe0_calls == 1);

    void *res_alloc = func_0021DC50(0, 1, 2, 3);
    assert(res_alloc != 0);
    assert(alloc_calls == 1);
    assert(dbe0_calls == 2);
}

int main() {
    test_trade_action_helper_21DC50();
    return 0;
}
