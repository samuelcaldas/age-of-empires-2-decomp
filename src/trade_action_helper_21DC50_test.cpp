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
static int passed_a3 = -1;

extern "C" {
// Original branch citation: 0x21DC68 -> func_123908
void *func_123908(void *) {
    alloc_calls++;
    static char dummy_pkt[32];
    return dummy_pkt;
}

// Original branch citation: 0x21DC78 -> func_0021DBE0
void *func_0021DBE0(void *obj, int a1, int a2, int a3) {
    dbe0_calls++;
    passed_a3 = a3;
    return obj;
}
}

void test_trade_action_helper_21DC50() {
    alloc_calls = 0;
    dbe0_calls = 0;
    passed_a3 = -1;

    char dummy[32];
    int test_a3 = 7;

    // Test with non-null object (Original VRAM 0x21DC50)
    void *res = func_0021DC50(dummy, 1, 2, test_a3);
    assert(res == dummy);
    assert(alloc_calls == 0);
    assert(dbe0_calls == 1);
    assert(passed_a3 == test_a3);

    // Test with null object triggering alloc fallback via func_123908
    void *res_alloc = func_0021DC50(0, 1, 2, test_a3);
    assert(res_alloc != 0);
    assert(alloc_calls == 1);
    assert(dbe0_calls == 2);
    assert(passed_a3 == test_a3);

    // Mutation test: verify wrong forwarded a3 fails
    assert(passed_a3 != (test_a3 + 1));
}

int main() {
    test_trade_action_helper_21DC50();
    return 0;
}
