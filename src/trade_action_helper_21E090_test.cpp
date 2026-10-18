#include <cassert>
#include <cstring>
#include <cstdint>

extern "C" {
int func_0021E090(void *obj, int a1, int a2);
}

void test_trade_action_helper_21E090() {
    char dummy[32];

    // Test valid condition
    assert(func_0021E090(dummy, 20, 1) == 1);
    assert(func_0021E090(dummy, 19, 1) == 1);
    assert(func_0021E090(dummy, 20, 0) == 0);

    // Test invalid condition (wrong a1)
    assert(func_0021E090(dummy, 18, 1) == 0);

    // Test null safety
    assert(func_0021E090(0, 20, 1) == 0);

    // Mutation test: ensure wrong a1 comparison fails
    bool mutation_fails = (func_0021E090(dummy, 21, 1) == 1);
    assert(!mutation_fails);
}

int main() {
    test_trade_action_helper_21E090();
    return 0;
}
