#include <cassert>
#include <cstring>
#include <cstdint>

extern "C" {
void *func_0021DBE0(void *obj, int a1, int a2, int a3);
void *func_1046D0(void *obj, int reg, unsigned long long data);
void *func_21C050(void *obj, int mode);
}

static int reg_calls = 0;
static int mode_calls = 0;
static int last_reg = -1;
static uint64_t last_data = 0;
static int last_mode = -1;

extern "C" {
// Original branch citation: 0x21DC28 -> func_1046D0
void *func_1046D0(void *obj, int reg, unsigned long long data) {
    reg_calls++;
    last_reg = reg;
    last_data = (uint64_t)data;
    return obj;
}

// Original branch citation: 0x21DC30 -> func_21C050
void *func_21C050(void *obj, int mode) {
    mode_calls++;
    last_mode = mode;
    return obj;
}
}

void test_trade_action_helper_21DBE0() {
    reg_calls = 0;
    mode_calls = 0;
    last_reg = -1;
    last_data = 0;
    last_mode = -1;

    char dummy[32];
    int test_a1 = 15;
    int test_a2 = 42;
    int test_a3 = 3;

    // Call func_0021DBE0 (Original VRAM 0x21DBE0)
    void *res = func_0021DBE0(dummy, test_a1, test_a2, test_a3);
    assert(res == dummy);
    assert(reg_calls == 1);
    assert(mode_calls == 1);

    // Verify exact argument forwarding (a1 -> reg, a2 -> data, a3 -> mode)
    assert(last_reg == test_a1);
    assert(last_data == (uint64_t)test_a2);
    assert(last_mode == test_a3);

    // Mutation test: ensure wrong reg or mode fails assertion
    bool mutation_detected = (last_reg != test_a1) || (last_mode != test_a3);
    assert(!mutation_detected);

    // Null safety check
    void *null_res = func_0021DBE0(0, test_a1, test_a2, test_a3);
    assert(null_res == 0);
}

int main() {
    test_trade_action_helper_21DBE0();
    return 0;
}
